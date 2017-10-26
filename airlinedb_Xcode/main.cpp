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
#include "OrderedLinkedList.h"
#include "Passenger.hpp"
#include <iostream>
using namespace std;

int main() {
    int FLIGHT_1 = 100;
    LinkedList* LIST_1;
    LIST_1 = new LinkedList();                                                                                  cout << "made list" << endl;
    Passenger* P_1;
    Passenger* P_2;
    Passenger* P_3;
    P_1 = new Passenger("steve", "smith", "5012 245th ave ne Redmond, WA 98052", "425-885-5535");               cout << "made passenger" << endl;
    P_2 = new Passenger("jason", "dillon", "5012 245th ave ne Redmond, WA 98052", "425-885-5535");              cout << "made passenger" << endl;
    P_3 = new Passenger("mike", "ungaro", "5012 245th ave ne Redmond, WA 98052", "425-885-5535");              cout << "made passenger" << endl;
    
    cout << "checking LENGTH from main: " << "\tLIST_1->length() = " << LIST_1->length() << endl;
//    cout << "checking HEAD from main: " << "\tLIST_1->getFront().getFirstName() = " << LIST_1->getFront().getFirstName() << endl;
//    cout << "checking last from main: " << "\tLIST_1->getBack().getFirstName() = " << LIST_1->getBack().getFirstName() << endl;

    LIST_1->insertNode(*P_1);                                   cout << "inserted passenger P_1 to list" << endl;
    
    
    cout << "checking LENGTH from main: " << "\tLIST_1->length() = " << LIST_1->length() << endl;
    cout << "checking HEAD from main: " << "\tLIST_1->getFront().getFirstName() = " << LIST_1->getFront().getFirstName() << endl;
    cout << "checking last from main: " << "\tLIST_1->getBack().getFirstName() = " << LIST_1->getBack().getFirstName() << endl;
    
    LIST_1->searchList("steve", "smith", FLIGHT_1);
    cout << "searched list" << endl;
    
    
    
    
    LIST_1->insertNode(*P_2);                                   cout << "inserted passenger P_2 to list" << endl;
//            cout << "checking head from main: " << "\t\tisEmpty() = " << LIST_1->isEmpty() << endl;
//            cout << "getFront().getFirstName(): \t" << (LIST_1->getFront()).getFirstName() << endl;
//            cout << "getFront2().data.getFirstName(): \t" << (LIST_1->getFront2()).data.getFirstName() << endl;
    cout << "checking LENGTH from main: " << "\tLIST_1->length() = " << LIST_1->length() << endl;
    cout << "checking HEAD from main: " << "\tLIST_1->getFront().getFirstName() = " << LIST_1->getFront().getFirstName() << endl;
    cout << "checking last from main: " << "\tLIST_1->getBack().getFirstName() = " << LIST_1->getBack().getFirstName() << endl;
    
    LIST_1->searchList("jason", "dillon", FLIGHT_1);
    cout << "searched list" << endl;
    
    
    
    
    
    LIST_1->insertNode(*P_3);                                   cout << "inserted passenger P_3 to list" << endl;
    //            cout << "checking head from main: " << "\t\tisEmpty() = " << LIST_1->isEmpty() << endl;
    //            cout << "getFront().getFirstName(): \t" << (LIST_1->getFront()).getFirstName() << endl;
    //            cout << "getFront2().data.getFirstName(): \t" << (LIST_1->getFront2()).data.getFirstName() << endl;
    cout << "checking LENGTH from main: " << "\tLIST_1->length() = " << LIST_1->length() << endl;
    cout << "checking HEAD from main: " << "\tLIST_1->getFront().getFirstName() = " << LIST_1->getFront().getFirstName() << endl;
    cout << "checking last from main: " << "\tLIST_1->getBack().getFirstName() = " << LIST_1->getBack().getFirstName() << endl;
    
    LIST_1->searchList("mike", "ungaro", FLIGHT_1);
    cout << "searched list" << endl;
    
    
    
    LIST_1->searchList("jason", "dillon", FLIGHT_1);
    cout << "searched list" << endl;
    
    
    // testing LIST
    cout << endl << endl << "about to print list" << endl;
    LIST_1->list();
    
//    // testing DELETE
//    cout << endl << endl << "about to delete steve" << endl;
//    LIST_1->deleteNode("jason", "dillon");
//    LIST_1->list();
//
//    LIST_1->destroyList();
//            cout << "destroyed list" << endl;
    
    
    
    // testing string comparison
    string dillon = "dillon";
    string smith = "smith";
    cout << endl << "\tdillon < smith:\t" << ( dillon<smith )<< endl;
    cout << endl << "\tdillon > smith:\t" << ( dillon>smith )<< endl;
    
    
    cout << endl << endl << endl << "making ORDERED linked list now..." << endl;
    OrderedLinkedList* oList_1;
    oList_1 = new OrderedLinkedList();
    cout << "list length:\t\t" << oList_1->length() << endl;
    cout << "about to add:\t\t:" << P_1->getFirstName() << " " << P_1->getLastName() << endl;
    oList_1->insertNode(*P_1);
    cout << "list length:\t\t" << oList_1->length() << endl;
    cout << "Front entry:\t\t" << oList_1->getFront().getFirstName() << endl;
    oList_1->list();
    cout << "about to add:\t\t:" << P_2->getFirstName() << " " << P_2->getLastName() << endl;
    oList_1->insertNode(*P_2);
    cout << "list length:\t\t" << oList_1->length() << endl;
    cout << "Front entry:\t\t" << oList_1->getFront().getFirstName() << endl;
    oList_1->list();
    cout << "about to add:\t\t:" << P_3->getFirstName() << " " << P_3->getLastName() << endl;
    oList_1->insertNode(*P_3);
    cout << "list length:\t\t" << oList_1->length() << endl;
    cout << "Front entry:\t\t" << oList_1->getFront().getFirstName() << endl;
    oList_1->list();
    
    
    
    
    
    
    
    
    
    
    return 0;
}
