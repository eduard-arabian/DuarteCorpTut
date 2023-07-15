#ifndef LINKEDLIST_LISTA_H_
#define LINKEDLIST_LISTA_H_

typedef struct Nodo Nodo;
typedef struct Lista Lista;

struct Nodo {
  float val;
  Nodo *next;
};

struct Lista {
  Nodo *inicio;
};

Lista *lista_new(void);
void lista_add(Lista *L, float val);
void lista_print(const Lista *L);
void lista_free(Lista *L);

#endif  // LINKEDLIST_LISTA_H_
