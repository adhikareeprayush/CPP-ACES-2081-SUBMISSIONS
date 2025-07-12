#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class Bank {
    int accNumber;
    char name[50];
    char type;
    double balance;

public:
    void createAccount() {
        cout << "\nEnter Account Number: ";
        cin >> accNumber;
        cout << "Enter Account Holder Name: ";
        cin.ignore();
        cin.getline(name, 50);
        cout << "Enter Account Type (S for Savings / C for Current): ";
        cin >> type;
        cout << "Enter Initial Deposit Amount: ";
        cin >> balance;
        cout << "\nAccount Created Successfully!\n";
    }

    void showAccount() const {
        cout << "\nAccount No.: " << accNumber;
        cout << "\nName: " << name;
        cout << "\nType: " << (type == 'S' || type == 's' ? "Savings" : "Current");
        cout << "\nBalance: $" << fixed << setprecision(2) << balance << endl;
    }

    void deposit(double amt) {
        balance += amt;
    }

    bool withdraw(double amt) {
        if (amt > balance) {
            cout << "\nInsufficient Balance!\n";
            return false;
        }
        balance -= amt;
        return true;
    }

    int getAccNo() const {
        return accNumber;
    }

    void report() const {
        cout << setw(10) << accNumber << setw(20) << name
             << setw(10) << type << setw(10) << balance << endl;
    }
};

void writeAccount() {
    Bank ac;
    ofstream outFile("accounts.dat", ios::binary | ios::app);
    ac.createAccount();
    outFile.write(reinterpret_cast<char*>(&ac), sizeof(Bank));
    outFile.close();
}

void displayAccount(int num) {
    Bank ac;
    ifstream inFile("accounts.dat", ios::binary);
    bool found = false;

    while (inFile.read(reinterpret_cast<char*>(&ac), sizeof(Bank))) {
        if (ac.getAccNo() == num) {
            ac.showAccount();
            found = true;
        }
    }
    inFile.close();
    if (!found) cout << "\nAccount not found.\n";
}

void depositWithdraw(int num, int option) {
    Bank ac;
    fstream File("accounts.dat", ios::binary | ios::in | ios::out);
    bool found = false;

    while (!File.eof() && !found) {
        int pos = File.tellg();
        File.read(reinterpret_cast<char*>(&ac), sizeof(Bank));
        if (ac.getAccNo() == num) {
            ac.showAccount();
            double amt;
            cout << "\nEnter Amount: ";
            cin >> amt;
            if (option == 1)
                ac.deposit(amt);
            else if (!ac.withdraw(amt))
                return;

            File.seekp(pos);
            File.write(reinterpret_cast<char*>(&ac), sizeof(Bank));
            cout << "\nTransaction Successful.\n";
            found = true;
        }
    }
    File.close();
    if (!found) cout << "\nAccount not found.\n";
}

void displayAll() {
    Bank ac;
    ifstream inFile("accounts.dat", ios::binary);
    cout << "\n\n\t\tACCOUNT HOLDER LIST\n\n";
    cout << "====================================================\n";
    cout << "Acc No.      Name             Type     Balance\n";
    cout << "====================================================\n";

    while (inFile.read(reinterpret_cast<char*>(&ac), sizeof(Bank))) {
        ac.report();
    }
    inFile.close();
}

int main() {
    int choice;
    int accNo;

    do {
        cout << "\n\n*** BANK MANAGEMENT SYSTEM ***\n";
        cout << "1. Create Account\n";
        cout << "2. View Account\n";
        cout << "3. Deposit Money\n";
        cout << "4. Withdraw Money\n";
        cout << "5. View All Accounts\n";
        cout << "6. Exit\n";
        cout << "Select option (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1:
                writeAccount();
                break;
            case 2:
                cout << "Enter Account Number: ";
                cin >> accNo;
                displayAccount(accNo);
                break;
            case 3:
                cout << "Enter Account Number: ";
                cin >> accNo;
                depositWithdraw(accNo, 1);
                break;
            case 4:
                cout << "Enter Account Number: ";
                cin >> accNo;
                depositWithdraw(accNo, 2);
                break;
            case 5:
                displayAll();
                break;
            case 6:
                cout << "Thank you for using our system!\n";
                break;
            default:
                cout << "Invalid option! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
