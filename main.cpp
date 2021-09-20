#include <iostream>
#include <string.h>
#include "people.h"
#include "cashier.h"
#include "accountant.h"
#include "manager.h"
#include "ceo.h"
#include "president.h"
#include "groups.h"
#include "seniorPartnerGroup.h"
#include "juniorPartnerEmployees.h"
#include "juniorEmployeeGroup.h"
#include "bank.h"




int main() {

    cout << "Testing!" << endl;
    int choice = 0;
    cout << "1. Printing employee information." << endl;
    cout << "2. Firing of employees and re-hiring them." << endl;
    cout << "3. Opening and closing of bank accounts." << endl;
    cout << "4. Withdrawing and depositing cash." << endl;
    cout << "5. Conducting inter and outer bank transactions." << endl;
    cout << "6. Requesting loans, repayment and account closure." << endl;
    cout << "Enter choice: ";
    cin >> choice;
    if (choice > 6 || choice < 1) {
        cout << "Choice not in valid range." << endl;
        return 1;
    }
    cout << "Testing case: " << choice << endl;
    Bank bank1("HSBC");
    Bank bank2("QB");

    Ceo ceo1("chriss", "pratt", 24);
    Ceo ceo2("Harry", "Styles", 25);

    President pr1("Tim", "Cook", 25);
    President pr2("Jim", "Dawn", 26);

    Manager m1("Manu", "ferris", 28);
    Manager m2("Kim", "Player", 29);

    Cashier csh1("Artur", "Godw", 27);
    Cashier csh2("Lloyd", "Punj", 29);

    Accountant actn1("Mike", "keaton", 26);
    Accountant actn2("Panther", "Pink", 30);

    bank1.addCeoToBank(ceo1);
    //bank2.addCeoToBank(ceo1);
    bank1.addManagerToBank(m1);
    bank1.addPresidentToBank(pr1);
    bank1.addAccountantToBank(actn1);


    bank1.addCashierToBank(csh1);
    bank2.addCashierToBank(csh1);
    bank2.addAccountantToBank(actn2);

    Client client1("Ninja");
    Client client2("Lee");

    switch (choice) {
        case 1: {

            bank2.printEmployeeInformation();
            bank1.printEmployeeInformation();
            break;
        }
        case 2: {
            cout << "Before deletion!" << endl;
            bank1.printEmployeeInformation();

           	//bank1.removeCeo(ceo1);
          	//bank1.removePresident(pr1);
             bank1.removeManager(m1);
             bank1.removeManager(m1);
          	//bank1.fireCashier(csh1);
            //bank1.fireAccountant(actn1);
            cout << "After deletion!" << endl;
            bank1.printEmployeeInformation();
            break;
        }

        case 3: {
            bank1.openAccount(client1, 5555, 20000);
            //bank1.openAccount(client1, 5555, 15000);
            //bank1.openAccount(client1, 6464, 15000);
           // bank2.openAccount(client1, 6464, 10000);
           // bank1.openAccount(client2, 4545, 12000);
            bank1.printClientInformation();
           // bank2.printClientInformation();

           // bank1.closeAccount(client1,5555);
            bank1.closeAccount(client1, 5555);
           // bank1.printClientInformation();
            break;
        }
        case 4: {
            bank1.openAccount(client1, 5555, 15000);
            //bank1.openAccount(client1, 6969, 18000);
            //bank1.depositCash(client1, 5555, 12000);
            bank1.depositCash(client1, 5555, 2000);
           // bank1.getAccountBalance(client1, 5555 );
            //bank1.getAccountBalance(client1, 6969);

           bank1.withdrawCash(client1, 5555, 100);
           bank1.getAccountBalance(client1, 5555);
            break;
        }
        case 5: {
            cout << "!-------Inter Bank transfer simulation---------!" << endl;
             //bank1.openAccount(client1, 4646, 12000);
            // bank1.openAccount(client1, 4646, 12000);

              bank1.openAccount(client1, 5454, 15000);
              bank2.openAccount(client2, 4545, 15000);

           // bank1.getAccountBalance(client2, 6565);
           // bank1.getAccountBalance(client1, 4646);
            // bank1.transferMoney(client1, 4646, 2000, client1, 4646);
            //bank1.getAccountBalance(client1, 4646);
           // bank1.getAccountBalance(client1, 4646);
            cout << "!------------------------------------------------" << endl;
            cout << "!-------Cross Bank transfer simulation---------!" << endl;
           // bank2.getAccountBalance(client2, 4545);
           	bank1.crossBankTransfer(client1, 5454, 3000, client2, 4545, bank2);
            bank2.getAccountBalance(client2, 4545);
		    bank1.getAccountBalance(client1, 5454);
            cout << "!----------------------------------------------!" << endl;
        break;
        }
        case 6: {
            cout << "!---------Loan request simulation-----------!" << endl;
            bank1.openAccount(client1, 4545, 12000);
            bank1.requestForLoan(client1, 4545, 25000);
           	//bank1.repayLoan(client1, 4545, 15000);
           //	bank1.requestForLoan(client1, 4545, 25000);

            //bank1.closeAccount(client1, 4545);
           // bank1.repayLoan(client1, 4545, 10000);

              bank1.getAccountBalance(client1, 4545);
          //  bank1.requestForLoan(client1, 4545, 2500);
            	bank1.repayLoan(client1, 4545, 25000);
              bank1.closeAccount(client1, 4545);
            bank1.printClientInformation();
            cout <<"!--------------------------------------------!" << endl;
            break;
        }


    }

}
