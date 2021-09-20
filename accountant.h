#include "people.h"
#include <iostream>
#include <string.h>
#include  "enumerations.h"
#include "juniorPartnerEmployees.h"
using namespace std;

#ifndef OBJECT_ORIENTED_ACCOUNTANT_H
#define OBJECT_ORIENTED_ACCOUNTANT_H

class Accountant:public juniorPartnerEmployee {
public:
    Accountant();
    Accountant(string first, string last, int age);
    ~Accountant() { }

    int getJuniorPartnerId() const;

    void setHasBeenHired(bool state);
    bool getHasBeenHired() const;


    Role_t getThisRole();
private:
    int juniorPartnerId;
    bool hasBeenHired = false;
    Role_t role;
};

Accountant::Accountant() {
    this->firstName = "";
    this->lastName = "";
    this->age=18;
    this->role=ACCNTS;
    this->juniorPartnerId=0;
    this->hasBeenHired = false;
    this->hiredGroupName = "";
}


Accountant::Accountant(string first, string last, int age) {
    this->firstName = first;
    this->lastName = last;
    this->age=age;
    this->role=ACCNTS;
    this->juniorPartnerId=0;
    this->hasBeenHired = false;
    this->hiredGroupName = "";

}

int Accountant::getJuniorPartnerId() const {
    return this->juniorPartnerId;
}

void Accountant::setHasBeenHired(bool state) {
    this->hasBeenHired = state;
}

bool Accountant::getHasBeenHired() const {
    return this->hasBeenHired;
}

Role_t Accountant::getThisRole(){
    return this->role;
}

#endif //OBJECT_ORIENTED_ACCOUNTANT_H
