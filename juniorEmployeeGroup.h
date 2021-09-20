#include "people.h"
#include "enumerations.h"
#include "juniorPartnerEmployees.h"
#include "manager.h"
#include "accountant.h"
#include "cashier.h"
#include <string.h>
#include <iostream>

#ifndef BANKINGPROJECT_JUNIOREMPLOYEEGROUP_H
#define BANKINGPROJECT_JUNIOREMPLOYEEGROUP_H

class juniorEmployeeGroup: public Groups {
public:
    juniorEmployeeGroup();
    juniorEmployeeGroup(string group_name);
    ~juniorEmployeeGroup() { }

    bool addManager(Manager& manager);
    bool addAccountant(Accountant& accountant);
    bool addCashier(Cashier& cashier);


    bool removeManager();
    bool removeAccountant(int bankerId);
    bool removeCashier(int bankerId);

    Manager& getManager();
    Accountant& getAccountant(int id);
    Cashier& getCashier(int juniorBankerId);
    Cashier& fastAccessCashier();
    Accountant& fastAccessAccountant();
    bool hasManagerNot() const {
        return this->hasManager;
    }

    bool printGroupInformation();

    void setManagerHireState(bool state);
    int getCashierCount() const;
    int getAccountantCount() const;
private:
    std::vector<juniorPartnerEmployee> junior_holder;
    std::vector<Accountant> accountant_holder;
    std::vector<Cashier> cashier_holder;
    std::vector<Manager> manager_holder;
    bool   hasManager       = false;
    int    accountantCount  = 0;
    int    cashierCount     = 0;

};

juniorEmployeeGroup::juniorEmployeeGroup() {
    this->groupName = "";
    this->hasManager  = false;
    this->accountantCount = 0;
    this->cashierCount = 0;
}

juniorEmployeeGroup::juniorEmployeeGroup(string group_name) {
    this->groupName = (group_name);
    this->hasManager = false;
    this->accountantCount = 0;
    this->cashierCount = 0;
}

int juniorEmployeeGroup::getCashierCount() const {
    return this->cashierCount;
}

int juniorEmployeeGroup::getAccountantCount() const {
    return this->accountantCount;
}

bool juniorEmployeeGroup::addManager(Manager &manager) {
    if(!manager.getHasBeenHired()){
        if(!this->hasManager){
            //this->junior_holder.push_back(manager);
            this->manager_holder.push_back(manager);
            this->setManagerHireState(true);
            manager.setHasBeenHired(true);
            manager.setHiredGroup(this->getGroupName());
            cout << "Manager " << manager.get_name() << " has been added to this group, " << this->groupName << endl;
            return 0;
        }
        else {
            cout << "Manager " << this->getManager().get_name() << " is already hired in this group, " << this->getGroupName() << endl;
            return 1;
        }
    }
    else {
        //cout << "Manager " << manager.get_name() << " has already been added to another banking group,  " << manager.getHiredGroup() << endl;
        return 1;
    }
}

bool juniorEmployeeGroup::addAccountant(Accountant  &accountant) {
    if(!accountant.getHasBeenHired()) {
        this->junior_holder.push_back(accountant);
        this->accountant_holder.push_back(accountant);
        this->accountantCount++;
        accountant.setHasBeenHired(true);
        accountant.setHiredGroup(this->getGroupName());
        cout << "Accountant " << accountant.get_name() << " has been added to this group, " << this->getGroupName() << endl;
        return 0;
    }
    else {

        if(accountant.getHiredGroup() == this->groupName) {
            throw std::invalid_argument("Accountant " + accountant.get_name() + " has already been hired to this group " + this->groupName);
        }
        else {
            throw std::invalid_argument("Accountant " + accountant.get_name() + " has already been hired to another group " + this->groupName);
        }
        return 1;
    }

}

bool juniorEmployeeGroup::addCashier(Cashier &cashier) {
    if(!cashier.getHasBeenHired()) {
        this->junior_holder.push_back(cashier);
        this->cashier_holder.push_back(cashier);
        this->cashierCount++;
        cashier.setHiredGroup(this->groupName);
        cashier.setHasBeenHired(true);
        cout <<"Cashier " << cashier.get_name() << " has been hired to this group, "<< this->getGroupName() << endl;
        return 0;
    }
    else {
        //cout << "Cashier " << cashier.get_name() << " has already been hired to another group, " << cashier.getHiredGroup() << endl;
        if (cashier.getHiredGroup() == this->groupName) {
            try {
                throw std::invalid_argument("Cashier " + cashier.get_name() + " has already been hired to this group " + cashier.getHiredGroup());
            }
            catch (std::exception& e) {
                cout << e.what() << endl;
                return 1;
            }

        }
        else {
            throw std::invalid_argument("Cashier " + cashier.get_name() + " has already been hired to another group " + cashier.getHiredGroup());
            return 1;
        }

    }
    return false;
}

bool juniorEmployeeGroup::removeManager() {
    int positionCounter = 0;
    if(this->hasManagerNot()) {
        this->manager_holder.pop_back();
        this->hasManager = false;
        return 0;
    }
    //cout << "Manager not found in group " << this->getGroupName() << " to be removed." << endl;
    throw std::invalid_argument("Manager not found in group " + this->getGroupName() + " to be removed.");
    return 1;
}


