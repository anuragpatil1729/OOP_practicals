#include <iostream>
#include <string>
using namespace std;

class shape
{
public:
    long long int a, b;

    void get_data()
    {
        cin >> a >> b;
    }

    virtual void display_area() = 0;
};

class triangle : public shape
{
public:
    void display_area()
    {
        cout << "Area of triangle is: " << 0.5 * a * b << endl;
    }
};

class rectangle : public shape
{
public:
    void display_area()
    {
        cout << "Area of rectangle is: " << a * b << endl;
    }
};

int main()
{
    triangle t;
    rectangle r;

    int choice;

    cout << "Enter 1 for calculating Area of Triangle  ";
    cout << "\nEnter 2 for calculating Area of Rectangle ";
    cout << "\nEnter 3 for calculating Both Area of Triangle and Rectangle ";
    cout << "\nChoice :";
    cin >> choice;

    if (choice == 1)
    {
        shape *st = &t;
        cout << "Enter the base and height of the Triangle: ";
        st->get_data();
        st->display_area();
    }

    else if (choice == 2)
    {
        shape *sr = &r;
        cout << "\nEnter the length and breadth of the Rectangle: ";
        sr->get_data();
        sr->display_area();
    }
    else
    {
        shape *st = &t;
        cout << "Enter the base and height of the Triangle: ";
        st->get_data();
        st->display_area();

        shape *sr = &r;
        cout << "\nEnter the length and breadth of the Rectangle: ";
        sr->get_data();
        sr->display_area();

        return 0;
    }
}
