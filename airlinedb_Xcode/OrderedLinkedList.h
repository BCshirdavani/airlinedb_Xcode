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
//    node* temp;
//    node* oldHead = new node;
//    oldHead = head;
    temp->data.setFirstName( item.getFirstName() );
    temp->data.setLastName( item.getLastName() );
    temp->data.setAddress( item.getAddress() );
    temp->data.setPhone( item.getPhone() );
    // list was empty
    if( count == 0 ){
        cout << "\t\t\tORDERED list was empty, adding new node for:\t\t" << item.getFirstName() << " " << item.getLastName() << endl;
        head = temp;
        last = head;
        count++;
    }
    // list was not empty, find spot for alphabetical node entry
    else{
        node* lookHere = head;
//        oldHead = head;
        bool spotBefore = 0;
        int indexSpot = 0;
        // search for place to alphabetically insert
        // spotBefore = 1 when location found
        // stop search when lenght of list is reached...
        while ( spotBefore == 0 || indexSpot <= length() ){
            if ( ( item.getLastName() < lookHere->data.getLastName() ) ){
                cout << "\t\t\tfound place to add at:\t" << indexSpot << endl;
//                spotBefore = 1;
                break;
            }
            // stop while loop when spot should be at end...
            else if( indexSpot == length() ){
                spotBefore = 1;
                break;
            }
            else{
                cout << "\t\t\tlooking next for spot..." << endl;
                indexSpot++;
                cout << "\t\t\tlookHere was:\t\t" << lookHere << endl;
                lookHere = lookHere->next;
                cout << "\t\t\tlookHere is now:\t\t" << lookHere << endl;
            }
        }
        // spot is at front
        if ( indexSpot == 0 ){
            cout << "\t\t\tinserting at front..." << endl;
            head->prev = temp;
            temp->next = head;
            head = temp;
            count++;
        }
        // spot is at end
        else if ( indexSpot == length() ){
            cout << "\t\t\tinserting at end..." << endl;
            cout << "\t\t\tindex spot:\t" << indexSpot << " length():\t" << length() << endl;
            last->next = temp;
            temp->prev = last;
            last = temp;
            count++;
        }
        // spot is in middle
        else{
            cout << "\t\t\tinserting in middle..." << endl;
            cout << "\t\t\tindex spot:\t" << indexSpot << " length():\t" << length() << endl;
            node* right = head;
            node* left = head;
            for ( int i = 0; i < indexSpot; i++ ){
                right = right->next;
            }
            for ( int i = 1; i < indexSpot; i++ ){
                left = left->next;
            }
            temp->next = right;
            temp->prev = left;
            left->next = temp;
            right->prev = temp;
            count++;
        }
    }
//    delete temp;
//    delete oldHead;
    
}


#endif /* OrderedLinkedList_h */
