//
// Created by Samuel Benichou on 2020-01-04.
//

#pragma once
#ifndef HW5_POLITICIAN_H
#define HW5_POLITICIAN_H

#include <iostream>
#include <string>


using namespace std;

class Party;

class Politician {

protected:
    string firstName;
    string lastName;
    string id;
    int power;
    Party *party;
    Politician *chairman;

public:

    //^^^^^^^^^^ Constructors and Destructor ^^^^^^^^^^//

    Politician(string,string,string,int);
    virtual ~Politician();

    //^^^^^^^^^^^^^^Getters and Setters^^^^^^^^^^^^^^//

    const string &getFirstName() const;
    const string &getLastName() const;
    const string &getId() const;
    void setParty(Party *other);
    void setChaiman(Politician*);
    Party* getParty();
    Politician* getChairman();
    string getChairmanName();

    //^^^^^^^^^^^^^^Pure Virtual Functions^^^^^^^^^^^^^^//

    virtual void print() = 0;
    virtual bool isLeader()const = 0;
    virtual bool isSocial()const = 0;
    virtual bool isRepublic()const = 0;
    virtual bool isDemoc()const = 0;
    virtual int getPower() = 0;
    virtual void handleParty(Party* p) = 0;
    virtual int getLeaderPower() = 0;
    virtual void handleEmptyParty(Party* p) = 0;

};


#endif //HW5_POLITICIAN_H
