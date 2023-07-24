#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>

#define CREATE_TABLE_PERSONA \
    "CREATE TABLE IF NOT EXISTS persona " \
    "(id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL" \
    ", name TEXT NOT NULL" \
    ", age INTEGER NOT NULL)"

int manageError(sqlite3 *db)
{
    fprintf(stderr, "Error: %s\n", sqlite3_errmsg(db));
    return sqlite3_errcode(db);
}

int main(void)
{
    int status = EXIT_SUCCESS;
    sqlite3 *db = NULL;
    const char *filename = "MyDB.db";

    if (!status && sqlite3_open(filename, &db) != SQLITE_OK) {
        status = manageError(db);
    }

    if (!status && sqlite3_exec(db, CREATE_TABLE_PERSONA, NULL, NULL, NULL) != SQLITE_OK) {
        status = manageError(db);
    }

    return status;
}
