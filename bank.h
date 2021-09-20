//
// Created by prati on 12/12/2018.
//
#include "people.h"
#include "groups.h"
#include "juniorEmployeeGroup.h"
#include "juniorPartnerEmployees.h"
#include "seniorEmployees.h"
#include "seniorPartnerGroup.h"
#include "enumerations.h"
#include "client.h"
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <ctime>

#ifndef BANKINGPROJECT_BANK_H
#define BANKINGPROJECT_BANK_H
using namespace std;

class Bank {
public:

    struct BankAccounts {
        string bankName;
        string accountHolderName;
        int accountNumber;
        int accountBalance;
        int loanAmount;
        bool hasLoan;
        int amountRepayed;
        int previousNumberOfLoans;

        BankAccounts() {
            this->bankName = "";
            this->accountHolderName = "";
            this->accountNumber = 0;
            this->accountBalance = 0;
            this->loanAmount = 0;
            this->amountRepayed = 0;
            this->previousNumberOfLoans = 0;
            this->hasLoan = false;
        }

        BankAccounts(string name) {
            this->bankName = name;
            this->accountHolderName = "";
            this->accountNumber = 0;
            this->accountBalance = 0;
            this->loanAmount = 0;
            this->amountRepayed = 0;
            this->previousNumberOfLoans = 0;
            this->hasLoan = false;
        }
        void setAccountNumber(int accountNumber) {
            this->accountNumber = accountNumber;
        }

        void setAccountHolderName(string name) {
            this->accountHolderName = name;
        }

        void setAccountBalance(int balance) {
            this->accountBalance  = this->getAccountBalance()+balance;
        }

        bool loanTaken() {
            return this->hasLoan;
        }

        int getAccountBalance() {
            return this->accountBalance;
        }

        void deductFromBalance(int amount) {
            this->accountBalance -= amount;
        }




    };
    Bank();
    Bank(string name);
    ~Bank() { }

    bool addCeoToBank(Ceo& ceo);
    bool addPresidentToBank(President& president);
    bool addManagerToBank(Manager& manager);
    bool addClientToBank(Client& client);
    bool addCashierToBank(Cashier& cashier);
    bool addAccountantToBank(Accountant& accountant);


    bool removeCeo(Ceo& ceo);
    bool removePresident(President& president);
    bool removeManager(Manager& manager);
    bool removeClient(Client& client);

    bool fireCashier(Cashier& cashier);
    bool fireAccountant(Accountant& accountant);




    bool requestBankForLoan(Bank& bank);
    bool respondToLoanRequest(Bank& bank);

    void printEmployeeInformation();
    void printClientInformation();


    string getBankName()           const;
    int    getGetBankNetWorth()    const;
    int    getBankCredibility()    const;
    string getCeoName()            const;
    string getPresidentName()      const;
    bool   openAccount(Client& client, int accountNumber, int balance);
    bool   addAccount(Client& client, int accountNumber, int balance);
    int    getAccountBalance(Client const &  client, int accountNumber);
    bool   closeAccount(Client& client, int accountNumbe);
    bool   depositCash(Client& client, int accountNumber, int amount);
    bool   withdrawCash(Client& client, int accountNumber,  int amount);
    bool   requestForLoan(Client& client, int accountNumber,
            int amount);


    bool transferMoney(Client& client1, int actn1, int amount, Client& client2, int acnt2);
    bool crossBankTransfer(Client& sender,int actn1, int amount, Client& recipient,int actn2, Bank& recipientBank);
    bool repayLoan(Client& client, int acctn, int amount);

private:
    string bankName;
    int bankNetWorth;
    int bankCredibility;
    seniorPartnerGroup  gp1;
    juniorEmployeeGroup gp2;
    std::vector<BankAccounts> bankAccounts;
    Manager siteManager;

};


Bank :: Bank() {
    this->bankName = "";
    this->bankNetWorth = 0;
    this->bankCredibility = 0;
    srand(time(NULL));
    seniorPartnerGroup      tmpGrp1("random");
    juniorEmployeeGroup     tmpGrp2("random");
    this->gp1 = tmpGrp1;
    this->gp2 = tmpGrp2;

    Manager m1("dfd","sds",21);
    this->siteManager = m1;
}

