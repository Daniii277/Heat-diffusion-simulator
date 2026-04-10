# À propos de ce projet

L'objectif de ce projet est de réaliser un travail universitaire dans le but d'apprendre à utiliser de manière optimale les outils de parallélisation matérielle et logicielle, ainsi que d'appliquer diverses techniques ou concepts d'optimisation tels que la localité spatiale. Il ne s'agit pas de développer un programme à usage professionnel ; il peut contenir de nombreuses erreurs typiques d'un projet non collaboratif à visée éducative. Les commentaires sont également les bienvenus afin d'apporter de nouvelles connaissances ou des solutions aux problèmes rencontrés.


# Contexte du projet

Ce projet consiste à simuler la **diffusion de chaleur** sur une plaque, dans laquelle le bord supérieur est maintenu à 100°C et les bords latéraux et inférieur à 0°C afin qu'il y ait diffusion de chaleur au fil du temps. Pour simplifier la logique de ce projet, seul le chaleur provenant de ses 4 voisins les plus proches (gauche, droite, haut et bas) est pris en compte, et non l'ensemble de son voisinage. C'est pourquoi le calcul de la chaleur au fil du temps utilise un stencil simplifié à 5 points qui suit la formule suivante :

### $$T_{i,j}^{t+1} = \frac{T_{i-1,j}^t + T_{i+1,j}^t + T_{i,j-1}^t + T_{i,j+1}^t}{4}$$

# Développement du projet

Pour réaliser ce projet de manière séquentielle, en ajoutant les avancées jusqu'à la version finale avec toutes les optimisations appliquées, les versions suivantes seront développées dans des branches distinctes :

- **Version séquentielle** : Cette version n'inclura que des optimisations de code sans utiliser aucune des technologies mentionnées. Elle s'exécutera de manière séquentielle et n'utilisera que des concepts ou techniques d'optimisation appliqués au calcul haute performance lorsque nécessaire (utilisation de templates, prétraitement, localité spatiale ou temporelle...).

- **Version avec OpenMP** : OpenMP sera appliqué à la version séquentielle pour optimiser les processus par parallélisation matérielle.

- **Version avec MPI** : MPI sera appliqué à la version séquentielle pour optimiser les processus par parallélisation logicielle à l'aide de plusieurs ordinateurs.

- **Version avec CUDA** : CUDA sera appliqué à la version séquentielle pour optimiser les processus en utilisant le GPU.

- **Version avec OpenMP/MPI** : L'utilisation d'OpenMP et MPI sera combinée pour obtenir une plus grande parallélisation des processus.

- **Version avec OpenMP/CUDA** : L'utilisation d'OpenMP et CUDA sera combinée pour profiter du calcul GPU et de la parallélisation matérielle.

- **Version avec MPI/CUDA** : L'utilisation de MPI et CUDA sera combinée pour profiter du calcul GPU et de la parallélisation logicielle.

- **Version finale** : Une version finale sera créée où toutes les améliorations précédentes seront utilisées (OpenMP, MPI, CUDA...).

# Objectif

L'objectif final du projet est l'apprentissage de l'utilisation des outils mentionnés et l'analyse des améliorations implémentées dans les différentes versions du projet. Pour cela, des mesures de temps d'exécution seront prises pour chaque version afin d'évaluer les gains apportés par ces technologies.

Étant donné que l'utilisation de MPI nécessite plusieurs ordinateurs exécutant le programme, les mesures seront effectuées sur un seul ordinateur grâce à la simulation des ressources MPI. Si possible, trois ordinateurs seront utilisés, dont les caractéristiques seront précisées dans les analyses finales.

Pour CUDA, l'outil **Google Colab** sera utilisé, qui permet l'exécution de code en ligne avec des GPUs, et éventuellement un ordinateur équipé d'une carte graphique **NVIDIA**.

Comme mentionné, les analyses préciseront les détails sur l'exécution des différentes versions du programme et sur le matériel sur lequel elles sont exécutées afin d'obtenir des résultats plus précis.