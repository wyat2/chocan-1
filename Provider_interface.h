/*
    ProviderInterface.h
    Header for the ProviderInterface class.
*/

#ifndef Provider_interface_H
#define Provider_interface_H

#include "Provider_db.h"

using namespace std;

class Provider_interface
{
    public:
        Provider_interface();

        bool provider_welcome();
        bool provider_menu();
	bool verify_provider(string id);
	int verify_member(string id);
        bool service_member();
	/*
        bool lookup_service_code();
        bool validate_member();
        bool record_service();
        void get_service_codes();
	*/

    protected:

    private:
        Provider_db provide_db;
        //Reports a_report; //should we remove?
};

#endif