Bank::Bank(string name) {
    srand(time(NULL));
    this->bankName = name;
    this->bankNetWorth    = ( rand() % 100000 )  + 60000 ;
    this->bankCredibility = ( rand() % 1000000 ) + 1000000;
    seniorPartnerGroup      tmpGrp1(name);
    juniorEmployeeGroup     tmpGrp2(name);

    this->gp1 = tmpGrp1;
    this->gp2 = tmpGrp2;
    Manager m1("dfd","sds",21);
    this->siteManager = m1;
}

string Bank::getBankName() const {
    return this->bankName;
}

int Bank::getGetBankNetWorth() const {
    return this->bankNetWorth;
}

int Bank::getBankCredibility() const {
    return this->bankCredibility;
}

bool Bank::addCeoToBank(Ceo &ceo) {
    ceo.setBankerId((rand()% 600) + 50);
    ceo.setSeniorPartnerId((rand()%10000)+5000);
    if(!this->gp1.addCeo(ceo)){
        return true;
    }
    else {

        try {
            throw std::invalid_argument("CEO " + ceo.get_name() + " has already been hired to " + ceo.getHiredGroup());
        }
        catch (std::exception& e) {
            cout << e.what() << endl;
            return false;
        }

    }

}

bool Bank::addPresidentToBank(President &president) {
    president.setBankerId((rand()% 600) + 50);
    president.setSeniorPartnerId((rand()%10000)+5000);
    if(!this->gp1.addPresident(president)) return true;
    else {
        try {
            throw std::invalid_argument("President " + president.get_name() +" has already been hired to  "+ president.getHiredGroup());
        }
        catch (std::exception& e) {
            cout << e.what() << endl;
            return false;
        }
    }
}

bool Bank::addManagerToBank(Manager &manager) {
    manager.setBankerId((rand()% 600) + 50);
    manager.setJuniorEmployeeId((rand()% 600)+50);
    if(!this->gp2.addManager(manager)) {
        return true;
    }
    else {
        try {
            throw std::invalid_argument("Manager " + manager.get_name() + " has already been hired to " + manager.getHiredGroup());
        }
        catch(std::exception& e) {
            cout << e.what() << endl;
            return false;
        }

    }
}

bool Bank::addAccountantToBank(Accountant &accountant) {
    accountant.setBankerId((rand()%600)+100);
    accountant.setJuniorEmployeeId((rand()%600)+50);
    try {
        if(!this->gp2.addAccountant(accountant)) return true;
    }
    catch (std::exception& e) {
        cout << e.what() << endl;
    }
    return false;
}

bool Bank::addCashierToBank(Cashier &cashier) {

    try {
        cashier.setBankerId( (rand() % 500) + 100);
        cashier.setJuniorEmployeeId((rand()%500)+100);
        if(!this->gp2.addCashier(cashier)) {

            return true;
        }
    }
    catch (std::exception& e) {
        cout <<  e.what() << endl;
    }
    return false;
}

bool Bank::removeCeo(Ceo &ceo) {
    try {
        if(!this->gp1.removeCeo()){
            ceo.setHire(false);
            ceo.setHiredGroup("not hired.");
            return true;
        }
        else {
            throw std::invalid_argument("Cant find CEO in this bank " + this->getBankName());
            return false;
        }
    }
    catch (exception& e) {
        cout << e.what() << endl;
        return false;
    }

}

bool Bank::removePresident(President &president) {
    if(!this->gp1.removePresident()) {
        president.setStateOfHire(false);
        president.setHiredGroup("not hired");
        return true;
    }
    else {
        try {
            throw std::invalid_argument("Cant find President in this bank " + this->getBankName());
        }
        catch (std::exception& e) {
            cout << e.what() << endl;
            return false;
        }
    }
}

bool Bank::removeManager(Manager &manager) {
    try {
        if(!this->gp2.removeManager()) {
            manager.setHasBeenHired(false);
            manager.setJuniorEmployeeId(0);
            manager.setBankerId(0);
            cout << "Manager " << manager.get_name() << " has been removed from the group " << this->getBankName() << endl;
            return true;
        }
    }
    catch (std::exception& e) {
        cout << e.what() << endl;
        return false;
    }

    return false;
}


