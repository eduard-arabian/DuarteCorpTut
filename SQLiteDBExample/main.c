#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CREATE_TABLE_PERSONA                       \
  "CREATE TABLE IF NOT EXISTS persona "            \
  "(id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL" \
  ", name TEXT NOT NULL"                           \
  ", age INTEGER NOT NULL)"

typedef struct Persona Persona;

struct Persona {
  char name[500];
  int age;
  int id;
  Persona *next;
};

int manageError(sqlite3 *db) {
  fprintf(stderr, "Error: %s\n", sqlite3_errmsg(db));
  return sqlite3_errcode(db);
}

Persona *PersonaNew(const Persona *persona) {
  Persona *new = (Persona *)malloc(sizeof(Persona));
  strcpy(new->name, persona->name);
  new->age = persona->age;
  //    new->id = persona->id;
  new->id = -1;
  new->next = NULL;
  return new;
}

void PersonaAdd(Persona **lista, const Persona *persona) {
  if (!lista) {
  } else if (!*lista) {
    *lista = PersonaNew(persona);
  } else {
    Persona *ix = *lista;
    while (ix->next) {
      ix = ix->next;
    }
    ix->next = PersonaNew(persona);
  }
}

void PersonaListFree(Persona *lista) {
  if (lista) {
    Persona *M = NULL, *ix = lista;
    while (ix) {
      M = ix;
      ix = ix->next;
      free(M);
      M = NULL;
    }
  }
}

void showLista(const Persona *lista) {
  if (lista) {
    const Persona *ix = lista;
    while (ix) {
      printf("ID: %d;Name: %s;Age: %d\n", ix->id, ix->name, ix->age);
      ix = ix->next;
    }
    printf("\n");
  } else {
    printf("[List is empty]\n");
  }
}

void inputDatas(const Persona *lista, sqlite3 *db) {
  if (lista) {
    int status = EXIT_SUCCESS;
    const Persona *ix = lista;
    char sql[600];
    while (ix && !status) {
      sprintf(sql, "INSERT INTO persona (name, age) VALUES ('%s', %d)",
              ix->name, ix->age);
      if (sqlite3_exec(db, sql, NULL, NULL, NULL) != SQLITE_OK) {
        status = manageError(db);
      } else {
        ix = ix->next;
      }
    }
  } else {
    printf("[List is empty]\n");
  }
}

int callback(void *ptr, int numberOfColumns, char **valueColumn,
             char **nameColumn) {
  (void)ptr;
  //  printf("%d\n", numberOfColumns);
  //  printf("%s\n", *valueColumn);
  //  printf("%s\n\n", *nameColumn);
  for (int i = 0; i < numberOfColumns; ++i) {
    printf("%s: %s\n", nameColumn[i], valueColumn[i]);
  }
  printf("\n");
  return 0;
}

void readDataBase(sqlite3 *db) {
  sqlite3_exec(db, "SELECT * FROM persona", callback, NULL, NULL);
}

int main(void) {
  FILE *file = NULL;
  Persona persona;
  Persona *lista = NULL;
  int status = EXIT_SUCCESS;
  sqlite3 *db = NULL;
  const char *filenameDB = "MyDB.db";
  const char *filenameLista = "datas.txt";

  if (!status && sqlite3_open(filenameDB, &db) != SQLITE_OK) {
    status = manageError(db);
  }

  if (!status &&
      sqlite3_exec(db, CREATE_TABLE_PERSONA, NULL, NULL, NULL) != SQLITE_OK) {
    status = manageError(db);
  }

  if (!status && !(file = fopen(filenameLista, "r"))) {
    fprintf(stderr, "Error opening file\n");
    status = ferror(file);
  }

  if (!status) {
    while (!feof(file)) {
      fscanf(file, "%499s%d", persona.name, &persona.age);
      PersonaAdd(&lista, &persona);
    }
  }
  if (file) {
    fclose(file);
    file = NULL;
    showLista(lista);
  }
  if (!status) {
    inputDatas(lista, db);
  }

  readDataBase(db);

  if (db) {
    sqlite3_close(db);
  }

  PersonaListFree(lista);
  lista = NULL;

  return status;
}
