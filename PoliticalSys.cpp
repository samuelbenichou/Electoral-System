//
// Created by Samuel Benichou on 2020-01-04.
//

#include "PoliticalSys.h"

/* Default Constructor */
PoliticalSys::PoliticalSys() {
    this->numOfParties = 0;
    this->numOfPoliticians = 0;
    this->DemocratParties = 0;
    this->RepublicanParties = 0;
}

/* Append Politician */
void PoliticalSys::addPolitician() {
    bool isCorrect = false;
    cout << "---Create Politician---" << endl;
    string firstName,lastName,id,power,type,typePolitician;
    int s;
    while (!isCorrect) {
        cout << "First name:" << endl;
        cin >> firstName;
        cout << "Last name:" << endl;
        cin >> lastName;
        cout << "ID:" << endl;
        cin >> id;
        cout << "Power:" << endl;
        cin >> power;
        cout << "Republican or Democratic person" << endl;
        cin >> type;
        cout << "Leader or Social" << endl;
        cin >> typePolitician;
        s = atoi(power.c_str());
        try{
            if (isIDexist(id) || s < 0 || (type != "D" && type != "R") || (typePolitician != "L" && typePolitician != "S"))
                throw dataError();
            else
                isCorrect = true;
        }catch (dataError &e){
            cout << e.what() << endl;
        }
    }

    int i = std::atoi(power.c_str());
    if (typePolitician == "L" && type == "D"){
        DemocratLeaderPolitician *newPol = new DemocratLeaderPolitician(firstName,lastName,id,i);
        addPoliticianToParty(newPol);
        this->listOfPoliticians.push_back(newPol);
    }
    else if (typePolitician == "S" && type == "D"){
        DemocratSocialPolitician *newPol = new DemocratSocialPolitician(firstName,lastName,id,i);
        addPoliticianToParty(newPol);
        this->listOfPoliticians.push_back(newPol);
    }
    else if(typePolitician == "S" && type == "R"){
        RepulicanSocialPolitician *newPol = new RepulicanSocialPolitician(firstName,lastName,id,i);
        addPoliticianToParty(newPol);
        this->listOfPoliticians.push_back(newPol);
    }else{
        RepublicanLeaderPolitician *newPol = new RepublicanLeaderPolitician(firstName,lastName,id,i);
        addPoliticianToParty(newPol);
        this->listOfPoliticians.push_back(newPol);
    }
    numOfPoliticians++;
    updateQueue();
}

/* Check if ID exist */
bool PoliticalSys::isIDexist(string id) {
    for (list<Politician*>::iterator it = listOfPoliticians.begin();it != listOfPoliticians.end();it++) {
        if ((*it)->getId() == id)
            return true;
    }
    return false;
}
 /* Append Politician to party */
void PoliticalSys::addPoliticianToParty(Politician *p) {
    int size;
    bool first = false;
    Party *temp;
    for (list<Party*>::iterator it = listOfParties.begin();it != listOfParties.end();it++) {
        if ((*it)->politicalMatch(p)){// a verifier
        //if (((*it)->isDemocratic() && p->isDemoc()) || ((*it)->isRepublican() && p->isRepublic())){ // a modifier
            if (!first){
                // In the first party we pass out all the politicians according to their political opinion
                p->handleParty((*it));
                first = true;
                size = (*it)->getSize();
                temp = *it;
            }
            else if (size > (*it)->getSize()){
                temp->deletePolitician(p);
                p->handleParty((*it));
                size = (*it)->getSize();
                p->setParty((*it));
                temp = *it;
            } else
                continue;
        }
    }
}

/* Append Party */
void PoliticalSys::addParty() {
    bool isCorrect = false;
    cout << "---Create Party---" << endl;
    string partyName,partyType;
    while (!isCorrect) {
        cout << "Name:" << endl;
        cin >> partyName;
        cout << "Republican or Democratic party" << endl;
        cin >> partyType;
        try{
            if ((partyType != "D" && partyType != "R") || isPartyExist(partyName))
                throw dataError();
            else
                isCorrect = true;
        }catch (dataError &e){
            cout << e.what() << endl;
        }
    }

    if (partyType == "D"){
        Democratic *newParty = new Democratic(partyName);
        this->DemocratParties++;
        insertPoliticianToParty(newParty);
        this->listOfParties.push_back(newParty);
    }
    if (partyType == "R"){
        Republican *newParty = new Republican(partyName);
        RepublicanParties++;
        insertPoliticianToParty(newParty);
        this->listOfParties.push_back(newParty);
    }
    numOfParties++;
    updateQueue();
}

/* Print Politician */
void PoliticalSys::printPoliticians() {
    cout << "----Politicians----" << endl;
    for (list<Politician*>::iterator it = listOfPoliticians.begin();it != listOfPoliticians.end();it++) {
        (*it)->print();
    }
}

