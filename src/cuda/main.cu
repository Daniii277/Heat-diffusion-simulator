#include <stdio.h>
#include <iostream>
#include <cstdint>
#include <vector>
#include <cuda_runtime.h>
#include "../include/heatDiffusion.hpp"
#include "../include/matrixGenerator.hpp"

int main(int argc, char* argv[]){
    uint32_t rowSize;
    uint32_t iter;
    std::cout << "Introduzca el número de dimensiones de la matriz cuadrada : " << std::endl;
    std::cin >> rowSize;
    std::cout << "Introduzca el número de iteraciones : " << std::endl;
    std::cin >> iter;
    size_t MATRIX_SIZE = rowSize * rowSize;
    size_t MATRIX_BYTES = MATRIX_SIZE * sizeof(float);
    //Creo el vector que contendrá la matriz con memoria contigua.
        std::vector<float> h_matrix_old = std::vector<float>(MATRIX_SIZE, 0.0f);
        std::vector<float> h_matrix_new = std::vector<float>(MATRIX_SIZE, 0.0f);
        generateMatrix(h_matrix_old, rowSize);
        generateMatrix(h_matrix_new, rowSize);

        //std::cout << "tamaño de la matriz : " << MATRIX_SIZE << std::endl;
        //std::cout << "Matriz inicial : " << std::endl;
        //printMatrix(h_matrix_old, MATRIX_SIZE, rowSize);

        //Programa de CUDA
        //Creación de punteros
        float *d_matrix_old = nullptr;
        float *d_matrix_new = nullptr;

        //Reserva de memoria
        cudaMalloc(&d_matrix_old, MATRIX_BYTES);
        cudaMalloc(&d_matrix_new, MATRIX_BYTES);

        //Copia de los datos a GPU
        cudaMemcpy(d_matrix_old,h_matrix_old.data(), MATRIX_BYTES, cudaMemcpyHostToDevice);
        cudaMemcpy(d_matrix_new, h_matrix_new.data(), MATRIX_BYTES, cudaMemcpyHostToDevice);

        //Ejecución del Kernel
        //Dimensiones de los bloques
        dim3 blockDim(16,16);
        //Elementos por bloque
        dim3 gridDim(rowSize / 16, rowSize / 16);
        //Lanzamiento del kernel
        for(int i = 0; i < iter; i++){
            heatDiffusionKernel<<<blockDim, gridDim>>>(d_matrix_old, d_matrix_new,rowSize);
            cudaDeviceSynchronize();
            std::swap(d_matrix_old, d_matrix_new);
        }
        //Copiar datos de la GPU
        cudaMemcpy(h_matrix_new.data(), d_matrix_new, MATRIX_BYTES, cudaMemcpyDeviceToHost);
        //Liberar punteros
        cudaFree(d_matrix_old);
        cudaFree(d_matrix_new);
        

        //std::cout << "El programa ha tardado : " << time.count() << " segundos" << std::endl;
}