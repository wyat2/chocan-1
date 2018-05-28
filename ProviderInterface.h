/*
    ProviderInterface.h
    Header for the ProviderInterface class.
*/

#include "Reports.h"

using namespace std;

class ProviderInterface : public Reports //derived from Reports
{
    public:
        ProviderInterface();
        bool ValidateMember();
        bool RecordService();
        void GetServiceCodes();


    protected:

    private:
};
