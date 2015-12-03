/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   hash.h
 * Author: ericapeharda
 *
 * Created on December 2, 2015, 3:01 PM
 */
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;


#ifndef HASH_H
#define HASH_H

class hashClass
{
    
private:
    //allows me to define the table size inside the class definition and use it from there
    static const int tableSize = 10;
    
    //defined what an item in the hash table looks like and what it contains
    struct item{
        string name;
        string drink;
        item* next;
    };
    
    //creating the hash table
    //each of those items has a pointer that can point to some next item
    item* HashTable[tableSize];

public:
    hashClass();
    int Hash(string key);

    //creating a new function prototype
    void AddItem(string name, string drink);
    
    //helper function that counts the number of items that is in our list or hashtable
    int NumberOfItemsInIndex(int index);
    
    //creating a print function
    void PrintTable();
    
    //to print the items in the collision index
    void PrintItemsInIndex(int index);
    
    //searching for item
    void FindDrink(string name);

};


#endif /* HASH_H */

