//
// Created by samuel Benichou on 2020-01-08.
//

#ifndef HW5_DEMOCRATSOCIALPOLITICIAN_H
#define HW5_DEMOCRATSOCIALPOLITICIAN_H

#include "DemocratPolitician.h"
#include "Social.h"

class DemocratSocialPolitician : public DemocratPolitician, public Social {

public:
    DemocratSocialPolitician(string firstName,string lastName,string id, int power) : Social(firstName,lastName,id,power),DemocratPolitician(firstName,lastName,id,power),Politician(firstName,lastName,id,power) {};
    virtual void print();
};


#endif //HW5_DEMOCRATSOCIALPOLITICIAN_H
