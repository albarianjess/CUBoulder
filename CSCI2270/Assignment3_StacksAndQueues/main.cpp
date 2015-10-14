//-----------------------------------------
//  CSCI2270
//  Recitation 103
//  Homework 3
//
//  Created by Jessie Albarian on 10/2/15.
//  Copyright (c) 2015
//  All rights reserved.
//-----------------------------------------

//#include <iostream>
#include "stackArray.h"
#include "stackLinkedList.h"
#include "queueArray.h"
#include "queueLinkedList.h"




//////  //////    ///   //////  //  //  //////        ///   //\   //  //////
//        //    //  //  //      // //   //          //  //  //\\  //  //   //
//////    //    //////  //      ////\   //////      //////  // \\ //  //   //
    //    //    //  //  //      //  \\      //      //  //  //  \\//  //   //
//////    //    //  //  //////  //   \\ //////      //  //  //   \\/  //////

//////  //  //  //////  //  //  //////  //////
//  //  //  //  //      //  //  //      //
//  //  //  //  //////  //  //  //////  //////
// \//  //  //  //      //  //  //          //
//////  //////  //////  //////  //////  //////


int main() {

    StackArray aStack;      // object from stack array
    LinkedList lStack;      // object from stack linked-list
    
    QueueArray aQueue;      // object from queue array
    QueueLinkedList lQueue; // object from queue linked-list
    
    bool mainCheck = true;
    bool check1 = true;
    bool check2 = true;
    bool check3 = true;
    
    
//----------------
// Let's start!
//----------------
    while (mainCheck == true){
    int input;
    cout << "----------------------------"  << endl;
    cout << " Type (1) to create a stack."  << endl;
    cout << " Type (2) to create a queue."  << endl;
    cout << " Type (3) to exit."            << endl;
    cout << "----------------------------"  << endl;
    cout << ">> ";
    cin >> input;
    
        
        
//-----------------------------------
//              STACK
//-----------------------------------
    while (check1 == true){
    if (input == 1){
        //--------------
        // Stack chosen
        //--------------
        int inputStack;
        cout << "----------------------------"  << endl;
        cout << "You chose to create a stack!"  << endl;
        cout << "Do you want"                   << endl;
        cout << "(1) an array or"               << endl;
        cout << "(2) a singly-linked list?"     << endl;
        cout << "----------------------------"  << endl;
        cout << ">> ";
        cin >> inputStack;

        while (check2 == true){
            //-------------------------
            // Create stack with array
            //-------------------------
            if (inputStack == 1){
                int inputSA;
                cout << "----------------------------"  << endl;
                cout << "(1) Push"                      << endl;
                cout << "(2) Pop"                       << endl;
                cout << "(3) Display Stack"             << endl;
                cout << "(4) Exit"                      << endl;
                cout << "----------------------------"  << endl;
                cout << ">> ";
                cin >> inputSA;
                    
                check3 = true;
                while (check3 == true){
                    if (inputSA == 1){
                        int num;
                        cout << "Enter a number to add to the stack" << endl;
                        cin >> num;
                        aStack.push(num);
                        check3 = false;
                    } else if (inputSA == 2){
                        aStack.pop();
                        check3 = false;
                    } else if (inputSA == 3){
                        //call display
                        aStack.display();
                        check3 = false;
                    } else if (inputSA == 4){
                        cout << "Goodbye" << endl;
                        check1 = false;
                        check2 = false;
                        mainCheck = false;
                        check3 = false;
                    } else {
                        cout << "Please enter a proper number." << endl;
                        check3 = false;
                    }
                }
            } else if (inputStack == 2){
                //-------------------------------
                // Create stack with linked list
                //-------------------------------
                while(check2 == true){
                int inputSLL;
                    cout << "----------------------------"  << endl;
                    cout << "(1) Push"                      << endl;
                    cout << "(2) Pop"                       << endl;
                    cout << "(3) Display Stack"             << endl;
                    cout << "(4) Exit"                      << endl;
                    cout << "----------------------------"  << endl;
                    cout << ">> ";
                    cin >> inputSLL;
                    check3 = true;
                    while (check3 == true){
                        if (inputSLL == 1){
                            int num;
                            cout << "Enter a number to add to the stack" << endl;
                            cin >> num;
                            lStack.insert(num);
                            check3 = false;
                        } else if (inputSLL == 2){
                            lStack.remove();
                            check3 = false;
                        } else if (inputSLL == 3){
                            lStack.display();
                            check3 = false;
                        } else if (inputSLL == 4){
                            cout << "Goodbye" << endl;
                            check1 = false;
                            check3 = false;
                            mainCheck = false;
                            check2 = false;
                        } else {
                            cout << "Please enter a proper number." << endl;
                            check3 = false;
                        }
                    }
                }
            } else {
                cout << "Please enter 1 or 2." << endl;
                check2 = false;
            }
        }
        //check1 = false;
      
        
        
        
        
//-----------------------------------
//               QUEUE
//-----------------------------------
        } else if (input == 2){
            //--------------
            // Queue chosen
            //--------------
            while (check1 == true){
            int inputQueue;
            cout << "-------------------------"     << endl;
            cout << "You chose to create a queue!"  << endl;
            cout << "Do you want"                   << endl;
            cout << "(1) an array or"               << endl;
            cout << "(2) a singly-linked list?"     << endl;
            cout << "-------------------------"     << endl;
            cout << ">> ";
            cin >> inputQueue;
            
            while(check2 == true){
                if (inputQueue == 1){
                    int inputQA;
                    cout << "----------------------------"  << endl;
                    cout << "(1) Enqueue"                   << endl;
                    cout << "(2) Dequeue"                   << endl;
                    cout << "(3) Display Queue"             << endl;
                    cout << "(4) Exit"                      << endl;
                    cout << "----------------------------"  << endl;
                    cout << ">> ";
                    cin >> inputQA;
            
                    check3 = true;
                    while (check3 == true){
                        if (inputQA == 1){
                            int num;
                            cout << "Enter a number to add to the queue" << endl;
                            cin >> num;
                            aQueue.enqueue(num);
                            check3 = false;
                        } else if (inputQA == 2){
                            aQueue.dequeue();
                            check3 = false;
                        } else if (inputQA == 3){
                            aQueue.display();
                            check3 = false;
                        } else if (inputQA == 4){
                            cout << "Goodbye" << endl;
                            check2 = false;
                            check1 = false;
                            mainCheck = false;
                            check3 = false;
                        } else {
                            cout << "Please enter a proper number." << endl;
                            check3 = false;
                        }
                    }
                    
                } else if (inputQueue == 2){
                        //-------------------------------
                        // Create queue with linked list
                        //-------------------------------
                        while(check1 == true){
                            int inputQLL;
                            cout << "----------------------------"  << endl;
                            cout << "(1) Enqueue"                   << endl;
                            cout << "(2) Dequeue"                   << endl;
                            cout << "(3) Display Queue"             << endl;
                            cout << "(4) Exit"                      << endl;
                            cout << "----------------------------"  << endl;
                            cout << ">> ";
                            cin >> inputQLL;
                            
                            check2 = true;
                            while (check2 == true){
                                if (inputQLL == 1){
                                    int num;
                                    cout << "Enter a number to add to the queue" << endl;
                                    cin >> num;
                                    lQueue.enqueue(num);
                                    check2 = false;
                                } else if (inputQLL == 2){
                                    lQueue.dequeue();
                                    check2 = false;
                                } else if (inputQLL == 3){
                                    lQueue.display();
                                    check2 = false;
                                } else if (inputQLL == 4){
                                    cout << "Goodbye" << endl;
                                    check1 = false;
                                    mainCheck = false;
                                    check2 = false;
                                } else {
                                    cout << "Please enter a proper number." << endl;
                                    check2 = false;
                                }
                            }
                        }
                } else {
                    cout << "Please enter 1 or 2." << endl;
                    check3 = false;
                    }
                }
                check2 = false;
            }
        //----------
        // End game
        //----------
        } else if (input == 3){
        cout << "Goodbye!" << endl;
        mainCheck = false;
        check1 = false;
        } else {
            cout << "Please enter 1, 2, or 3." << endl;
            check1 = false;
        }
    }
}
    return 0;
}



