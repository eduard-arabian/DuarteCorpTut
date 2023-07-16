#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *key;
    char *value;
} Pair;

typedef struct
{
    Pair *pairs;
    int size;
} Dict;

int main()
{
    Dict *D = NULL;
    D = malloc(sizeof(Dict));
    D->size = 0;
    D->pairs = NULL;
    D->size = 1;

    D->pairs = malloc(sizeof(Pair) * D->size);
    char *key = "FreeBSD";
    D->pairs[0].key = malloc(sizeof(char) * strlen(key) + 1);
    strcpy(D->pairs[D->size - 1].key, key);
    char *value = "Derived from Unix";
    D->pairs[0].value = malloc(sizeof(char) * strlen(value) + 1);
    strcpy(D->pairs[D->size - 1].value, value);

    printf("%s: %s\n", D->pairs[0].key, D->pairs[0].value);
    free(D->pairs[0].key);
    D->pairs[0].key = NULL;
    free(D->pairs[0].value);
    D->pairs[0].value = NULL;
    free(D->pairs);
    D->pairs = NULL;
    free(D);
    D = NULL;
    return 0;
}