/* Print Party */
void PoliticalSys::printParties() {
    cout << "----Parties----" << endl;
    for (list<Party*>::iterator it = listOfParties.begin();it != listOfParties.end();it++) {
        (*it)->printParty();
    }
}

/* Delete Politician */
void PoliticalSys::removePolitician() {
    bool isCorrect = false;
    cout << "---Remove Politician---" << endl;
    string id;
    while(!isCorrect) {
        cout << "Enter the ID:" << endl;
        cin >> id;
        try{
            if (!isIDexist(id) || atoi(id.c_str()) < 0)
                throw idException();
            else
                isCorrect = true;
        }catch (idException &e){
            cout << e.what() << endl;
        }
    }

    for (list<Politician*>::iterator it = listOfPoliticians.begin();it != listOfPoliticians.end();it++) {
        if ((*it)->getId() == id) {
            Party *temp = (*it)->getParty();
            temp->deletePolitician(*it);
            Politician *temp1 = *it;
            listOfPoliticians.erase(it);
            delete(temp1);
            break;
        }
    }
    updateQueue();
}

/* Constructor with a path to read */
PoliticalSys::PoliticalSys(string path) {
    this->numOfParties = 0;
    this->numOfPoliticians = 0;
    this->RepublicanParties = 0;
    this->DemocratParties = 0;
    string line;
    ifstream myFile;
    myFile.open(path.c_str());
    if (! myFile)
        cout << "GD: Error reading from file..." << endl;
    if (myFile.is_open()){
        while (getline(myFile,line)){
            if (line.substr(0,line.size()-1) == "Politicians:"){
                while(getline(myFile,line) && line.substr(0,line.size()-1) != "Parties:"){
                    istringstream iss(line.substr(0,line.size()-1));
                    string firstName,lastName,id,type;
                    string data[6];
                    int i = 0;
                    while (iss){
                        iss >> data[i];
                        i++;
                    }
                    firstName = data[0];
                    lastName = data[1];
                    id = data[2];
                    stringstream geek(data[3]);
                    int power;
                    geek >> power;
                    if (data[5] == "L" && data[4] == "D"){
                        DemocratLeaderPolitician *newPol = new DemocratLeaderPolitician(firstName,lastName,id,power);
                        this->listOfPoliticians.push_back(newPol);
                    }
                    else if (data[5] == "S" && data[4] == "D"){
                        DemocratSocialPolitician *newPol = new DemocratSocialPolitician(firstName,lastName,id,power);
                        this->listOfPoliticians.push_back(newPol);
                    }
                    else if(data[5] == "S" && data[4] == "R"){
                        RepulicanSocialPolitician *newPol = new RepulicanSocialPolitician(firstName,lastName,id,power);
                        this->listOfPoliticians.push_back(newPol);
                    }else{
                        RepublicanLeaderPolitician *newPol = new RepublicanLeaderPolitician(firstName,lastName,id,power);
                        this->listOfPoliticians.push_back(newPol);
                    }
                    numOfPoliticians++;
                }
            }
            if(line.substr(0,line.size()-1) == "Parties:"){
                while(getline(myFile,line)){
                    string temp = line;
                    istringstream iss(line.substr(0,line.size()-1));
                    string name;
                    string data[2];
                    int i = 0;
                    while (iss){
                        iss >> data[i];
                        i++;
                    }
                    name = data[0];
                    if (data[1] == "R"){
                        Republican *newRepublic = new Republican(name);
                        RepublicanParties++;
                        insertPoliticianToParty(newRepublic);
                        this->listOfParties.push_back(newRepublic);
                    }
                    else if (data[1] == "D"){
                        Democratic *newDemocrat = new Democratic(name);
                        DemocratParties++;
                        insertPoliticianToParty(newDemocrat);
                        this->listOfParties.push_back(newDemocrat);
                    }
                    else{
                        istringstream f(temp);
                        string s;
                        string data1[2];
                        int j = 0;
                        while (getline(f, s, ' ')) {
                            data1[j] = s;
                            j++;
                        }
                        if (data1[1] == "R"){
                            Republican *newRepublic = new Republican(name);
                            this->RepublicanParties++;
                            insertPoliticianToParty(newRepublic);
                            this->listOfParties.push_back(newRepublic);
                        }
                        else if (data1[1] == "D"){
                            Democratic *newDemocrat = new Democratic(name);
                            this->DemocratParties++;
                            insertPoliticianToParty(newDemocrat);
                            this->listOfParties.push_back(newDemocrat);
                        }
                    }
                    numOfParties++;
                }
            }
        }
        for (list<Party*>::iterator it = listOfParties.begin();it != listOfParties.end();it++) {
            (*it)->setPartyToPoliticians();
            partiesSorted.push(*it);
        }
        myFile.close();
    }
    else
        cout << "Unable to open file";
}

