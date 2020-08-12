//
// Created by samuel Benichou on 2020-01-08.
//

#ifndef HW5_DEMOCRATPOLITICIAN_H
#define HW5_DEMOCRATPOLITICIAN_H

#include "Politician.h"


class DemocratPolitician : public virtual Politician {

public:

    //^^^^^^^^^^ Constructors and Destructor ^^^^^^^^^^//

    DemocratPolitician(string firstName,string lastName,string id, int power) : Politician(firstName,lastName,id,power) {};

    //^^^^^^^^^^ Override Functions ^^^^^^^^^^//

    virtual void handleParty(Party* p);
    virtual bool isRepublic()const { return false; };
    virtual bool isDemoc()const { return true; };
    virtual void handleEmptyParty(Party* p);

};


#endif //HW5_DEMOCRATPOLITICIAN_H
