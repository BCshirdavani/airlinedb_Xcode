//
//  main.cpp
//  airlinedb_Xcode
//
//  Created by shy macbook on 10/15/17.
//  Copyright © 2017 shy macbook. All rights reserved.
//
//                                      FIX while loop from SEARCH function of LINKED LIST. The pointers erroneously move to next
//                                      which then calls a Passenger function from a null pointer.

#include "LinkedList.h"
#include "Passenger.hpp"
#include <iostream>
using namespace std;

int main() {
    int FLIGHT_1 = 100;
    LinkedList* LIST_1;
    LIST_1 = new LinkedList();                                                                          cout << "made list" << endl;
    Passenger* P_1;
    P_1 = new Passenger("steve", "smith", "5012 245th ave ne Redmond, WA 98052", "425-885-5535");            cout << "made passenger" << endl;
    Passenger P_2("steve", "smith", "5012 245th ave ne Redmond, WA 98052", "425-885-5535");

    
    LIST_1->insertNode(*P_1);                                   cout << "inserted passenger to list" << endl;
//    LIST_1->insertNode(P_2);
    cout << "checking head from main: " << "\t\tisEmpty() = " << LIST_1->isEmpty() << endl;
    cout << "getFront().getFirstName(): \t" << LIST_1->getFront().getFirstName() << endl;

    cout << "about to search" << endl;
    
    LIST_1->searchList("steve", "smith", FLIGHT_1);
    cout << "searched list" << endl;
    LIST_1->destroyList();
    cout << "destroyed list" << endl;
    
    
    
    
    
    
    
    
    
    
    return 0;
}
