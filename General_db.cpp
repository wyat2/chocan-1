/*
    General_db.cpp
    Implementation of the General_db class.

    The General_db class will perform operations on the database that
    are shared between Manager_db and Provider_db.
    It is also where we will keep the sqlite3 object as well as
    data members to store the results of sqlite queries.
*/

#include "General_db.h"

using namespace std;

const char dbfile[12] = "chocandb.db";

General_db::General_db():db(NULL), num_col(0), fields(NULL), col_names(NULL)
{
    cout << "In General_db constructor...";
    if(sqlite3_open(dbfile, &db)) //try to open database
    {
        cout << "\nCan't open database\n";
    } else {
        cout << "\nOpened database successfully\n";
    }
}

void General_db::display_members()
{
    //display all members
    char * sql = new char [strlen("SELECT * FROM members;") + 1];
    strcpy(sql, "SELECT * FROM members;");
    if(sqlite3_exec(db, sql, callback_display, 0, &zErrMsg) != SQLITE_OK)
    {
        cout << "\nSQL error: " << zErrMsg << endl;
        sqlite3_free(zErrMsg);
    }
}

int General_db::exec(string sql)
{
    if(sqlite3_exec(db, sql.c_str(), callback_display, 0, &zErrMsg) != SQLITE_OK)
    {
        cout << "\nSQL error: " << zErrMsg << endl;
        sqlite3_free(zErrMsg);
        return false;
    }
    return true;
}

int General_db::callback_data(void * NotUsed, int num_col, char ** fields, char ** col_names)
{
    /*
    //delete data members before updating them...
    if(this->fields && this->col_names)
    {
        for(int i = 0; i < num_col; ++i)
        {
            delete [] this->fields[i];
            this->fields[i] = NULL;
            delete [] this->col_names[i];
            this->col_names = NULL;
        }
        this->fields = NULL;
        this->col_names = NULL;
    }

    this->num_col = num_col;

    for(int i = 0; i < num_col; ++i)
    {
        //cout << col_names[i] << ": " << fields[i] << endl;
        
        //copy data into class
        this->fields[i] = new char [strlen(fields[i]) + 1]; 
        this->col_names[i] = new char [strlen(col_names[i]) + 1]; 
        strcpy(this->fields[i], fields[i]);
        strcpy(this->col_names[i], col_names[i]);
    }
    return 1;
    */
}

int General_db::callback_display(void * NotUsed, int num_col, 
    char ** fields, char ** col_names)
{
    for(int i = 0; i < num_col; ++i)
    {
        cout << col_names[i] << ": " << fields[i] << endl;
    }
    return 0; //have to return 0 (sqlite sucess flag)
}
