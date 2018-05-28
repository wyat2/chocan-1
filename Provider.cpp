/*
    Provider.cpp
    Implementation of the Provider class.
*/

#include "Provider.h"

using namespace std;

Provider::Provider(): 
    provider_name(NULL), provider_number(0), provider_address(NULL), 
    provider_city(NULL), provider_state(""), provider_zip(0), validity(0)
{

}

Provider::Provider(
    char * provider_name, int provider_number, char * provider_address, 
    char * provider_city, char provider_state[2],int provider_zip, int validity):
    provider_name(NULL), provider_number(0), provider_address(NULL),
    provider_city(NULL), provider_state(""), provider_zip(0), validity(0)
{

}

Provider::Provider(const Provider & copy_from)
{

}

Provider::~Provider()
{

}
