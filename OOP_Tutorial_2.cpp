#include <iostream>
#include <string>
using namespace std;

class employee
{
private:
    static int count;

public:
    string name;
    int employee_id;
    string department;
    string date_of_joining;
    string address;
    long telephone_number;

    employee()
    {
        count++;
    }

    employee(string n, int id, string dept, int doj, string addr, long tel)
    {
        name = n;
        employee_id = id;
        department = dept;
        date_of_joining = doj;
        address = addr;
        telephone_number = tel;
        count++;
    }

    employee(const employee &e)
    {
        name = e.name;
        employee_id = e.employee_id;
        department = e.department;
        date_of_joining = e.date_of_joining;
        address = e.address;
        telephone_number = e.telephone_number;
        count++;
    }

    ~employee()
    {
        count--;
    }

    void input()
    {
        cout << "Enter the name of an employee: ";
        getline(cin, name);

        cout << "Enter the employee identity number: ";
        cin >> employee_id;
        cin.ignore();

        cout << "Enter the department of an employee: ";
        getline(cin, department);

        cout << "Enter date of joining: ";
        cin >> date_of_joining;
        cin.ignore();

        cout << "Enter the permanent address of employee: ";
        getline(cin, address);

        cout << "Enter the telephone number: ";
        cin >> telephone_number;
        cin.ignore();
    }

    inline void output() const
    {
        cout << "Name of the employee: " << name << endl;
        cout << "Employee ID: " << employee_id << endl;
        cout << "Department of the employee: " << department << endl;
        cout << "Date of joining: " << date_of_joining << endl;
        cout << "Permanent address of the employee: " << address << endl;
        cout << "Permanent telephone number of employee: " << telephone_number << endl;
    }

    static int getCount()
    {
        return count;
    }
};

int employee::count = 0;

int main()
{
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;
    cin.ignore(); // clear newline after reading n

    // Dynamic memory allocation for array of objects
    employee *employees = new employee[n];

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter details for Employee " << (i + 1) << ":\n";
        employees[i].input();
    }

    for (int i = 0; i < n; i++)
    {
        cout << "\nThe entered details for Employee " << (i + 1) << " are:\n";
        employees[i].output();
    }

    cout << "\nTotal employees created: " << employee::getCount() << endl;

    delete[] employees;

    return 0;
}
