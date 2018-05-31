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

const int MAX_RESULTS = 50;

class General_db
{
    public:
        General_db();
        ~General_db();

        void get_results(string *& results, int & num_rows);
        string get_error();
        //need to create get_error

        int display_members();

        int exec(const string sql);
        void set_info(int num_col, string col_names, string rows); 

        static int callback_data(void * NotUsed, int num_col, 
            char ** fields, char ** col_names);
        static int callback_display(void * NotUsed, int num_col, 
            char ** fields, char ** col_names);
        string results[MAX_RESULTS];
    protected:

    private:
        //sqlite3 * obj to interface with database
        sqlite3 * db;
        //sqlite3_smt * obj to prepare statements
        sqlite3_stmt * res;

        //data memebers that get updated with sqlite_exec func
        string error_msg;
        int num_col;
        int num_rows;
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
