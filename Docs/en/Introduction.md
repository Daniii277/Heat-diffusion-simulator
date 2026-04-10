# About this project

The objective of this project is to carry out a university assignment aimed at learning how to optimally use hardware and software parallelization tools, as well as applying various optimization techniques and concepts such as spatial locality. This is not intended to be a professional-grade program; it may contain multiple errors typical of a non-collaborative, educational project. Comments are also highly appreciated in order to contribute new knowledge or solutions to problems encountered.


# Project Context

This project consists of simulating **heat diffusion** on a plate, where the top edge is kept at 100°C and the side and bottom edges are kept at 0°C, allowing heat to diffuse over time. To simplify the logic of the project, only the heat from its 4 nearest neighbors (left, right, up, and down) is taken into account, rather than considering the full neighborhood. Therefore, the heat calculation over time uses a simplified 5-point stencil that follows this formula:

### $$T_{i,j}^{t+1} = \frac{T_{i-1,j}^t + T_{i+1,j}^t + T_{i,j-1}^t + T_{i,j+1}^t}{4}$$

# Project Development

To carry out this project sequentially, adding improvements until reaching the final version with all optimizations applied, the following versions will be developed in separate branches:

- **Sequential Version**: This version will only include code optimizations without using any of the mentioned technologies. It will run sequentially and will only use optimization concepts or techniques applied to high-performance computing when necessary (use of templates, preprocessing, spatial or temporal locality, etc.).

- **OpenMP Version**: OpenMP will be applied to the sequential version to optimize the processes through hardware parallelization.

- **MPI Version**: MPI will be applied to the sequential version to optimize the processes through software parallelization using multiple computers.

- **CUDA Version**: CUDA will be applied to the sequential version to optimize the processes by using the GPU.

- **OpenMP/MPI Version**: The use of OpenMP and MPI will be combined to achieve greater parallelization of the processes.

- **OpenMP/CUDA Version**: The use of OpenMP and CUDA will be combined to take advantage of GPU computing and hardware parallelization.

- **MPI/CUDA Version**: The use of MPI and CUDA will be combined to take advantage of GPU computing and software parallelization.

- **Final Version**: A final version will be created that incorporates all the previous improvements (OpenMP, MPI, CUDA, etc.).

# Objective

The ultimate goal of the project is to learn how to use the aforementioned tools and to analyze the improvements implemented in the different versions of the project. For this purpose, execution time measurements will be taken for each version in order to evaluate the benefits provided by these technologies.

Since using MPI requires several computers running the program, measurements will be taken on a single computer using MPI resource simulation. If possible, three computers will be used, and their specifications will be detailed in the final analysis.

For CUDA, the **Google Colab** tool will be used, which allows the execution of code online with GPUs, and possibly a computer with an **NVIDIA** graphics card.

As mentioned, the analyses will specify the details about the execution of the different program versions and the hardware on which they are run to obtain more accurate results.