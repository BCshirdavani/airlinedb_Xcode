//
//  LinkedList.h
//  airlinedb_Xcode
//
//  Created by Shy on 10/17/17.
//  Copyright © 2017 shy macbook. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h
#include "Passenger.hpp"
#include <iostream>
using namespace std;


//**************************************************************
//                                          Make Nodes
//template <class T>
struct node{
//    T data;
    Passenger data;
    node* next;
    node* prev;
};


//**************************************************************
//                          Make DOUBLY Linked List Parent Class
//template <class T>
class LinkedList{
private:
//    LinkedList(const LinkedList&)=delete; //copy constructor
protected:
    int count;
    node *head, *last;
public:
    LinkedList();
    LinkedList& operator=(LinkedList&);
    bool isEmpty();
    int length();
    Passenger getFront();
    Passenger getBack();
    virtual void insertNode(Passenger&);
//    virtual void deleteNode(T&);
    virtual void searchList(string _first, string _last, int FLIGHT_NO);
    void destroyList();
//    template <class U>
    friend ostream& operator<<(ostream& os, LinkedList& list);
    ~LinkedList();
};

//**************************************************************
//                                          define = operator
//template <class T>
//LinkedList& LinkedList::operator=(LinkedList& list){
//    if(this!= &list){
//        copylist(list);
//    }
//    return *this;
//}

//**************************************************************
//                                          define CONSTRUCTOR
//template <class T>
LinkedList::LinkedList(){
    head = last = NULL;
    count = 0;
}

//**************************************************************
//                                          define isEmpty()
//template <class T>
bool LinkedList::isEmpty(){
    return head==NULL;
}

//**************************************************************
//                                          define length()
//template <class T>
int LinkedList::length(){
    return count;
}

//**************************************************************
//                                          define getFront()
//template <class T>
Passenger LinkedList::getFront(){
    return head->data;
}

//**************************************************************
//                                          define getBack()
//template <class T>
Passenger LinkedList::getBack(){
    return last->data;
}

//**************************************************************
//                                          define insertNode()
//                              simple insert only adds to front
//template <class T>
void LinkedList::insertNode(Passenger& item){       cout << "\t\tinserting: " << item.getFirstName() << endl;
    node *temp = new node;
    if(count == 0){                                 cout << "\t\tlist was empty, inserting..." << endl;
        head = temp;
        temp->data = item;                     // & or no &
        last = head;
    }
    else{                                           cout << "\t\tlist was not empty, inserting..." << endl;
        temp->data = item;
        temp->next = last;
        last->prev = temp;
        head = temp;
    }
    count++;
    if(last==NULL) last = temp;
    delete temp;                                // free memory? Or cause problems?
}

//**************************************************************
//                                          define deleteNode()
//                  simple delete requires full node as parameter
//template <class T>
//void LinkedList<T>::deleteNode(T& item){
//    if(head == NULL)
//        cout << "list was already empty";
//    else{
//        if(head->data == item){
//            node<T>* p = head;
//            head = head->next;
//            head->prev = NULL;              // added for double link
//            delete p;
//            count--;
//            if(head==NULL){
//                last = NULL;
//            }
//        }else{
//            node<T>* p = head;
//            node<T>* q = p->next;
//            while(q!=NULL && q->data != item){
//                p = q;
//                q = q->next;
//            }
//            if(q!=NULL){
//                p->next = q->next;
//                q->next->prev = p;         // added for double link
//                count--;
//                if(last == q) last = p;
//                delete q;
//            }
//        }
//    }
//}

//**************************************************************
//                                          define searchList()
//                                              simple search
//template<class T>
void LinkedList::searchList(string _first, string _last, int FLIGHT_NO){
    node* lookHere;
    lookHere = this->head;                                              // this->head ? or head ?
    cout << "\t\tabout to start while from within search" << endl << endl;
    cout << "\t\tcheck if head is NULL" << endl;
    if (head == NULL){cout << "\t\thead is NULL " << endl;}
    cout << "\t\thead contains: " << head << endl;
    cout << "\t\thead->data.getFirstName() contains: " << this->head << " " << head->data.getFirstName() << " " << head->data.getLastName() << endl;
    
    cout << "\t\thead contains: " << head->data.getFirstName() << endl;
    cout << "\t\tsearching for: " << _first << " " << _last << endl;         // ERROR HERE *********************************************
    
    while( ! ( (lookHere->data.getFirstName() == _first) && (lookHere->data.getLastName() == _last) /*&& (lookHere->next != NULL)*/ ) )
    {
        cout << "\t\tcannot find first/last names, or next = null" << endl;
        if((lookHere->data.getFirstName() == _first) && (lookHere->data.getLastName() == _last))
        {
            cout << "\t\tfound it" << endl;
        }
        cout << "\t\tmoving next look here pointer" << endl;
        lookHere = lookHere->next;
    }
    if (lookHere->next == NULL)
    {
        cout << "\t\tcould not find that person." << endl;
    }
    else
    {
        cout << "Flight Number: " << FLIGHT_NO << endl;
        cout << "First Name: " << lookHere->data.getFirstName() << endl;
        cout << "Last Name: " << lookHere->data.getLastName() << endl;
        cout << "Address: " << lookHere->data.getAddress() << endl;
        cout << "Phone: " << lookHere->data.getPhone() << endl;
    }
}

//**************************************************************
//                                          define << operator
//template <class T>
ostream& operator<<(ostream& os, LinkedList& list){
    node *p = list.head;
    while(p!= NULL){
        os << p->data.getFirstName() <<" "<<endl;
        p = p->next;
    }
    
//    for (int i = 0; i < list.length(); i++){
//        os << p->data.getFirstName() <<" "<<endl;
//        p = p->next;
//    }
     return os;
}

//**************************************************************
//                                          define destroyList()
//template <class T>
void LinkedList::destroyList(){
    node *p;
    while(head != NULL){
        p = head;
        head = head->next;
        delete p;
    }
    last = NULL;
    count = 0;
}

//**************************************************************
//                                          define Destructor
//template <class T>
LinkedList::~LinkedList(){
    destroyList();
}


#endif /* LinkedList_h */
