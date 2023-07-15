#include <stdio.h>

static int suma(int x, int y)
{
    return x + y;
}

void imprime(void)
{
    printf("Suma: %d\n", suma(1, 2));
}
