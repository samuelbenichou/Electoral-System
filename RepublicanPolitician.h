//
// Created by samuel Benichou on 2020-01-08.
//

#ifndef HW5_REPUBLICANPOLITICIAN_H
#define HW5_REPUBLICANPOLITICIAN_H

#include "Politician.h"


class RepublicanPolitician : public virtual Politician{

public:

    //^^^^^^^^^^ Constructors and Destructor ^^^^^^^^^^//

    RepublicanPolitician(string firstName,string lastName,string id, int power) : Politician(firstName,lastName,id,power) {};

    //^^^^^^^^^^ Override Functions ^^^^^^^^^^//

    virtual void handleParty(Party* p);
    virtual bool isRepublic()const { return true; };
    virtual bool isDemoc()const { return false; };
    virtual void handleEmptyParty(Party* p);

};


#endif //HW5_REPUBLICANPOLITICIAN_H
