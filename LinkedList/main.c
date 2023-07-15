#include <stdio.h>

#include "lista.h"

int main() {
  Lista *L = NULL;

  L = lista_new();
  lista_add(L, 1.5f);
  lista_add(L, 55.5f);
  lista_add(L, -6.7f);
  lista_add(L, 100.f);
  lista_add(L, 843.8f);
  lista_print(L);
  lista_free(L);
  L = NULL;

  return 0;
}
