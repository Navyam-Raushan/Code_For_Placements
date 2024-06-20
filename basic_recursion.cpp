#include <bits/stdc++.h>
using namespace std;

void print_name_n_times(string name, int n, int count)
{

    if (count > n)
        return;

    cout << name << endl;
    return print_name_n_times(name, n, count + 1);
}

// Start++ and start + 1 is different here;
void print_one_to_n(int start, int n)
{
    if (start > n)
        return;

    cout << start << endl;
    // start++;
    print_one_to_n(start + 1, n);
}

void print_n_to_one(int end, int n)
{
    if (end > n)
        return;

    cout << n << endl;
    print_n_to_one(end, n - 1);
}

// Optimal approach return n(n+1)/2
// But trying here with recursion for practice - Parametrised approach
int sum_of_first_n(int n, int sum = 0)
{

    if (n == 0)
        return sum;

    sum = sum + n;
    return sum_of_first_n(n - 1, sum);
}

// Functional approach (more optimal)
// Important
int sum_by_func(int n)
{
    if (n == 0)
        return 0;
    
    return n + sum_by_func(n-1);
}

int main()
{
    string name;
    int n, res;
    // getline(cin, name);

    cin >> n;

    res =sum_of_first_n(n);
    cout<< res;

    return 0;
}