//
// Created by Samuel Benichou on 2020-01-04.
//

#pragma once
#ifndef HW5_PARTY_H
#define HW5_PARTY_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

class Politician;

class Party {

protected:
    string name;
    Politician *chairman;
    list<Politician*> listOfMembers;
    int size;

public:

    //^^^^^^^^^^ Constructors and Destructor ^^^^^^^^^^//
    Party(string);
    virtual ~Party();

    //^^^^^^^^^^ General Functions ^^^^^^^^^^//
    void deletePolitician(Politician* newPolitician);
    void primeRise();
    int partyPower();

    //^^^^^^^^^^ Pure Virtual Functions ^^^^^^^^^^//
    virtual bool isRepublican()const = 0;
    virtual bool isDemocratic()const = 0;
    virtual void printParty() = 0;
    virtual void addDemocratPolitician(Politician*) = 0;
    virtual void addRepublicanPolitician(Politician*) = 0;
    virtual void updateNumOfParties(int*,int*) = 0;
    virtual bool politicalMatch(Politician*) = 0;

    //^^^^^^^^^^^^^^Getters and Setters^^^^^^^^^^^^^^//
    Politician* getChairman();
    string getPartyName();
    int getSize();
    list<Politician*> getList();
    Politician* getAndDelFirstPolitician();
    string getChairmanFirstName();
    void setPartyToPoliticians();

};



#endif //HW5_PARTY_H
