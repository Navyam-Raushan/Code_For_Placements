#include <bits/stdc++.h>
using namespace std;


// This binary search will only work on sorted arrays
// And it return the indices of elements in sorted array


int myBinarySearch(int arr[], int size, int target)
{
    int start, end;
    start = 0;
    end = size - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        // Check target is present at mid
        // If this block is executed it will be a successfl search
        if (arr[mid] == target)
        {
            return mid;
        }
        // Ignore left half
        if (arr[mid] < target)
        {
            start = mid + 1;
        }

        // Ignore right half
        else
        {
            end = mid - 1;
        }
    }

    // If unsuccessful
    return -1;
}



int main()
{
    int n, x, res;
    // cin >> n;
    cin >> x;


    // Do this when you need to take input from keyboard
    // int *arr = new int[n];

    int arr[] = {5,8,2,1,4,};

    // You have to get the size by this this
    n = sizeof(arr)/sizeof(arr[0]);

    sort(arr, arr + n);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    

    res = myBinarySearch(arr, n, x);
    cout << "The index of the element is " << res;

    return 0;
}