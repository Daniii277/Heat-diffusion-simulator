#include <stdio.h>
#include <iostream>
#include <cstdint>
#include <vector>
#include <chrono>
#include "../include/heatDiffusion.hpp"
#include "../include/matrixGenerator.hpp"

int main(int argc, char* argv[]){
    uint32_t rowSize;
    uint32_t iter;
    std::cout << "Introduzca el número de dimensiones de la matriz cuadrada : " << std::endl;
    std::cin >> rowSize;
    std::cout << "Introduzca el número de iteraciones : " << std::endl;
    std::cin >> iter;
    uint32_t MATRIX_SIZE = rowSize * rowSize;
    //Creo el vector que contendrá la matriz con memoria contigua.
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
            heatDiffusionByBlocks(h_matrix_old, h_matrix_new, MATRIX_SIZE, rowSize, 16);
            //printMatrix(h_matrix_new, MATRIX_SIZE, rowSize);
            h_matrix_old.swap(h_matrix_new);
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> time = end - start;
        std::cout << "El programa ha tardado : " << time.count() << " segundos" << std::endl;
}