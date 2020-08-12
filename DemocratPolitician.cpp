//
// Created by samuel Benichou on 2020-01-08.
//

#include "DemocratPolitician.h"
#include "Democratic.h"

void DemocratPolitician::handleParty(Party* p) {
    p->addDemocratPolitician(this);
    this->setParty(p);
    this->setChaiman(p->getChairman());
}

void DemocratPolitician::handleEmptyParty(Party *p) {
    p->addDemocratPolitician(this);
}
