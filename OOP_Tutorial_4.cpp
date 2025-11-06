#include <iostream>
using namespace std;

class Complex
{
public:
    int real;
    int img;

    // Default constructor
    Complex()
    {
        real = 0;
        img = 0;
    }

    // Parameterized constructor
    Complex(int r, int i)
    {
        real = r;
        img = i;
    }

    // Copy constructor
    Complex(const Complex &c)
    {
        real = c.real;
        img = c.img;
    }

    // Overloading >> operator (input)
    friend istream &operator>>(istream &in, Complex &c)
    {
        cout << "Enter the real part: ";
        in >> c.real;
        cout << "Enter the imaginary part: ";
        in >> c.img;
        return in;
    }

    // Overloading << operator (output)
    friend ostream &operator<<(ostream &out, const Complex &c)
    {
        if (c.img < 0)
            out << c.real << " - " << -c.img << "i";
        else
            out << c.real << " + " << c.img << "i";
        return out;
    }

    // Overloading + operator (member function)
    Complex operator+(const Complex &obj)
    {
        Complex temp;
        temp.real = real + obj.real;
        temp.img = img + obj.img;
        return temp;
    }

    // Overloading * operator (friend function)
    friend Complex operator*(const Complex &c1, const Complex &c2)
    {
        Complex temp;
        temp.real = c1.real * c2.real - c1.img * c2.img;
        temp.img = c1.real * c2.img + c1.img * c2.real;
        return temp;
    }
};

int main()
{
    Complex c1, c2;

    cin >> c1;
    cout << "First complex number: " << c1 << endl;

    cin >> c2;
    cout << "Second complex number: " << c2 << endl;

    Complex sum = c1 + c2;
    cout << "Sum: " << sum << endl;

    Complex product = c1 * c2;
    cout << "Product: " << product << endl;

    return 0;
}