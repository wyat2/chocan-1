/*
    Member.cpp
    Implementation of the Member class.
*/

#include <iostream>
#include <cstring>
#include "Member.h"

using namespace std;

//default constructor
Member::Member():memberName(NULL), memberNumber(0), memberAddress(NULL),
                 memberCity(NULL), memberState(""), memberZip(0), validity(0)
{

}

//constructor with args
Member::Member(char * memberName, int memberNumber, char * memberAddress,
            char * memberCity, char memberState[2], int memberZip, int validity)
    :memberName(NULL), memberNumber(0), memberAddress(NULL),
    memberCity(NULL), memberState(""), memberZip(0), validity(0)
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

