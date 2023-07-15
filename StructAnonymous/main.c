#include <stdio.h>

struct
{
    int a;
    float b;
    double d;
    char c;
    int *x[10];
} m, n, k, r, t;

int w;

int main()
{
    (void) w;
    m.a = 7;
    n.c = 'a';
    k.d = 0.5f;
    r.x[0] = &m.a;
    t.b = 1.23f;

    return 0;
}
