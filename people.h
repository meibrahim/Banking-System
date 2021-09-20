#include <iostream>
#include <string.h>
#include "enumerations.h"


#ifndef PEOPLE_H_
#define PEOPLE_H_
using namespace std;


class People {
public:
    People();
    People(string first_name, string last_name, int age);
    ~People() { }
    string get_name()const ;
    Role_t get_role()const;
    int getBankerId() const;
    void setBankerId(int id);
    string get_lastName() const;

protected:
    string    firstName;
    string    lastName;
    int       age;
    int       banker_id;
    int       netWorth;
    Role_t    role;
};

People::People() {
    this->firstName = "";
    this->lastName = "";
    this->age   =18;
    this->role  = PEOPLE;
    this->netWorth = 0;

}

People::People(string first, string last, int age){
    this->firstName = first;
    this->lastName = last;
    this->age   = age;
    this->role  = PEOPLE;
    this->netWorth = 0;
}

string People::get_name() const {
    return this->firstName;
}

Role_t People::get_role() const {
    return this->role;
}

int People::getBankerId() const {
    return this->banker_id;
}

string People::get_lastName() const {
    return this->lastName;
}

void People::setBankerId(int id) {
    this->banker_id = id;
}
#endif //PEOPLE_H_