bool Bank::fireCashier(Cashier &cashier) {
    if(!this->gp2.removeCashier(cashier.getBankerId())) {
        cashier.setHasBeenHired(false);
        cashier.setJuniorEmployeeId(0);
        cashier.setBankerId(0);
        return true;
    }
    else {
        try {
            throw std::invalid_argument("Cant find cashier in this bank " + this->getBankName());
        }
        catch (std::exception& e){
            cout << e.what() << endl;
            return false;
        }

    }
}

bool Bank::fireAccountant(Accountant &accountant) {
    if(!this->gp2.removeAccountant(accountant.getBankerId())) {
        accountant.setHasBeenHired(false);
        accountant.setJuniorEmployeeId(0);
        accountant.setBankerId(0);
        return true;
    }
    else {
        try {
            throw std::invalid_argument("Cant find accountant in this bank " + this->getBankName());
        }
        catch (std::exception& e) {
            cout << e.what() << endl;
            return false;
        }

    }
}


bool Bank::openAccount(Client &client, int accountNumber, int balances) {
    try {
        if(!this->addAccount(client, accountNumber, balances )){
                return true;
        }
    }
    catch (std::exception& e) {
        cout << e.what() << endl;
    }
    return false;
}

bool Bank::addAccount(Client& client, int accountNumber, int balance){


    std::vector<BankAccounts>::iterator iter;
    for(iter = this->bankAccounts.begin(); iter != bankAccounts.end(); iter++) {
        if((*iter).accountNumber == accountNumber) {
            //cout << "Account with account number: " << (*iter).accountNumber << " already exists!, Please choose another account number." << endl;
            throw std::runtime_error("Account with account number: " + std::to_string((*iter).accountNumber) + " already existss!, Please choose another account number");
            return 1;
        }
    }
    if(balance >= 10000) {
        struct BankAccounts newAccount(this->getBankName());
        newAccount.setAccountHolderName(client.getClientName());
        newAccount.setAccountNumber(accountNumber);
        newAccount.setAccountBalance(balance);
        this->bankAccounts.push_back(newAccount);
        client.setNetWorth(balance);
        cout << client.getClientName() << "'s account has been opened: " << newAccount.accountNumber << endl;
        return 0;
    }
    else {
        //cout << "Client " << client.getClientName() << " is not recommended by " << recommendedClient.getClientName() << endl;
        throw std::domain_error("Client " + client.getClientName() + " has to deposit amount greater than 10000 to open account.");
        return 1;
    }
}

int Bank::getAccountBalance(Client const &client, int accountNumber) {
    std::vector<BankAccounts>::iterator it;
    if(!this->gp2.fastAccessAccountant().get_role() == ACCNTS) {
        try {
            throw std::domain_error("Accountant retrieval error!"); 
            }
        catch(std::exception& e) {
            cout << e.what() << endl;
            return 1;
        }
        
    }
    else {
        for(it = this->bankAccounts.begin(); it != this->bankAccounts.end(); it++) {

            if((*it).accountHolderName == client.getClientName() && (*it).accountNumber == accountNumber) {
                cout << "!-----------Balance sheet------------!" << endl;
                cout << "Name: "  << (*it).accountHolderName << endl;
                cout << "Account number: " << (*it).accountNumber << endl;
                cout << "Balance: " << (*it).getAccountBalance() << endl;
                cout << "Loans: " << (*it).loanAmount << endl;
                cout << "Repayed: " << (*it).amountRepayed << endl;
                cout << "!------------------------------------!" << endl;
                return 0;
            }
        }

        try{
            throw std::runtime_error("Client not found in system: " + client.getClientName());
        }
        catch(std::exception& e) {
            cout << e.what() << endl;
            return 1;
        }

    }

}

