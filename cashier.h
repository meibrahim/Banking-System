//
// Created by prati on 12/7/2018.
//
#include "people.h"
#include <iostream>
#include "enumerations.h"
#include <string.h>
#include "juniorPartnerEmployees.h"
#ifndef OBJECT_ORIENTED_CASHIER_H
#define OBJECT_ORIENTED_CASHIER_H
using namespace std;


class Cashier:public juniorPartnerEmployee {
public:
    Cashier();
    Cashier(string first, string last, int age);
    ~Cashier() { }

    void setHasBeenHired(bool state);
    bool getHasBeenHired() const;

    Role_t getThisRole();
private:
    int juniorPartnerId;
    bool hasBeenHired = false;
    Role_t role;
};
Cashier::Cashier() {
    this->firstName = "";
    this->lastName = "";
    this->age=18;
    this->role=CASHRS;
    this->juniorPartnerId=0;
    this->hasBeenHired = false;
}

Cashier::Cashier(string first, string last, int age) {
    this->firstName = first;
    this->lastName = last;
    this->age=age;
    this->role=CASHRS;
    this->juniorPartnerId=0;
    this->hasBeenHired = false;
}

void Cashier::setHasBeenHired(bool state) {
    this->hasBeenHired = state;
}

bool Cashier::getHasBeenHired() const {
    return this->hasBeenHired;
}

Role_t Cashier::getThisRole() {
    return this->role;
}
#endif //OBJECT_ORIENTED_CASHIER_H
