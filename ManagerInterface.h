/*
    MangerInterface.h
    Header for the manager_interface class.
*/

#include <iostream>
#include <cstring>
#include <sqlite3.h>

class manager_interface
{
    public:
        manager_interface();
        
        //callback func for sqlite3_exec
        int callback(void * NotUsed, int num_col, 
                char ** fields, char ** col_names);

        void display_menu();
        void req_member_rcrd();

        bool req_member_rcrd(const char * StartDate, const char * EndDate, 
                const int & MemberID);
        void req_pvdr_rcrd();
        bool req_pvdr_rcrd(const char * StartDate, const char * EndDate, 
                const int & ProviderID);
        bool add_mbr();
        bool add_prvd();
        bool rem_prvd();
        bool rem_mbr();
        bool edit_prvd();
        bool edit_mbr();

    protected:

    private:
        //sqlite db object
        sqlite3 * db;
        //data memebers that get updated with sqlite_exec func
        int num_col;
        char ** fields;
        char ** col_names;
};