bool Bank::closeAccount(Client &client, int accountNumber) {
    std::vector<BankAccounts>::iterator it;
    int positionCounter = 0;
    for(it = this->bankAccounts.begin(); it != this->bankAccounts.end(); it++) {
        if((*it).accountHolderName == client.getClientName() && (*it).accountNumber == accountNumber) {
            try {
                if((*it).accountNumber != accountNumber) {
                    throw std::invalid_argument("The account number is incorrect! " + std::to_string(accountNumber));
                }
                else {
                    if (siteManager.agreeToClose((*it).loanTaken())) {
                        this->bankAccounts.erase(this->bankAccounts.begin() + positionCounter);
                        if((*it).accountBalance >= 2000) {
                            ///Money given back if balance greater than 2000.
                            (*it).deductFromBalance(2000);
                            client.deductNetWorth(2000);
                        }
                        cout << client.getClientName() << "'s account has been closed." << endl;
                        return 0;
                    }
                    else {
                        //cout << client.getClientName() <<" has outstanding loans amounting to " << (*it).loanAmount << endl;
                        throw std::runtime_error(client.getClientName() + " has outstanding loans amounting to " + std::to_string((*it).loanAmount) + " account closure request has been turned down!");
                        return 1;
                    }
                }
            }
            catch (std::exception& e) {
                cout << e.what() << endl;
                return 1;
            }
        }
        else positionCounter++;
    }
    try {
        throw std::runtime_error("The requested account has not been found: " + client.getClientName() + ", account number " + std::to_string(accountNumber));
    }
    catch (std::exception& e) {
        cout << e.what() << endl;
        return 1;
    }
}

bool Bank::depositCash(Client &client, int accountNumber,  int amount) {

    if( this->gp2.fastAccessCashier().getThisRole() == CASHRS) {
        std::vector<BankAccounts>::iterator iter;
        for (iter = this->bankAccounts.begin(); iter != this->bankAccounts.end(); iter++) {
            if ((*iter).accountHolderName == client.getClientName() && (*iter).accountNumber == accountNumber) {
                    if(amount >= 10000) {
                            if(this->gp2.fastAccessAccountant().getThisRole() == ACCNTS) {
                                (*iter).setAccountBalance(amount);
                                client.addNetWorth(amount);
                                cout << "Amount " << amount << " has been deposited to the account." << endl;
                                return 0;
                            }
                            else {
                                try {
                                    throw std::domain_error("Accountant retrieval error");
                                }
                                catch (std::exception& e) {
                                    cout << e.what() << endl;
                                    return 1;
                                }
                            }
                    }
                    else {
                        (*iter).setAccountBalance(amount);
                        client.addNetWorth(amount);
                        cout << "Amount " << amount << " has been deposited to the account." << endl;
                        return 0;
                    }
            }
        }
    }
    else {

        try {
            throw std::domain_error("Cashier retrieval error");
        }
        catch(std::exception& e) {
            cout << e.what() << endl;
            return 1;
        }
    }
        try {
            throw std::invalid_argument("Operation failure!");
            
        }
        catch (std::exception& e) {
            cout << e.what() << endl;
            return 1;
        }
}

bool Bank::withdrawCash(Client &client, int accountNumber, int amount) {
    if(this->gp2.fastAccessCashier().getThisRole() == CASHRS) {
        std::vector<BankAccounts>::iterator iter;
        int positionCounter = 0;
        int foundPerson = 0;
        for (iter = this->bankAccounts.begin(); iter != this->bankAccounts.end(); iter++) {
            if ((*iter).accountHolderName == client.getClientName() && (*iter).accountNumber == accountNumber) {
                foundPerson = 1;
                if((*iter).getAccountBalance() >= amount) {
                    if(amount > 10000) {
                        if(this->gp2.fastAccessAccountant().get_role() == ACCNTS) {
                            //client.setNetWorth((*iter).getAccountBalance() + amount);
                            (*iter).deductFromBalance(amount);
                            cout << amount  << " has been deducted from the account of " << client.getClientName() << ", " << (*iter).accountNumber << endl;
                            return 0;
                        }
                    }
                    //client.setNetWorth((*iter).getAccountBalance() + amount);
                    (*iter).deductFromBalance(amount);
                    cout << amount  << " has been deducted from the account of " << client.getClientName() << ", " << (*iter).accountNumber << endl;
                    return 0;
                }
                else {
                    //cout << "Not enough funds in account to withdraw, Choose a smaller amount." << endl;
                    try {
                        throw std::domain_error("Not enough funds in account to withdraw, Choose a smaller amount.");
                    }
                    catch(std::exception& e) {
                        cout << e.what() << endl;
                        return 1;
                    }
                }

            }
        }
        if(!foundPerson) {
            try{
                throw std::invalid_argument("Client " + client.getClientName() + " not part of this bank!");
            }
            catch(std::exception& e){
                cout << e.what() << endl;
                return 1;
            }
        }
    }
    else {
        cout << "Cashier retrieval error!" << endl;
        return 1;
    }
    return 1;
}


