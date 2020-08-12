//
// Created by samuel Benichou on 2020-01-08.
//

#include "DemocratSocialPolitician.h"

void DemocratSocialPolitician::print() {
    cout << "Democratic Person:" << firstName << " " << lastName << ", Id:"
    << id << ", Power:" << power << ", Type:S, Chairman: " << this->getChairmanName() << endl;
}

