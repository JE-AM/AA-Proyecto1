#include <stdio.h>
#include <stdlib.h>

void generateMagicSquare(int n, int magicSquare[n][n]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            magicSquare[i][j] = 0;
    int row = 0;
    int col = n / 2;
    magicSquare[row][col] = 1;
    for (int num = 2; num <= n * n; num++) {
        int newRow = row - 1;
        int newCol = col + 1;
        if (newRow < 0) newRow = n - 1;
        if (newCol == n) newCol = 0;
        if (magicSquare[newRow][newCol] != 0) {
            newRow = row + 1;
            newCol = col;
        }
        magicSquare[newRow][newCol] = num;
        row = newRow;
        col = newCol;
    }
}
