#include <stdio.h>
/*
    Find a number and its first position
*/

int existe(int n, int a[], int size);

int main()
{
    int a[] = {1, 5, 10, 4, 4, 2000, 2, 23, 5, 6, 11, 11, 2};
    int size = sizeof(a) / sizeof(int);
    int number = 6;
    int e = 0;
    if ((e = existe(number, a, size))) {
        printf("%d is found on first position %d\n", number, e);
    } else {
        printf("There is no %d\n", number);
    }
    return 0;
}

int existe(int n, int a[], int size)
{
    int i = 0;
    int status = 0;
    for (; i < size && n != a[i]; ++i) {
    }
    if (n == a[i]) {
        status = ++i;
    }
    return status;
}
