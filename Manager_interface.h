/*
    Manager_interface.h
    Header for the Manager_interface class.
    This class will provide the user interface for a Manager terminal
*/

#ifndef Manager_interface_H
#define Manager_interface_H

#include <iostream>
#include <cstring>
#include <sqlite3.h>
#include "Manager_db.h"
#include "Member.h"

class Manager_interface
{
    public:
        Manager_interface();
        
        //callback func for sqlite3_exec
        //int callback(void * NotUsed, int num_col, 
        //        char ** fields, char ** col_names);

        void display_menu();
        void display_members();
        void req_member_rcrd();
        int check_member();

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
        //Manager_db obj to handle db interactions
        Manager_db manage_db;
};

#endif
