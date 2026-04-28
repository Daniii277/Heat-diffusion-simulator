#include <stdint.h>
#include <stdlib.h>
#include <vector>
#include "../include/matrixGenerator.hpp"

void generateMatrix(std::vector<float>& matrix, const uint32_t size){
    //Relleno el borde superior que valdrá 100ºC
    for(uint32_t i = 0; i < size; i++){
        matrix[i] = 100.0;
    }
}