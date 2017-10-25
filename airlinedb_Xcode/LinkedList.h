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
    bool sameNames(Passenger&, Passenger&);
    int length();
    Passenger getFront();                                                 // commented out on 2017-10-19
    node getFront2();
    Passenger getBack();
    virtual void insertNode(Passenger&);
//    virtual void deleteNode(string, string);
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
//                                          define saneAs()
bool LinkedList::sameNames(Passenger& itemA, Passenger& itemB){
    if( ( itemA.getFirstName() == itemB.getFirstName() ) && ( itemA.getLastName() == itemB.getLastName() ) )
    {
        return true;
    }
    else
        return false;
}

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
    return head->data;                                          // commented out data
}
////template <class T>
//node* LinkedList::getFront(){
//    return head/*->data*/;                                          // commented out data
//}

//**************************************************************
//                                          define getFront2()  NODE
//template <class T>
node LinkedList::getFront2(){
    return *head;                                          // commented out data
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
    node *oldHead = new node;
    if(count == 0){                                 cout << "\t\tlist was empty, inserting..." << endl;
//        temp->data = item;                     // & or no &
        temp->data.setFirstName( item.getFirstName() );
        temp->data.setLastName( item.getLastName() );
        temp->data.setAddress( item.getAddress() );
        temp->data.setPhone( item.getPhone() );
        head = temp;
        last = head;
    }
    else{                                           cout << "\t\tlist was not empty, inserting..." << endl;
//        temp->data = item;
        oldHead = head;                 // NEW ****************
        temp->data.setFirstName( item.getFirstName() );
        temp->data.setLastName( item.getLastName() );
        temp->data.setAddress( item.getAddress() );
        temp->data.setPhone( item.getPhone() );
        temp->next = last;
        oldHead->prev = temp;
        head = temp;
        temp->next = oldHead;   // NEW ****************
//        head->next = last;   
    }
    count++;
    if(last==NULL) last = temp;
//    delete temp;                                // free memory? Or cause problems?
}

//**************************************************************
//                                          define deleteNode()
//                  simple delete requires full node as parameter
//template <class T>
//void LinkedList::deleteNode(string _first, string _last){
//    if(head == NULL)
//        cout << "list was already empty";
//    else{
//        if(/*head->data == item*/  ){
//            node<T>* p = head;
//            head = head->next;
//            head->prev = NULL;              // added for double link
//            delete p;
//            count--;
//            if(head==NULL){
//                last = NULL;
//            }
//        }else{
//            node* p = head;
//            node* q = p->next;
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
            cout << "\t\tsearching for: " << _first << " " << _last << endl;
    while( ( !(lookHere->data.getFirstName() == _first) || !(lookHere->data.getLastName() == _last) ) )
    {
                cout << "\t\t\tnot yet, still in while search loop..." << endl;
                cout << "\t\t\thead->data.getFirstName() contains: " << this->head << " " << head->data.getFirstName() << endl;
                cout << "\t\tmoving next look here pointer" << endl;
        lookHere = lookHere->next;                      // FAILURE TO MOVE NEXT. Maybe an INSERT problem **************
        if((lookHere->data.getFirstName() == _first) && (lookHere->data.getLastName() == _last))
        {
                    cout << "\t\tfound it" << endl;
            break;
        }
//        else{
//                    cout << "\t\tmoving next look here pointer" << endl;
//            lookHere = lookHere->next;                      // FAILURE TO MOVE NEXT. Maybe an INSERT problem **************
//        }

    }
    if((lookHere->data.getFirstName() == _first) && (lookHere->data.getLastName() == _last))
    {
        cout << "\t\tfound it" << endl;
        cout << "Flight Number: " << FLIGHT_NO << endl;
        cout << "First Name: " << lookHere->data.getFirstName() << endl;
        cout << "Last Name: " << lookHere->data.getLastName() << endl;
        cout << "Address: " << lookHere->data.getAddress() << endl;
        cout << "Phone: " << lookHere->data.getPhone() << endl;
    }
    else if (lookHere->next == NULL)
    {
        cout << "\t\tnext = NULL...could not find that person." << endl;
    }
//    else
//    {
//        cout << "Flight Number: " << FLIGHT_NO << endl;
//        cout << "First Name: " << lookHere->data.getFirstName() << endl;
//        cout << "Last Name: " << lookHere->data.getLastName() << endl;
//        cout << "Address: " << lookHere->data.getAddress() << endl;
//        cout << "Phone: " << lookHere->data.getPhone() << endl;
//    }
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
