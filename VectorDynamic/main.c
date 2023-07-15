#include "vector.h"
#include <stdio.h>

int main()
{
    Vector *v = vector_new();
    vector_add(v, 0.5f);
    vector_add(v, 110.63f);
    vector_add(v, -530.9f);
    vector_add(v, 54.34f);
    vector_add(v, -777.777f);
    vector_print(v);
    vector_free(v);

    return 0;
}
