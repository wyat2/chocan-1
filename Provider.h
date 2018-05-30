/*
    Provider.h
    Header for the Provider class.
*/


#ifndef Provider_H
#define Provider_H

#include <iostream>
#include <cstring>

class Provider
{
    public:
        Provider();
        Provider(
        char * provider_name, int provider_number, char * provider_address, 
        char * provider_city, char provider_state[2],int provider_zip, 
        int validity); //constructor with args
        Provider(const Provider & copy_from); //copy constructor
        ~Provider();

    protected:

    private:
        char * provider_name;
        int provider_number;
        char * provider_address;
        char * provider_city;
        char provider_state[2];
        int provider_zip;
        int validity;
};

#endif
