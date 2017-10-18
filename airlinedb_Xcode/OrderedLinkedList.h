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
#include <iostream>
#include <string>
using namespace std;


//**************************************************************
//  Make CHILD class for ORDERED DOUBLY Linked List
//  that inherrits from LinkedList parent
template <class T>
class OrderedLinkedList : public LinkedList{
    
public:
    void insertNode(T&);
    void deleteNode(string _lName, string _fName);
    void searchList(string _lName, string _fName);
};


#endif /* OrderedLinkedList_h */
