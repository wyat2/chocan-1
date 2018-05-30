/*
    Member.cpp
    Implementation of the Member class.
*/

#include <iostream>
#include <cstring>
#include "Member.h"

using namespace std;

//default constructor
Member::Member():member_name(NULL), member_number(NULL), member_address(NULL),
                 member_city(NULL), member_state(""), member_zip(NULL), validity("")
{
    
}

//constructor with args
Member::Member(char * member_name, char * member_number, char * member_address,
            char * member_city, char member_state[2], char * member_zip, char validity[2])
    :member_name(NULL), member_number(NULL), member_address(NULL),
    member_city(NULL), member_state(""), member_zip(NULL), validity("")
{
    this->member_name = new char [strlen(member_name) + 1];
    strcpy(this->member_name, member_name);

    this->member_number = new char [strlen(member_number) + 1];
    strcpy(this->member_number, member_number);

    this->member_address = new char [strlen(member_address) + 1];
    strcpy(this->member_address, member_address);

    this->member_city = new char [strlen(member_city) + 1];
    strcpy(this->member_city, member_city);

    strcpy(this->member_state, member_state);

    this->member_zip = new char [strlen(member_zip) + 1];
    strcpy(this->member_zip, member_zip);

    strcpy(this->validity, validity);
}

//copy constructor
Member::Member(const Member & copy_from)
{

}

//destructor
Member::~Member()
{

}

char * Member::get_info()
{
    //char * combined = NULL;

    //string name(member_name);
    //cout << name;



    /*
    int len = strlen(member_name) + s
    char * temp = new char[;
    str
    */

}
















