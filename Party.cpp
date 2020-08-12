//
// Created by Samuel Benichou on 2020-01-04.
//

#include "Party.h"
#include "Politician.h"

Party::Party(string name) {
    this->name = name;
    this->chairman = NULL;
    this->size = 0;
}

void Party::deletePolitician(Politician *newPolitician) {
    // Iterate over the list using Iterators and erase newPolitician
    list<Politician*>::iterator it = this->listOfMembers.begin();
    while (it != this->listOfMembers.end()){
        if ((*it)->getId() == newPolitician->getId()) {
            if (this->chairman == (*it)){
                for (list<Politician*>::iterator it = listOfMembers.begin();it != listOfMembers.end();it++){
                    (*it)->setChaiman(NULL);
                }
                this->chairman = NULL;
            }
            it = this->listOfMembers.erase(it);
            break;
        }
        else
            it++;
    }
    size--;
}

void Party::primeRise() {
    int max = 0;
    // Iterate over the list using Iterators and choose the most powerful member
    list<Politician*>::iterator it = this->listOfMembers.begin();
    while (it != this->listOfMembers.end()){
        if ((*it)->getLeaderPower() > max) {
            max = (*it)->getLeaderPower();
            this->chairman = *it;
        }
        it++;
    }
    if (this->chairman != NULL) {
        for(list<Politician*>::iterator it = listOfMembers.begin();it != listOfMembers.end();++it){
            (*it)->setChaiman(this->chairman);
        }
    }
}

int Party::partyPower() {
    int sum = 0;
    // Iterate over the list using Iterators and choose the powerful member
    list<Politician*>::iterator it = this->listOfMembers.begin();
    while (it != this->listOfMembers.end()){
        sum += (*it)->getPower();
        it++;
    }
    return sum;
}

Party::~Party() {
}

Politician* Party::getChairman(){
    return chairman;
}

string Party::getPartyName() {
    return this->name;
}

int Party::getSize() {
    return size;
}

list<Politician *> Party::getList() {
    return list<Politician*>();
}

Politician *Party::getAndDelFirstPolitician() {
    if (this->size > 0) {
        Politician *temp;
        list<Politician *>::iterator it = listOfMembers.begin();
        temp = (*it);
        deletePolitician((*it));
        if (temp == this->chairman){
            for (list<Politician*>::iterator it = listOfMembers.begin();it != listOfMembers.end();it++){
                (*it)->setParty(NULL);
            }
        }
        temp->setParty(NULL);
        return temp;
    }
    return NULL;
}


void Party::setPartyToPoliticians() {
    for (list<Politician*>::iterator it = listOfMembers.begin();it != listOfMembers.end();it++){
        (*it)->setParty(this);
    }
}

string Party::getChairmanFirstName() {
    if (chairman != NULL)
        return this->chairman->getFirstName();
    return "None";
}

