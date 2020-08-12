//
// Created by samuel Benichou on 2020-01-08.
//

#ifndef HW5_REPULICANSOCIALPOLITICIAN_H
#define HW5_REPULICANSOCIALPOLITICIAN_H

#include "RepublicanPolitician.h"
#include "Social.h"


class RepulicanSocialPolitician : public RepublicanPolitician, public Social {

public:
    RepulicanSocialPolitician(string firstName,string lastName,string id, int power) : Social(firstName,lastName,id,power),RepublicanPolitician(firstName,lastName,id,power),Politician(firstName,lastName,id,power) {};
    virtual void print();

};


#endif //HW5_REPULICANSOCIALPOLITICIAN_H
