#include<iostream>
#include<string>
using namespace std;
class PasswordChecker{
    private:
    string password;
    bool hasUpper, hasLower,hasDigit, hasSpecial;
    int length;
    public:
    void inputPassword() {
        cout << "Enter a password to check: ";
        getline(cin, password);
        analyzePassword();
    }

    void analyzePassword() {
        hasUpper = hasLower = hasDigit = hasSpecial = false;
        length = password.length();

        for (char ch : password) {
            if (isupper(ch)) hasUpper = true;
            else if (islower(ch)) hasLower = true;
            else if (isdigit(ch)) hasDigit = true;
            else hasSpecial = true;
        }
    }

    void displayStrength() {
        cout << "\n Analysis:\n";
        cout << " Length: " << length << endl;
        cout << " Uppercase: " << (hasUpper ? "Yes" : "No") << endl;
        cout << " Lowercase: " << (hasLower ? "Yes" : "No") << endl;
        cout << " Digits: " << (hasDigit ? "Yes" : "No") << endl;
        cout << " Special Characters: " << (hasSpecial ? "Yes" : "No") << endl;

        cout << "\n Password Strength: ";
        if (length >= 8 && hasUpper && hasLower && hasDigit && hasSpecial)
            cout << "STRONG \n";
        else if (length >= 6 && ((hasUpper && hasLower) || (hasDigit && hasSpecial)))
            cout << "MEDIUM \n";
        else
            cout << "WEAK \n";
            suggestPassword();
    }
    void suggestPassword(){
        cout<<"\n Password Tip:\n";
        cout<<"Use atleast 8 characters\n";
        cout<<"Include uppercase and lowercase letters\n";
        cout<<"Add digits (0-9)\n";
        cout<<"Use special characters like @,!,# etc.\n";
        cout<<"\n Example Strong Password:Ab@1515ef\n";
    }
};

int main() {
    PasswordChecker checker;
    char choice;

    do {
        checker.inputPassword();
        checker.displayStrength();

        cout << "\nDo you want to check another password? (y/n): ";
        cin >> choice;
        cin.ignore(); 
    } while (tolower(choice) == 'y');

    cout << "\nThank you for using Password Strength Checker!\n";
    return 0;
}