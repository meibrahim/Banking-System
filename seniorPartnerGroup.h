#include "groups.h"
#include "people.h"
#include "enumerations.h"
#include <iostream>
#include <string>


#ifndef SENIOR_PARTNER_GROUP_H_
#define SENIOR_PARTNER_GROUP_H_
using namespace std;
class seniorPartnerGroup : public Groups{
public:
    seniorPartnerGroup();
    seniorPartnerGroup(string group_name);
    ~seniorPartnerGroup() { }

    bool addCeo(Ceo &ceo);
    bool addPresident(President& president);

    bool removeCeo(string name);
    bool removeCeo();


    bool removePresident(string name);
    bool removePresident();


    seniorEmployee& getCeo();
    seniorEmployee& getPresident();

    bool hasCeoNot() const;
    bool hasPresidentNot() const;
    bool printListSeniorPartner();
private:
    std::vector<seniorEmployee> senior_holder;
    bool hasCeo = false;
    bool hasPresident = false;
    int  groupNetworth = 0;

};

seniorPartnerGroup::seniorPartnerGroup() {
    this->groupName        = "";
    this->hasCeo             = false;
    this->hasPresident       = false;
    this->groupNetworth      = 0;
    this->groupCount         = 0;

}

seniorPartnerGroup::seniorPartnerGroup(string group_name) {
    this->groupName        = std::move(group_name);
    this->hasCeo             = false;
    this->hasPresident       = false;
    this->groupNetworth      = 0;
    this->groupCount         = 0;
}


bool seniorPartnerGroup::addCeo(Ceo &ceo) {
    if(ceo.getHire()) {
        //cout << "CEO " << ceo.get_name() << " already hired to " << ceo.getHiredGroup() << endl;
        return 1;
    }
    else {
        if(!this->hasCeoNot()) {
            this->senior_holder.push_back(ceo);
            ceo.setHire(1);
            this->hasCeo = true;
            ceo.setHiredGroup(this->getGroupName());
            cout << "CEO " << ceo.get_name() << " has been hired!" << endl;
            return 0;
        }
        else {
            //cout << "CEO " <<  ceo.get_name() << " already added! " << this->getGroupName() << endl;
            return 1;
        }
    }

}

bool seniorPartnerGroup::addPresident(President &president) {
    if(!president.getStateOfHire() ) {
        if(!this->hasPresidentNot()) {
            this->senior_holder.push_back(president);
            cout << president.get_name() << " has been hired!" << endl;
            this->hasPresident = true;
            president.setStateOfHire(true);
            president.setHiredGroup(this->getGroupName());
            return 0;
        }
        else {
            cout << president.get_name() << " has already been hired into group!" << endl;
            return 1;
        }
    }
    else {
        cout << president.get_name() << " has already been hired into another banking group " << president.getHiredGroup() << endl;
        return 1;
    }

}

bool seniorPartnerGroup:: hasCeoNot() const {
    return this->hasCeo;
}

bool seniorPartnerGroup:: hasPresidentNot() const {
    return this->hasPresident;
}

bool seniorPartnerGroup::removeCeo(string name) {
    std::vector<seniorEmployee>::iterator it;
    int positionCounter = 0;
    bool foundCeo = false;
    for(it = this->senior_holder.begin(); it != this->senior_holder.end(); it++) {
        if (name == (*it).get_name()) {
            cout << "Found CEO " << name <<  endl;
            this->senior_holder.erase(this->senior_holder.begin()+positionCounter);
            foundCeo = true;
            this->hasCeo = false;

        }
        if(foundCeo) {
            cout << "Deletion success!" << endl;
            return 0;
        }
        positionCounter++;
    }
    cout << "CEO " << name << " isn't in this bank " << this->getGroupName() << " to be removed!" << endl;
    return 1;
}

bool seniorPartnerGroup::removeCeo() {
    std::vector<seniorEmployee>::iterator it;
    int positionCounter = 0;
    bool foundCeo = false;
    for(it = this->senior_holder.begin(); it != this->senior_holder.end(); it++) {
        if ((*it).getRole()==CEO) {
            cout << "Found CEO " << (*it).get_name() << endl;
            this->senior_holder.erase(this->senior_holder.begin() + positionCounter);
            foundCeo = true;
            this->hasCeo = false;
        }
        if(foundCeo) {
            cout << "Deletion success!" << endl;
            return 0;
        }
        positionCounter++;
    }
    cout << "CEO isn't in this bank " << this->getGroupName() << " to be removed!" << endl;
    return 1;
}


