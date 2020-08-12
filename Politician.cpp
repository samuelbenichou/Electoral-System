//
// Created by Samuel Benichou on 2020-01-04.
//

#include "Politician.h"
#include "Party.h"

Politician::Politician(string firstName,string lastName,string id,int power) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->id = id;
    this->power = power;
    this->chairman = NULL;
    this->party = NULL;
}

Politician::~Politician() {
}

const string &Politician::getFirstName() const {
    return firstName;
}

const string &Politician::getLastName() const {
    return lastName;
}

const string &Politician::getId() const {
    return id;
}

void Politician::setParty(Party *other) {
    this->party = other;
}

Party *Politician::getParty() {
    return this->party;
}

Politician *Politician::getChairman() {
    return chairman;
}

string Politician::getChairmanName() {
    if (chairman == NULL)
        return "None";
    return chairman->firstName;
}

void Politician::setChaiman(Politician* chaiman) {
    this->chairman = chaiman;
}



