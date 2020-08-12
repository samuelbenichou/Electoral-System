//
// Created by samuel Benichou on 2020-01-08.
//

#ifndef HW5_REPUBLICANLEADERPOLITICIAN_H
#define HW5_REPUBLICANLEADERPOLITICIAN_H

#include "RepublicanPolitician.h"
#include "Leader.h"


class RepublicanLeaderPolitician : public RepublicanPolitician, public Leader {

public:
    RepublicanLeaderPolitician(string firstName,string lastName,string id, int power) : Leader(firstName,lastName,id,power),RepublicanPolitician(firstName,lastName,id,power),Politician(firstName,lastName,id,power) {};
    virtual void print();
};


#endif //HW5_REPUBLICANLEADERPOLITICIAN_H