bool seniorPartnerGroup::removePresident(string name) {
    std::vector<seniorEmployee>::iterator it;
    int positionCounter = 0;
    bool foundPresident = false;
    for(it = this->senior_holder.begin(); it != this->senior_holder.end(); it++) {
        if (name == (*it).get_name()) {
            cout << "Found President " << name <<  endl;
            this->senior_holder.erase(this->senior_holder.begin()+positionCounter);
            foundPresident = true;
            this->hasPresident = false;
        }
        if(foundPresident) {
            cout << "Deletion success!" << endl;
            return 0;
        }
        positionCounter++;
    }
    cout << "President: " << name << " wasn't in the bank " << this->getGroupName() <<" to be removed!" << endl;
    return 1;
}

bool seniorPartnerGroup::removePresident( ) {
    std::vector<seniorEmployee>::iterator it;
    int positionCounter = 0;
    bool foundPresident = false;
    for(it = this->senior_holder.begin(); it != this->senior_holder.end(); it++) {
        if ((*it).get_role() == PRSDNT) {
            cout << "Found President " << (*it).get_name() <<  endl;
            this->senior_holder.erase(this->senior_holder.begin()+positionCounter);
            foundPresident = true;
            this->hasPresident = false;
        }
        if(foundPresident) {
            cout << "Deletion success!" << endl;
            return 0;
        }
        positionCounter++;
    }
    cout << "President wasn't in the bank " << this->getGroupName() <<" to be removed!" << endl;
    return 1;
}





seniorEmployee& seniorPartnerGroup::getCeo() {
    std::vector<seniorEmployee>::iterator it;
    bool foundCeo = false;
    for(it = this->senior_holder.begin(); it != this->senior_holder.end(); it++) {
        if((*it).get_role() == CEO) {
            foundCeo = true;
            //cout << "Returning CEO " << (*it).get_name() << endl;
        }
        if(foundCeo){
            return (*it);
        }
    }
    if(!foundCeo){
        seniorEmployee *snr;
        cout << "CEO not found!" << endl;
        return *snr;
    }
    seniorEmployee *snr;
    return *snr;
}

seniorEmployee& seniorPartnerGroup::getPresident() {
    std::vector<seniorEmployee>::iterator it;
    bool foundPresident = false;
    for(it = this->senior_holder.begin(); it != this->senior_holder.end(); it++) {
        if((*it).get_role() == PRSDNT) {
            foundPresident = true;
            //cout << "Returning President " << (*it).get_name() << endl;
        }
        if(foundPresident){
            return (*it);
        }
    }
    if(!foundPresident){
        seniorEmployee *snr;
        cout << "President not found!" << endl;
        return *snr;
    }
    seniorEmployee *snr;
    return *snr;
}

bool seniorPartnerGroup::printListSeniorPartner() {


    if(!this->hasCeoNot()) {

        cout << "!----------------Senior Partners----------------!" << endl;
        cout << "Name: " << this->getPresident().get_name() << endl;
        cout << "Last name: " << this->getPresident().get_lastName() << endl;;
        cout << "BankedID: " << this->getPresident().getBankerId() << endl;
        cout << "JuniorPartnerID: " << this->getPresident().getSeniorPartnerId() << endl;
        cout << "Postion: President" << endl;
        cout << "!-----------------------------------------------!" << endl;
    }
    else if(!this->hasPresidentNot()) {
        cout << "!----------------Senior Partners----------------!" << endl;
        cout << "Name: " << this->getCeo().get_name() << endl;
        cout << "Last name: " << this->getCeo().get_lastName() << endl;;
        cout << "BankedID: " << this->getCeo().getBankerId() << endl;
        cout << "JuniorPartnerID: " << this->getCeo().getSeniorPartnerId() << endl;
        cout << "Postion: CEO" << endl;
        cout << "!-----------------------------------------------!" << endl;
    }
    else if((!this->hasPresidentNot()) && (!this->hasCeoNot())) {
        throw std::invalid_argument("Empty senior partner group.");
        return 1;
    }
    else {
        cout << "!----------------Senior Partners----------------!" << endl;
        cout << "Name: " << this->getCeo().get_name() << endl;
        cout << "Last name: " << this->getCeo().get_lastName() << endl;;
        cout << "BankedID: " << this->getCeo().getBankerId() << endl;
        cout << "JuniorPartnerID: " << this->getCeo().getSeniorPartnerId() << endl;
        cout << "Postion: CEO" << endl;
        cout << "!-----------------------------------------------!" << endl;
        cout << "!----------------Senior Partners----------------!" << endl;
        cout << "Name: " << this->getPresident().get_name() << endl;
        cout << "Last name: " << this->getPresident().get_lastName() << endl;;
        cout << "BankedID: " << this->getPresident().getBankerId() << endl;
        cout << "JuniorPartnerID: " << this->getPresident().getSeniorPartnerId() << endl;
        cout << "Postion: President" << endl;
        cout << "!-----------------------------------------------!" << endl;
    }


    return 0;
}

#endif //SENIOR_PARTNER_GROUP_H_