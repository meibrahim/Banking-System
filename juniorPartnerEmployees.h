//
// Created by prati on 12/9/2018.
//

#include <iostream>
#include "people.h"
#include "enumerations.h"
#include "string.h"
using namespace std;

#ifndef BANKINGPROJECT_JUNIORPARTNEREMPLOYEES_H
#define BANKINGPROJECT_JUNIORPARTNEREMPLOYEES_H

class juniorPartnerEmployee:public People {
public:
    juniorPartnerEmployee();
    juniorPartnerEmployee(string first, string last, int age);
    ~juniorPartnerEmployee() { }

    int getJuniorEmployeeId() const;
    int setJuniorEmployeeId(int id);
    Role_t getRole() const;

    void setHiredGroup(string name);
    string getHiredGroup() const;

protected:
    int    juniorPartnerId;
    string hiredGroupName;
};

juniorPartnerEmployee::juniorPartnerEmployee() {
    this->firstName = "";
    this->lastName = "";
    this->age = 18;
    this->banker_id = 0;
    this->netWorth = 0;
    this->hiredGroupName = "";
    this->role     = JUNIORPTR;
}

juniorPartnerEmployee::juniorPartnerEmployee(string first, string last, int age) {
    this->firstName = first;
    this->lastName = last;
    this->age = age;
    this->banker_id = 0;
    this->netWorth = 0;
    this->hiredGroupName = "";
    this->role     = JUNIORPTR;
}

int juniorPartnerEmployee::getJuniorEmployeeId() const {
    return this->juniorPartnerId;
}

int juniorPartnerEmployee::setJuniorEmployeeId(int id) {
    this->juniorPartnerId = id;
    return 0;
}

Role_t juniorPartnerEmployee::getRole() const {
    return this->role;
}

void juniorPartnerEmployee::setHiredGroup(string name) {
    this->hiredGroupName = name;
}

string juniorPartnerEmployee::getHiredGroup() const {
    return this->hiredGroupName;
}

#endif //BANKINGPROJECT_JUNIORPARTNEREMPLOYEES_H
