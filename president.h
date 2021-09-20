#include "people.h"
#include "enumerations.h"
#include "seniorEmployees.h"
#include <iostream>
#include <string.h>
using namespace std;


#ifndef PRESEIDENT_H_
#define PRESIDENT_H_

class President : public seniorEmployee {
public:
    President();
    President(string first, string last, int age);
    ~President() { }

    void setStateOfHire(bool state);
    bool getStateOfHire() const;

private:
bool stateOfHire = false;
};

President::President() {
    this->firstName = "";
    this->lastName  = "";
    this->age  = 18;
    this->role = PRSDNT;
    this->netWorth = 0;
    this->stateOfHire = false;
}

President::President(string first, string last, int age) {
    this->firstName = first;
    this->lastName = last;
    this->age   = age;
    this->role  = PRSDNT;
    this->netWorth = 0;
    this->stateOfHire = false;
}

void President::setStateOfHire(bool state) {
    this->stateOfHire = state;
}

bool President::getStateOfHire() const {
    return this->stateOfHire;
}

#endif //PRESIDENT_H_