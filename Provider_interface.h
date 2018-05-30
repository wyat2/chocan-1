/*
    ProviderInterface.h
    Header for the ProviderInterface class.
*/

#ifndef Provider_interface_H
#define Provider_interface_H

#include "Reports.h"
#include "Provider_db.h"

using namespace std;

class Provider_interface
{
    public:
        Provider_interface();

        void display_members();
        bool provider_welcome();
        bool provider_menu();
        bool lookup_service_code();
        bool service_member();
        bool validate_member();
        bool record_service();
        void get_service_codes();


    protected:

    private:
        Provider_db provide_db;
        //Reports a_report; //should we remove?
};

#endif
