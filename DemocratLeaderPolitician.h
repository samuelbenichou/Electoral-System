//
// Created by samuel Benichou on 2020-01-08.
//

#ifndef HW5_DEMOCRATLEADERPOLITICIAN_H
#define HW5_DEMOCRATLEADERPOLITICIAN_H

#include "DemocratPolitician.h"
#include "Leader.h"


class DemocratLeaderPolitician : public DemocratPolitician, public Leader {

public:
    DemocratLeaderPolitician(string firstName,string lastName,string id, int power) : Leader(firstName,lastName,id,power),DemocratPolitician(firstName,lastName,id,power),Politician(firstName,lastName,id,power) {};
    virtual void print();
};


#endif //HW5_DEMOCRATLEADERPOLITICIAN_H
