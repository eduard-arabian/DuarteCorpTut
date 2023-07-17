#include "diccionario.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Dict *dict_new(void) {
  Dict *D = NULL;
  D = malloc(sizeof(Dict));
  if (D) {
    D->pairs = NULL;
    D->size = 0;
  }
  return D;
}

void dict_increase(Dict *D, int size) {
  if (D) {
    D->size += size;
    D->pairs = realloc(D->pairs, sizeof(Pair) * D->size);
  }
}

void dict_add(Dict *D, const char *key, const char *value) {
  if (D) {
    dict_increase(D, 1);
    D->pairs[D->size - 1].key = malloc(sizeof(char) * strlen(key) + 1);
    strncpy_s(D->pairs[D->size - 1].key, strlen(key) + 1, key, strlen(key) + 1);
    D->pairs[D->size - 1].value = malloc(sizeof(char) * strlen(value) + 1);
    strncpy_s(D->pairs[D->size - 1].value, strlen(value) + 1, value, strlen(value) + 1);
  }
}

void dict_print(Dict *D) {
  for (int i = 0; i < D->size; ++i) {
    printf("%s: %s\n", D->pairs[i].key, D->pairs[i].value);
  }
}

void dict_free(Dict *D) {
  if (D) {
    for (int i = 0; i < D->size; ++i) {
      free(D->pairs[i].key);
      D->pairs[i].key = NULL;
      free(D->pairs[i].value);
      D->pairs[i].value = NULL;
    }
    free(D->pairs);
    D->pairs = NULL;
    free(D);
  }
}
