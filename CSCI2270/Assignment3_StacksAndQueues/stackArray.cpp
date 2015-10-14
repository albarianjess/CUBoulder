//-----------------------------------------
//  CSCI2270
//  Recitation 103
//  Homework 3
//
//  Created by Jessie Albarian on 10/2/15.
//  Copyright (c) 2015
//  All rights reserved.
//-----------------------------------------

#include "stackArray.h"



//-----------------------------
// Creates array of size length
//-----------------------------
StackArray::StackArray(){
    length = 0;
    maxsize = 10;
    arr = new int[10];
}



//-----------
// Destructor
//-----------
StackArray::~StackArray(){
    if(arr!=0)
        delete [] arr;
}



//---------------------
// Add element to stack
//---------------------
void StackArray::push(int element){
    if (length == maxsize){
        char input;
        cout << "Stack is full!!" << endl;
        cout << "Do you want to make new room for the array? Y/N" << endl;
        cin >> input;
        
        if (input == 'Y' || input == 'y'){
            newArray = new int[maxsize*2];
            for (int i = 0; i < maxsize; i++){
                newArray[i] = arr[i];
            }
            maxsize = maxsize * 2;
            delete arr;
            arr = newArray;
            arr[length] = element;
            length++;
        }
    } else {
        arr[length] = element;
        length++;
    }
}



//------------------------------
// Pop off last element in stack
//------------------------------
int StackArray::pop(){
    if (length == 0){
        cout << "Stack is empty." << endl;
        return -1;
    } else {
        length--;
        return arr[length];
    }
}



//--------------------------
// Display elements in stack
//--------------------------
void StackArray::display(){
    if (length == 0){
        cout << "Stack is empty." << endl;
    }
    for (int i = 0; i < length; i++){
        cout << arr[i] << " ";
        cout << endl;
    }
}
