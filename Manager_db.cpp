/*
    Manager_db.cpp
    Implementation of the Manager_db class.
*/

#include "Manager_db.h"

using namespace std;

const int IGNORE = 100;
const int NAME_MAX = 20;
extern const int RESULTS_MAX;

Manager_db::Manager_db()
{

}

void Manager_db::req_member_rcrd()
{

}
        
bool Manager_db::req_member_rcrd(const char * StartDate, 
        const char * EndDate, const int & MemberID)
{
    return false;
}

void Manager_db::req_pvdr_rcrd()
{

}

bool Manager_db::req_pvdr_rcrd(const char * StartDate, 
        const char * EndDate, const int & ProviderID)
{
    return false;
}

bool Manager_db::add_mbr(const Member & to_insert)
{ 
    string values = to_insert.get_values();
    string sql = "INSERT INTO members (memberName, memberNumber, memberAddress, memberCity, memberState, memberZip, validity) VALUES " + to_insert.get_values();
    cout << "\nsql: \n";
    cout << sql << endl;
    exec(sql);
    return true;
}

bool Manager_db::add_prvd()
{
    return false;
}

bool Manager_db::rem_prvd()
{
    return false;
}

bool Manager_db::rem_mbr()
{

    return false;
}

bool Manager_db::edit_prvd()
{

    return false;
}

bool Manager_db::edit_mbr()
{
    return false;
}

