# Automa Cellulare - Regola 30

## Descrizione
Questo progetto implementa un automa cellulare unidimensionale basato sulla **Regola 30** di Stephen Wolfram.  
La simulazione utilizza una griglia di 50 celle che evolve nel tempo e viene visualizzata in console, mostrando l’evoluzione dello stato delle celle.

La Regola 30 è un esempio classico di come regole semplici possano generare pattern complessi e caotici partendo da condizioni iniziali semplici.

## Funzionalità
- Inizializza una riga con tutte le celle inattive (0), tranne quella centrale che è attiva (1).
- Calcola la generazione successiva applicando la Regola 30.
- Visualizza ogni generazione in console, usando `*` per celle attive e spazi per quelle inattive.
- Aggiorna la visualizzazione ogni 500 millisecondi per un totale di 50 generazioni.

## Requisiti
- Sistema operativo Windows (la funzione `Sleep` usata per la pausa è specifica di Windows).
- Compilatore C compatibile con lo standard C99 o superiore (es. GCC, MSVC).

## Come usare
1. Clona o scarica questo repository.
2. Compila il file sorgente con un compilatore C. Ad esempio, da terminale usando GCC:
   ```bash
   gcc -o regola30 regola30.c
   ```
3. Esegui il programma:
   ```bash
   ./regola30
   ```
4. Osserva l’evoluzione della griglia nella console.

## Struttura del codice
- `INIT_GRID(int *grid)`: inizializza la griglia impostando tutte le celle a 0.
- `STAMPA_MATRICE(int *grid)`: stampa la griglia corrente sulla console, rappresentando le celle attive con `*`.
- `RULE_30(int *grid, int j)`: calcola lo stato della cella `j` nella generazione successiva secondo la Regola 30.
- `NEXT_GENERATION(int *grid)`: calcola e aggiorna la griglia alla generazione successiva.
- `main()`: inizializza la griglia con un singolo punto attivo al centro e avvia la simulazione.

## Note
- I bordi della griglia sono considerati inattivi (0) e non cambiano mai.
- La Regola 30 è nota per generare comportamenti complessi da regole semplici.
- La pausa tra le generazioni è gestita tramite la funzione `Sleep` della libreria Windows, quindi il programma è specifico per ambienti Windows.

---

## Autore
Omar Dernjani

## Data
2025


## Licenza
Questo progetto è rilasciato sotto licenza MIT. Consulta il file LICENSE per i dettagli.
