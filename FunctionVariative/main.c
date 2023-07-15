#include <stdarg.h>
#include <stdio.h>

double suma(int n, ...);

int main()
{
    double x = suma(10, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0);
    printf("Suma: %lf\n", x);
    return 0;
}

double suma(int n, ...)
{
    double s = 0.0f;
    va_list parametros;
    va_start(parametros, n);
    for (int i = 0; i < n; ++i) {
        s += va_arg(parametros, double);
    }
    va_end(parametros);
    return s;
}
