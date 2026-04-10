# Über dieses Projekt

Das Ziel dieses Projekts ist es, eine universitäre Übung durchzuführen, um optimal den Umgang mit Hardware- und Software-Parallelisierungswerkzeugen zu erlernen sowie verschiedene Optimierungstechniken und -konzepte wie die räumliche Lokalität anzuwenden. Es handelt sich nicht um die Entwicklung eines professionellen Programms; es kann mehrere Fehler enthalten, die für ein nicht-kollaboratives, bildendes Projekt typisch sind. Kommentare sind ebenfalls sehr willkommen, um neues Wissen oder Lösungen für aufgetretene Probleme beizusteuern.


# Projektkontext

Dieses Projekt besteht darin, die **Wärmeausbreitung** auf einer Platte zu simulieren, bei der der obere Rand auf 100°C gehalten wird und die seitlichen sowie der untere Rand auf 0°C, damit Wärme mit der Zeit diffundiert. Zur Vereinfachung der Projektlogik wird nur die Wärme der 4 nächsten Nachbarn (links, rechts, oben und unten) berücksichtigt und nicht das gesamte Nachbarschaftsfeld. Daher wird für die Wärmeberechnung über die Zeit ein vereinfachtes 5-Punkt-Stencil verwendet, das folgender Formel folgt:

### $$T_{i,j}^{t+1} = \frac{T_{i-1,j}^t + T_{i+1,j}^t + T_{i,j-1}^t + T_{i,j+1}^t}{4}$$

# Projektentwicklung

Um dieses Projekt sequentiell durchzuführen und schrittweise bis zur finalen Version mit allen Optimierungen zu gelangen, werden die folgenden Versionen in separaten Branches entwickelt:

- **Sequenzielle Version**: Diese Version enthält ausschließlich Code-Optimierungen ohne Verwendung der genannten Technologien. Sie läuft sequentiell und verwendet nur Optimierungskonzepte der Hochleistungsrechnung, wenn nötig (Templates, Preprocessing, räumliche oder zeitliche Lokalität usw.).

- **OpenMP-Version**: OpenMP wird auf die sequenzielle Version angewendet, um die Prozesse durch Hardware-Parallelisierung zu optimieren.

- **MPI-Version**: MPI wird auf die sequenzielle Version angewendet, um die Prozesse durch Software-Parallelisierung mit mehreren Computern zu optimieren.

- **CUDA-Version**: CUDA wird auf die sequenzielle Version angewendet, um die Prozesse durch die Nutzung der GPU zu optimieren.

- **OpenMP/MPI-Version**: Die Kombination von OpenMP und MPI wird verwendet, um eine höhere Parallelisierung der Prozesse zu erreichen.

- **OpenMP/CUDA-Version**: Die Kombination von OpenMP und CUDA wird verwendet, um die GPU-Berechnung und die Hardware-Parallelisierung zu nutzen.

- **MPI/CUDA-Version**: Die Kombination von MPI und CUDA wird verwendet, um die GPU-Berechnung und die Software-Parallelisierung zu nutzen.

- **Finale Version**: Es wird eine finale Version erstellt, die alle vorherigen Verbesserungen integriert (OpenMP, MPI, CUDA...).

# Ziel

Das endgültige Ziel des Projekts ist das Erlernen der genannten Tools und die Analyse der implementierten Verbesserungen in den verschiedenen Versionen. Zu diesem Zweck werden Zeitmessungen für jede Version durchgeführt, um die Vorteile dieser Technologien zu bewerten.

Da die Nutzung von MPI mehrere Computer erfordert, werden die Messungen auf einem einzelnen Computer mit MPI-Simulation durchgeführt. Falls möglich, werden drei Computer verwendet, deren technische Daten in der Abschlussanalyse angegeben werden.

Für CUDA wird das Tool **Google Colab** verwendet, das die Ausführung von Code online mit GPUs ermöglicht, und gegebenenfalls ein Computer mit einer **NVIDIA**-Grafikkarte.

Wie bereits erwähnt, werden in den Analysen die Details zur Ausführung der verschiedenen Programmversionen und zur verwendeten Hardware angegeben, um möglichst genaue Ergebnisse zu erhalten.