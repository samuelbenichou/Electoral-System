//
// Created by Samuel Benichou on 2020-01-04.
//

#include "Democratic.h"
#include "Politician.h"


void Democratic::printParty() {
    cout << "Democrat Party: " << name << ", chairman:" << this->getChairmanFirstName() << ", Size:" << size << endl;
    for (list<Politician*>::const_iterator it = listOfMembers.begin();it != listOfMembers.end();++it) {
        cout << "        ";
        (*it)->print();
    }

}

void Democratic::addDemocratPolitician(Politician *p) {
    this->listOfMembers.push_back(p);
    this->size++;
}

void Democratic::addRepublicanPolitician(Politician *) {
}

void Democratic::updateNumOfParties(int *RepublicanParties, int *DemocratParties) {
    *DemocratParties = *DemocratParties - 1;
}

bool Democratic::politicalMatch(Politician *p) {
    if (p->isDemoc())
        return true;
    return false;
}



