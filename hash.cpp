#include <cstdlib>
#include <iostream>
#include <string>

#include "hash.h"

using namespace std;
//creating constructor
hashClass::hashClass()
{
    //initalizing the array
    for(int i = 0; i < tableSize; i++)
    {
        //creating a new item from the item struct
        HashTable[i] = new item;
        //gives values a default value
        HashTable[i] -> name = "empty";
        HashTable[i] -> drink = "empty"; 
        HashTable[i] -> next = NULL;
    }
}

void hashClass::AddItem(string name, string drink)
{
    int index = Hash(name);
    
    //inspect the bucket in the hashtable that is associated w/that index
    if(HashTable[index] -> name == "empty")
    {
        
    }

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
    cout << "hash = " << hash << endl;
    index = hash % tableSize;
    
    return index;

}

