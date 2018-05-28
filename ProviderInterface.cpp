/*
    ProviderInterface.cpp
    Implementation of the ProviderInterface class.
*/
#include "ProviderInterface.h"

Provider_interface::Provider_interface()//default constructor
{

}

/*
bool Provider_interface::provider_menu()
{
	int option_choice = 0;
	cout << "Choose option: ";
	cin >> option_choice;
	cin.ignore();

	if(option_choice == 1)
		service_member();
	else if(option_choice == 2)
		lookup_service_code();
	else if(option_choice == 3)
		cout << "Exiting" << endl;

	return false;
}

bool Provider_interface::service_member()
{


	return false;
}

bool Provider_interface::lookup_service_code()
{
	int service_code;
	cout << "Service code: ";
	cin >> service_code;
	cin.ignore();	


	return false;
}
*/

bool Provider_interface::validate_member()
{
    return false;
}

bool Provider_interface::record_service()
{
    return false;
}

void Provider_interface::get_service_codes()
{

}
