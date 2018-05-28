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

        int check_Member();
        Member get_Member(const int & MemberID);
        bool add_Member(const Member & to_insert);
        bool add_provider(const Provider & to_insert);
        bool service_codes_report();
        bool weekly_summary_report();
        bool weekly_Member_report(const int & Member_ID);
        bool provider_report(const int & provider_ID);
        bool eft_report(const char * start_date, const char * end_date, 
                const int & provider_ID);

    protected:

    private:
        sqlite3 * db; //sqlite3 object

};
