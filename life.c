#include <stdio.h>
#include <windows.h> 


#define GRID_ROWS 20
#define GRID_COLS 20
#define ALIVE '*'
#define DEAD '.'

//inizializza la matrice
void INIT_GRID(char grid[GRID_ROWS][GRID_COLS]) {
    for (int i = 0; i < GRID_ROWS; i++) {
        for (int j = 0; j < GRID_COLS; j++) {
            grid[i][j] = DEAD;
        }
    }
}

//modifica la matrice
void MODIFICA_GRIGLIA(char grid[GRID_ROWS][GRID_COLS], int x, int y, char state){
    if (x >= 0 && x < GRID_ROWS && y >= 0 && y < GRID_COLS)
        grid[x][y] = state;
}

//conta le adiacenti vive
int CONTA_ADIACENTI(char grid[GRID_ROWS][GRID_COLS], int x, int y){
    int adj = 0;
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) continue;
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < GRID_ROWS && ny >= 0 && ny < GRID_COLS) {
                if (grid[nx][ny] == ALIVE)
                    adj++;
            }
        }
    }
    return adj;
}

//calcola la successiva generazione secondo le regole
void NEXT_GENERATION(char grid[GRID_ROWS][GRID_COLS]) {
    char next[GRID_ROWS][GRID_COLS];

    for (int i = 0; i < GRID_ROWS; i++) {
        for (int j = 0; j < GRID_COLS; j++) {
            int adj = CONTA_ADIACENTI(grid, i, j);

            if (grid[i][j] == ALIVE) {
                if (adj < 2 || adj > 3)
                    next[i][j] = DEAD;
                else
                    next[i][j] = ALIVE;
            } else {
                if (adj == 3)
                    next[i][j] = ALIVE;
                else
                    next[i][j] = DEAD;
            }
        }
    }


    for (int i = 0; i < GRID_ROWS; i++) {
        for (int j = 0; j < GRID_COLS; j++) {
            grid[i][j] = next[i][j];
        }
    }
}

//stampa la griglia
void STAMPA_GRID(char grid[GRID_ROWS][GRID_COLS]) {
    for (int i = 0; i < GRID_ROWS; i++) {
        for (int j = 0; j < GRID_COLS; j++) {
            printf("%c", grid[i][j]);
        }
        printf("\n"); 
    }
}


int main(void) {
    char grid[GRID_ROWS][GRID_COLS];
    INIT_GRID(grid);

    MODIFICA_GRIGLIA(grid, 5, 5, ALIVE);
    MODIFICA_GRIGLIA(grid, 5, 6, ALIVE);
    MODIFICA_GRIGLIA(grid, 5, 7, ALIVE);

    for (int i = 0; i < 20; i++) {
    printf("\033[H\033[J"); 
    printf("Generazione %d:\n", i);
    STAMPA_GRID(grid);
    NEXT_GENERATION(grid);
    Sleep(1000); 
    }

    return 0;
}
