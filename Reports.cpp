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

int Reports::check_Member()
{
    return 0;
}

Member Reports::get_Member(const int & Member_ID)
{
    Member a_Member;
    return a_Member;
}

bool Reports::add_Member(const Member & to_insert)
{
    return false;
}

bool Reports::add_provider(const Provider & to_insert)
{
    return false;
}

bool Reports::service_codes_report()
{

    return false;
}

bool Reports::weekly_summary_report()
{

    return false;
}

bool Reports::weekly_Member_report(const int & Member_ID)
{
    return false;
}

bool Reports::provider_report(const int & provider_ID)
{
    return false;
}

bool Reports::eft_report(const char * start_date, const char * end_date, 
                        const int & provider_ID)
{
    return false;
}
