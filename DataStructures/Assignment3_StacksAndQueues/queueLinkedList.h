//-----------------------------------------
//  CSCI2270
//  Recitation 103
//  Homework 3
//
//  Created by Jessie Albarian on 10/2/15.
//  Copyright (c) 2015
//  All rights reserved.
//-----------------------------------------

#ifndef __Homework3__queueLinkedList__
#define __Homework3__queueLinkedList__

#include <stdio.h>
#include <iostream>

using namespace std;



//----------------------
// Node Struct for Queue
//----------------------
struct QueueNode {
    int queueData;
    QueueNode* nextNode;
};



//----------------------------
// Linked-List class for Queue
//----------------------------
class QueueLinkedList {
private:
    int length;
    QueueNode* head;
public:
    QueueLinkedList();
    void display();
    int enqueue(int element);
    int dequeue();
};



#endif
