#include "enumerations.h"
#include "people.h"
#include <iostream>
#include <string.h>
#include "juniorPartnerEmployees.h"
#include "client.h"
using namespace std;

#ifndef MANAGER_H_
#define MANAGER_H_

class Manager:public juniorPartnerEmployee {
public:
    Manager();
    Manager(string first, string last, int age);
    ~Manager() { }

    int getJuniorPartnerId() const;

    void setHasBeenHired(bool state);
    bool getHasBeenHired() const;

    bool agreeToClose(bool hasLoan) const;

    bool agreeForLoan(Client& client, int loanAmount);

    string getHiredGroupName() const;
    Role_t getThisRole() const;
private:
    int juniorPartnerId;
    bool hasBeenHired = false;

};

Manager::Manager() {
    this->firstName = "";
    this->lastName = "";
    this->age = 18;
    this->role=MNGR;
    this->juniorPartnerId = 0;
    this->netWorth = 0;
    this->hiredGroupName = "";
    this->hasBeenHired = false;
}

Manager::Manager(string first, string last, int age) {
    this->firstName = first;
    this->lastName  = last;
    this->age=age;
    this->role=MNGR;
    this->juniorPartnerId = 0;
    this->netWorth = 0;
    this->hiredGroupName = "";
    this->hasBeenHired = false;
}

int Manager::getJuniorPartnerId() const {
    return this->juniorPartnerId;
}

bool Manager::getHasBeenHired() const {
    return this->hasBeenHired;
}

void Manager::setHasBeenHired(bool state) {
    this->hasBeenHired = state;
}

bool Manager::agreeToClose(bool hasLoan) const {
    if(hasLoan) return false;
    else return true;
}

bool Manager::agreeForLoan(Client &client, int loanAmount) {
    
    if( client.getNetWorth() >= (0.25 * loanAmount) ) {
        cout << "Loan can be granted." << endl;
        return 1;
    }
    else {
        cout << "Loan cannot be granted!" << endl;
        return 0;
    }
}

string Manager::getHiredGroupName() const {
    return this->hiredGroupName;
}

Role_t Manager::getThisRole() const {
    return this->role;
}
#endif //MANAGER_H_
