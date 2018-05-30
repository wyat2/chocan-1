/*
    Member.h
    Header for the Member class.
*/

#ifndef Memeber_H
#define Memeber_H

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Member
{
    public:
        Member();
        Member(string member_name, string member_number, string member_address,
        string member_city, string member_state, string member_zip, string validity);
        Member(const Member & copy_from);
        ~Member();

        string get_values() const;

    protected:

    private:
        string member_name;
        string member_number;
        string member_address;
        string member_city;
        string member_state;
        string member_zip;
        string validity;
};

#endif
