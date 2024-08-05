#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <windows.h>

using namespace std;

class BankSystem {
private:
    string name;
    string email;
    double balance;
    mutable vector<string> transactions;
    string pin;

    void displayLogoOnce() {
        static bool logoDisplayed = false;
        if (!logoDisplayed) {
            ifstream logoFile("C:\\Users\\mriga\\OneDrive\\Desktop\\Stuff\\QT_Integrated_Terminal_Suite\\PayBuddy\\transctionhead.txt");
            string line;

            if (logoFile.is_open()) {
                while (getline(logoFile, line)) {
                    cout << line << endl;
                }
                logoFile.close();
                logoDisplayed = true;
            } else {
                cerr << "Error opening logo file!" << endl;
            }
            cout << "Press Enter to continue...";
            cin.get();
            system("cls");
        }
    }

    void displayUserInfo() const {
        cout << " __________________________________________________" << endl;
        cout << "|                                                   |" << endl;
        cout << "| USER: " << name << "                                    |" << endl;
        cout << "| EMAIL: " << email << "                       |" << endl;
        cout << "|___________________________________________________|" << endl;
        cout << "|                                                   |" << endl;
        cout << "| Bank Balance: $" << balance << "                               |" << endl;
        cout << "|___________________________________________________|";
    }

    void displayLastTransactions() const {
        cout << "|                                                   |" << endl;
        cout << "|                    Last Transactions:             |" << endl;
        cout << "|___________________________________________________|" << endl;
        for (const auto& transaction : transactions) {
            cout << "| " << transaction << endl;
        }
        cout << "|___________________________________________________|";
    }

    void playBeepLoop(int frequency, int duration, int repetitions) const {
        for (int i = 0; i < repetitions; ++i) {
            Beep(frequency, duration);
            Sleep(duration);
        }
    }

    void playMelody() const {
        int notes[] = { 494, 523};
        int durations[] = { 500, 500};
        int numNotes = sizeof(notes) / sizeof(notes[0]);

        for (int i = 0; i < numNotes; ++i) {
            Beep(notes[i], durations[i]);
            Sleep(50);
        }
    }

public:
    BankSystem(const string& name, const string& email, double balance, const string& pin)
        : name(name), email(email), balance(balance), pin(pin) {}

    void makePaymentToMerchant(double amount, const string& merchant) {
        cout << "Enter your PIN to authorize the payment: ";
        string enteredPin;
        cin >> enteredPin;

        if (enteredPin == pin) {
            if (balance >= amount) {
                balance -= amount;
                time_t currentTime = time(nullptr);
                string transaction = "Paid $" + to_string(amount) + " to " + merchant + " on " + asctime(localtime(&currentTime));
                transactions.push_back(transaction);
                cout << "Payment successful!" << endl;
                playBeepLoop(1000, 500, 3);
                playMelody();
            } else {
                cout << "Insufficient balance!" << endl;
                Beep(500, 1000);
            }
        } else {
            cout << "Incorrect PIN! Payment authorization failed." << endl;
        }
    }

    void displayMenu() {
        char choice;
        string merchantName;
        do {
            if (transactions.empty()) {
                system("cls");
            }
            displayLogoOnce();
            cout << endl;
            displayUserInfo();
            cout << endl;
            displayLastTransactions();
            cout << endl;
            cout << " _________________________________________________" << endl;
            cout << "|                                                 |" << endl;
            cout << "|                     MENU                        |" << endl;
            cout << "|_________________________________________________|" << endl;
            cout << "|                                                 |" << endl;
            cout << "| 1. Make Payment to Merchant                     |" << endl;
            cout << "| 2. Exit                                         |" << endl;
            cout << "|_________________________________________________|" << endl;
            cout << " Enter your choice: ";
            cin >> choice;
            switch(choice) {
                case '1':
                    cout << endl;
                    double paymentAmount;
                    cout << "Enter merchant name: ";
                    cin.ignore();
                    getline(cin, merchantName);
                    cout << "Enter payment amount: $";
                    cin >> paymentAmount;
                    makePaymentToMerchant(paymentAmount, merchantName);
                    break;
                case '2':
                    cout << "Exiting..." << endl;
                    break;
                default:
                    cout << "Invalid choice! Please enter a valid option." << endl;
            }
            cout << endl << "Press Enter to continue...";
            cin.ignore();
            cin.get();
            system("cls");
        } while (choice != '2');
    }
};

int main() {
    BankSystem bankSystem("John Doe", "john.doe@example.com", 9000.0, "1234");
    bankSystem.displayMenu();

    return 0;
}
