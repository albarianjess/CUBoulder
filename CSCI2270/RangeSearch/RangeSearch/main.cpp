//
//  main.cpp
//  RangeSearch
//
//  Created by Jessie Albarian on 12/1/15.
//  Copyright © 2015 Albarian. All rights reserved.
//

#include <iostream>
#include "Header.h"
using namespace std;



void RangeSearch(TreeNode *node, int m, int n){
    
    if(node == NULL){
        return;
    }
    
    if (m < node->key){
        RangeSearch(node->left, m, n);
    }
    
    if (m <= node->key && n >= node->key){
        cout << node->key << " ";
    }
    
    if (n > node->key){
        RangeSearch(node->right, m, n);
    }
}



int main() {
    TreeNode * root = new TreeNode;
    int m = 10, n = 25;
    
    /* Constructing tree */
    root->key = 20;
    root->left = new TreeNode;
    root = root->left;
    root->key = 22;
    
    
    
    /*root->right = newNode(22);
    root->left->left = newNode(4);
    root->left->right = newNode(12);*/
        
    RangeSearch(root, m, n);

    return 0;
}





