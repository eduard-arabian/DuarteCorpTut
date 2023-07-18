#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int len;
    int array[];
} ArrFlex;

int main()
{
    int size = 10;
    ArrFlex *T = malloc(sizeof(ArrFlex) + size * sizeof(int));
    if (T) {
        T->len = size;
        for (int i = 0; i < T->len; ++i) {
            T->array[i] = i;
            printf("%d\n", T->array[i]);
        }
    }

    size = size * 2;
    T = realloc(T, sizeof(ArrFlex) + size * sizeof(int));
    if (T) {
        T->len = size;
        for (int i = T->len / 2; i < T->len; ++i) {
            T->array[i] = i;
        }

        puts("");
        for (int i = 0; i < T->len; ++i) {
            printf("%d\n", T->array[i]);
        }
    }

    if (T) {
        free(T);
        T = NULL;
    }

    return 0;
}
