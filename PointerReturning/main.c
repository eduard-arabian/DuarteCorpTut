#include <stdio.h>
#include <stdlib.h>

int *funcion(void)
{
    int *x;
    x = malloc(sizeof(int));

    return x;
}

int main()
{
    int *p;
    p = funcion();
    *p = 5;
    printf("%p: %d\n", p, *p);
    free(p);

    return 0;
}
