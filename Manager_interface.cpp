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
//extern const int RESULTS_MAX;
extern const int MAX_ROW;
extern const int MAX_COL;

//default constructor
Manager_interface::Manager_interface()
{
}

void Manager_interface::display_menu()
{
    char r = '1';
    do
    {
        cout << "\n1. Check member\n";
        cout << "2. List members\n";
        cout << "3. Add member\n";
        cout << "4. Exit\n";
        cout << ">>>";
        cin >> r;
        cin.ignore(IGNORE,'\n');
        switch (r)
        {
            case('1'):
                check_member();
                break;
            case('2'):
                display_members();
                break;
            case('3'):
                add_mbr();
                break;
            case('4'):
                return;
            default:
                cout << "Invalid entry.\n";
        }
    }while(r != 4);
}

void Manager_interface::display_members()
{
    //call display_members function from Manager_db obj
    //This func calls General_db::exec(string sql)
    if(!manage_db.display_members())
    {
        cout << "Couldn't display members. \nError: " << manage_db.get_error();
    }

    //get the results from obj
    string results[MAX_ROW][MAX_COL];
    int num_rows = 0;
    int num_col = 0;
    manage_db.get_results(results, num_rows, num_col); 

    //can call display func or do yourself like comment below
    manage_db.display_results(); 

    /*
     * example of if you wanted to format it yourself...
    //display and format results from Manger_db obj
    for(int i = 0; i < num_rows; ++i) //iterates through rows
    {
        for(int j = 0; j < num_col; ++j) //iterates through columns
        {
            //output a column in the row until no more columns
            cout << results[i][j]; 
        }
        cout << endl; //add new line at end of row
    }
    */
}

int Manager_interface::check_member()
{
    string member_number;
    cout << "\nEnter member number to check: ";
    getline(cin, member_number);
    int test = manage_db.check_member(member_number);
    switch(test)
    {
        case (-1):
            cout << "Member found but has been invalidated.\n";
            break;
        case (0):
            cout << "Member not found.\n";
            break;
        case (1):
            cout << "Member found!\n";
            break;
        default:
            cout << "Member not found.\n";
    }
    return test;        
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
 * ignore... might use as reference if reverting back to char *
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
