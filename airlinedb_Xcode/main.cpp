//
//  main.cpp
//  airlinedb_Xcode
//
//  Created by shy macbook on 10/15/17.
//  Copyright © 2017 shy macbook. All rights reserved.
//

#include "LinkedList.h"
#include "Passenger.hpp"
#include <iostream>
using namespace std;

int main() {
    int FLIGHT_1 = 100;
    cout << "made flight" << endl;
    LinkedList<Passenger> LIST_1 = LinkedList<Passenger>();
    cout << "made list" << endl;
    Passenger P_1 = Passenger("steve", "smith", "5012 245th ave ne Redmond, WA 98052", "425-885-5535");
    cout << "made passenger" << endl;
//    Passenger P_2 = Passenger("jason", "dillon", "4434 245th ave ne Redmond, WA 98052", "425-885-8429");
    LIST_1.insertNode(P_1);
    cout << "inserted passenger to list" << endl;
//    LIST_1.insertNode(P_2);
    cout << "about to search" << endl;
    LIST_1.searchList("steve", "smith", FLIGHT_1);
    cout << "searched list" << endl;
    LIST_1.destroyList();
    cout << "destroyed list" << endl;
    
    
    
    
    
    
    
    
    
    
    return 0;
}
