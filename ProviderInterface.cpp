/*
    ProviderInterface.cpp
    Implementation of the ProviderInterface class.
*/
#include "ProviderInterface.h"

Provider_interface::Provider_interface()//default constructor
{

}

//Provider menu simulates provider terminal "switched on"
bool Provider_interface::provider_welcome()
{
	int provider_id;

	cout << "Welcome to the ChocAN Provider terminal. Please enter your 9 digit provider ID to continue: ";
	cin >> provider_id;
	cin.ignore();

	//verify provider ID: provider_verify(provider_id);
	//if(provider_id) provider_menu(); 
	provider_menu();

	return false;
}

bool Provider_interface::provider_menu()
{
	int provider_option = 0;
	cout << "Welcome to the provider terminal." << endl;
	cout << "Please select from the following options. " << endl;;
	cout << "1. Look up service code" << endl;
	cout << "2. Service member" << endl;
	cout << "3. Exit" << endl;

	cin >> provider_option;
	cin.ignore();

	if(provider_option == 1)
		lookup_service_code();
	else if(provider_option == 2)
		service_member();
	else if(provider_option ==3)
		cout << "Exiting.." << endl;

	return false;
}

bool Provider_interface::service_member()
{
	int member_id;

	cout << "Please scan or manually enter the member's 9 digit member ID: ";
	cin >> member_id;
	cin.ignore();

	//retrieve member information from database..


	return false;
}

bool Provider_interface::lookup_service_code()
{
	int service_code;
	cout << "Welcome to the ChocAN service code lookup. Please enter a 6 digit service code ID: ";
	cin >> service_code;
	cin.ignore();	

	//retrieve service from database..


	return false;
}

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
