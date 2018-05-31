/*
    Manager_interface.cpp
    Implementation of the Manager_interface class.
*/

#include "Manager_interface.h"
#include "Manager_db.h"

using namespace std;

const int IGNORE = 100;
//constants for max member data length
const int NAME = 20;
const int NUM = 9;
const int ADDRESS = 100;
const int CITY = 20;
const int STATE = 3;
const int ZIP = 6;

//default constructor
Manager_interface::Manager_interface()
{
}

void Manager_interface::display_menu()
{
    char r = '9';
    cout << "\n1. Add member\n";
    cout << ">>>";
    cin >> r;
    cin.ignore(IGNORE,'\n');
    switch (r)
    {
        case('1'):
            add_mbr();
            break;
    }
}

void Manager_interface::display_members()
{
    //call display_members function from Manager_db obj
    manage_db.display_members();//This func calls General_db::exec(string sql)

    //get the results from obj
    string * results;
    int num_rows = 0;
    manage_db.get_results(results, num_rows); 

    //display and format results from Manger_db obj
    for(int i = 0; i < num_rows; ++i)
        cout << results[i] << endl;
}

void Manager_interface::req_member_rcrd()
{

}
        
bool Manager_interface::req_member_rcrd(const char * StartDate, 
        const char * EndDate, const int & MemberID)
{
    return false;
}

void Manager_interface::req_pvdr_rcrd()
{

}

bool Manager_interface::req_pvdr_rcrd(const char * StartDate, 
        const char * EndDate, const int & ProviderID)
{
    return false;
}

bool Manager_interface::add_mbr()
{ 
    string name = "";
    string num = ""; 
    string address = "";
    string city = "";
    string state = "";
    string zip = "";
    string validity = "1";

    cout << "\nEnter member name: ";
    getline(cin, name, '\n');

    cout << "\nEnter member number: ";
    getline(cin, num, '\n');

    cout << "\nEnter member address: ";
    getline(cin, address, '\n');

    cout << "\nEnter member city: ";
    getline(cin, city, '\n');

    cout << "\nEnter member state: ";
    getline(cin, state, '\n');

    cout << "\nEnter member zip: ";
    getline(cin, zip, '\n');

    Member to_insert(name, num, address, city, state, zip, validity);
    
    manage_db.add_mbr(to_insert);

    /*
    char temp[300]; //temp to hold input

    char * name = NULL;
    char * num = NULL; 
    char * address = NULL;
    char * city = NULL;
    char state[STATE];
    char * zip = NULL;
    char validity[2] = {'1', '\0'};

    cout << "\nEnter member name: ";
    cin.get(temp, NAME, '\n');
    cin.ignore(IGNORE, '\n');
    name = new char [strlen(temp) + 1];
    strcpy(name, temp);

    cout << "\nEnter member number: ";
    cin.get(temp, NUM, '\n');
    cin.ignore(IGNORE, '\n');
    num = new char [strlen(temp) + 1];
    strcpy(num, temp);

    cout << "\nEnter member address: ";
    cin.get(temp, ADDRESS, '\n');
    cin.ignore(IGNORE, '\n');
    address = new char [strlen(temp) + 1];
    strcpy(address, temp);

    cout << "\nEnter member city: ";
    cin.get(temp, CITY, '\n');
    cin.ignore(IGNORE, '\n');
    city = new char [strlen(temp) + 1];
    strcpy(city, temp);

    cout << "\nEnter member state: ";
    cin.get(temp, STATE, '\n');
    cin.ignore(IGNORE, '\n');
    //state = new char [strlen(temp) + 1];
    strcpy(state, temp);

    cout << "\nEnter member zip: ";
    cin.get(temp, ZIP, '\n');
    cin.ignore(IGNORE, '\n');
    zip = new char [strlen(temp) + 1];
    strcpy(zip, temp);

    Member to_insert(name, num, address, city, state, zip, validity);
    
    manage_db.add_mbr(to_insert);

    if(name)
        delete [] name;
    if(num)
        delete [] num;
    if(address)
        delete [] address;
    if(city)
        delete [] city;
    if(zip)
        delete [] zip;
    */
    return false;
}

bool Manager_interface::add_prvd()
{
    return false;
}

bool Manager_interface::rem_prvd()
{
    return false;
}

bool Manager_interface::rem_mbr()
{

    return false;
}

bool Manager_interface::edit_prvd()
{

    return false;
}

bool Manager_interface::edit_mbr()
{
    return false;
}
/*
int Manager_interface::callback(void * NotUsed, int num_col, char ** fields, char ** col_names)
{
    //delete data members before updating them...
    if(this->fields && this->col_names)
    {
        for(int i = 0; i < num_col; ++i)
        {
            delete [] this->fields[i];
            this->fields[i] = NULL;
            delete [] this->col_names[i];
            this->col_names = NULL;
        }
        this->fields = NULL;
        this->col_names = NULL;
    }

    this->num_col = num_col;

    for(int i = 0; i < num_col; ++i)
    {
        //cout << col_names[i] << ": " << fields[i] << endl;
        
        //copy data into class
        this->fields[i] = new char [strlen(fields[i]) + 1]; 
        this->col_names[i] = new char [strlen(col_names[i]) + 1]; 
        strcpy(this->fields[i], fields[i]);
        strcpy(this->col_names[i], col_names[i]);
    }
    return 1;
}
*/
