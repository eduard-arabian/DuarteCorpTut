#include <stdio.h>

typedef struct
{
    char *nombre;
    int edad;
    float salario;
} Persona;

void persona_muestra(const Persona *p);

int main()
{
    Persona pedro = {"Pedro", 25, 1000.0f};
    Persona juan = {"Juan", 30, 5000.0f};
    persona_muestra(&pedro);
    persona_muestra(&juan);

    return 0;
}

void persona_muestra(const Persona *p)
{
    printf("Nombre: %s\n", (*p).nombre); // pointer-to-struct-member
    printf("Edad: %d\n", p->edad);       // pointer-to-struct-member
    printf("Salario: %f\n", p->salario);
    printf("\n");
}
