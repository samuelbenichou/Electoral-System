//
// Created by samuel Benichou on 2020-01-04.
//

#ifndef HW5_POLITICALSYS_H
#define HW5_POLITICALSYS_H


#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include "Politician.h"
#include "Party.h"
#include "Republican.h"
#include "Leader.h"
#include "Social.h"
#include "Democratic.h"
#include "DemocratSocialPolitician.h"
#include "DemocratLeaderPolitician.h"
#include "RepublicanLeaderPolitician.h"
#include "RepulicanSocialPolitician.h"
#include "Exception.h"

class CompareParties
{
public:
    bool operator() (Party* a, Party* b)
    {
        if (a->getSize() == b->getSize())
            return a->getPartyName() < b->getPartyName();
        return a->getSize() < b->getSize();
    }
};


class PoliticalSys {

private:
    list<Politician*> listOfPoliticians;
    list<Party*> listOfParties;
    priority_queue<Party*,vector<Party*>,CompareParties> partiesSorted;
    int numOfPoliticians;
    int numOfParties;
    int DemocratParties;
    int RepublicanParties;

private:

    bool isIDexist(string);
    void addPoliticianToParty(Politician*);
    void insertPoliticianToParty(Party*);
    bool isPartyExist(string);
    void updateQueue();

public:

    //^^^^^^^^^^ Constructors ^^^^^^^^^^//

    PoliticalSys();
    PoliticalSys(string);
    virtual ~PoliticalSys();

    //^^^^^^^^^^^^^^^^^^ GAME LOGIC ^^^^^^^^^^^^^^^^^^//

    void addPolitician();
    void addParty();
    void removePolitician();
    void removeParty();
    void elections();
    void printPoliticians();
    void printParties();
    void BiggestParty();
    //void insertPoliticianToParty(Party*);


};



#endif //HW5_POLITICALSYS_H
