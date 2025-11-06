#include <iostream>
using namespace std;
class Divide
{
public:
    double dividend;
    double divisor;
    void getdata();
    void answer();
};
void Divide::getdata()
{
    cout << "Enter the dividend: ";
    cin >> dividend;
    cout << "Enter the divisor: ";
    cin >> divisor;
}
void Divide::answer()
{
    try
    {
        if (divisor == 0)
            throw divisor;
        double result = dividend / divisor;
        cout << "The division is: " << result << endl;
    }
    catch (double y)
    {
        cout << "Can’t Divide By Zero exception" << endl;
    }
}
int main()
{
    Divide d;
    while (true)
    {
        d.getdata();
        d.answer();
        char choice;
        cout << "Do you want to continue? (y/n): ";
        cin >> choice;
        if (choice != 'y' && choice != 'Y')
        {
            break;
        }
    }
    return 0;
}