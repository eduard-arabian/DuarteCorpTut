#include <stdio.h>

int x;
void funcion(void);

int main()
{
    x = 5;
    funcion();
    printf("%d\n", x);
    return 0;
}

void funcion(void)
{
    x = 7;
}
