/*
    MangerInterface.h
    Header for the ManagerInterface class.
*/

#include <iostream>
#include <cstring>
#include <sqlite3.h>

class ManagerInterface
{
    public:
        ManagerInterface();
        
        //callback func for sqlite3_exec
        int callback(void * NotUsed, int num_col, 
                char ** fields, char ** col_names);

        void DisplayMenu();
        void ReqMemberRcrd();

        bool ReqMemberRcrd(const char * StartDate, const char * EndDate, 
                const int & MemberID);
        void ReqPvdrRcrd();
        bool ReqPvdrRcrd(const char * StartDate, const char * EndDate, 
                const int & ProviderID);
        bool add_mbr();
        bool add_prvd();
        bool RemPrvd();
        bool RemMbr();
        bool EditPrvd();
        bool EditMbr();

    protected:

    private:
        //sqlite db object
        sqlite3 * db;
        //data memebers that get updated with sqlite_exec func
        int num_col;
        char ** fields;
        char ** col_names;
};
