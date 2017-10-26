//
//  Passenger.hpp
//  airlinedb_Xcode
//
//  Created by Shy on 10/17/17.
//  Copyright © 2017 shy macbook. All rights reserved.
//

#ifndef Passenger_hpp
#define Passenger_hpp
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;



//**************************************************************
//                                          Make Passenger Class
class Passenger{

private:
//    Passenger(const Passenger&) = delete;     //copy constructor
    string mFirstName;
    string mLastName;
    string mAddress;
    string mPhone;
public:
    Passenger& operator=(Passenger&);
    string getFirstName();
    string getLastName();
    string getAddress();
    string getPhone();
    void setFirstName(string);
    void setLastName(string);
    void setAddress(string);
    void setPhone(string);
    Passenger();                            // defult constructor
    Passenger(string, string, string, string);
//    template <class T>
//    friend ostream& operator<<(ostream& os, Passenger& person);
};

//**************************************************************
//                                          define << operator
//template <class T>
// ostream& operator<<(ostream& os, Passenger& p){
//    cout << p.getFirstName() << " " << p.getLastName() << " [" << p.getAddress() << "] [" << p.getPhone() << " ]";
//}

#endif /* Passenger_hpp */
