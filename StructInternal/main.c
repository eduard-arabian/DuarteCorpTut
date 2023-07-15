#include <stdio.h>

typedef struct
{
    char *nombre;
    int edad;
    struct
    {
        float x, y;
    } Q;
} Persona;

int main()
{
    Persona juan = {"Juan", 30, {-1.2f, 54.7}};

    printf("Nombre: %s\n", juan.nombre);
    printf("Edad: %d\n", juan.edad);
    printf("Punto: (%f, %f)\n", juan.Q.x, juan.Q.y);

    return 0;
}
