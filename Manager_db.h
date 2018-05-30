/*
    Manager_db.h
    Header for the Manager_db class.
*/

#ifndef Manager_db_H
#define Manager_db_H

#include <iostream>
#include <string>
#include <cstring>
#include <sqlite3.h>
#include "General_db.h"
#include "Member.h"

class Manager_db: public General_db
{
    public:
        Manager_db();

        void req_member_rcrd();
        bool req_member_rcrd(const char * StartDate, const char * EndDate, 
                const int & MemberID);
        void req_pvdr_rcrd();
        bool req_pvdr_rcrd(const char * StartDate, const char * EndDate, 
                const int & ProviderID);
        bool add_mbr(const Member & to_insert);
        bool add_prvd();
        bool rem_prvd();
        bool rem_mbr();
        bool edit_prvd();
        bool edit_mbr();

    protected:

    private:

};

#endif
