//
// Created by samuel Benichou on 2020-01-04.
//

#pragma once
#ifndef HW5_LEADER_H
#define HW5_LEADER_H

#include <iostream>
#include <string>
#include "Politician.h"

using namespace std;

class Leader : public virtual Politician {

public:

    //^^^^^^^^^^ Constructors and Destructor ^^^^^^^^^^//

    Leader(string firstName,string lastName,string id, int power) : Politician(firstName,lastName,id,power) {};
    virtual ~Leader() {};

    //^^^^^^^^^^ Override Functions ^^^^^^^^^^//

    virtual bool isLeader()const { return true; };
    virtual bool isSocial()const { return false; };
    virtual int getPower();
    virtual int getLeaderPower();

};


#endif //HW5_LEADER_H
