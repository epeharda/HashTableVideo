#include <cstdlib>
#include <iostream>
#include <string>

#include "hash.h"

using namespace std;
//creating constructor
hashClass::hashClass()
{
    tableSize = 100;
}


int hashClass::Hash(string key)
{
    int hash = 0;
    int index;
    
    for(int x = 0; x < key.length(); x ++)
    {
        hash = hash +  (int)key[x];
        //cout << "key = " << key[x] << " ascii = " << (int)key[x] << endl;
    }
    
    index = hash % tableSize;
    
    return index;

}