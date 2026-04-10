# Sobre este projeto

O objetivo deste projeto é realizar uma prática universitária com o intuito de aprender a utilizar de forma ótima ferramentas de paralelização por hardware e software, além de aplicar diversas técnicas ou conceitos de otimização como a localidade espacial. Não se pretende desenvolver um programa para uso profissional; pode conter múltiplos erros próprios de um projeto não colaborativo e com fins educativos. Comentários também são muito bem-vindos para contribuir com novos conhecimentos ou soluções para os problemas encontrados.


# Contexto do projeto

Este projeto consiste em simular a **difusão de calor** em uma placa, na qual o bordo superior se encontra a 100°C e os bordos laterais e inferior a 0°C para que haja difusão de calor com o passar do tempo. Para simplificar a lógica deste projeto, apenas o calor dos seus 4 vizinhos mais próximos (esquerda, direita, cima e baixo) será considerado, e não toda a sua vizinhança. Por isso, para o cálculo do calor ao longo do tempo utiliza-se um stencil simplificado de 5 pontos que segue a seguinte fórmula:

### $$T_{i,j}^{t+1} = \frac{T_{i-1,j}^t + T_{i+1,j}^t + T_{i,j-1}^t + T_{i,j+1}^t}{4}$$

# Desenvolvimento do projeto

Para realizar este projeto de forma sequencial, adicionando os avanços até a versão final com todas as otimizações aplicadas, serão desenvolvidas em ramos separados as seguintes versões:

- **Versão sequencial**: Esta versão terá apenas otimizações de código sem o uso de nenhuma das tecnologias mencionadas. Será executada de forma sequencial e utilizará apenas conceitos ou técnicas de otimização aplicadas à computação de alto desempenho quando necessário (uso de templates, pré-processamento, localidade espacial ou temporal...).

- **Versão com OpenMP**: OpenMP será aplicado à versão sequencial para otimizar os processos por meio de paralelização por hardware.

- **Versão com MPI**: MPI será aplicado à versão sequencial para otimizar os processos por meio de paralelização por software com o uso de múltiplos computadores.

- **Versão com CUDA**: CUDA será aplicado à versão sequencial para otimizar os processos por meio do uso da GPU.

- **Versão com OpenMP/MPI**: Será combinado o uso de OpenMP e MPI para obter uma maior paralelização dos processos.

- **Versão com OpenMP/CUDA**: Será combinado o uso de OpenMP e CUDA para aproveitar o cálculo em GPU e a paralelização por hardware.

- **Versão com MPI/CUDA**: Será combinado o uso de MPI e CUDA para aproveitar o cálculo em GPU e a paralelização por software.

- **Versão final**: Será criada uma versão final onde serão utilizadas todas as melhorias anteriores (OpenMP, MPI, CUDA...).

# Objetivo

O objetivo final do projeto é o aprendizado no uso das ferramentas mencionadas e na análise das melhorias implementadas nas diversas versões do projeto. Para isso, serão realizadas medições de tempo de cada versão com o fim de avaliar as melhorias que estas tecnologias proporcionam.

Devido ao fato de que o uso de MPI requer vários computadores executando o programa, as medições serão feitas com um único computador graças à simulação de recursos MPI. Caso seja possível, serão utilizados 3 computadores, cujos recursos serão especificados nas análises finais.

Para o uso de CUDA será utilizada a ferramenta **Google Colab** que permite o uso de GPUs para executar código online e possivelmente um computador com uma placa gráfica **NVIDIA**.

Como mencionado, nas análises serão especificados os detalhes sobre a execução das diversas versões do programa e sobre o hardware onde são executadas para obter resultados mais precisos.