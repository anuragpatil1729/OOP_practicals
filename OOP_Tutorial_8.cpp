#include <iostream>
using namespace std;

template <class T>
void sort(T a[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                T temp;
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

template <class T>
void display(T a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    int choice, n;

    cout << "Choose array type:\n1. Integer\n2. Float\nEnter choice: ";
    cin >> choice;

    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Number of elements must be greater than 0!" << endl;
        return 0;
    }

    if (choice == 1)
    {
        int *arr = new int[n]; // Dynamically allocate memory based on user input
        cout << "Enter " << n << " integers:\n";
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        sort(arr, n);

        cout << "Sorted array: ";
        display(arr, n);

        delete[] arr; // Free the dynamically allocated memory
    }
    else if (choice == 2)
    {
        float *arr = new float[n]; // Dynamically allocate memory based on user input
        cout << "Enter " << n << " floats:\n";
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        sort(arr, n);

        cout << "Sorted array: ";
        display(arr, n);

        delete[] arr; // Free the dynamically allocated memory
    }
    else
    {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
