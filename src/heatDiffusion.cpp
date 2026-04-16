#include "../include/heatDiffusion.hpp"
#include <iostream>

void heatDiffusionSequential(const std::vector<float>& matrix_old, std::vector<float>& matrix_new, const uint32_t matrixSize, const uint32_t rowSize){
    
    //#pragma omp for schedule(static)
    for (uint32_t i = rowSize; i < matrixSize - rowSize; i++) {

        // borde izquierdo/derecho
        if (i % rowSize == 0 || i % rowSize == rowSize - 1)
            continue;

        matrix_new[i] = (matrix_old[i - 1] + matrix_old[i + 1] + matrix_old[i - rowSize] + matrix_old[i + rowSize]) *0.25f;
    }
}


void heatDiffusionByBlocks(const std::vector<float>& matrix_old, std::vector<float>& matrix_new, const uint32_t matrixSize, const uint32_t rowSize){
    const uint32_t BLOCK = 32; // tamaño de bloque

    //#pragma omp for schedule(static)
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


void printMatrix(const std::vector<float>& matrix, uint32_t matrixSize, uint32_t rowSize){
    for (uint32_t i = 0; i < matrixSize; i++) {
        std::cout << matrix[i] << "  ";
        if ((i + 1) % rowSize == 0) {
            std::cout << "\n";
        }
    }
    std:: cout << std::endl;
}