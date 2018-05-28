/*
    Member.cpp
    Implementation of the Member class.
*/

#include <iostream>
#include <cstring>
#include "Member.h"

using namespace std;

//default constructor
Member::Member():member_name(NULL), member_number(0), member_address(NULL),
                 member_city(NULL), member_state(""), member_zip(0), validity(0)
{

}

//constructor with args
Member::Member(char * member_name, int member_number, char * member_address,
            char * member_city, char member_state[2], int member_zip, int validity)
    :member_name(NULL), member_number(0), member_address(NULL),
    member_city(NULL), member_state(""), member_zip(0), validity(0)
{

}

//copy constructor
Member::Member(const Member & copy_from)
{

}

//destructor
Member::~Member()
{

}

