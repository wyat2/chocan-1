/*
    Reports.cpp
    Implementation of the reports class.
*/

#include "Reports.h"

const char dbfile[12] = "chocandb.db";

//default constructor
Reports::Reports(): db(NULL)
{
    if(sqlite3_open(dbfile, &db)) //try to open database
    {
        //cout << "\nCan't open database\n\n";
    } else {
        //cout << "\nOpened database successfully\n\n";
    }

}

Reports::~Reports()
{
    sqlite3_close(db); //clost sqlite3 obj
}

int Reports::CheckMember()
{
    return 0;
}

Member Reports::GetMember(const int & MemberID)
{

}

bool Reports::AddMember(const Member & to_insert)
{
    return false;
}

bool Reports::AddProvider(const Provider & to_insert)
{
    return false;
}
