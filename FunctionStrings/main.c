#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nombre[50], x[5], y[50];
    strcpy(nombre, "Juan LOpez Murrieta");
    printf("%s\n", nombre);
    strcpy(x, "Holb");
    strcpy(y, "Hola");
    printf("%d\n", strcmp(x, y));
    strcat(x, y + 3);
    printf("%s\n", x);
    memset(x + 2, '@', 2);
    printf("%s\n", x);
    return 0;
}
