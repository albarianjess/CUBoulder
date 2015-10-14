//-----------------------------------------
//  CSCI2270
//  Recitation 103
//  Homework 3
//
//  Created by Jessie Albarian on 10/2/15.
//  Copyright (c) 2015
//  All rights reserved.
//-----------------------------------------

#ifndef Homework3_queueArray_h
#define Homework3_queueArray_h

#include <iostream>
using namespace std;


//------------------
// Queue Array Class
//------------------
class QueueArray {
private:
    int* arr;
    int* newArray;
    int length, maxsize, element;
    
public:
    QueueArray();               //constructor
    ~QueueArray();              //destructor
    void display();             //display elements in stack
    int enqueue(int element);   //enqueue
    int dequeue();              //dequeue
};



#endif
