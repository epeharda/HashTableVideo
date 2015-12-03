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
        HashTable[index] -> name = name;
        HashTable[index] -> drink = drink;
    }
    else
    {
        //creates the item to add
        item* ptr = HashTable[index];
        item* newItem = new item;
        newItem -> name = name;
        newItem -> drink = drink;
        newItem -> next = NULL;
        
        //finds the place in the collision linklist to add it
        while(ptr -> next != NULL)
        {
            ptr = ptr -> next;
        }
        
        ptr -> next = newItem;
        
    }

}

int hashClass::NumberOfItemsInIndex(int index)
{
    int count = 0;
    
    if(HashTable[index]->name =="empty")
    {
        return 0;
    }
    else
    {
        count = 1;
        item* ptr = HashTable[index];
        while(ptr -> next != NULL)
        {
            count = count + 1;
            ptr = ptr -> next;
        }
        return count;
    }
}

void hashClass::PrintTable()
{
    //holds number of elements in each bucket
    int number;
    
    for(int i = 0; i < tableSize; i ++)
    {
        number = NumberOfItemsInIndex(i);
        cout << "index = " << i << endl;
        cout << HashTable[i] -> name << endl;
        cout << HashTable[i] -> drink << endl;
        cout << "# of items in this collision = " << number << endl;
        cout << "--------------------------\n";
    }
}

void hashClass::PrintItemsInIndex(int index)
{
    item* ptr = HashTable[index];
    
    if(HashTable[index]->name =="empty")
    {
        cout << "index = " << index << " is empty" << endl;
    }
    else
    {
        cout << "index = " << index << " contains the following items"<< endl;
        while(ptr != NULL)
        {
            cout << "****************" << endl;
            cout << ptr -> name << endl;
            cout << ptr -> drink << endl;
            ptr = ptr -> next;
        } 
    }

}

void hashClass::FindDrink(string name)
{
    int index = Hash(name);
    bool foundName = false;
    string drink;
    
    item* ptr = HashTable[index];
    
    while(ptr != NULL)
    {
        if(ptr -> name == name)
        {
            foundName = true;
            drink = ptr -> drink;
        }
        ptr = ptr -> next;
    }
    
    if(foundName == true){
        cout << "Favorite drink = " << drink << endl;
    }else{
        cout << name << "'s info was not found in the Hash Table\n";
    }
    
}

int hashClass::Hash(string key)
{
    int hash = 0;
    int index;
    
    for(int x = 0; x < key.length(); x ++)
    {
        hash = hash +(int)key[x];
    }
    index = hash % tableSize;
    
    return index;

}

