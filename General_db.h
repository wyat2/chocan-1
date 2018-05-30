/*
    General_db.h
    Header for the General_db class.
*/

#ifndef General_db_H
#define General_db_H

#include <iostream>
#include <cstring>
#include <sqlite3.h>

class General_db
{
    public:
        General_db();

        void display_members();

        int callback_data(void * NotUsed, int num_col, 
            char ** fields, char ** col_names);
        static int callback_display(void * NotUsed, int num_col, 
            char ** fields, char ** col_names);

    protected:

    private:
        //sqlite3 * obj to interface with database
        sqlite3 * db;
        //data memebers that get updated with sqlite_exec func
        char * zErrMsg;
        int num_col;
        char ** fields;
        char ** col_names;
};

#endif
