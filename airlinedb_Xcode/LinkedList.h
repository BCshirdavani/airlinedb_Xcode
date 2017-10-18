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
template <class T>
struct node{
    T data;
    node* next;
    node* prev;
};



//**************************************************************
//                          Make DOUBLY Linked List Parent Class
template <class T>
class LinkedList{
private:
    
protected:
    int count;
    node<T> *head, *last;
public:
    LinkedList();
//    LinkedList<T>& operator=(LinkedList<T>&);
    bool isEmpty();
    int length();
    T getFront();
    T getBack();
    virtual void insertNode(T&);
    virtual void deleteNode(T&);
    virtual void searchList(T&);
    void destroyList();
    template <class U>
    friend ostream& operator<<(ostream& os, LinkedList<U>& list);
    ~LinkedList();
};

//**************************************************************
//                                          define = operator
//template <class T>
//LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>& list){
//    if(this!= &list){
//        copylist(list);
//    }
//    return *this;
//}

//**************************************************************
//                                          define CONSTRUCTOR
template <class T>
LinkedList<T>::LinkedList(){
    head = last = NULL;
    count = 0;
}

//**************************************************************
//                                          define isEmpty()
template <class T>
bool LinkedList<T>::isEmpty(){
    return head==NULL;
}

//**************************************************************
//                                          define length()
template <class T>
int LinkedList<T>::length(){
    return count;
}

//**************************************************************
//                                          define getFront()
template <class T>
T LinkedList<T>::getFront(){
    return head->data;
}

//**************************************************************
//                                          define getBack()
template <class T>
T LinkedList<T>::getBack(){
    return last->data;
}

//**************************************************************
//                                          define insertNode()
//                              simple insert only adds to front
template <class T>
void LinkedList<T>::insertNode(T& item){
    node<T> *temp = new node<T>;
    temp->data = item;
    temp->next = head;
    head->prev = temp;
    head = temp;
    count++;
    if(last==NULL) last = temp;
}

//**************************************************************
//                                          define deleteNode()
//                  simple delete requires full node as parameter
template <class T>
void LinkedList<T>::deleteNode(T& item){
    if(head == NULL)
        cout << "list was already empty";
    else{
        if(head->data == item){
            node<T>* p = head;
            head = head->next;
            head->prev = NULL;              // added for double link
            delete p;
            count--;
            if(head==NULL){
                last = NULL;
            }
        }else{
            node<T>* p = head;
            node<T>* q = p->next;
            while(q!=NULL && q->data != item){
                p = q;
                q = q->next;
            }
            if(q!=NULL){
                p->next = q->next;
                q->next->prev = p;         // added for double link
                count--;
                if(last == q) last = p;
                delete q;
            }
        }
    }
}

//**************************************************************
//                                          define searchList()


//**************************************************************
//                                          define << operator
template <class T>
ostream& operator<<(ostream& os, LinkedList<T>& list){
    node<T> *p = list.head;
    while(p!= NULL){
        os<<p->data<<" "<<endl;
        p = p->next;
    }
}

//**************************************************************
//                                          define destroyList()
template <class T>
void LinkedList<T>::destroyList(){
    node<T> *p;
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
template <class T>
LinkedList<T>::~LinkedList(){
    destroyList();
}


#endif /* LinkedList_h */
