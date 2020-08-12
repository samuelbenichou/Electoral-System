//
// Created by samuel Benichou on 2020-01-08.
//

#include "RepulicanSocialPolitician.h"

void RepulicanSocialPolitician::print() {
    cout << "Republican Person:" << firstName << " " << lastName << ", Id:"
    << id << ", Power:" << power << ", Type:S, Chairman: "  << this->getChairmanName() << endl;
}
