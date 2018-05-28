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
        int validity); //constructor with args
        Provider(const Provider & copy_from); //copy constructor
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
