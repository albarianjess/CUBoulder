//
//  BinaryTree.h
//  Assignment3
//
//  Created by Jessie Albarian on 10/24/15.
//  Copyright (c) 2015 Albarian. All rights reserved.
//

#ifndef __Assignment3__BinaryTree__
#define __Assignment3__BinaryTree__

#include <iostream>
#include <stdio.h>
/*

struct BinaryTreeNode {
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};



class BinaryTree {
public:
    BinaryTree();
    int Size();
    bool Contains(int value);
    bool Insert(int value);
    bool Remove(int value);
    void Clear();
    void Display();
    
    BinaryTreeNode* root;
};
*/


using namespace std;

struct BinaryTreeNode{
    int data;
    BinaryTreeNode* left_child;
    BinaryTreeNode* right_child;
};


class BinaryTree{
private:
    BinaryTreeNode* head = NULL;
public:
    BinaryTree();
    int Size();
    bool Contains(int);
    bool Insert(int);
    bool Remove(int);
    //void Clear();
    string ToString();
    BinaryTreeNode* FindMax(BinaryTree* head);
};

#endif /* defined(__Assignment3__BinaryTree__) */
