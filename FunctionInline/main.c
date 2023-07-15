#include <stdio.h>

inline int sum(int x, int y);

int main()
{
    printf("%d\n", sum(3, 4));
    return 0;
}

int sum(int x, int y)
{
    return x + y;
}
