//
//  main.cpp
//  Assignment3
//
//  Created by Jessie Albarian on 10/24/15.
//  Copyright (c) 2015 Albarian. All rights reserved.
//

#include <iostream>
#include "BinaryTree.h"
using namespace std;

/*
int main() {
    
    BinaryTree* test;
    
    
    bool check;
    while (check == true){
        int input;
        cout << "--------------------"  << endl;
        cout << "Choose an option:"     << endl;
        cout << "(1) Print the size."   << endl;
        cout << "(2) Search the tree."  << endl;
        cout << "(3) Insert a leaf."    << endl;
        cout << "(4) Remove a leaf."    << endl;
        cout << "(5) Exit."             << endl;
        cout << ">> "                   << endl;
        cin >> input;
    
        if (input == 1){
            cout << "The size of the tree is: " << test->Size() << endl;
            cout << endl;
            
        } else if (input == 2){
            int value;
            cout << "What value are you searching for? " << endl;
            cin >> value;
            if (test->Contains(value) == true){
                cout << "The value " << value << " is in the tree!" << endl;
            } else {
                cout << "The value " << value << " is not in the tree!" << endl;
            }
            
        } else if (input == 3){
            int value;
            cout << "Enter a value to be inserted: " << endl;
            cin >> value;
            if (test->Insert(value) == true){
                cout << "Success!" << endl;
            } else {
                cout << "There was already that value in the tree." << endl;
            }
            
        } else if (input == 4){
            int value;
            cout << "Enter a value to be removed: " << endl;
            cin >> value;
        } else if (input == 5){
            cout << "Goodbye!!" << endl;
            check = false;
            
        } else {
            cout << "Please enter 1 through 5." << endl;
        }
    }
    
    //test->Clear();
    delete test;
    
    return 0;
}*/

int main(){
    
    BinaryTree* fuckeroo = new BinaryTree();
    
    string choice;
    int value;
    cout<<"Please select one of the following options: \n (1)Print size \n (2)Search \n (3)Insert \n (4)Remove \n (5)Exit program"<<endl;
    cin>>choice;
    while(choice != "5"){
        //////////////////////////
        ///	Size
        /////////////////////////
        if(choice=="1"){
            cout<<"Tree size: "<<fuckeroo->Size()<<endl;
        }
        
        /////////////////////////
        ///	Search
        ////////////////////////
        else if(choice=="2"){
            cout<<"Enter a value to search for: ";
            cin>>value;
            if(fuckeroo->Contains(value)){
                cout<<value<<" was found."<<endl;
            }
            else{
                cout<<value<<" does not exist!"<<endl;
            }
        }
        
        /////////////////////////
        ///	Insert
        ////////////////////////
        else if(choice=="3"){
            cout<<"Enter a value to insert: ";
            cin>>value;
            if(fuckeroo->Insert(value)){
                cout<<value<<" was successfully added."<<endl;
            }
            else{
                cout<<"Error:\n"<<value<<" could not be added."<<endl;
            }
        }
        
        ////////////////////////
        ///	Remove
        ///////////////////////
        else if(choice=="4"){
            cout<<"Enter a value to remove: ";
            cin>>value;
            if(fuckeroo->Remove(value)){
                cout<<value<<" was successfully removed."<<endl;
            }
            else{
                cout<<"Error:\n"<<value<<" value could not be removed."<<endl;
            }
        }
        else{
            cout<<"Please enter a valid option..."<<endl;	
        }
        cout<<"Please select one of the following options: \n (1)Print size \n (2)Search \n (3)Insert \n (4)Remove \n (5)Exit program"<<endl;
        cin>>choice;
    }
    //fuckeroo->Clear();
    delete fuckeroo;
    cout<<"KThxBai!!!"<<endl;
    return 0;
}