bool juniorEmployeeGroup::removeAccountant(int bankerId) {
    std::vector<juniorPartnerEmployee>::iterator it;
    int positionCounter = 0;
    for(it = this->junior_holder.begin(); it != this->junior_holder.end(); it++) {
        if(bankerId == (*it).getBankerId()) {
            this->junior_holder.erase(this->junior_holder.begin() + positionCounter);
            this->accountant_holder.erase(this->accountant_holder.begin() + positionCounter);
            this->accountantCount--;
            (*it).setHiredGroup("not hired");
            cout <<"Accountant " << (*it).get_name() << " has been fired from the group " << this->getGroupName() << endl;
            return 0;
        }
        else
            positionCounter++;
    }
    //cout << "Accountant with banked id " << bankerId << " has not beed found in this group "  << this->getGroupName() << endl;
    return 1;
}

bool juniorEmployeeGroup::removeCashier(int bankerId) {
    std::vector<juniorPartnerEmployee>::iterator it;
    int positionCounter = 0;
    for(it = this->junior_holder.begin(); it != this->junior_holder.end(); it++) {
        if(bankerId == (*it).getBankerId()) {
            this->junior_holder.erase(this->junior_holder.begin() + positionCounter);
            this->cashier_holder.erase(this->cashier_holder.begin() + positionCounter);
            this->cashierCount--;
            (*it).setHiredGroup("Not hired");
            cout << "Cashier " << (*it).get_name() << " has been fired!" << endl;
            return 0;
        }
        else
            positionCounter++;
    }
    //cout << "Cashier with banker id: " << bankerId <<" has not been found in the records." << endl;
    return 1;
}


Manager& juniorEmployeeGroup::getManager() {

    return this->manager_holder.front();
}

Accountant& juniorEmployeeGroup::getAccountant(int id){
    std::vector<Accountant>:: iterator it;
    int positionCounter = 0;
    for(it = this->accountant_holder.begin(); it != this->accountant_holder.end(); it++) {
        if((*it).getBankerId() == id) {
            cout << "Accountant " << (*it).get_name() << " returned." << endl;
            return (*it);
        }
        else
            positionCounter++;
    }
    //cout << "Couldn't find accountant with id " << id << endl;
    Accountant *jp1;
    return *jp1;
}



Cashier& juniorEmployeeGroup::getCashier(int juniorBankerId){
    std::vector<Cashier>::iterator it;
    int positionCounter = 0;
    for(it = this->cashier_holder.begin(); it != this->cashier_holder.end(); it++) {
        if(juniorBankerId == (*it).getBankerId()) {
            cout << "Cashier " << (*it).get_name() << " returned." << endl;
            return (*it);
        }
        else
            positionCounter++;
    }
    //cout << "Cashier with id " << juniorBankerId << " does not exist." << endl;
    Cashier *jp1;
    return *jp1;
}

void juniorEmployeeGroup::setManagerHireState(bool state) {
    this->hasManager = state;
}

Cashier& juniorEmployeeGroup::fastAccessCashier() {
    if (this->cashier_holder.size() == 0){
        Cashier *cashier;
        return *cashier;
    } else return this->cashier_holder.front();
}

Accountant& juniorEmployeeGroup::fastAccessAccountant() {
    if(this->accountant_holder.size() == 0) {
        Accountant* acctn;
        return *acctn;
    }
    else return this->accountant_holder.front();
}

bool juniorEmployeeGroup::printGroupInformation() {

    std::vector<juniorPartnerEmployee>:: const_iterator iter;
    std::vector<Cashier>:: const_iterator iter2;
    std::vector<Accountant>::const_iterator iter3;
    if(cashier_holder.empty() && accountant_holder.empty() && manager_holder.empty()) {
        return 1;
    }
    else {
        cout << "!----------------Junior Employees---------------!" << endl;
        if(!this->manager_holder.empty()) {
            cout << "!-------------Manager-------------!" << endl;
            cout << "Manager Name: " << this->getManager().get_name() << endl;
            cout << "Manager Last name: " << this->getManager().get_lastName() << endl;
            cout << "Banker ID: " << this->getManager().getBankerId() << endl;
            cout << "Role: Manager" << endl;
            cout << "Junior Banker ID: " << this->getManager().getJuniorEmployeeId() << endl;
            cout <<"!----------------------------------!" << endl;
        }
        else {
            cout << "No Manager in group!" << endl;
        }

        if(!this->cashier_holder.empty()) {
            for(iter2 = this->cashier_holder.begin(); iter2 != cashier_holder.end(); iter2++) {
                cout << "Name: " << (*iter2).get_name() << endl;
                cout << "Last Name: " << (*iter2).get_lastName() << endl;
                cout << "Banker ID: " << (*iter2).getBankerId() << endl;
                cout << "Junior ID: "  << (*iter2).getJuniorEmployeeId() << endl;
                cout << "Position: Cashier" << endl;
            }
            cout <<"!----------------------------------!" << endl;
        }
        else {
            cout << "No cashier in group!" << endl;
        }


        if(!this->accountant_holder.empty()) {
            for(iter3 = this->accountant_holder.begin(); iter3 != this->accountant_holder.end(); iter3++) {
                cout << "Name: " << (*iter3).get_name() << endl;
                cout << "Last name: " << (*iter3).get_lastName() << endl;
                cout << "Banker ID: " << (*iter3).getBankerId() << endl;
                cout << "Junior ID: " << (*iter3).getJuniorEmployeeId() << endl;
                cout << "Position: Accountant" << endl;

            }
        }
        else {
            cout << "No acocuntant in this group!" << endl;
        }
        return 0;
    }

}


#endif //BANKINGPROJECT_JUNIOREMPLOYEEGROUP_H
