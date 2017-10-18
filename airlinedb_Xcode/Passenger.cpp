//
//  Passenger.cpp
//  airlinedb_Xcode
//
//  Created by Shy on 10/17/17.
//  Copyright © 2017 shy macbook. All rights reserved.
//

#include "Passenger.hpp"
#include <stdio.h>
#include <iostream>
#include <string>


//**************************************************************
//                                          Define CONSTRUCTOR
Passenger::Passenger(string _fName, string _lName, string _addr, string _phone){
    mFirstName = _fName;
    mLastName = _lName;
    mAddress = _addr;
    mPhone = _phone;
}


//**************************************************************
//                                          Define GETTERS
string Passenger::getFirstName(){
    return mFirstName;
}

string Passenger::getLastName(){
    return mLastName;
}

string Passenger::getPhone(){
    return mPhone;
}

string Passenger::getAddress(){
    return mAddress;
}







