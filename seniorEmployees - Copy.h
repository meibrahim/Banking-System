//
// Created by prati on 12/8/2018.
//

#include "people.h"
#include "enumerations.h"
#include <string.h>
#include <iostream>

#ifndef BANKINGPROJECT_SENIOREMPLOYEES_H
#define BANKINGPROJECT_SENIOREMPLOYEES_H

class seniorEmployee:public People {
public:
    seniorEmployee();

    seniorEmployee(string first, string last, int age);

    ~seniorEmployee() {}


    int getSeniorPartnerId() const;
    int setSeniorPartnerId(int id);


    void   setHiredGroup(string name);
    string getHiredGroup();
    Role_t getRole() const;

protected:
    int seniorPartnerId;
    string hiredGroup;
};


seniorEmployee::seniorEmployee() {
   this->firstName = "";
   this->lastName = "";
   this->age = 18;
   this->banker_id = 0;
   this->netWorth = 0;
   this->hiredGroup = "";
   this->role     = SENIORPTR;

}

seniorEmployee::seniorEmployee(string first, string last, int age) {
    this->firstName = first;
    this->lastName = last;
    this->age = age;
    this->banker_id = 0;
    this->netWorth = 0;
    this->hiredGroup = "";
    this->role     = SENIORPTR;
}

int seniorEmployee::getSeniorPartnerId() const {
    return this->seniorPartnerId;
}

int seniorEmployee::setSeniorPartnerId(int id) {
    this->seniorPartnerId = id;
    cout << "ID set:" << this->seniorPartnerId << endl;
    return 0;
}


Role_t seniorEmployee::getRole() const {
    return this->role;
}


void seniorEmployee::setHiredGroup(string name) {
    this->hiredGroup = name;
}

string seniorEmployee::getHiredGroup() {
    return this->hiredGroup;
}
#endif //BANKINGPROJECT_SENIOREMPLOYEES_H
