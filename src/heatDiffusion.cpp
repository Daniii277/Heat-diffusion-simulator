#include "../include/heatDiffusion.hpp"
#include <iostream>

void heatDiffusion(const std::vector<float>& matrix_old, std::vector<float>& matrix_new, const uint32_t matrixSize, const uint32_t rowSize){
    for (uint32_t i = rowSize; i < matrixSize - rowSize; i++) {

        // borde izquierdo/derecho
        if (i % rowSize == 0 || i % rowSize == rowSize - 1)
            continue;

        matrix_new[i] = (matrix_old[i - 1] + matrix_old[i + 1] + matrix_old[i - rowSize] + matrix_old[i + rowSize]) / 4.0f;
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