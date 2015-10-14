//-----------------------------------------
//  CSCI2270
//  Recitation 103
//  Homework 3
//
//  Created by Jessie Albarian on 10/2/15.
//  Copyright (c) 2015
//  All rights reserved.
//-----------------------------------------

#ifndef Homework3_stack_h
#define Homework3_stack_h

#include <iostream>
using namespace std;



//------------------
// Stack Array Class
//------------------
class StackArray {
private:
    int* arr;
    int* newArray;
    int length, maxsize;
public:
    StackArray();       //constructor
    ~StackArray();      //destructor
    void push(int num);     //add element
    int pop();          //delete element
    void display();     //display elements in stack
};



#endif