bool Bank::transferMoney(Client &client1, int actn1, int amount, Client &client2, int actn2) {

    std::vector<BankAccounts>::iterator iter;
    if(this->gp2.fastAccessCashier().getThisRole() == CASHRS) {
        int foundClient1 = 0;
        for(iter = this->bankAccounts.begin(); iter != this->bankAccounts.end(); iter++) {
            if((*iter).accountHolderName == client1.getClientName() && (*iter).accountNumber == actn1) {
                //cout << "Found " << client1.getClientName() << endl;
                foundClient1 = 1;
                std::vector<BankAccounts>::iterator iter2;
                int foundClient2 = 0;
                int accountNumber = (*iter).accountNumber;
                for(iter2 = this->bankAccounts.begin(); iter2 != this->bankAccounts.end(); iter2++) {

                    if((*iter2).accountHolderName == client2.getClientName() && (*iter2).accountNumber == actn2) {

                        if((*iter2).accountNumber == accountNumber ) {
                            //cout << "Transferring amount between same accounts is not permitted." << endl;
                            try {
                                throw std::domain_error("Transferring amount between the same account is not permitted. You can try depositing.");
                            }
                            catch(std::exception& e) {
                                cout <<e.what() << endl;
                                return 1;
                            }

                        }
                        //cout << "Found " << client2.getClientName() << endl;
                        foundClient2 = 1;
                        if (amount >= 10000) {
                            if (this->gp2.fastAccessAccountant().get_role() == ACCNTS) {
                                if (amount <= (*iter).getAccountBalance()) {
                                    client1.deductNetWorth(amount);
                                    (*iter).deductFromBalance(amount);

                                    client2.addNetWorth(amount);
                                    (*iter2).setAccountBalance(amount);

                                    cout << "Inter bank transaction has been completed between " << client1.getClientName()
                                         << " and " << client2.getClientName() << " with the help of "
                                         << this->gp2.fastAccessAccountant().get_name() << endl;
                                    return 0;
                                }
                                else {
                                    //cout << "Not enough Funds!" << endl;
                                    try {
                                        throw std::domain_error("Not enough funds!");
                                    }
                                    catch (std::exception& e) {
                                        cout << e.what() << endl;
                                        return 1;
                                    }

                                }

                            }
                            else {
                                //cout << "Accountant retrieval error!" << endl;
                                try {
                                    throw std::domain_error("Accountant retrieval error.");
                                }
                                catch (std::exception& e) {
                                    cout << e.what() << endl;
                                    return 1;
                                }

                            }
                        }
                        else {
                                client1.deductNetWorth(amount);
                                (*iter).deductFromBalance(amount);
                                (*iter2).setAccountBalance(amount);
                                client2.addNetWorth(amount);
                                cout << "Transaction has been completed between " << client1.getClientName() << " and " << client2.getClientName() << endl;
                                return 0;
                            }
                    }
                }
                if(!foundClient2) {
                    //cout << "Client2 " << client2.getClientName() << " is not part of the bank " << this->getBankName() << endl;
                    try {
                        throw std::domain_error("Client 2 " + client2.getClientName() + " is not part of the bank " + this->getBankName());
                    }
                    catch (std::exception& e) {
                        cout << e.what() << endl;
                        return 1;
                    }

                }
            }
        }
        if(!foundClient1) {
            //cout << "Client1 " << client1.getClientName() << " is not part of the bank " << this->getBankName() << endl;
            try {
                throw std::domain_error("Client 1 " + client1.getClientName() + " is not part of the bank " + this->getBankName());
            }
            catch(std::exception& e) {
                cout << e.what() << endl;
                return 1;
            }

        }
    }
    return false;
}

