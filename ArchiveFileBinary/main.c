#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char *name;
    int age;
    double salario;
} Persona;

void printEmpleados(const Persona empleados[], int count);
void printPersona(const Persona *empleado);
int writeArchive(Persona empleados[], int size, const char *path);
int readArchive(Persona empleados[], int size, const char *path);

int main()
{
    Persona empleados[] = {{"Juan", 23, 3000.0},
                           {"Carlos", 25, 3500.0},
                           {"Maria", 29, 4300.0},
                           {"Casar", 35, 6500.0}};
    const char *path = "personas.txt";
    int count = sizeof(empleados) / sizeof(Persona);
    Persona empleados_from_file[count];
    writeArchive(empleados, count, path);
    readArchive(empleados_from_file, count, path);
    printEmpleados(empleados_from_file, count);

    return 0;
}

void printEmpleados(const Persona empleados[], int count)
{
    for (int i = 0; i < count; ++i) {
        printPersona(&empleados[i]);
        printf("\n");
    }
}

void printPersona(const Persona *empleado)
{
    printf("Name: %s\n", empleado->name);
    printf("Age: %d\n", empleado->age);
    printf("Salario: %.2lf\n", empleado->salario);
}

int writeArchive(Persona empleados[], int size, const char *path)
{
    int status = 0;
    FILE *F = NULL;
    F = fopen(path, "wb");
    if (F) {
        for (int i = 0; i < size; ++i) {
            fwrite(&empleados[i], sizeof(Persona), 1, F);
        }
        fflush(F);
        fclose(F);
        status = 1;
    }
    return status;
}

int readArchive(Persona empleados[], int size, const char *path)
{
    int status = 0;
    FILE *F = NULL;
    F = fopen(path, "rb");
    if (F) {
        for (int i = 0; i < size; ++i) {
            fread(&empleados[i], sizeof(Persona), 1, F);
        }
        fclose(F);
        status = 1;
    }
    return status;
}
