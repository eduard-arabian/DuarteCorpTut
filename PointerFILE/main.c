#include <stdio.h>

int main()
{
    int x = 5;
    FILE *archivo = fopen("C:/Users/payne/Downloads/_SmartCalc_/Projects/PointerFILE/test.txt", "w");
    if (archivo) {
        fprintf(archivo, "Successful writing to a file parameter x = %d\n", x);
        fflush(archivo);
        fclose(archivo);
    } else {
        ferror(archivo);
    }
    return 0;
}
