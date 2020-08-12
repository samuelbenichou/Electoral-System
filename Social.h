//
// Created by Samuel Benichou on 2020-01-04.
//

#pragma once
#ifndef HW5_SOCIAL_H
#define HW5_SOCIAL_H

#include <iostream>
#include <string>
#include "Politician.h"


class Social : public virtual Politician {

public:

    //^^^^^^^^^^ Constructors and Destructor ^^^^^^^^^^//

    Social(string firstName,string lastName,string id, int power) : Politician(firstName,lastName,id,power) {};
    virtual ~Social() {};

    //^^^^^^^^^^ Override Functions ^^^^^^^^^^//

    virtual bool isLeader()const { return false; };
    virtual bool isSocial()const { return true; };
    virtual int getPower();
    virtual int getLeaderPower();
};


#endif //HW5_SOCIAL_H
