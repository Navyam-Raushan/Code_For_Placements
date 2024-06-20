#include <bits/stdc++.h>
using namespace std;

vector<int> extract_digits(int n)
{
    // Store them into a vector and print size of vector
    // For that convert integer into a string
    vector<int> store_digit;
    string number = to_string(n);

    // It's a for each loop

    for (char str_digit : number)
    {
        // This is a way to convert string back to integer
        int digit = str_digit - '0';

        // digit = stoi(str_digit); //stoi doen't work over a single digit (don't know why)

        store_digit.push_back(digit);
    }

    return store_digit;
}

// This is by string methods
int count_digits_1(int n)
{
    vector<int> digits = extract_digits(n);

    // Not covering the case of trailing zeroes- i.e 00001
    return digits.size();
}

// The most optimal approach is count = log10(n) + 1 (new and important)
int optimal_count_digits(int n)
{
    int count;

    // adding 1 is for the case when n is at the power of 10
    count = (int)(log10(n) + 1);

    return count;
}

// Reverse a number - Two approaches (i) modulo (ii) string
// Choosing string method
// Firstly get the digits into a vector, returned reverse vector then
// This approach is more efficient because its reusable - Make a function extracting digits and reuse it.
vector<int> reverse_number(int n)
{
    vector<int> digits = extract_digits(n);

    // This line will reverse the vector;
    reverse(digits.begin(), digits.end());

    return digits;
}

// Now see even to check palindrome i can use above functions
// only limitation is that it takes extra space.
int check_palindrome(int n)
{
    vector<int> original_num, reversed_num;

    original_num = extract_digits(n);
    reversed_num = reverse_number(n);

    if (original_num == reversed_num)
    {
        return 1;
    }
    else
        return 0;
}

// To find gcd of two number

// Get the factors of each number
vector<int> factors(int n)
{
    vector<int> num_factors;
    num_factors.push_back(1);

    // This function will return the factors
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            num_factors.push_back(i);
        }
    }

    num_factors.push_back(n);

    return num_factors;
}

// Find the common elements of two arrays (using set approach)
vector<int> find_common_elements(vector<int> arr1,
                                 vector<int> arr2)
{
    // I will put first array elements into an unordered set
    // And then compare it with second array if elements matched
    // Push back into the result array

    unordered_set<int> first_arr;
    vector<int> common_elements;

    for (int i : arr1)
    {
        // Pushing all the elements of arr1 in set
        first_arr.insert(i);
    }

    // Comparing with second array
    for (int i : arr2)
    {
        // If we find arr2 elements in our set then it's common
        if (first_arr.find(i) != first_arr.end())
        {
            common_elements.push_back(i);
        }
    }

    return common_elements;
}

int gcd(int n1, int n2)
{
    // Case for one zero number
    if (n1 == 0)
        return n2;

    if (n2 == 0)
        return n1;

    if (n1 == 0 && n2 == 0)
        return -1;

    // Firstly you have to get factors of both nums
    vector<int> factors_n1, factors_n2, common_factors;

    factors_n1 = factors(n1);
    factors_n2 = factors(n2);

    common_factors = find_common_elements(factors_n1, factors_n2);

    // To get maximum element in an array (sort the array)
    sort(common_factors.begin(), common_factors.end());

    int res = common_factors.back();

    return res;
}

/*
    The most optimum approach for gcd finding - Euclidean approach

    It operates on the principle that the GCD of two numbers remains the
    same even if the smaller number is subtracted from
    the larger number.

    Repeatedly subtract the smaller number from the larger number
    until one of them becomes 0.
    Once one of them becomes 0, the other number is
    the GCD of the original numbers
*/
// Euclidean approach - Done by recursion
int gcd_optimal(int n1, int n2)
{
    if (n1 == 0)
    {
        return n2;
    }
    if (n2 == 0)
    {
        return n1;
    }

    int smaller_num = min(n1, n2);
    int larger_num = max(n1, n2);

    return gcd_optimal(larger_num - smaller_num, smaller_num);
}

// Check a number is armstrong number or not
/*
    Armstrong number = 1^3+5^3+3^3 = 1 + 125 + 27 = 153
    You can also use this function to find armstrong number
    in a given range

    Brute force approach
    Firstly extract the digits, get its size
    and apply digit^(size of num)- added for all digits
*/
bool armstrong_number(int n)
{
    vector<int> digits = extract_digits(n);
    int size = digits.size();
    // int size = optimal_count_digits(n)

    // You can use log10(n) + 1 formula to count digits

    // Consider it as a float otherwise 1 will be considered as 0;
    float sum = 0;
    for (int i : digits)
    {

        sum += pow(i, size);
    }

    if (sum == n)
        return true;
    else
        return false;
}

int main()
{
    int num1, num2, res;

    bool final_res;
    cin >> num1;
    // cin >> num2;

    final_res = armstrong_number(num1);
    cout << final_res;

    // res = gcd_optimal(num1, num2);
    // cout << res;

    // if (res == 1)
    //     cout<< "A Palindrome" << endl;
    // else
    //     cout<< "Not a Palindrome" << endl;

    // vector<int> result;
    // for (int i : result)
    // {
    //     // if (i != 0)
    //     // {
    //     //     cout << i;
    //     // }

    //     cout << i << " ";
    // }

    return 0;
}