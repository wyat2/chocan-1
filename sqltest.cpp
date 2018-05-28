/*
   main.cpp
   Compile with -lsqlite3 flag (ex. g++ *.cpp -lsqlite3

*/


#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <sqlite3.h>

using namespace std;

const char dbfile[12] = "chocandb.db";

//callback func used for sql commands
int callback(void *NotUsed, int argc, char **argv, char **azColName);

int main()
{
    sqlite3 *db; //create sqlite3 object
    char * sql = NULL;
    char *zErrMsg = NULL;

    if(sqlite3_open(dbfile, &db)) //try to open database
    {
        cout << "\nCan't open database\n\n";
        return 0;
    } else {
        cout << "\nOpened database successfully\n\n";
    }

    //sql = new char [strlen("UPDATE members SET validity = 1 WHERE memberNumber = 123456789;") + 1];
    sql = new char [strlen("SELECT * FROM members;") + 1];
    //strcpy(sql, "UPDATE members SET validity = 1 WHERE memberNumber = 023456789;");
    strcpy(sql, "SELECT * FROM members;");
    if(sqlite3_exec(db, sql, callback, 0, &zErrMsg) != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    
    sqlite3_close(db);
    return 1;
}

int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    for(int i = 0; i < argc; ++i)
    {
        cout << azColName[i] << ": " << argv[i] << endl;
    }
    return 0;
}








