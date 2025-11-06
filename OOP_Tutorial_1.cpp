#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class bank_customer
{
public:
    string name;
    string account_type;
    int account_number;
    int available_amount;

    bank_customer(string n, string t, int i)
    {
        name = n;
        account_type = t;
        account_number = i;

        available_amount = rand() % 9001 + 1000;
    }

    void deposit(int amount)
    {
        available_amount += amount;
        cout << "$" << amount << " deposited successfully." << endl;
    }

    void withdraw(int amount)
    {
        if (amount <= available_amount)
        {
            available_amount -= amount;
            cout << "$" << amount << " withdrawn successfully." << endl;
        }
        else
        {
            cout << "Insufficient balance!" << endl;
        }
    }

    void display()
    {
        cout << "\nCustomer Details:\n";
        cout << "Name: " << name << endl;
        cout << "Account Type: " << account_type << endl;
        cout << "Account Number: " << account_number << endl;
        cout << "Available Balance: $" << available_amount << endl;
    }
};

int main()
{
    srand(time(0)); // Use to generate a random number between 1000 to 10000

    string name, account_type;
    int account_number;
    int choice, amount;

    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Enter your account number: ";
    cin >> account_number;

    cin.ignore();

    cout << "Enter your account type: ";
    getline(cin, account_type);

    bank_customer customer(name, account_type, account_number);

    int option;
    do
    {
        cout << "\n--- Bank Menu ---" << endl;
        cout << "1. Display Account Details" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> option;

        switch (option)
        {
        case 1:
            customer.display();
            break;
        case 2:
            cout << "Enter amount to deposit: ";
            cin >> amount;
            customer.deposit(amount);
            break;
        case 3:
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            customer.withdraw(amount);
            break;
        case 4:
            cout << "Exiting... Thank you!" << endl;
            break;
        default:
            cout << "Invalid choice. Try again!" << endl;
        }
    } while (option != 4);

    return 0;
}
