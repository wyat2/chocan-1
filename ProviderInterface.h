/*
    ProviderInterface.h
    Header for the ProviderInterface class.
*/

#include "Reports.h"

using namespace std;

class Provider_interface //derived from Reports
{
    public:
        Provider_interface();
	//bool provider_menu();
	//bool lookup_service_code();
	//bool service_member();
        bool validate_member();
        bool record_service();
        void get_service_codes();


    protected:

    private:
        Reports a_report;
};
