/*
   ProviderInterface.cpp
   Implementation of the ProviderInterface class.
 */

#include "Provider_interface.h"
#include <stdlib.h>

Provider_interface::Provider_interface()//default constructor
{

}

//Provider menu simulates provider terminal "switched on"
bool Provider_interface::provider_welcome()
{
	string provider_id_check;

	cout << "Welcome to the ChocAN Provider terminal. \n";
	cout << "Please enter your 9 digit provider ID to continue: ";
	getline(cin, provider_id_check);

	//verify provider ID: provider_verify(provider_id);
	if(verify_provider(provider_id_check))
		provider_menu();
	//if(provider_id) provider_menu(); 

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
	cout << ": ";
	cin >> provider_option;
	cin.ignore();

	//	if(provider_option == 1)
	//	lookup_service_code();
	if(provider_option == 2)
		service_member();
	else if(provider_option ==3)
		cout << "Exiting.." << endl;
	return false;
}

bool Provider_interface::verify_provider(string id)
{
	string query = "SELECT providerNumber FROM providers WHERE providerNumber = " + id + ";";
	provide_db.exec(query);
	if(provide_db.results[0] != "\0")
		return true;
	else return false;
}

bool Provider_interface::service_member()
{
	string member_id;

	cout << "Please enter 9 digit member ID: ";
	getline(cin, member_id);

	int member_status = verify_member(member_id);
	if(member_status == -1)
		cout << "member status: -1" << endl;
	else if(member_status == 0)
		cout << "member status: 0" << endl;
	else if(member_status == 1)
		cout << "member status: 1" << endl;
	else if(member_status == 2)
		cout << "Member number does not exist." << endl;


	return false;
}

int Provider_interface::verify_member(string id)
{
	string query = "SELECT validity FROM members WHERE memberNumber = " + id + ";";
	provide_db.exec(query);
	if(provide_db.results[0] != "\0")
		//convert "validity" string to int and return value
		return atoi(provide_db.results[0].c_str());
	else
		return 2;
}

/*
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
 */
