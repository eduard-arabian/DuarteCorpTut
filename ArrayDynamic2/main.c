#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **matriz = NULL;
    int nfilas, ncols;

    nfilas = 5;
    ncols = 5;

    matriz = (int **) calloc(nfilas, sizeof(int *));
    for (int i = 0; i < nfilas; ++i) {
        matriz[i] = (int *) calloc(ncols, sizeof(int));
        for (int j = 0; j < ncols; ++j) {
            matriz[i][j] = i + j;
        }
    }

    for (int i = 0; i < nfilas; ++i) {
        for (int j = 0; j < ncols; ++j) {
            printf("%4d", matriz[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < nfilas; ++i) {
        free(matriz[i]);
        matriz[i] = NULL;
    }
    free(matriz);
    matriz = NULL;

    return 0;
}
