#include "lista.h"

#include <stdio.h>
#include <stdlib.h>

Lista *lista_new(void) {
  Lista *L = (Lista *)malloc(sizeof(Lista));
  L->inicio = NULL;
  return L;
}

void lista_add(Lista *L, float val) {
  if (L->inicio) {
    Nodo *N = NULL;
    N = L->inicio;
    while (N->next) {
      N = N->next;
    }
    N->next = (Nodo *)malloc(sizeof(Nodo));
    N->next->val = val;
    N->next->next = NULL;
  } else {
    L->inicio = (Nodo *)malloc(sizeof(Nodo));
    L->inicio->val = val;
    L->inicio->next = NULL;
  }
}

void lista_print(const Lista *L) {
  Nodo *N = L->inicio;
  while (N) {
    printf("%f\n", N->val);
    N = N->next;
  }
}

void lista_free(Lista *L) {
  Nodo *M = NULL, *N = L->inicio;
  while (N) {
    M = N;
    N = N->next;
    free(M);
    M = NULL;
  }
  L->inicio = NULL;
  free(L);
}
