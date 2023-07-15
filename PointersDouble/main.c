#include <stdio.h>

int main()
{
    int x, y, *p, *q, **t;
    x = 5;
    y = 6;
    p = &x;
    q = &y;
    t = &p;
    printf("%d %d %d\n", x, *p, **t);
    t = &q;
    printf("%d %d %d\n", y, *q, **t);

    return 0;
}
