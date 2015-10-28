//
//  BinaryTree.cpp
//  Assignment3
//
//  Created by Jessie Albarian on 10/24/15.
//  Copyright (c) 2015 Albarian. All rights reserved.
//

#include "BinaryTree.h"
/*
//---------------------------------------------
//              Helper Methods
//---------------------------------------------

//---------------------
// Get size recursively
//---------------------
int SizeRecursive(const BinaryTreeNode* treeNode){
    if (treeNode == NULL) {
        return 0;
    } else {
        return SizeRecursive(treeNode->left) + SizeRecursive(treeNode->right) + 1;
    }
    return 0;
}

//------------------------
// Check if tree has value
//------------------------
bool ContainsRecursive(const BinaryTreeNode* treeNode, int value){
    if (treeNode == NULL) {
        return false;
    } else if (value == treeNode->data) {
        return true;
    } else if (value < treeNode->data && treeNode->left != NULL){
        return ContainsRecursive(treeNode->left, value);
    } else if (value > treeNode->data && treeNode->right != NULL){
        return ContainsRecursive(treeNode->right, value);
    }
    return false;
}

//--------------------
// Insert Recursively
//--------------------
bool InsertRecursively(BinaryTreeNode* treeNode, int value){
    if (treeNode == NULL){
        BinaryTreeNode* newNode = new BinaryTreeNode;
        newNode->data = value;
        treeNode = newNode;
        return true;
    } else if (treeNode->left == NULL && value < treeNode->data){
        BinaryTreeNode* newNode = new BinaryTreeNode;
        newNode->data = value;
        treeNode->left = newNode;
        return true;
    } else if (treeNode->right == NULL && value > treeNode->data){
        BinaryTreeNode* newNode = new BinaryTreeNode;
        newNode->data = value;
        treeNode->right = newNode;
        return true;
    } else if (value <= treeNode->data) {
        return InsertRecursively(treeNode->left, value);
    } else {
        return InsertRecursively(treeNode->right, value);
    }
    return false;
}

//--------------------
// Remove Recursively
//--------------------
bool RemoveRecursively(BinaryTreeNode*& treeNode, int value){
    
    return false;
}






//---------------------------------------------
//          BinaryTree Class Methods
//---------------------------------------------

// Constructor
BinaryTree::BinaryTree(){
    root = nullptr;
}

// Get size of tree
int BinaryTree::Size(){
    BinaryTreeNode* treeNode = root;
    int size = SizeRecursive(treeNode);
    return size;
}


bool BinaryTree::Contains(int value){
    return false;
}

bool BinaryTree::Insert(int value){
    return false;
}

bool BinaryTree::Remove(int value){
    return false;
}

void Clear(){
    
}

void Display(){
    
}*/


///---------------------
// Get size recursively
//----------------------
int SizeRecursive(const BinaryTreeNode* tree_node) {
    if (tree_node == NULL) {
        return 0;
    } else {
        return SizeRecursive(tree_node->left_child) +
        SizeRecursive(tree_node->right_child) + 1;
    }
    return 0;
}

//------------------------
// Check if tree has value
//------------------------
bool ContainsRecursive(const BinaryTreeNode* tree_node, int value) {
    if (tree_node == NULL){
        return false;
    } else if (value == tree_node->data){
        return true;
    } else if (value < tree_node->data) {
        return ContainsRecursive(tree_node->left_child, value);
    } else if (value > tree_node->data) {
        return ContainsRecursive(tree_node->right_child, value);
    }
    return false;
}


