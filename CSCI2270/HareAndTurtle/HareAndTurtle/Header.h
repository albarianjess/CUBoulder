//
//  Header.h
//  HareAndTurtle
//
//  Created by Jessie Albarian on 12/1/15.
//  Copyright © 2015 Albarian. All rights reserved.
//


#ifndef Header_h
#define Header_h

struct node
{
    int value;
    node *next;
};


class LinkedList {
    bool hasCycle(node* head);
};

#endif
