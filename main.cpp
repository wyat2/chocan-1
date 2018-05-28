/*
   main.cpp
   Compile with -lsqlite3 flag (ex. g++ *.cpp -lsqlite3)

*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <sqlite3.h>
#include "ProviderInterface.h"
#include "ManagerInterface.h"

using namespace std;

const char dbfile[12] = "chocandb.db";

//callback func used for sql commands
int callback(void *NotUsed, int num_col, char **fields, char **col_names);

int main()
{
    sqlite3 *db; //create sqlite3 object
    char * sql = NULL;
    char *zErrMsg = NULL;

    ProviderInterface pinter;
    ManagerInterface minter;

    if(sqlite3_open(dbfile, &db)) //try to open database
    {
        cout << "\nCan't open database\n\n";
        return 0;
    } else {
        cout << "\nOpened database successfully\n\n";
    }

    //display all members
    sql = new char [strlen("SELECT * FROM members;") + 1];
    strcpy(sql, "SELECT * FROM members;");
    if(sqlite3_exec(db, sql, callback, 0, &zErrMsg) != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
 
    sqlite3_close(db);
    return 1;
}

int callback(void *NotUsed, int num_col, char **fields, char **col_names)
{
    for(int i = 0; i < num_col; ++i)
    {
        cout << col_names[i] << ": " << fields[i] << endl;
    }
    return 0;
}