bool Bank::crossBankTransfer(Client& sender, int actn1, int amount,  Client& recipient,int actn2, Bank& recipientBank) {
    if(this->gp2.fastAccessCashier().getThisRole() == CASHRS) {
        std::vector<BankAccounts> :: iterator iter;
        int foundSender = 0;
        for(iter = this->bankAccounts.begin(); iter != this->bankAccounts.end(); iter++) {
            std::vector<BankAccounts>::iterator iter2;
            int foundRecipient=0;

            if((*iter).accountHolderName == sender.getClientName() && (*iter).accountNumber == actn1) {
                foundSender = 1;
                for(iter2 = recipientBank.bankAccounts.begin(); iter2!= recipientBank.bankAccounts.end(); iter2++) {
                    if(amount <= (*iter).getAccountBalance()) {

                        if(this->gp2.fastAccessAccountant().getThisRole() == ACCNTS && recipientBank.gp2.fastAccessAccountant().getThisRole() == ACCNTS) {
                            if((*iter2).accountHolderName == recipient.getClientName() && (*iter2).accountNumber == actn2) {
                                foundRecipient = 1;
                                cout << "Both clients have been found!" << endl;
                                sender.deductNetWorth(amount);
                                (*iter).deductFromBalance(amount);

                                (*iter2).setAccountBalance(amount);
                                recipient.addNetWorth(amount);
                                cout << "Transaction has been complete between " << (*iter2).accountHolderName << " & " << sender.getClientName() << " of bank " << recipientBank.getBankName() << " & " << this->getBankName()  << endl;
                                return 0;
                            }
                        }
                        else {
                            //cout << "Accountant retrieval error!" << endl;
                            try {
                                throw std::domain_error("Amount retrieval error.");
                            }
                            catch (std::exception& e) {
                                cout << e.what() << endl;
                                return 1;
                            }
                        }
                    }
                    else {
                        //cout << "No sufficient funds to complete transaction." << endl;
                        try {
                            throw std::domain_error("No sufficient funds to complete transaction.");
                        }
                        catch (std::exception& e) {
                            cout << e.what() << endl;
                            return 1;
                        }
                    }

                }
            }

            if(!foundRecipient) {
                //cout << "Recipient account does not exist!" << endl;
                try {
                    throw std::invalid_argument("Recipient account does not exist.");
                }
                catch (std::exception& e) {
                    cout << e.what() << endl;
                    return 1;
                }
            }
        }
        if(!foundSender) {
            //cout << "Senders account does not exist!" << endl;
            try {
                throw std::invalid_argument("Senders account does not exist");
            }
            catch (std::exception& e) {
                cout << e.what() << endl;
                return 1;
            }
        }
    }
    else {
        //cout << "Cashier retrieval error." << endl;
        try {
            throw std::invalid_argument("Cashier retrieval error.");
        }
        catch(std::exception& e){
            cout << e.what() << endl;
            return 1;
        }

    }
    cout << "Operation failure!" << endl;
    return 1;
}


bool Bank::requestForLoan(Client &client, int accountNumber, int amount) {
    std::vector<BankAccounts>::iterator iter;
    int foundClient = 0;
    for(iter = this->bankAccounts.begin(); iter != this->bankAccounts.end(); iter++) {

        if((*iter).accountHolderName == client.getClientName() && (*iter).accountNumber == accountNumber) {
            if((*iter).hasLoan) {
                cout << "This client has a loan of " << (*iter).loanAmount << endl;
                if((*iter).amountRepayed >= (0.6)*(*iter).loanAmount) {
                    cout << "Amount repaid(" << (*iter).amountRepayed << "), greater than 0.6 times the loan amount of " << (*iter).loanAmount << " equalling " << (*iter).loanAmount * 0.6 << endl;
                    if(this->gp2.getManager().agreeForLoan(client, amount)) {
                        (*iter).hasLoan = true;
                        (*iter).loanAmount = (*iter).loanAmount + amount;

                        (*iter).setAccountBalance(amount);
                        client.addNetWorth(amount);
                        return 0;
                    }
                    else {

                        try {
                            throw invalid_argument("Manager has not agreed to grant the loan, since the loan amount is not less than 0.25 * net worth of the client.");
                        }
                        catch (std::exception& e){
                            cout << e.what() << endl;
                            return 1;
                        }
                    }
                }else {
                    //cout << "Previous loan amount of " << (*iter).loanAmount << " has not been paid, or atleast 0.6 times the loan amount has not been re-paid, loan shall not be granted." << endl;
                    try {
                        throw std::domain_error("Previous loan amount of " + std::to_string((*iter).loanAmount) + " has not been paid, or atleast 0.6 * the loans amount has not been re-paid.");
                    }
                    catch (std::exception& e){
                        cout << e.what() << endl;
                        return 1;
                    }

                }
            }
            else {
                if(this->gp2.getManager().agreeForLoan(client, amount)) {
                    (*iter).hasLoan = true;
                    (*iter).loanAmount  = (*iter).loanAmount +  amount;

                    (*iter).setAccountBalance(amount);
                    client.addNetWorth(amount);
                    return 0;
                }
                else {
                     try {
                         throw std::invalid_argument("Manager has not agreed to grant the loan, since the loan amount is not less than 0.25 * net worth of the client.");
                     }
                     catch (std::exception& e) {
                         cout << e.what() << endl;
                         return 1;
                     }

                }
            }

            foundClient = 1;
        }
    }
    if(!foundClient) {
        //cout << "Client not part of this bank." << endl;
        try {
            throw std::domain_error("Client not part of this bank.");
        }
        catch(std::exception& e) {
            cout << e.what() << endl;
            return 1;
        }
    }
    else
        return 0;
}


