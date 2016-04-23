#include "binary_tree.h"
#include <iostream>

namespace thilenius {
namespace external {
namespace csci2270 {
namespace assignments {
namespace binary_tree {

namespace {




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



//--------------------
// Insert recursively
//--------------------
bool InsertRecursive(BinaryTreeNode* tree_node, int value) {
  BinaryTreeNode* newNode = new BinaryTreeNode;
  newNode->data = value;
  newNode->right_child = NULL;
  newNode->left_child = NULL;
    
    if (tree_node == NULL){
        tree_node = newNode;
        return true;
  } else if(tree_node->left_child == NULL && value < tree_node->data){
                tree_node->left_child = newNode;
                return true;
  } else if (tree_node->right_child == NULL && value > tree_node->data) {
                tree_node->right_child = newNode;
                return true;
  } else if(value < tree_node->data) { 
                return InsertRecursive(tree_node->left_child, value);
  } else { 
                return InsertRecursive(tree_node->right_child, value);
  }
  return false;
}



//-----------------
// Find max element
//-----------------
BinaryTreeNode* FindMax(BinaryTreeNode* tree_node){
	if(tree_node == NULL)
		return NULL;
	
	while(tree_node->right_child != NULL){
		tree_node = tree_node->right_child;
	}
	return tree_node;
}



//-------------------
// Remove recursively
//-------------------
bool RemoveRecursive(BinaryTreeNode*& tree_node, int value) {
  if(tree_node == NULL){
			return false;
	} else if(value < tree_node->data){
			return RemoveRecursive(tree_node->left_child, value);
	} else if(value > tree_node->data) {
			return RemoveRecursive(tree_node->right_child,value);
	} else {
			if(tree_node->left_child != NULL && tree_node->right_child != NULL){
					BinaryTreeNode* temp;
					temp = FindMax(tree_node->left_child);
					tree_node->data = temp->data;
					return RemoveRecursive(tree_node->left_child, tree_node->data);
			} else {
					BinaryTreeNode* temp;
					temp = tree_node;
					if (tree_node->left_child == NULL)
						tree_node = tree_node->right_child;
					else if(tree_node->right_child == NULL)	
						tree_node = tree_node->left_child;
					delete temp;
					return true;
			}			
	}	
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
}  // namespace




//-----------------------------------
//            Methods
//----------------------------------- 


//-------------
// Constructor
//-------------
BinaryTree::BinaryTree() {
  head = nullptr;
}



//-------------------------
// Get the size of the tree
//-------------------------
int BinaryTree::Size() {
  BinaryTreeNode* tree_node = head;
  return SizeRecursive(tree_node);
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



//-------------
// Insert Node
//-------------
bool BinaryTree::Insert(int value) { 
  BinaryTreeNode* temp = head;
  bool contains = Contains(value);
  if (head == nullptr){
    BinaryTreeNode* newNode = new BinaryTreeNode;
    newNode->data = value;
    newNode->left_child = nullptr;
    newNode->right_child = nullptr;
    head = newNode;
    return true;
  } else if (contains == false){
     return InsertRecursive(temp, value);
  }
  return false;
}



//------------
// Remove Node
//------------
bool BinaryTree::Remove(int value) {
  BinaryTreeNode* temp = head;
  bool contains = Contains(value);
  if (head == nullptr){
    delete head;
    return true;
  } else if (contains == false){
    return false;
  } else {
    return RemoveRecursive(temp, value);
  }
  return false;
}



//------------------
// Clear recursively
//------------------
void deleteAll(BinaryTreeNode* tree_node){

    if (tree_node->left_child != NULL){
      deleteAll(tree_node->left_child);
    }
    if (tree_node->right_child != NULL){
      deleteAll(tree_node->right_child);
    }
    delete tree_node;
}



//------------------
// Clear entire tree
//------------------
void BinaryTree::Clear() {
  BinaryTreeNode* tree_node = head;
  
  deleteAll(tree_node);
  
  head = nullptr;
}



std::string BinaryTree::ToString() {
  return "[ " + ToStringRecursiveDepthFirst(head, 0) + "]";
}

}  // namespace binary_tree
}  // namespace assignments
}  // namespace csci2270
}  // namespace external
}  // namespace thilenius