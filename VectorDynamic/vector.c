#include "vector.h"

#include <stdio.h>
#include <stdlib.h>

Vector *vector_new(void) {
  Vector *v = (Vector *)malloc(sizeof(Vector));
  v->array = NULL;
  v->size = 0;
  return v;
}

void vector_add(Vector *v, float val) {
  ++v->size;
  v->array = realloc(v->array, sizeof(float) * v->size);
  v->array[v->size - 1] = val;
}

void vector_print(Vector *v) {
  for (int i = 0; i < v->size; ++i) {
    printf("%f\n", v->array[i]);
  }
}

void vector_free(Vector *v) {
  free(v->array);
  v->array = NULL;
  free(v);
}
