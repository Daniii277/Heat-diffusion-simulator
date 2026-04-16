# Diseño secuencial del programa

Para la ejecución secuencial del programa se ha implementado :

Una función para la inicialización de los valores de los bordes de la matriz de celdas, que en este caso es sencilla al solo tener que asignar un valor de 100 a cada celda de la primera fila (borde superior).

```cpp
void generateMatrix(std::vector<float>& matrix, const uint32_t size){
    //Relleno el borde superior que valdrá 100ºC
    for(uint32_t i = 0; i < size; i++){
        matrix[i] = 100.0;
    }
}
```

Una función para imprimir las celdas de la matriz por consola.

```cpp
void printMatrix(const std::vector<float>& matrix, uint32_t matrixSize, uint32_t rowSize){
    for (uint32_t i = 0; i < matrixSize; i++) {
        std::cout << matrix[i] << "  ";
        if ((i + 1) % rowSize == 0) {
            std::cout << "\n";
        }
    }
    std:: cout << std::endl;
}
```

Una función principal que contiene el algoritmo de difusión de calor, que consiste en un stencil de 5 puntos simplificado, donde el nuevo valor de cada celda es la media de los valores de sus 4 celdas vecinas (arriba, abajo, izquierda y derecha). Para mejorar el rendimiento con la operación de difusión, se ha sustituido la división entre 4 por una multiplicación decimal, que resulta menos costosa para la CPU.

```cpp
void heatDiffusion(const std::vector<float>& matrix_old, std::vector<float>& matrix_new, const uint32_t matrixSize, const uint32_t rowSize){
    for (uint32_t i = rowSize; i < matrixSize - rowSize; i++) {

        // borde izquierdo/derecho
        if (i % rowSize == 0 || i % rowSize == rowSize - 1)
            continue;

        matrix_new[i] = (matrix_old[i - 1] + matrix_old[i + 1] + matrix_old[i - rowSize] + matrix_old[i + rowSize]) *0.25;
    }
}
```

El programa principal pide por consola el tamaño de la matriz y las iteraciones de tiempo que se van a ejecutar, crea una matriz para contener los valores iniciales de cada iteración y otra matriz para guardar los nuevos valores calculados evitando conflictos de lectura errónea. Ejecuta el algoritmo el número de unidades de tiempo especificado y se da la duración de la ejecución del algoritmo.

