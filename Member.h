/*
    Member.h
    Header for the Member class.
*/

class Member
{
    public:
        Member();
        Member(char * memberName, int memberNumber, char * memberAddress,
        char * memberCity, char memberState[2], int memberZip, int validity);
        Member(const Member & copy_from);
        ~Member();

    protected:

    private:
        char * memberName;
        int memberNumber;
        char * memberAddress;
        char * memberCity;
        char memberState[2];
        int memberZip;
        int validity;
};
