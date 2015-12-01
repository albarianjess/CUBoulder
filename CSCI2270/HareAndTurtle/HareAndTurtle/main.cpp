//
//  main.cpp
//  HareAndTurtle
//
//  Created by Jessie Albarian on 12/1/15.
//  Copyright © 2015 Albarian. All rights reserved.
//

#include <iostream>
#include "Header.h"

//--------------------------------
// Tortoise and the Hare Algorithm
//--------------------------------
// Use two pointers that each start
// at the head of the linked-list
// but go at different "speeds."
// 'slow' goes to the next node
// 'fast' goes to the second to next
// node.
// If they eventually meet up, then
// the linked-list has a loop


int main() {
    bool hasCycle(node* head);
    return 0;
}


bool hasCycle(node* head){
    node* slow = head;
    node* fast = head;
    
    if (head == NULL){
        return false;
    }
    while(true){
        slow = slow->next;  //slow hops 1
        
        if (fast->next != NULL){
            fast = fast->next->next; //fast hops 2
        } else {
            return false;
        }
        if (slow == NULL || fast == NULL){
            return false;
        }
        if (slow == fast){
            return true;
        }
    }
    return false;
}
