#include <math.h>
#include <stdio.h>
typedef struct
{
    float d, x1, x2, a, b, c;
} ec2dogr;

int main()
{
    ec2dogr ex1;
    printf("Entre a: ");
    scanf("%f", &ex1.a);
    printf("Entre b: ");
    scanf("%f", &ex1.b);
    printf("Entre c: ");
    scanf("%f", &ex1.c);
    ex1.d = ex1.b * ex1.b - 4.0 * ex1.a * ex1.c;
    if (ex1.d < 0) {
        printf("No hay solucion\n");
    } else {
        ex1.x1 = (-ex1.b + sqrt(ex1.d)) / (2. * ex1.a);
        printf("x1: %f\n", ex1.x1);
        ex1.x2 = (-ex1.b - sqrt(ex1.d)) / (2. * ex1.a);
        printf("x2: %f\n", ex1.x2);
    }
    return 0;
}
