#include "people.h"
#include <iostream>
#include <string.h>

#include <cstdlib>
#include <ctime>

#ifndef BANKINGPROJECT_CLIENT_H
#define BANKINGPROJECT_CLIENT_H
using namespace std;



class Client : public People{
public:


    Client();
    Client(string client_name);
    ~Client() { }

    string getClientName()        const;
    int    getExternalpartnerId() const;
    double getBankAccountNumber() const;


    int setBalance(int amount);

    int setAccountNumber(uint32_t number);

    bool removeAccount(string name);
    int generateReferenceNumber() const;
    int askRecommendationNumber(Client& client);
    bool agreeingToReccommendation();
    int setRecommendationNumber(int number);
    int getRecommendationNumber() const;
    void setNetWorth(int amount);
    int getNetWorth() const;

    void addNetWorth(int amount);
    void deductNetWorth(int amount);
private:
    string clientName;
    uint32_t bankAccountNumber;
    int externalPartnerId;
    int referenceNumber;

    int networth;
};

Client::Client() {
    this->clientName = "";
    srand(time(NULL));
    this->bankAccountNumber = 0;
    this->externalPartnerId = 0;
    this->referenceNumber= 0;
}

Client::Client(string name) {
    this->clientName        = name;
    this->referenceNumber = 0;
    this->bankAccountNumber = 0;
    this->externalPartnerId = 0;
    srand(time(NULL));
}

string Client::getClientName() const {
    return this->clientName;

}

int Client::getExternalpartnerId() const {
    return this->externalPartnerId;
}


int Client::setRecommendationNumber(int number) {
    this->referenceNumber = number;
    return 1;
}

bool Client::agreeingToReccommendation() {
    return true;
}

int Client::generateReferenceNumber() const {

    return ((rand()%2000) + 1000);
}

void Client::addNetWorth(int amount) {
    this->netWorth += amount;
}

void Client::deductNetWorth(int amount) {
    this->netWorth -=amount;
}

int Client::getRecommendationNumber() const {
    return this->referenceNumber;
}

int Client::askRecommendationNumber(Client& client) {
    if (this->getClientName() == client.getClientName()) {
        cout << "Self recommendation is not allowed." << endl;
        return 1;
    }
    int token = client.generateReferenceNumber();
    this->setRecommendationNumber(token);
    client.setRecommendationNumber(token);
    //cout << "Recomendation number: " << client.getRecommendationNumber() << endl;
    return 0;
}

void Client::setNetWorth(int amount) {
    this->netWorth = amount;

}

int Client::getNetWorth() const {
    return this->netWorth;
}


#endif //BANKINGPROJECT_CLIENT_H
