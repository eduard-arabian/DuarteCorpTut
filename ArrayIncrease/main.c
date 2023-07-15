#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *a = NULL;

    if ((a = calloc(5, sizeof(int)))) {
        a[0] = 5;
        a[1] = 7;
        a[2] = 9;
        a[3] = 11;
        a[4] = 13;
        for (int i = 0; i < 5; ++i)
            printf("%d\n", a[i]);
        if ((a = realloc(a, 10 * sizeof(int)))) {
            a[5] = 15;
            a[6] = 17;
            a[7] = 19;
            a[8] = 111;
            a[9] = 113;
            for (int i = 5; i < 10; ++i)
                printf("%d\n", a[i]);
            free(a);
            a = NULL;
        }
    }

    return 0;
}
