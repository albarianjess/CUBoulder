//-----------------------------------------
//  CSCI2270
//  Recitation 103
//  Homework 3
//
//  Created by Jessie Albarian on 10/2/15.
//  Copyright (c) 2015
//  All rights reserved.
//-----------------------------------------

#include "queueLinkedList.h"



//-------------
// Constructor
//-------------
QueueLinkedList::QueueLinkedList(){
    head = nullptr;
}



//--------
// Enqueue
//--------
int QueueLinkedList::enqueue(int element){
    QueueNode* newNode = new QueueNode;
    QueueNode* temp = head;
    if (head == NULL){
        newNode->queueData = element;
        head = newNode;
    } else {
        while(temp->nextNode != NULL){
            temp = temp->nextNode;
        }
        temp->nextNode = newNode;
        newNode->queueData = element;
    }
    return 0;
}



//--------
// Dequeue
//--------
int QueueLinkedList::dequeue(){
    QueueNode* temp = head;
    if (temp == NULL){
        cout << "Queue is empty." << endl;
    }
    if (head != nullptr){
        head = head->nextNode;
        delete temp;
    }
    return 0;
}



//---------
// Display
//---------
void QueueLinkedList::display(){
    QueueNode* temp = head;
    while(temp != NULL){
        cout << temp->queueData << endl;
        temp = temp->nextNode;
    }
}



