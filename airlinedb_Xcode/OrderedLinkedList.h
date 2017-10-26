//
//  OrderedLinkedList.h
//  airlinedb_Xcode
//
//  Created by Shy on 10/17/17.
//  Copyright © 2017 shy macbook. All rights reserved.
//

#ifndef OrderedLinkedList_h
#define OrderedLinkedList_h
#include "LinkedList.h"
//#include "Passenger.hpp"                // redundant to include this again???
#include <iostream>
#include <string>
using namespace std;


//**************************************************************
//  Make CHILD class for ORDERED DOUBLY Linked List
//  that inherrits from LinkedList parent

//template <class T>
class OrderedLinkedList:public LinkedList
{
public:
    void insertNode(Passenger&);
//    void deleteNode(string _lName, string _fName);
//    void searchList(string _lName, string _fName);
};


void OrderedLinkedList::insertNode(Passenger& item){
    cout << "\t\t\tinserting into ORDERED linked list..." << endl;
    node* temp = new node;
    node* oldHead = new node;
    temp->data.setFirstName( item.getFirstName() );
    temp->data.setLastName( item.getLastName() );
    temp->data.setAddress( item.getAddress() );
    temp->data.setPhone( item.getPhone() );
    // list was empty
    if( count == 0 ){
        cout << "\t\t\tORDERED list was empty, adding new node..." << endl;
        head = temp;
        last = head;
    }
    // list was not empty, find spot for alphabetical node entry
    else{
        node* lookHere = head;
        oldHead = head;
        bool spotBefore = 0;
        int indexSpot = 0;
        while ( spotBefore == 0 || indexSpot == length() ){
            if ( item.getLastName() < lookHere->data.getLastName() ){
                cout << "found place to add at:\t" << indexSpot << endl;
                spotBefore = 1;
            }
            
        }
        
    }
    
    
    
    
}


#endif /* OrderedLinkedList_h */
