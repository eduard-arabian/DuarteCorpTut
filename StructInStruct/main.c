#include <stdio.h>

typedef struct
{
    float x, y;
} Punto;

typedef struct
{
    char *nombre;
    int edad;
    Punto p;
} Persona;

int main()
{
    Punto q = {-5.234f, 34.0f};
    Persona juan = {"Juan", 30, q};
    //    Persona juan = {"Juan", 30, {-5.234f, 34.0f}};
    printf("Nombre: %s\n", juan.nombre);
    printf("Edad: %d\n", juan.edad);
    printf("Punto: (%f, %f)\n", juan.p.x, juan.p.y);

    return 0;
}
