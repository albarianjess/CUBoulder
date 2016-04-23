//-----------------------------------------
//  CSCI2270
//  Recitation 103
//  Homework 3
//
//  Created by Jessie Albarian on 10/2/15.
//  Copyright (c) 2015
//  All rights reserved.
//-----------------------------------------

#include "stackLinkedList.h"


//-------------
// Constructor
//-------------
LinkedList::LinkedList(){
    head = nullptr;
}



//-----
// Pop
//-----
void LinkedList::insert(int num){
    Node* newNode = new Node;
    
    if (head == NULL){
        newNode->data = num;
        head = newNode;
    } else {
        newNode->nextNode = head;
        head = newNode;
        newNode->data = num;
    }
}



//------
// Push
//------
void LinkedList::remove(){
    Node* temp = head;
    if (temp == NULL){
        cout << "Stack is empty!" << endl;
    }
    if(head != nullptr){
        head = head->nextNode;
        delete temp;
    }
}



//-------------
// Display list
//-------------
void LinkedList::display(){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << endl;
        temp = temp->nextNode;
    }
}



