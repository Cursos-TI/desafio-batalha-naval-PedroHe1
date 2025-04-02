#include <stdio.h>

#define SIZE 10       // Tamanho do tabuleiro
#define SKILL 5  // Tamanho da matriz de habilidades

// Tabuleiro 10x10
int board[SIZE][SIZE] = {0};

// Matrizes das habilidades
int coneSkill[SKILL][SKILL] = {
    {0, 0, 1, 0, 0},
    {0, 1, 1, 1, 0},
    {1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
};

int crossSkill[SKILL][SKILL] = {
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {1, 1, 1, 1, 1},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0}
};

int octahedronSkill[SKILL][SKILL] = {
    {0, 0, 1, 0, 0},
    {0, 1, 1, 1, 0},
    {1, 1, 1, 1, 1},
    {0, 1, 1, 1, 0},
    {0, 0, 1, 0, 0}
};

// Aplica a habilidade no tabuleiro com base na matriz da habilidade
void applySkill(int skill[SKILL][SKILL], int originX, int originY) {
    int offset = SKILL / 2; // Define o centro da matriz

    for (int i = 0; i < SKILL; i++) {
        for (int j = 0; j < SKILL; j++) {
            int x = originX + i - offset;
            int y = originY + j - offset;

            // Verifica se está dentro do tabuleiro antes de marcar
            if (x >= 0 && x < SIZE && y >= 0 && y < SIZE && skill[i][j] == 1) {
                if (board[x][y] == 0) { // Apenas substitui se for água
                    board[x][y] = 5; // Marca como área afetada
                }
            }
        }
    }
}

// Exibe o tabuleiro
void displayBoard() {
    char linha[SIZE] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int coluna[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printf("\n   "); // Espaço para alinhar os números
    for (int i = 0; i < SIZE; i++) {
        printf(" %c", linha[i]);
    }
    printf("\n");

    for (int i = 0; i < SIZE; i++) {
        printf("%2d ", coluna[i]); // Números da coluna à esquerda
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0)
                printf(" 0"); // Água
            else if (board[i][j] == 3)
                printf(" 3"); // Navio
            else if (board[i][j] == 5)
                printf(" 5"); // Área afetada
        }
        printf("\n");
    }
}

// Programa principal
int main() {
    // Posiciona alguns navios no tabuleiro
    board[5][5] = 3;
    board[5][6] = 3;
    board[6][5] = 3;

    printf("\nTABULEIRO ANTES DAS HABILIDADES:\n");
    displayBoard();

    // Aplica habilidades em posições diferentes
    applySkill(coneSkill, 2, 2);
    applySkill(crossSkill, 4, 4);
    applySkill(octahedronSkill, 7, 6);

    printf("\nTABULEIRO APÓS APLICAÇÃO DAS HABILIDADES:\n");
    displayBoard();

    return 0;
}