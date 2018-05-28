/*
    Member.h
    Header for the Member class.
*/

class Member
{
    public:
        Member();
        Member(char * member_name, int member_number, char * member_address,
        char * member_city, char member_state[2], int member_zip, int validity);
        Member(const Member & copy_from);
        ~Member();

    protected:

    private:
        char * member_name;
        int member_number;
        char * member_address;
        char * member_city;
        char member_state[2];
        int member_zip;
        int validity;
};
