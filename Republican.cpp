//
// Created by Samuel Benichou on 2020-01-04.
//

#include "Republican.h"
#include "Politician.h"


void Republican::printParty() {
    cout << "Republican Party: " << name << ", chairman:" << this->getChairmanFirstName() << ", Size:" << size << endl;
    for (list<Politician*>::const_iterator it = listOfMembers.begin();it != listOfMembers.end();++it) {
        cout << "        ";
        (*it)->print();
    }

}

void Republican::addDemocratPolitician(Politician *) {

}

void Republican::addRepublicanPolitician(Politician *p) {
    this->listOfMembers.push_back(p);
    this->size++;
}

void Republican::updateNumOfParties(int *RepublicanParties, int *DemocratParties) {
    *RepublicanParties = *RepublicanParties - 1;
}

bool Republican::politicalMatch(Politician *p) {
    if (p->isRepublic())
        return true;
    return false;
}


