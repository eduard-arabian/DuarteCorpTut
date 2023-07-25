#include <stdio.h>

int main(void)
{
    int a = 0;
    asm("movl %1, %0\n"
        : "=g"(a) // salida
        : "g"(5)  // entrada
        :         // clobbers
    );
    printf("a: %d\n", a);
    return 0;
}
