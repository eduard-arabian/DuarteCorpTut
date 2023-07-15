#ifndef LISTA_H
#define LISTA_H

typedef struct Nodo Nodo;
typedef struct Lista Lista;

struct Nodo
{
    float val;
    Nodo *next;
};

struct Lista
{
    Nodo *inicio;
};

Lista *lista_new(void);
void lista_add(Lista *L, float val);
void lista_print(const Lista *L);
void lista_free(Lista *L);

#endif // LISTA_H
