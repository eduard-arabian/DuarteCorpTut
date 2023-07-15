#include <stdio.h>

typedef union {
    char nombre[50];
    char inicial;
} Persona;

int main()
{
    //    Persona juan = {"Juan", 'J'};
    Persona juan = {"Juan"};
    printf("Nombre: %s\n", juan.nombre);
    printf("Inicial: %c\n", juan.inicial);
    juan.inicial = 'H';
    printf("Nombre: %s\n", juan.nombre);
    printf("Inicial: %c\n", juan.inicial);
    return 0;
}
