/*
    Provider.h
    Header for the Provider class.
*/

#include <iostream>
#include <cstring>

class Provider
{
    public:
        Provider();
        Provider(
        char * providerName, int providerNumber, char * providerAddress, 
        char * providerCity, char providerState[2],int providerZip, 
        int validity);
        Provider(const Provider & copy_from);
        ~Provider();

    protected:

    private:
        char * providerName;
        int providerNumber;
        char * providerAddress;
        char * providerCity;
        char providerState[2];
        int providerZip;
        int validity;
};
