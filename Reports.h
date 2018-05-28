/*
    Reports.h
    Header for the Reports class.
*/

#include <sqlite3.h>
#include <iostream>
#include <cstring>
#include "Member.h"
#include "Provider.h"

class Reports
{
    public:
        Reports();
        ~Reports();

        int CheckMember();
        Member GetMember(const int & MemberID);
        bool AddMember(const Member & to_insert);
        bool AddProvider(const Provider & to_insert);
        bool ServiceCodesReport();
        bool WeeklySummaryReport();
        bool WeeklyMemberReport(const int & MemberID);
        bool ProviderReport(const int & ProviderID);
        bool EftReport(const char * StartDate, const char * EndDate, 
                const int & ProviderID);

    protected:

    private:
        sqlite3 * db; //sqlite3 object

};
