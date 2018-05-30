/*
    General_db.h
    Header for the General_db class.
*/

#ifndef General_db_H
#define General_db_H

#include <iostream>
#include <cstring>
#include <string>
#include <sqlite3.h>

using namespace std;

class General_db
{
    public:
        General_db();

        void display_members();

        int exec(string sql);
        void set_info(int num_col, string col_names, string rows); 

        static int callback_data(void * NotUsed, int num_col, 
            char ** fields, char ** col_names);
        static int callback_display(void * NotUsed, int num_col, 
            char ** fields, char ** col_names);

    protected:

    private:
        //sqlite3 * obj to interface with database
        sqlite3 * db;
        //data memebers that get updated with sqlite_exec func
        string error_msg;
        int num_col;
        string col_names;
        string rows;
        /*
        char * zErrMsg;
        int num_col;
        char ** fields;
        char ** col_names;
        */
};

#endif
