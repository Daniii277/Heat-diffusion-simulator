#include <vector>
#include <cstdint>

void heatDiffusionSequential(const std::vector<float>& matrix_old, std::vector<float>& matrix_new, const uint32_t matrixSize, const uint32_t rowSize);

void heatDiffusionByBlocks(const std::vector<float>& matrix_old, std::vector<float>& matrix_new, const uint32_t matrixSize, const uint32_t rowSize);

void printMatrix(const std::vector<float>& matrix, uint32_t matrixSize, uint32_t rowSize);
