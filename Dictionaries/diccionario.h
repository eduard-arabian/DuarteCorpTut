#ifndef DICTIONARIES_DICCIONARIO_H_
#define DICTIONARIES_DICCIONARIO_H_

typedef struct {
  char *key;
  char *value;
} Pair;

typedef struct {
  Pair *pairs;
  int size;
} Dict;

Dict *dict_new(void);
void dict_increase(Dict *D, int size);
void dict_add(Dict *D, const char *key, const char *value);
void dict_print(Dict *D);
void dict_free(Dict *D);

#endif  // DICTIONARIES_DICCIONARIO_H_
