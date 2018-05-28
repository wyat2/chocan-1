/*
    MangerInterface.h
    Header for the ManagerInterface class.
*/

class ManagerInterface
{
    public:
        ManagerInterface();

        void DisplayMenu();
        void ReqMemberRcrd();

        bool ReqMemberRcrd(const char * StartDate, const char * EndDate, 
                const int & MemberID);
        void ReqPvdrRcrd();
        bool ReqPvdrRcrd(const char * StartDate, const char * EndDate, 
                const int & ProviderID);
        bool AddMbr();
        bool AddPrvd();
        bool RemPrvd();
        bool RemMbr();
        bool EditPrvd();
        bool EditMbr();

    protected:

    private:
};
