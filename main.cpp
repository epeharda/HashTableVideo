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
    
    int index; 
    hashClass hashObject;
    
    index = hashObject.Hash("Erica");
    
    cout << "index = " << index << endl;
    
    return 0;
}

