//
// Created by samuel Benichou on 2020-01-08.
//

#include "DemocratLeaderPolitician.h"

void DemocratLeaderPolitician::print() {
    cout << "Democratic Person:" << firstName << " " << lastName << ", Id:"
    << id << ", Power:" << power << ", Type:L, Chairman: " << this->getChairmanName() << endl;
}

