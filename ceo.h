#include "people.h"
#include "enumerations.h"
#include "seniorEmployees.h"
#include <string.h>
#include <iostream>


using namespace std;

#ifndef CEO_H_
#define CEO_H_
class Ceo : public seniorEmployee{
public:
    Ceo();
    Ceo(string first, string last, int age);
    ~Ceo() { }


    void setHire(bool stateOfHire);
    bool getHire() const;
    bool hired = false;

private:

};



Ceo::Ceo() {
    this->firstName = "";
    this->lastName = "";
    this->age   =18;
    this->role  =  CEO;
    this->netWorth = 0;
    this->hired = false;
}

Ceo::Ceo(string first, string last, int age) {
    this->firstName = first;
    this->lastName = last;
    this->age   =age;
    this->role  =  CEO;
    this->netWorth = 0;
    this->hired = false;
}


bool Ceo::getHire() const {
    return this->hired;
}

void Ceo::setHire(bool stateOfHire) {
    this->hired = stateOfHire;

}

#endif //CEO_H_