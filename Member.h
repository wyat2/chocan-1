/*
    Member.h
    Header for the Member class.
*/

#ifndef Memeber_H
#define Memeber_H

class Member
{
    public:
        Member();
        Member(char * member_name, char * member_number, char * member_address,
        char * member_city, char member_state[2], char * member_zip, char * validity);
        Member(const Member & copy_from);
        ~Member();

        char * get_info();

    protected:

    private:
        char * member_name;
        char * member_number;
        char * member_address;
        char * member_city;
        char member_state[2];
        char * member_zip;
        char * validity;
};

#endif
