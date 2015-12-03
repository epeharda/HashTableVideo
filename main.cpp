/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: ericapeharda
 *
 * Created on December 2, 2015, 3:00 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include "hash.h"

using namespace std;

int main(int argc, char** argv) {
    
    //testing our hash!
    string name;
    
    hashClass Hashy;  
    Hashy.AddItem("Paul", "Locha");
    Hashy.AddItem("Kim", "Iced Mocha");
    Hashy.AddItem("Emma", "Strawberry Smoothie");
    Hashy.AddItem("Annie", "Hot Chocolate");
    Hashy.AddItem("Sarah", "Passion Tea");
    Hashy.AddItem("Pepper", "Caramel Mocha");
    Hashy.AddItem("Mike", "Chai Tea");
    Hashy.AddItem("Steve", "Apple Cider");
    Hashy.AddItem("Bill", "Root Beer");
    Hashy.AddItem("Marie", "Skinny Latte");
    Hashy.AddItem("Susan", "Water");
    Hashy.AddItem("Joe", "Green Tea");
   
    //Hashy.FindDrink("Emma");
    while(name != "exit")
    {
        cout << "Search for ";
        cin >> name;
        if(name != "exit")
        {
            Hashy.FindDrink(name);
        }
    }
    
    
    return 0;
}

