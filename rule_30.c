#include <stdio.h>
#include <windows.h>

#define GRID_COLS 50
#define GRID_ROWS 50

// Inizializza la griglia impostando tutte le celle a 0

void INIT_GRID(int *grid){
    int i;
    for ( i= 0; i < GRID_COLS; ++i){
        grid[i] = 0;
    }
}

// Stampa la riga corrente della griglia: '*' per celle attive, spazio per quelle inattive

void STAMPA_MATRICE(int *grid){
    for (int i = 0; i < GRID_COLS; ++i){
            if (grid[i] == 1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
}

// Applica la regola 30 sulla cella j, considerando la cella stessa e le due vicine

int RULE_30(int *grid, int j){
    int q, p, r;
    if ( j != 0 && j != GRID_COLS - 1){
        q = grid[j];
        p = grid[j - 1];
        r = grid[j + 1];
        return p ^ (q || r);
    } else {
        if (j == 0 || j == GRID_COLS - 1)
        return 0;
    }
}

// Calcola la generazione successiva secondo la regola 30 e aggiorna la griglia

void NEXT_GENERATION(int *grid){
    int j;
    int next_generation[GRID_COLS];
    next_generation[0] = 0;

    for (j = 1; j < GRID_COLS - 1; ++j){

        next_generation[j] = RULE_30(grid, j);
    }
    next_generation[GRID_COLS - 1] = 0;

    for (int i = 0; i < GRID_COLS; ++i){
        grid[i] = next_generation[i];
    }

}
int main (void){
    int i;
    int grid[GRID_COLS];
    INIT_GRID(grid);
    grid[GRID_COLS / 2] = 1;

    // Loop di simulazione che stampa e aggiorna la griglia per GRID_ROWS volte
    
    for (i = 0; i < GRID_ROWS; i++){
        STAMPA_MATRICE(grid);
        NEXT_GENERATION(grid);
        Sleep(500);
    }
}