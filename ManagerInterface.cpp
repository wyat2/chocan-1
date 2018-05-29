/*
    Manager_interface.cpp
    Implementation of the Manager_interface class.
*/

#include "ManagerInterface.h"

using namespace std;

const char dbfile[12] = "chocandb.db";

//default constructor
Manager_interface::Manager_interface():db(NULL), num_col(0), fields(NULL), col_names(NULL)
{
    if(sqlite3_open(dbfile, &db)) //try to open database
    {
        //cout << "\nCan't open database\n\n";
    } else {
        //cout << "\nOpened database successfully\n\n";
    }
}

void Manager_interface::display_menu()
{

}

void Manager_interface::req_member_rcrd()
{

}
        
bool Manager_interface::req_member_rcrd(const char * StartDate, 
        const char * EndDate, const int & MemberID)
{
    return false;
}

void Manager_interface::req_pvdr_rcrd()
{

}

bool Manager_interface::req_pvdr_rcrd(const char * StartDate, 
        const char * EndDate, const int & ProviderID)
{
    return false;
}

bool Manager_interface::add_mbr()
{ 
    char temp[300]; //temp to hold input
    char * input = NULL;

    cout << "\nEnter Member Name:";

    return false;
}

bool Manager_interface::add_prvd()
{
    return false;
}

bool Manager_interface::rem_prvd()
{
    return false;
}

bool Manager_interface::rem_mbr()
{

    return false;
}

bool Manager_interface::edit_prvd()
{

    return false;
}

bool Manager_interface::edit_mbr()
{

    return false;
}

int Manager_interface::callback(void * NotUsed, int num_col, char ** fields, char ** col_names)
{
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
}

