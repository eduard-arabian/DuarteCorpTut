#include <stdio.h>

typedef struct
{
    float x, y;
} Punto;

void punto_muestra(const Punto *p);

int main()
{
    Punto coordinates[3] = {{0.0f, -5.0f}, {4.5f, -3.45}, {5.5554f, -789.987f}};

    for (int i = 0; i < (int) (sizeof(coordinates) / sizeof(Punto)); ++i) {
        punto_muestra(&coordinates[i]);
    }

    return 0;
}

void punto_muestra(const Punto *p)
{
    printf("(%f, %f)\n", p->x, p->y);
}
