#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *x = malloc(sizeof(int));
    if (x) {
        *x = 5;
        printf("%d\n", *x);
        free(x);
    }

    return 0;
}
