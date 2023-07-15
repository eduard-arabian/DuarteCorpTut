#include <stdio.h>

int main()
{
    int x;
    FILE *archivo = stdin;
    fprintf(stdout, "Ingresa un numero: ");
    fscanf(archivo, "%d", &x);
    printf("El valor ingresado ha sido este: %d\n", x);
    return 0;
}
