#include "diccionario.h"
#include <stdio.h>

int main()
{
    Dict *D = NULL;
    D = dict_new();

    dict_add(D, "FreeBSD", "Derived from Unix");
    dict_add(D, "MacOS", "Derived from FreeBSD");
    dict_add(D, "Windows", "Derived from MSDOS");
    dict_add(D, "Linux", "Derived from Unix");
    dict_print(D);
    dict_free(D);
    D = NULL;

    return 0;
}
