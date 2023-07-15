#ifndef VECTOR_H
#define VECTOR_H

typedef struct
{
    float *array;
    int size;
} Vector;

Vector *vector_new(void);
void vector_add(Vector *v, float val);
void vector_print(Vector *v);
void vector_free(Vector *v);

#endif // VECTOR_H
