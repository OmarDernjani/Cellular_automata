
# 🧬 Gioco della Vita - Conway's Game of Life in C

Questo è un semplice progetto in linguaggio C che implementa il famoso **Gioco della Vita** di John Conway, una simulazione di automi cellulari su una griglia bidimensionale.

## 📜 Descrizione

Il Gioco della Vita è una simulazione a zero giocatori dove una griglia di celle può essere "vive" o "morte". La simulazione evolve automaticamente secondo regole precise, basate sul numero di celle vive adiacenti.

Le regole sono:

- Una cella viva con meno di 2 vicine vive muore (sotto-popolazione).
- Una cella viva con 2 o 3 vicine vive sopravvive.
- Una cella viva con più di 3 vicine vive muore (sovra-popolazione).
- Una cella morta con esattamente 3 vicine vive prende vita (riproduzione).

## ⚙️ Funzionalità

- Griglia di dimensioni 20x20.
- Inizializzazione e modifica manuale dello stato delle celle.
- Evoluzione automatica della griglia ad ogni generazione.
- Visualizzazione della griglia in console.
- Simulazione animata (aggiornamento ogni secondo).

## 🛠️ Requisiti

- Compilatore C (es. GCC)
- Sistema Windows (usa `Sleep()` da `windows.h`)
- Terminale compatibile con escape sequences ANSI (`\033[H\033[J` per pulizia schermo)

## ▶️ Esecuzione

### Compilazione

Puoi compilare il programma con `gcc`:

```bash
gcc -o game_of_life game_of_life.c
```

### Avvio

```bash
game_of_life.exe
```

### Output

Il programma visualizzerà in console l'evoluzione della griglia, mostrando ogni generazione con un secondo di pausa tra una e l'altra.

## 🧩 Esempio di Pattern Iniziale

Nel `main()` viene creato un **oscillatore orizzontale** (blinker):

```c
MODIFICA_GRIGLIA(grid, 5, 5, ALIVE);
MODIFICA_GRIGLIA(grid, 5, 6, ALIVE);
MODIFICA_GRIGLIA(grid, 5, 7, ALIVE);
```

## 📂 Struttura del Codice

- `INIT_GRID`: inizializza tutta la griglia a celle morte.
- `MODIFICA_GRIGLIA`: modifica una singola cella (viva o morta).
- `CONTA_ADIACENTI`: conta quante celle vive ci sono attorno a una cella.
- `NEXT_GENERATION`: genera la prossima generazione secondo le regole del gioco.
- `STAMPA_GRID`: stampa la griglia sul terminale.

## 📌 Note

- La simulazione è limitata a una griglia di 20x20 per semplicità.
- I bordi della griglia non sono ciclici (non avvolgono).
- Usa `Sleep(1000)` per la pausa (Windows). Su Linux puoi sostituirlo con `sleep(1)` dopo aver incluso `unistd.h`.

## 📄 Licenza

Questo progetto è rilasciato con licenza MIT. Sentiti libero di modificarlo e utilizzarlo per scopi didattici o personali.
