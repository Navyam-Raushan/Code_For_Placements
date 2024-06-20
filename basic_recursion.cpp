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
    if(end > n)
        return;
    
    cout<< n << endl;
    print_n_to_one(end, n-1);
}



int main()
{
    string name;
    int n;
    // getline(cin, name);

    cin >> n;

    // print_name_n_times(name, n, 1);
    print_n_to_one(1, n);

    return 0;
}