void PoliticalSys::insertPoliticianToParty(Party *p) { // a modifier
    
    if (p->isRepublican()) {
        if (RepublicanParties == 1) {
            for (list<Politician *>::iterator it = listOfPoliticians.begin(); it != listOfPoliticians.end(); it++) {
                (*it)->handleEmptyParty(p);
            }
        }
        else {
            for (list<Party*>::reverse_iterator it = listOfParties.rbegin(); it != listOfParties.rend(); ++it) {
                if ((*it)->isRepublican() && (*it) != p) {
                    while (p->getSize() < (*it)->getSize()) {
                        ((*it)->getAndDelFirstPolitician())->handleParty(p);
                    }
                }
            }
        }
    }
    if (p->isDemocratic()) {
        if (DemocratParties == 1) {
            for (list<Politician *>::iterator it = listOfPoliticians.begin(); it != listOfPoliticians.end(); it++) {
                (*it)->handleEmptyParty(p);
            }
        }
        else {
            for (list<Party*>::reverse_iterator it = listOfParties.rbegin(); it != listOfParties.rend(); ++it) {
                if ((*it)->isDemocratic() && (*it) != p) {
                    while (p->getSize() < (*it)->getSize()) {
                        ((*it)->getAndDelFirstPolitician())->handleParty(p);
                    }
                }
            }
        }
    }
}

/* Delete Party */
void PoliticalSys::removeParty() {
    bool isCorrect = false;
    cout << "---Remove Party---" << endl;
    string name;
    while(!isCorrect) {
        cout << "Enter party name:" << endl;
        cin >> name;
        try {
            if (!isPartyExist(name))
                throw nameError();
            else
                isCorrect = true;
        }catch (nameError &e) {
            cout << e.what() << endl;
        }
    }

    list<Politician*> temp;
    for (list<Party*>::iterator it = listOfParties.begin();it != listOfParties.end();it++) {
        if ((*it)->getPartyName() == name ){
            while ((*it)->getSize() > 0) {
                temp.push_back((*it)->getAndDelFirstPolitician());
            }
            //cout << RepublicanParties << " " << DemocratParties << endl;
            // Update the num of parties by pointers
            (*it)->updateNumOfParties(&RepublicanParties,&DemocratParties);
            //cout << RepublicanParties << " " << DemocratParties << endl;
            /*if ((*it)->isRepublican())
                RepublicanParties--;
            else
                DemocratParties--;*/
            Party *temp = *it;
            listOfParties.erase(it);
            delete(temp);
            break;

        }
    }
    for (list<Politician*>::iterator it = temp.begin(); it != temp.end(); it++) {
        addPoliticianToParty(*it);
    }
    updateQueue();
}

/* United States Presidential Election */
void PoliticalSys::elections() {
    cout << "----Primaries----" << endl;
    for (list<Party*>::iterator it = listOfParties.begin();it != listOfParties.end();it++) {
        (*it)->primeRise();
        cout << (*it)->getChairmanFirstName() << " is the chairman of " << (*it)->getPartyName() << endl;
    }
    int max = -1;
    Party *temp;
    cout << "----Elections----" << endl;
    for (list<Party*>::iterator it = listOfParties.begin();it != listOfParties.end();it++) {
        cout << "Party: " << (*it)->getPartyName() << ",Power: " << (*it)->partyPower() << endl;
        if (max < (*it)->partyPower()){
            max = (*it)->partyPower();
            temp = (*it);
        }
    }
    cout << "----Elections Results----" << endl;
    cout << temp->getPartyName() << " party won the elections and " << temp->getChairmanFirstName() << " is the prime minister" << endl;
}

/* Find out the biggest party */
void PoliticalSys::BiggestParty() {
    cout << "----Biggest Party----" << endl;
    cout << "[" << partiesSorted.top()->getPartyName() << "," << partiesSorted.top()->getSize() << "]" << endl;
}

/* Destructor : Memory cleaner */
PoliticalSys::~PoliticalSys() {
    for (list<Politician*>::iterator it = listOfPoliticians.begin(); it != listOfPoliticians.end(); it++) {
        delete(*it);
    }
    for (list<Party*>::iterator it = listOfParties.begin();it != listOfParties.end();it++) {
        delete(*it);
    }
}

/* Check if the party already exist */
bool PoliticalSys::isPartyExist(string name) {
    for (list<Party*>::iterator it = listOfParties.begin();it != listOfParties.end();it++) {
        if ((*it)->getPartyName() == name)
            return true;
    }
    return false;
}

/* Update the Priority Queue */
void PoliticalSys::updateQueue() {
    while (!partiesSorted.empty()){
        partiesSorted.pop();
    }
    for (list<Party*>::iterator it = listOfParties.begin();it != listOfParties.end();it++) {
        partiesSorted.push(*it);
    }
}



