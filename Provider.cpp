/*
    Provider.cpp
    Implementation of the Provider class.
*/

#include "Provider.h"

using namespace std;

Provider::Provider(): 
    providerName(NULL), providerNumber(0), providerAddress(NULL), 
    providerCity(NULL), providerState(""), providerZip(0), validity(0)
{

}

Provider::Provider(
    char * providerName, int providerNumber, char * providerAddress, 
    char * providerCity, char providerState[2],int providerZip, int validity):
    providerName(NULL), providerNumber(0), providerAddress(NULL),
    providerCity(NULL), providerState(""), providerZip(0), validity(0)
{

}

Provider::Provider(const Provider & copy_from)
{

}

Provider::~Provider()
{

}
