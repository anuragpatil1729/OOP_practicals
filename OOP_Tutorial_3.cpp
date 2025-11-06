#include <iostream>
#include <string>
using namespace std;

/* Main class */
class Staff
{
protected:
    int staffID;
    string name;
    string designation;

public:
    void inputBasicDetails()
    {
        cout << "Enter Staff ID: ";
        cin >> staffID;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Designation: ";
        getline(cin, designation);
    }

    void displayBasicDetails()
    {
        cout << "\nStaff ID: " << staffID << endl;
        cout << "Name: " << name << endl;
        cout << "Designation: " << designation << endl;
    }
};

/* Derived class one (teaching) */
class Teaching : public Staff
{
private:
    string subject;
    int experience;

public:
    void inputDetails()
    {
        inputBasicDetails();
        cout << "Enter Subject Taught: ";
        getline(cin, subject);
        cout << "Enter Years of Experience: ";
        cin >> experience;
    }

    void displayDetails()
    {
        displayBasicDetails();
        cout << "Subject: " << subject << endl;
        cout << "Experience: " << experience << " years" << endl;
    }
};

/* Derived class two (Non Teaching) */
class NonTeaching : public Staff
{
private:
    string department;
    string duty;

public:
    void inputDetails()
    {
        inputBasicDetails();
        cout << "Enter Department: ";
        getline(cin, department);
        cout << "Enter Duty: ";
        getline(cin, duty);
    }

    void displayDetails()
    {
        displayBasicDetails();
        cout << "Department: " << department << endl;
        cout << "Duty: " << duty << endl;
    }
};

/* Derived class three (Administrative) */
class Administrative : public Staff
{
private:
    string section;
    string responsibility;

public:
    void inputDetails()
    {
        inputBasicDetails();
        cout << "Enter Section: ";
        getline(cin, section);
        cout << "Enter Responsibility: ";
        getline(cin, responsibility);
    }

    void displayDetails()
    {
        displayBasicDetails();
        cout << "Section: " << section << endl;
        cout << "Responsibility: " << responsibility << endl;
    }
};

/* Derived class four(student) */
class student : public Staff
{
protected:
    string PRN;
    long long int mobile_number;

public:
    void inputDetails()
    {
        inputBasicDetails();
        cout << "Enter the Permanent Registration number: ";
        getline(cin, PRN);
        cout << "Enter the contact number of the student: ";
        cin >> mobile_number;
        cin.ignore();
    }
    void displayDetails()
    {
        displayBasicDetails();
        cout << "Permanent Registration Number(PRN) of the student: " << PRN << endl;
        cout << "Mobile Number of the Student: " << mobile_number << endl;
    }
};

int main()
{
    int choice;
    cout << "Educational Institution Staff Management System\n";
    cout << "1. Teaching Staff\n";
    cout << "2. Non-Teaching Staff\n";
    cout << "3. Administrative Staff\n";
    cout << "4. Student \n";
    cout << "Enter your choice (1-4): ";
    cin >> choice;
    cin.ignore(); // Clear newline from buffer

    if (choice == 1)
    {
        Teaching t;
        t.inputDetails();
        cout << "\n--- Teaching Staff Details ---" << endl;
        t.displayDetails();
    }
    else if (choice == 2)
    {
        NonTeaching nt;
        nt.inputDetails();
        cout << "\n--- Non-Teaching Staff Details ---" << endl;
        nt.displayDetails();
    }
    else if (choice == 3)
    {
        Administrative a;
        a.inputDetails();
        cout << "\n--- Administrative Staff Details ---" << endl;
        a.displayDetails();
    }
    else if (choice == 4)
    {
        student st;
        st.inputDetails();
        cout << "\n--- Student Details ---" << endl;
        st.displayDetails();
    }

    return 0;
}
