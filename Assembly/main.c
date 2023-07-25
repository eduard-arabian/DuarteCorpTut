#include <stdio.h>

int main(void)
{
    int a = 0;
    // option 1
    __asm__("movl %1, %0\n"
            : "=g"(a) // salida, %0 = a
            : "g"(5)  // entrada, %1 = 5
            :         // clobbers
    );
    printf("a: %d\n", a);

    // option 2
    __asm__("movl %[value_of_a], %[variable_a]\n" : [variable_a] "=g"(a) : [value_of_a] "g"(7) :);

    printf("a: %d\n", a);
    return 0;
}
