//
//  main.cpp
//  Sorting
//
//  Created by Jessie Albarian on 12/11/15.
//  Copyright © 2015 Albarian. All rights reserved.
//

#include <iostream>
using namespace std;


int main() {

    int input;
    
    
    while (true) {
        cout << "Which type of sorting would you like to do?" << endl;
        cout << "1) Selection sort" << endl;
        cout << "2) Bubble sort" << endl;
        cout << "3) Insertion sort" << endl;
        cout << "4) Merge sort" << endl;
        cout << "5) Quick sort" << endl;
        cout << "6) Shell sort" << endl;
        cout << "7) EXIT" << endl;
        cin >> input;
        
        if (input == 1){
            //selectionSort();
        } else if (input == 2){
            //bubbleSort();
        } else if (input == 3){
            //insertionSort();
        } else if (input == 4){
            //mergeSort();
        } else if (input == 5){
            //quickSort();
        } else if (input == 6){
            //shellSort();
        } else if (input == 7){
            break;
        } else {
            cout << "Please enter a valid number" << endl;
        }
    }
    
    return 0;
}
