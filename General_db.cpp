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

General_db::General_db():db(NULL), error_msg(""), num_col(0), num_rows(0), 
    col_names(""), rows("")
{
    //cout << "In General_db constructor...";
    if(sqlite3_open(dbfile, &db)) //try to open database
    {
        cout << "\nCan't open database\n";
    } else {
        //cout << "\nOpened database successfully\n";
    }
}

General_db::~General_db()
{
    sqlite3_close(db);
}

void General_db::get_results(string results_in[MAX_ROW][MAX_COL], 
        int & num_rows_in, int & num_col_in)
{
    num_rows_in = this->num_rows;
    num_col_in = this->num_col;
    //results_in = this->results;
    
    //cout << "num_rows: " << this->num_rows << endl;
    //cout << "num_col: " << this->num_col << endl;

    //might be inefficient to copy over (how to get ref of 2d string arr?)
    for(int i = 0; i < num_rows; ++i)
    {
        for(int j = 0; j < num_col; ++j)
        {
            results_in[i][j] = this->results[i][j];
        }
    }
}

string General_db::get_error()
{
    return error_msg;  
}

int General_db::display_members()
{
    //This is an example for executing sql and using/formating results 
    //back in Manger_interface class but we'll change to below so when we
    //have lots of members we don't have to load them all into memory
    string sql("SELECT * FROM members;");
    return exec(sql);

    /*
    //display all members w/o writng to memory
    char * zErrMsg;
    char * sql = new char [strlen("SELECT * FROM members;") + 1];
    strcpy(sql, "SELECT * FROM members;");

    if(sqlite3_exec(db, sql, callback_display, 0, &zErrMsg) != SQLITE_OK)
    {
        cout << "\nSQL error: " << zErrMsg << endl;
        sqlite3_free(zErrMsg);
    }
    */
}

int General_db::check_member(string memberNumber)
{
    string sql("SELECT validity FROM members WHERE memberNumber = " 
            + memberNumber);
    exec(sql);
    //display_results();
    if(results[0][0] != "")
    {
        //cout << endl << results[0][0];
        if(results[0][0] == "-1")
        {
            return -1;
        }
        if(results[0][0] == "1")
        {
            return 1;
        }
    }
    return 0;
}

void General_db::display_results()
{
    for(int i = 0; i < num_rows; ++i) //iterates through rows
    {
        for(int j = 0; j < num_col; ++j) //iterates through columns
        {
            //output a column in the row until no more columns
            cout << results[i][j] << " "; 
        }
        cout << endl; //add new line at end of row
    }
}

int General_db::exec(const string sql)
{
    const unsigned char * temp;
    int rc = 0;
    for(int i = 0; i < num_rows; ++i)
    {
        for(int j = 0; j < num_col; ++j)
        {
            results[i][j] = "";
        }
    }
    this->num_rows = 0;
    this->num_col = 0;

    rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &res, 0);

    if(rc != SQLITE_OK)
    {
        //COPY OVER ERROR INTO DATA MEMBER
        //cout << "Failed to fetch data: " << sqlite3_errmsg(db) << endl;
        this->error_msg = "Failed to fetch data: " + string(
                reinterpret_cast<const char *>(sqlite3_errmsg(db)));
        return false;
    }

    this->num_col = sqlite3_column_count(res);
    while(sqlite3_step(res) == SQLITE_ROW && num_rows < MAX_RESULTS)
    {
        for(int i = 0; i < num_col; ++i)
        {
            temp = sqlite3_column_text(res, i);
            results[num_rows][i] = string(reinterpret_cast<const char *>(temp));
        }
        ++this->num_rows;
    }

    /*
    cout << "num_rows: " << this->num_rows << endl;
    cout << "num_col: " << this->num_col << endl;

    for(int i = 0; i < num_rows; ++i)
    {
        for(int j = 0; j < num_col; ++j)
            cout << results[i][j];
        cout << endl;
    }
    */
    /*
    //to test that results got populated correctly...
    for(int i = 0; i < num_rows; ++i)
    {
        cout << results[i] << endl;
    }
    */

    sqlite3_finalize(res);

    return true;
}

/*
 * old way with sqlite3_exec()
int General_db::exec(string sql)
{
    char * zErrMsg;
    if(sqlite3_exec(db, sql.c_str(), callback_display, 0, &zErrMsg) != SQLITE_OK)
    {
        cout << "\nSQL error: " << zErrMsg << endl;
        sqlite3_free(zErrMsg);
        return false;
    }
    return true;
}
*/

int General_db::callback_data(void * NotUsed, int num_col, char ** fields, char ** col_names)
{
    //how do I get results back to General_db::exec(string sql)?
    //can't return from this func...
    //can't update a argument b/c it has to have these args
    //can't update General_db data members b/c it has to be a static func
    //can't call a set_info func without a class obj from static func

    string col_names_temp = "";
    string rows_temp = "";

    for(int i = 0; i < num_col; ++i)
    {
        cout << col_names[i] << ": " << fields[i] << endl;
        
        col_names_temp = col_names_temp + col_names[i] + " ";
        rows_temp = rows_temp + fields[i] + " ";
    }
    //set_info(num_col, col_names_temp, rows_temp);
    //rows = rows_temp;
    return 0;
    
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
    return 0;
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

void General_db::set_info(int num_col, string col_names, string rows)
{
    this->error_msg = error_msg;
    this->num_col = num_col;
    this->col_names = col_names;
    this->rows = rows;
}

