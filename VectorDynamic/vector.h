#ifndef VECTORDYNAMIC_VECTOR_H_
#define VECTORDYNAMIC_VECTOR_H_

typedef struct {
  float *array;
  int size;
} Vector;

Vector *vector_new(void);
void vector_add(Vector *v, float val);
void vector_print(Vector *v);
void vector_free(Vector *v);

#endif  // VECTORDYNAMIC_VECTOR_H_
