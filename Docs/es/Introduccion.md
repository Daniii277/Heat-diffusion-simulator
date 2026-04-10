# Sobre este proyecto

El objetivo de este proyecto es llevar a cabo una práctica universitaria con el objetivo de aprender a utilizar de manera óptima herramientas de paralelización mediante hardware y software, además de utilizar diversas técnicas o conceptos de optimización como la localidad espacial. No se pretende desarrollar un programa para uso profesional, puede contar con múltiples errores propios de un proyecto no colaborativo y con fines educativos. También serán bien valorados comentarios con el fin de aportar nuevos conocimientos o soluciones a problemas encontrados.


# Contexto del proyecto

Este proyecto consiste en simular la **difusión de calor** en una placa, en la cual el borde superior se encontrará a 100ºC y los bordes laterales e inferior a 0ºC para que haya difusión de calor con el paso del tiempo. Para simplificar la lógica de este proyecto, solo se tendrá en cuenta el calor de sus 4 vecinos más próximos (izquierda, derecha, arriba y abajo) y no todas sus vecindades. Por ello para el cálculo del calor con el paso del tiempo se utiliza un Stencil de 5 puntos simplificado que sigue la siguiente fórmula : 

### $$T_{i,j}^{t+1} = \frac{T_{i-1,j}^t + T_{i+1,j}^t + T_{i,j-1}^t + T_{i,j+1}^t}{4}$$

# Desarrollo del proyecto

Para llevar a cabo este proyecto de forma sencuencial, añadiendo los avances hasta la versión final con todas las optimizaciones aplicadas, se desarrollarán en diversas ramas las siguientes versiones :

- **Versión sencuencial** : Esta versión tendrá únicamente optimizaciones de código sin el uso de ninguna de las        tecnologías mencionadas. Se ejecutará de forma sencuencial y solo utilizará conceptos o técnicas de optimización aplicadas a la computación de altas prestaciones necesarias (Uso de templates, preprocesado, localidad espacial o temporal...).

- **Versión con openMP** : Se aplicará a la versión secuencial el uso de openMP para optimizar los procesos mediante paralelización por hardware.

- **Versión con MPI** : Se aplicará a la versión secuencial el uso de MPI para optimizar los procesos mediante paralelización por software con el uso de múltiples computadores.

- **Versión con Cuda** : Se aplicará a la versión sencuencial el uso de Cuda para optimizar los procesos mediante el uso de GPU. 

- **Versión con openMP/MPI** : Se unirá el uso de openMP y MPI para obtener una mayor paralelización de los procesos.

- **Versión con openMP/Cuda** : Se unirá el uso de openMP y Cuda para aprovechar el cómputo de GPU y la paralelización por hardware.

- **Versión con MPI/Cuda** : Se unirá el uso de MPI y Cuda para aprovechar el cómputo de GPU y la parelelización por software.

- **Versión final** : Se creará una versión final donde se utilicen todas las mejoras anteriores (openMP, MPI, Cuda...).

# Objetivo

El objetivo final del proyecto es el aprendizaje en el uso de las herramientas mencionadas y en análisis de las mejoras implementadas en las diversas versiones del proyecto. Para ello se tomarán medidas de tiempo de cada versión con el fin de encontrar las mejoras que aportan estas tecnologías.

Debido a que el uso de MPI supone disponer de varios computadores que ejecuten el programa, se tomarán medidas con un único computador gracias a la simulación de MPI de estos recursos y en caso de ser posible se utilizarán 3 computadores de los cuales se especificarán sus recursos en los análisis finales.

Para el uso de Cuda se dispondrá de la herramienta **Google Collab** que permite el uso de GPUs para ejecutar código online y posiblemente de un computador con una tarjeta gráfica de **Nvidia**.

Como se ha comentado, en los análisis se especificarán los detalles sobre la ejecución de las diversas versiones del programa y sobre el hardware donde se ejecutan para obtener unos resultados más precisos.
