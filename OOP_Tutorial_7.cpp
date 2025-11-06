#include <iostream>
#include <fstream>
using namespace std;
class Inventory
{
    string name;
    int itemID;
    int quantity;
    double price;

public:
    void input();
    void display();
    void saveToFile(ofstream &out);
    void loadFromFile(ifstream &in);
};
void Inventory::input()
{
    cout << "Enter name of item: ";
    cin >> name;
    cout << "Enter item ID: ";
    cin >> itemID;
    cout << "Enter quantity of item: ";
    cin >> quantity;
    cout << "Enter price of item: ";
    cin >> price;
}
void Inventory::display()
{
    cout << "\nName: " << name;
    cout << "\nItem ID: " << itemID;
    cout << "\nQuantity: " << quantity;
    cout << "\nPrice: " << price << "\n";
}
void Inventory::saveToFile(ofstream &out)
{
    out << name << "\n"
        << itemID << "\n"
        << quantity << "\n"
        << price << "\n";
}
void Inventory::loadFromFile(ifstream &in)
{
    getline(in, name);
    in >> itemID;
    in >> quantity;
    in >> price;
    in.ignore(); // Ignore the newline after reading price to avoid issues
}
int main()
{
    Inventory obj;
    obj.input();
    ofstream file_out("Input.txt");
    if (!file_out)
    {
        cerr << "Error opening file for writing.\n";
        return 1;
    }
    obj.saveToFile(file_out);
    file_out.close();
    Inventory obj2;
    ifstream file_in("Input.txt");
    if (!file_in)
    {
        cerr << "Error opening file for reading.\n";
        return 1;
    }
    obj2.loadFromFile(file_in);
    file_in.close();
    cout << "\nData read from file:";
    obj2.display();
    return 0;
}
