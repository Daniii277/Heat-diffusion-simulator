# Diseño en paralelo con OMP

El programa secuencial original contaba con una función que ejecutaba el algoritmo recorriendo la matriz de forma secuencial, pero encontramos que el mayor problema de rendimiento del programa no son las operaciones de la CPU, sino los accesos a memoria para leer datos. Cada vez que actualizamos una celda hay que leer 4 posiciones de la matriz de memoria, sumarlas y dividirlas. Para reducir el coste de los calculos se optó por multiplicar por un decimal, debido al coste de ciclos de la división.

Para tratar de mejorar la pérdida de rendimiento por los numerosos accesos a memoria se ha creado una nueva función, que dado un tamaño de bloques, recorre la matriz dividiendola en bloques, y no de forma secuencial. De esta forma aprovechamos la carga de bloques de datos a memoria caché para reducir los accesos a memoria principal, que suponen un gran coste.

```cpp
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
```


Para la implementación de openMP se ha optado por probar varias cabeceras pragma y comparar tiempos de cada versión obtenida y se han obtenido los siguientes resultados con matrices cuadradas de 2000 * 2000 elementos y 20000 iteraciones de tiempo:

- La versión secuencial del programa sin ningún paralelismo tardaba una media de **185,059 segundos** y para tratar de paralelizarlo se ha utilizado la directiva **#pragma omp for schedule(static)**, que reparte entre los nucleos de la cpu las iteraciones del bucle para su ejecución en paralelo y la directiva **pragma omp simd** , que vectoriza el bucle para aplicar la misma instrucción a múltiples datos. Se ha comprobado el rendimiento utilizando ambas directivas o solo una de ellas y se ha llegado a las siguientes conclusiones : 
    - La mejor configuración es la división en bloques de 16 o 24 elementos con una mejora de hasta un 5,5% frente a otras configuraciones de bloques.
    - La opción con omp con mejor rendimiento en general ha sido con las 2 directivas utilizadas a la vez, aunque la mejora frente a la distribución por bloques sin paralelizar no es tan amplía.
    - La función secuencial paralelizada no obtiene una mejora frente a su versión sin paralelizar.
    - Usando solo una directiva, obtiene mejor resultado el uso de **Pragma omp simd**.
    - La mejora de la versión secuencial frente a la versión por bloques paralelizada es de un 45%.