// I used this helper to insert a value into a tree in any position except as
// the first item. I had a if (head == nullptr) case in my method for that case.
// This helper then would recursively find where the node needed to go, then
// inset it there. Keep in mind that because we aren't self-balancing these
// trees, you only inset into a 'leaf' node, that is, a node with no children.
// Because balancing a binary tree is a LOT of work, you can just leave it
// unbalanced, as long as it's a valid binary search tree.
bool InsertRecursive(BinaryTreeNode* tree_node, int value) {
    
    
    if (tree_node == NULL){
        BinaryTreeNode* newNode = new BinaryTreeNode;
        newNode->data = value;
        newNode->right_child = NULL;
        newNode->left_child = NULL;
        tree_node = newNode;
        return true;
    } else if(tree_node->left_child == NULL && value < tree_node->data){
        BinaryTreeNode* newNode = new BinaryTreeNode;
        newNode->data = value;
        newNode->right_child = NULL;
        newNode->left_child = NULL;
        tree_node->left_child = newNode;
        return true;
    } else if (tree_node->right_child == NULL && value > tree_node->data) {
        BinaryTreeNode* newNode = new BinaryTreeNode;
        newNode->data = value;
        newNode->right_child = NULL;
        newNode->left_child = NULL;
        tree_node->right_child = newNode;
        return true;
    } else if(value < tree_node->data) {
        return InsertRecursive(tree_node->left_child, value);
    } else{
        return InsertRecursive(tree_node->right_child, value);
    }
    
    return false;
}




// Used as a helper for the RemoveRecursive helper (like Inception!). This
// function finds the "buddy" node. Read through the link above to find out what
// a buddy is. It would also set the pointer to the buddy node in the parent to
// nullptr. That's why the node is passed in as a reference to a pointer to a
// BinaryTreeNode (so it can be nulled)
BinaryTreeNode* GetBuddyAndNullParentPtr(BinaryTreeNode*& node) {
    
    return node;
}

bool RemoveRecursive(BinaryTreeNode*& tree_node, int value) {
    return false;
}





std::string ToStringRecursiveDepthFirst(const BinaryTreeNode* tree_node, int depth) {
    if (!tree_node) {
        return "";
    }
    return ToStringRecursiveDepthFirst(tree_node->left_child, depth + 1) + "d" +
    std::to_string(depth) + "-" + std::to_string(tree_node->data) + " " +
    ToStringRecursiveDepthFirst(tree_node->right_child, depth + 1);
}




//----------
// Methods
//----------


//-------------
// Constructor
//-------------
BinaryTree::BinaryTree(){
    head = nullptr;
}

//-------------------------
// Get the size of the tree
//-------------------------
int BinaryTree::Size() {
    BinaryTreeNode* tree_node = head;
    int size = SizeRecursive(tree_node);
    return size;
}

//-------------------------
// Checks if tree has value
//-------------------------
bool BinaryTree::Contains(int value) {
    BinaryTreeNode* temp = head;
    bool contains = ContainsRecursive(temp, value);
    if (contains == true) {
        return true;
    }
    return false;
}


// The Insert method for the BinaryTree class. Inserts a new node (you'll need
// to "new" a "BinaryTreeNode" for that) into the tree if and only if the value
// isn't a duplicate. If the value is a duplicate, return false. Otherwise
// return true. See the link for how to do this, and the "InsertRecursive"
// helper above for hints on how to do it recursively.
bool BinaryTree::Insert(int value) {
    BinaryTreeNode* temp = head;
    bool contains = Contains(value);
    if (contains == false){
        return InsertRecursive(temp, value);
        //return true;
    }
    return false;
}

// The Remove method for the BinaryTree class. This is by far the hardest to
// implement. Removing from a binary search tree is a little tricky. See the
// link above to understand why. This function returns false if the value isn't
// anywhere in the tree, and true if the value was removed. You'll need to use
// the "delete" operator so you don't leak memory in this one.
bool BinaryTree::Remove(int value) {
    //BinaryTreeNode* temp;
    bool contains = Contains(value);
    if (contains == false) {
        return false;
    } else {
        return true;
    }
    return false;
}



// Extra Credit
// The Clear method for the BinaryTree class. Needs to call "delete" on each
// node, and set head to nullptr.
/*void BinaryTree::Clear() {
    BinaryTreeNode* tree_node = head;
    while (tree_node != NULL){
        if (tree_node->left_child == NULL && tree_node->right_child == NULL){
            delete tree_node;
        } else {
            if (tree_node->left_child != NULL) {
                tree_node = tree_node->left_child;
            }
            if (tree_node->right_child != NULL) {
                tree_node = tree_node->right_child;
            }
        }
    }
    head = nullptr;
}*/


std::string BinaryTree::ToString() {
    return "[ " + ToStringRecursiveDepthFirst(head, 0) + "]";
}
