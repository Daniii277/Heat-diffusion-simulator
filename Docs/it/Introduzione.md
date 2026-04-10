# Informazioni su questo progetto

L'obiettivo di questo progetto è svolgere un'esercitazione universitaria con lo scopo di imparare a utilizzare in modo ottimale strumenti di parallelizzazione hardware e software, oltre ad applicare varie tecniche o concetti di ottimizzazione come la località spaziale. Non si intende sviluppare un programma per uso professionale; può contenere numerosi errori tipici di un progetto non collaborativo a fini didattici. Sono anche molto apprezzati i commenti per contribuire con nuove conoscenze o soluzioni ai problemi riscontrati.


# Contesto del progetto

Questo progetto consiste nella simulazione della **diffusione di calore** su una piastra, nella quale il bordo superiore è mantenuto a 100°C e i bordi laterali e inferiore a 0°C in modo che ci sia diffusione di calore nel tempo. Per semplificare la logica di questo progetto, si considera solo il calore dei suoi 4 vicini più prossimi (sinistra, destra, sopra e sotto) e non l'intera vicinanza. Per questo motivo, il calcolo del calore nel tempo utilizza uno stencil semplificato a 5 punti che segue la seguente formula:

### $$T_{i,j}^{t+1} = \frac{T_{i-1,j}^t + T_{i+1,j}^t + T_{i,j-1}^t + T_{i,j+1}^t}{4}$$

# Sviluppo del progetto

Per realizzare questo progetto in modo sequenziale, aggiungendo progressivamente le migliorie fino alla versione finale con tutte le ottimizzazioni applicate, le seguenti versioni saranno sviluppate in rami separati:

- **Versione sequenziale**: Questa versione conterrà solo ottimizzazioni del codice senza l'uso di alcuna delle tecnologie menzionate. Verrà eseguita in modo sequenziale e utilizzerà solo concetti o tecniche di ottimizzazione applicati al calcolo ad alte prestazioni quando necessario (uso di template, preprocessing, località spaziale o temporale...).

- **Versione con OpenMP**: OpenMP verrà applicato alla versione sequenziale per ottimizzare i processi tramite parallelizzazione hardware.

- **Versione con MPI**: MPI verrà applicato alla versione sequenziale per ottimizzare i processi tramite parallelizzazione software utilizzando più computer.

- **Versione con CUDA**: CUDA verrà applicato alla versione sequenziale per ottimizzare i processi utilizzando la GPU.

- **Versione con OpenMP/MPI**: Verrà combinato l'uso di OpenMP e MPI per ottenere una maggiore parallelizzazione dei processi.

- **Versione con OpenMP/CUDA**: Verrà combinato l'uso di OpenMP e CUDA per sfruttare il calcolo GPU e la parallelizzazione hardware.

- **Versione con MPI/CUDA**: Verrà combinato l'uso di MPI e CUDA per sfruttare il calcolo GPU e la parallelizzazione software.

- **Versione finale**: Verrà creata una versione finale che utilizzi tutti i miglioramenti precedenti (OpenMP, MPI, CUDA...).

# Obiettivo

L'obiettivo finale del progetto è l'apprendimento dell'uso degli strumenti menzionati e l'analisi dei miglioramenti implementati nelle varie versioni del progetto. A tal fine, verranno effettuate misurazioni del tempo di esecuzione di ogni versione per valutare i benefici apportati da queste tecnologie.

Poiché l'uso di MPI richiede diversi computer che eseguano il programma, le misurazioni saranno effettuate su un singolo computer grazie alla simulazione delle risorse MPI. Se possibile, verranno utilizzati tre computer, di cui saranno specificate le caratteristiche nelle analisi finali.

Per CUDA verrà utilizzato lo strumento **Google Colab**, che permette l'esecuzione di codice online con GPU, e possibilmente un computer con una scheda grafica **NVIDIA**.

Come già detto, nelle analisi verranno specificati i dettagli sull'esecuzione delle diverse versioni del programma e sull'hardware su cui vengono eseguite per ottenere risultati più precisi.