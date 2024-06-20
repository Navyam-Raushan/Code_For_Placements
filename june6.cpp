#include <iostream>
using namespace std;

int peakElement(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int size;
    cin >> size; // Size of array

    int *a = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> a[i];
    }
    


    peakElement(a, size);

    return 0;
}
