#include <vector>
#include <cstdint>
#include <chrono>
#include "../include/matrixGenerator.hpp"

void heatDiffusionSequential(const std::vector<float>& matrix_old, std::vector<float>& matrix_new, const uint32_t matrixSize, const uint32_t rowSize);

void heatDiffusionByBlocks(const std::vector<float>& matrix_old, std::vector<float>& matrix_new, const uint32_t matrixSize, const uint32_t rowSize, const uint32_t blockSize);

void printMatrix(const std::vector<float>& matrix, uint32_t matrixSize, uint32_t rowSize);

double countTimeByBlocks(const uint32_t BlockSize, const uint32_t &MATRIX_SIZE, const uint32_t &rowSize, const uint32_t& iter, const uint32_t times);

__global__ void heatDiffusionKernel(const float* matrix_old, float* matrix_new, const uint32_t rowSize);
