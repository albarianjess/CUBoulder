//-----------------------------------------
//  CSCI2270
//  Recitation 103
//  Homework 3
//
//  Created by Jessie Albarian on 10/2/15.
//  Copyright (c) 2015
//  All rights reserved.
//-----------------------------------------

#ifndef Homework3_stackLinkedList_h
#define Homework3_stackLinkedList_h

#include <iostream>
using namespace std;



//-------------
// Node Struct
//-------------
struct Node{
    int data;
    Node* nextNode;
};



//-------------------
// Linked-List class
//-------------------
class LinkedList {
private:
    int length;
    Node* head;
public:
    LinkedList();
    void insert(int num);
    void remove();
    void display();
};



#endif

