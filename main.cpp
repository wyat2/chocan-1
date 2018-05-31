/*
   main.cpp
   Compile with -lsqlite3 flag (ex. g++ *.cpp -lsqlite3)

*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <sqlite3.h>
#include "Provider_interface.h"
#include "Manager_interface.h"

using namespace std;

int main()
{
    Provider_interface p_inter;
    Manager_interface m_inter;

    p_inter.provider_welcome(); 
   
//    m_inter.display_members();

//    m_inter.display_menu();

    return 1;
}

