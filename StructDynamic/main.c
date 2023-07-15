#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char *nombre;
    int edad;
    float salario;
} Persona;

void imprime(const Persona *p);

int main()
{
    Persona *juan, *pedro, *maria;
    juan = (Persona *) malloc(sizeof(Persona));
    pedro = (Persona *) malloc(sizeof(Persona));
    maria = (Persona *) malloc(sizeof(Persona));
    juan->nombre = "Juan";
    juan->edad = 33;
    juan->salario = 5000.0f;
    pedro->nombre = "Pedro";
    pedro->edad = 35;
    pedro->salario = 5100.0f;
    maria->nombre = "Maria";
    maria->edad = 20;
    maria->salario = 5700.0f;
    imprime(juan);
    imprime(pedro);
    imprime(maria);
    free(juan);
    free(pedro);
    free(maria);
    juan = NULL;
    pedro = NULL;
    maria = NULL;

    return 0;
}

void imprime(const Persona *p)
{
    printf("Nombre: %s:\n", p->nombre);
    printf("Edad: %d:\n", p->edad);
    printf("Salario: %f\n\n", p->salario);
}
