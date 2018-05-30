/*
    Member.cpp
    Implementation of the Member class.
*/

#include "Member.h"

using namespace std;

//default constructor
Member::Member():member_name(""), member_number(""), member_address(""),
                 member_city(""), member_state(""), member_zip(""), validity("")
{
    
}

//constructor with args
Member::Member(string member_name, string member_number, string member_address,
            string member_city, string member_state, string member_zip, string validity)
    :member_name(member_name), member_number(member_number), member_address(member_address),
    member_city(member_city), member_state(member_state), member_zip(member_zip), validity(validity)
{

    /*
    this->member_name = new string[strlen(member_name) + 1];
    strcpy(this->member_name, member_name);

    this->member_number = new string[strlen(member_number) + 1];
    strcpy(this->member_number, member_number);

    this->member_address = new string[strlen(member_address) + 1];
    strcpy(this->member_address, member_address);

    this->member_city = new string[strlen(member_city) + 1];
    strcpy(this->member_city, member_city);

    strcpy(this->member_state, member_state);

    this->member_zip = new string[strlen(member_zip) + 1];
    strcpy(this->member_zip, member_zip);

    strcpy(this->validity, validity);
    */
}

//copy constructor
Member::Member(const Member & copy_from)
{

}

//destructor
Member::~Member()
{

}

string Member::get_values() const
{
    string name(member_name);
    string num(member_number);
    string address(member_address);
    string city(member_city);
    string state(member_state);
    string zip(member_zip);
    string valid(validity);

    return "('" + name + "', '" + num + "', '" + address + "', '"
        + city + "', '" + state + "', '" + zip + "', '" + valid + "');";
}
















