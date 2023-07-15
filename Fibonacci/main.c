#include <stdio.h>

int fibonacci(int n)
{
    return (n == 1 || n == 2) ? 1 : fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n = 14;
    printf("Fibinacci hasta el numero %d es ", n);
    for (int i = 1; i < n + 1; ++i) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
    return 0;
}