bool Bank::repayLoan(Client &client, int acctn,  int amount ) {
    std::vector<BankAccounts>::iterator iter;
    int foundClient = 0;
    for(iter = this->bankAccounts.begin(); iter != this->bankAccounts.end(); iter++ ){
        if((*iter).accountHolderName == client.getClientName() && (*iter).accountNumber == acctn) {
            foundClient = 1;
            cout << "Client found." << endl;
            (*iter).amountRepayed += amount;
            cout << "Client re-paid " << amount << " off the loan of " << (*iter).loanAmount << endl;
            if((*iter).amountRepayed >= 0.6 * (*iter).loanAmount) {
                cout << "Client " << client.getClientName() << " is elligible for another loan." << endl;
                (*iter).hasLoan = false;
                return 0;
            }
            else {
                //cout << "Client " << client.getClientName() << " is not elligible for another loan." << endl;
                try {
                    throw std::invalid_argument ("Client " + client.getClientName() + " is not YET elligible for another loan.");
                }
                catch(std::exception& e) {
                    cout << e.what() << endl;
                }
                return 1;
            }
        }
    }
    if(!foundClient) {
        //cout << "Client not part of this bank." << endl;
        try {
            throw std::invalid_argument("Client not part of this bank.");
        }
        catch(std::exception& e) {
            cout << e.what() << endl;
            return 1;
        }

    }
    return 1;
}

void Bank::printEmployeeInformation()  {
    cout << "!------------ " <<  this->getBankName() << " ---------------!" << endl;
    try {
       if(!this->gp1.hasCeoNot() && !this->gp1.hasPresidentNot()) {
           throw std::invalid_argument("CEO and President are not added to this bank: " + this->getBankName() );
       }
       else {
           if(this->gp1.printListSeniorPartner()) {
               ///cout << "No memebers have been added to bank: " << this->getBankName() << endl;
               throw std::invalid_argument("No members have been added to this bank: " + this->getBankName());
           }
       }

       if(this->gp2.printGroupInformation()){
               throw std::invalid_argument("No junior employees have been added to this bank: " + this->getBankName());
            }
       }

    catch(std::exception& e) {
       cout << e.what() << endl;
    }
}


void Bank::printClientInformation() {
    try {
        if(this->bankAccounts.empty()) {
            throw std::invalid_argument("There are no clients in this bank " + this->getBankName());
        }
    }
    catch (std::exception& e) {
        cout << e.what() << endl;
    }

    std::vector<BankAccounts>::iterator iter;
    for(iter = this->bankAccounts.begin(); iter != this->bankAccounts.end(); iter++) {
        cout <<"!----------------Client Information: " << this->getBankName() <<" ----------------!" << endl;
        cout << "Name: " << (*iter).accountHolderName << endl;
        cout << "Account No: " << (*iter).accountNumber << endl;
        cout << "BankBalance: " << (*iter).getAccountBalance() << endl;
        if ((*iter).loanTaken()) {
            cout << "Loan: Has Loan to Clear!" << endl;
            cout << "Loan Amount: " << (*iter).loanAmount << endl;
            cout << "Amount repaid: " << (*iter).amountRepayed << endl;
        }else {
            cout << "Loan: Doesn't have a loan to clear!" << endl;
        }
        cout <<"!--------------------------------------------------!" << endl;
    }
}

#endif //BANKINGPROJECT_BANK_H
