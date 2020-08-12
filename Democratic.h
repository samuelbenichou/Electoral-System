//
// Created by samuel Benichou on 2020-01-04.
//

#ifndef HW5_DEMOCRATIC_H
#define HW5_DEMOCRATIC_H


#include "Party.h"

class Democratic : public Party {

public:

    //^^^^^^^^^^ Constructors and Destructor ^^^^^^^^^^//

    Democratic(string name) : Party(name){};
    virtual ~Democratic() {} ;

    //^^^^^^^^^^ Override Functions ^^^^^^^^^^//

    virtual bool isRepublican()const override { return false; };
    virtual bool isDemocratic()const override { return true; };
    virtual void printParty();
    virtual void addDemocratPolitician(Politician*);
    virtual void addRepublicanPolitician(Politician*);
    virtual void updateNumOfParties(int*,int*) ;
    virtual bool politicalMatch(Politician*);

};


#endif //HW5_DEMOCRATIC_H
