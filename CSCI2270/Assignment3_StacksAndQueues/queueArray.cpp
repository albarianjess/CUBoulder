//-----------------------------------------
//  CSCI2270
//  Recitation 103
//  Homework 3
//
//  Created by Jessie Albarian on 10/2/15.
//  Copyright (c) 2015
//  All rights reserved.
//-----------------------------------------

#include <stdio.h>
#include "queueArray.h"



//-------------
// Constructor
//-------------
QueueArray::QueueArray(){
    length = 0;
    maxsize = 10;
    arr = new int[10];
}



//-----------
// Destructor
//-----------
QueueArray::~QueueArray(){
    if(arr!=0)
        delete [] arr;
}



//---------
// Display
//---------
void QueueArray::display(){
    if (length == 0){
        cout << "Queue is empty!" << endl;
    }
    for (int i = 0; i < length; i++){
        cout << arr[i] << " ";
        cout << endl;
    }
}



//-------------------
// Enqueue: first in
//-------------------
int QueueArray::enqueue(int element){
    if (length == maxsize){
        cout << "Queue is full!" << endl;
        char input;
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
    return 0;
}



//-------------------
// Dequeue: first out
//-------------------
int QueueArray::dequeue(){
    if (length == 0){
        cout << "Queue is empty!" << endl;
        return -1;
    } else {
        int del = arr[0];
        for (int i = 0; i < length; i++){
            arr[i] = arr[i+1];
        }
        length--;
        return del;
    }
    
}

