#include "../include/heatDiffusion.hpp"
#include <iostream>

void heatDiffusionSequential(const std::vector<float>& matrix_old, std::vector<float>& matrix_new, const uint32_t matrixSize, const uint32_t rowSize){
    
    #pragma omp for schedule(static)
    for (uint32_t i = rowSize; i < matrixSize - rowSize; i++) {

        // borde izquierdo/derecho
        if (i % rowSize == 0 || i % rowSize == rowSize - 1)
            continue;

        matrix_new[i] = (matrix_old[i - 1] + matrix_old[i + 1] + matrix_old[i - rowSize] + matrix_old[i + rowSize]) *0.25f;
    }
}


void heatDiffusionByBlocks(const std::vector<float>& matrix_old, std::vector<float>& matrix_new, const uint32_t matrixSize, const uint32_t rowSize, const uint32_t blockSize){
    const uint32_t BLOCK = blockSize; // tamaño de bloque

    #pragma omp for schedule(static)
    for (uint32_t rowBlock = 1; rowBlock < rowSize - 1; rowBlock += BLOCK) {
        #pragma omp simd
        for (uint32_t colBlock = 1; colBlock < rowSize - 1; colBlock += BLOCK) {
            for (uint32_t row = rowBlock; row < std::min(rowBlock + BLOCK, rowSize - 1); row++) {
                for (uint32_t col = colBlock; col < std::min(colBlock + BLOCK, rowSize - 1); col++) {
                    uint32_t i = row * rowSize + col;
                    matrix_new[i] = (matrix_old[i-1] + matrix_old[i+1] +
                                     matrix_old[i-rowSize] + matrix_old[i+rowSize]) * 0.25f;
                }
            }
        }
    }
}


double countTimeByBlocks(const uint32_t BlockSize, const uint32_t &MATRIX_SIZE, const uint32_t &rowSize, const uint32_t& iter, const uint32_t times){
    
    std::chrono::duration<double> time(0);
    for(int i = 0; i < times; i++){
        std::vector<float> h_matrix_old = std::vector<float>(MATRIX_SIZE, 0.0f);
        std::vector<float> h_matrix_new = std::vector<float>(MATRIX_SIZE, 0.0f);
        generateMatrix(h_matrix_old, rowSize);
        generateMatrix(h_matrix_new, rowSize);

        //std::cout << "tamaño de la matriz : " << MATRIX_SIZE << std::endl;
        //std::cout << "Matriz inicial : " << std::endl;
        //printMatrix(h_matrix_old, MATRIX_SIZE, rowSize);

        auto start = std::chrono::high_resolution_clock::now();
        for(uint32_t i = 0; i < iter; i++){
            //std::cout << "iteración " << i+1 << std::endl;
            heatDiffusionByBlocks(h_matrix_old, h_matrix_new, MATRIX_SIZE, rowSize, BlockSize);
            //printMatrix(h_matrix_new, MATRIX_SIZE, rowSize);
            h_matrix_old.swap(h_matrix_new);
        }
        auto end = std::chrono::high_resolution_clock::now();
        time += end - start;
    }
    double timeBlocks = time.count()/times;
    return timeBlocks;

}


void printMatrix(const std::vector<float>& matrix, uint32_t matrixSize, uint32_t rowSize){
    for (uint32_t i = 0; i < matrixSize; i++) {
        std::cout << matrix[i] << "  ";
        if ((i + 1) % rowSize == 0) {
            std::cout << "\n";
        }
    }
    std:: cout << std::endl;
}