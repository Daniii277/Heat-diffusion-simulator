#include <stdio.h>
#include <iostream>
#include <cstdint>
#include <vector>
#include <chrono>
#include "../include/heatDiffusion.hpp"
#include "../include/matrixGenerator.hpp"

int main(int argc, char* argv[]){
    uint32_t matrixSize;
    uint32_t iter;
    std::cout << "Introduzca el número de dimensiones de la matriz : " << std::endl;
    std::cin >> matrixSize;
    std::cout << "Introduzca el número de iteraciones : " << std::endl;
    std::cin >> iter;

    //Creo el vector que contendrá la matriz con memoria contigua.
    std::vector<float> h_matrix = std::vector<float>(matrixSize, 0.0);
    generateMatrix(&h_matrix, matrixSize);
    auto start = std::chrono::high_resolution_clock::now();
    heatDiffusion(&h_matrix, matrixSize);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracion = end - start;

    std::cout << "El programa ha durado " << duracion.count() << " segundos";

    return 0;
}