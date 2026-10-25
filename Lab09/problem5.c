#include <stdio.h>

void printGrid(int (*grid)[5]) {
    int r, c;
    for (r = 0; r < 5; r++) {
        for (c = 0; c < 5; c++) {
            printf("%d ", grid[r][c]);
        }
        printf("\n");
    }
}

int countNeighbours(int (*grid)[5], int row, int col) {
    int count = 0;
    int r, c;
    for (r = row - 1; r <= row + 1; r++) {
        for (c = col - 1; c <= col + 1; c++) {
            if (r == row && c == col) {
                continue;
            }
            if (r < 0 || r >= 5 || c < 0 || c >= 5) {
                continue;
            }
            if (grid[r][c] & 1) {
                count++;
            }
        }
    }
    return count;
}

void nextGeneration(int (*grid)[5]) {
    int r, c, n;
    for (r = 0; r < 5; r++) {
        for (c = 0; c < 5; c++) {
            n = countNeighbours(grid, r, c);
            if ((grid[r][c] & 1) == 1) {
                if (n == 2 || n == 3) {
                    grid[r][c] = grid[r][c] | 2;
                }
            } else {
                if (n == 3) {
                    grid[r][c] = grid[r][c] | 2;
                }
            }
        }
    }
    for (r = 0; r < 5; r++) {
        for (c = 0; c < 5; c++) {
            grid[r][c] >>= 1;
        }
    }
}

int main() {
    int grid[5][5] = {0};
    int gens, i;

    grid[1][2] = 1;
    grid[2][2] = 1;
    grid[3][2] = 1;

    printf("Enter number of generations (0-50): ");
    scanf("%d", &gens);
    while (gens < 0 || gens > 50) {
        printf("Invalid number\n");
        printf("Enter number of generations (0-50): ");
        scanf("%d", &gens);
    }

    printf("Generation 0:\n");
    printGrid(grid);
    for (i = 1; i <= gens; i++) {
        nextGeneration(grid);
        printf("Generation %d:\n", i);
        printGrid(grid);
    }

    return 0;
}
