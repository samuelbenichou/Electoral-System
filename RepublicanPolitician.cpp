//
// Created by samuel Benichou on 2020-01-08.
//

#include "RepublicanPolitician.h"
#include "Republican.h"

void RepublicanPolitician::handleParty(Party *p) {
    p->addRepublicanPolitician(this);
    this->setParty(p);
    this->setChaiman(p->getChairman());
}

void RepublicanPolitician::handleEmptyParty(Party *p) {
    p->addRepublicanPolitician(this);
}
