#include <bits/stdc++.h>
using namespace std;

// X is the element that we need to find
// N is size of the array
// Title: Search an element in an array
int search(int arr[], int N, int X)
{
    
    for (int i = 0; i < N; i++)
    {
        
        if (arr[i] == X)
        {
            
            return i;
        }
    }

    return -1;
}

// Title: Find minimum and maximum element in an array



int main()
{
    int n, x, res;
    // cin >> n;
    cin >> x;

    // Do this when you need to take input from keyboard
    // int *arr = new int[n];

    int arr[] = {1, 2, 3, 4, 5};

    res = search(arr, 5, x);
    cout<< "The index of the element is " << res;

    return 0;
}