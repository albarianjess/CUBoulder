//
//Jessie Albarian
//

#include "linked_list.h"
#include <iostream>

using namespace std;

namespace thilenius {
namespace external {
namespace csci2270 {
namespace assignments {
namespace linked_list {

LinkedList::LinkedList() {
	head = nullptr;
	}

int LinkedList::Size() { 
	
	int counter = 0;					//create counter
	LinkedListNode* tempPtr = head;		//create temporary node of type LinkedListNode	
						
	while(tempPtr != nullptr){			//while tempPtr is not null...
		tempPtr = tempPtr->next_node;	//set tempPtr to tempNode->next_node
		counter++;
	}
	return counter;
}

bool LinkedList::InsertAtIndex(int value, int index) {
	LinkedListNode* newNode = new LinkedListNode;	// create a new node
	LinkedListNode* temp = head;					// create temp pointer; set it to head	
	newNode->data = value;							// set data value of newNode to value
	
	
		//check some stuff
		if(index==0){
			newNode->data = value;
			newNode->next_node = head;												
			head = newNode;
			return true;		
		}else if(index < 0 || index > LinkedList::Size()){
			return false; // do nothing
		}
		
		//main loop
		int i = 0;
		while(i != (index-1)){
			temp = temp->next_node;
			i++;
		}
		
		newNode->next_node = temp->next_node;
		temp->next_node = newNode;
				
  return true;
}

void LinkedList::PushFront(int value) {
	LinkedList::InsertAtIndex(value,0);
}

void LinkedList::PushBack(int value) {
	LinkedList::InsertAtIndex(value,Size());
	}

int& LinkedList::operator[](int index) {
	LinkedListNode* item = head;
	int i = 0;
	while(i < index){
		item = item->next_node;
		i++;
	}
	return item->data;
}


bool LinkedList::RemoveAtIndex(int index) { 
	
		if(index < 0 || index > LinkedList::Size()-1){
			return false;
		}
		else if(index == 0){
			LinkedListNode* temp = head;
			head = head->next_node;
			delete temp;
			return true;
		}
			LinkedListNode* temp = head;
			LinkedListNode* nodeToDelete;
			int i = 0;
			while(i < (index-1)){
				temp = temp->next_node;
				i++;
			}
			
			nodeToDelete = temp->next_node;					//this is at the index to delete
			temp->next_node = nodeToDelete->next_node;		//temp now equals index+1
			delete nodeToDelete;
			
			return true;
		
}

void LinkedList::Clear() {
	while(head->next_node != nullptr){
		LinkedListNode* temp = head->next_node;
		head->next_node = temp->next_node;
		delete temp;
	}
	LinkedListNode* temp = head;
	head = nullptr;
	delete temp;
}

void LinkedList::RemoveAll(int value) {
		
		
		while(head != NULL && head->data == value){
			LinkedListNode* temp = head;
			head = head->next_node;	//reassigns head
			delete temp;			//deletes head
		}
		if (head == NULL){			//checks for empty linked list
			return;
		}
		
		LinkedListNode* current = head;
		LinkedListNode* temp = head;
		while(current->next_node != NULL){
			if(current->next_node->data == value){
				temp = current->next_node;
				current->next_node = temp->next_node;
				delete temp;
			} else {
				current = current->next_node;
			}
		}
}

}  // namespace linked_list
}  // namespace assignments
}  // namespace csci2270
}  // namespace external
}  // namespace thilenius
