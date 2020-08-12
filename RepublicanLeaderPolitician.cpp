//
// Created by samuel Benichou on 2020-01-08.
//

#include "RepublicanLeaderPolitician.h"

void RepublicanLeaderPolitician::print() {
    cout << "Republican Person:" << firstName << " " << lastName << ", Id:"
         << id << ", Power:" << power << ", Type:L, Chairman: " << this->getChairmanName() << endl;
}
