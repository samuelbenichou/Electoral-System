//
// Created by Samuel Benichou on 2020-01-04.
//

#ifndef HW5_REPUBLICAN_H
#define HW5_REPUBLICAN_H

#include "Party.h"

class Republican : public Party {

public:

    //^^^^^^^^^^ Constructors and Destructor ^^^^^^^^^^//

    Republican(string name) : Party(name){};
    virtual ~Republican() {} ;

    //^^^^^^^^^^ Override Functions ^^^^^^^^^^//

    virtual bool isRepublican()const { return true; };
    virtual bool isDemocratic()const { return false; };
    virtual void printParty();
    virtual void addDemocratPolitician(Politician*);
    virtual void addRepublicanPolitician(Politician*);
    virtual void updateNumOfParties(int*,int*) ;

    virtual bool politicalMatch(Politician*);

};


#endif //HW5_REPUBLICAN_H
