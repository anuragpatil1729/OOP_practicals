#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    typedef map<int, string> mapType;
    mapType SMap;

    SMap.insert(pair<int, string>(1, "Tushar"));
    SMap.insert(pair<int, string>(2, "Vishwesh"));
    SMap.insert(pair<int, string>(3, "Sahil"));
    SMap.insert(pair<int, string>(4, "Abhijeet"));
    SMap.insert(pair<int, string>(5, "Pravin"));
    SMap.insert(pair<int, string>(6, "Avishkar"));

    mapType::iterator iter;
    cout << "======== Student Directory ==========\n";
    cout << "\nSize of SMap: " << SMap.size() << "\n";

    for (iter = SMap.begin(); iter != SMap.end(); iter++)
    {
        cout << iter->first << " : " << iter->second << "\n";
    }

    int PRN;
    cout << "\nEnter PRN of the student: ";
    cin >> PRN;

    iter = SMap.find(PRN);
    if (iter != SMap.end())
        cout << PRN << "'s name is " << iter->second << "\n";
    else
        cout << "PRN not found in Student Directory.\n";

    SMap.clear();
    return 0;
}
