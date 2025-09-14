#include "proyecto1.h"

int main() {
    int n;
    printf("Ingrese el tamaño del lado del cuadrado (impar mayor o igual a 3 y menor o igual a 21): ");
    scanf("%d", &n);
    int magicSquare[n][n];
	if (n < 3 || n % 2 == 0 || n>21) {
        printf("El tamaño debe ser un número impar mayor o igual a 3.\n");
        return 1;
    } else{
		generateMagicSquare(n, magicSquare);
	}
   
    // Mostrar cuadrado mágico
    printf("\nCuadrado Magico de orden %d:\n", n);
    int magicSum = n * (n * n + 1) / 2;
    printf("Cada fila, columna y diagonal suman: %d\n\n", magicSum);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", magicSquare[i][j]);
        }
        printf("\n");
    }

    return 0;
}
