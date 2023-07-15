#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *a = NULL;

    a = (int *) calloc(5, sizeof(int));
    if (a) {
        a[0] = 6;
        a[1] = -512;
        a[2] = 2001;
        a[3] = -3;
        a[4] = 10;

        for (int i = 0; i < 5; ++i) {
            printf("%d\n", a[i]);
        }

        free(a);
        a = NULL;
    }

    return 0;
}
