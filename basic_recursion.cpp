#include <bits/stdc++.h>
using namespace std;

void print_name_n_times(string name, int n, int count)
{

    if (count > n)
        return;

    cout << name << endl;
    return print_name_n_times(name, n, count++);
}

int main()
{
    string name;
    int n;
    getline(cin, name);

    cin >> n;

    print_name_n_times(name, n, 1);

    return 0;
}