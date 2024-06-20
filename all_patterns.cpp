#include <bits/stdc++.h>
using namespace std;

// This is from striver's a2z sheet-
// https://takeuforward.org/strivers-a2z-dsa-course/must-do-pattern-problems-before-starting-dsa/

// Title:Rectangular star Pattern
// Its same like 2d matrix
void pattern1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "*" << " ";
        }

        cout << endl;
    }
}

// Right angled Triangle Pattern
// Focus that number of stars = i+1 in each line
void pattern2(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << "*" << " ";
        }

        cout << endl;
    }
}

// Title: Right-Angled Number Pyramid
// Same as pattern2 just see value of j=
void pattern3(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < i + 2; j++)
        {
            cout << j << " ";
        }

        cout << endl;
    }
}

// Title: Right-Angled Number Pyramid - II
// Use a count variable to keep printing the same number in one line
void pattern4(int n)
{
    int count = 1;
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < i + 1; j++)
        {

            cout << count;
        }
        count++;
        cout << endl;
    }
}

// Inverted Right Pyramid
// Just reverse the outer loop of pattern2
// Whenever you need to invert patter reverse outer loop
void pattern5_inverted(int n)
{
    for (int i = n; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "*";
        }

        cout << endl;
    }
}

//  Inverted Numbered Right Pyramid
// Again we need to invert only outer loop
void pattern6_inverted(int n)
{
    for (int i = n; i > 0; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }

        cout << endl;
    }
}

// Star Pyramid (important)
// 1,3,5 ..... odd number series (2n-1)
// Keep in mind to center any pattern you need n-i-1 spaces before and after
void pattern7(int n)
{
    for (int i = 0; i < n; i++)
    {
        // To print n-i-1 spaces
        for (int k = 0; k < n - i - 1; k++)
        {
            cout << " ";
        }

        for (int j = 0; j < ((2 * i) + 1); j++)
        {
            cout << "*";
        }

        for (int k = 0; k < n - i - 1; k++)
        {
            cout << " ";
        }

        cout << endl;
    }
}

// Inverted Star Pyramid (important)
// This time we need to change outer loop as well as space loop
// And also see the starting value of i its n-1
void pattern8_inverted(int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        // For the spaces before
        for (int k = 0; k < n - i - 1; k++)
        {
            cout << " ";
        }

        // For printing *
        for (int j = (2 * i + 1); j > 0; j--)
        {
            cout << "*";
        }

        // For spaces after
        for (int k = 0; k < n; k++)
        {
            cout << " ";
        }

        cout << endl;
    }
}

// Diamond Star Pattern (important-combo)
// Its combination of pattern7 and pattern8 (so club both function)
void pattern9_combo(int n)
{
    // club both function
    pattern7(n);
    pattern8_inverted(n);
}

// Half diamond star pattern
// My solution which have so many loops
void pattern10(int n)
{
    // for printing first half
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << "*";
        }

        cout << endl;
    }

    // For printing second half
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = i; j > 0; j--)
        {
            cout << "*";
        }

        cout << endl;
    }
}

// Doing pattern 10 with minimum number of loops
// You need 2n-1 lines- outer loop
// You need to create formulas  by own
// Have same time complexity but lesser lines of code
void pattern10_optimum(int n)
{
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        // Logic is to update the number of stars when i > n
        int stars = i;

        if (i > n)
        {
            // This formula is important
            stars = 2 * n - i;
        }

        for (int j = 0; j < stars; j++)
        {
            cout << "*";
        }

        cout << endl;
    }
}

// Binary number Triangle Pattern (Important)
// The important part is odd even combination
// There is shorter code but i think this is good to go
void binary_triangle_11(int n)
{
    for (int i = 0; i < n; i++)
    {

        // Assign these values after each inner loop
        int c1 = 1;
        int c2 = 0;

        for (int j = 0; j < i + 1; j++)
        {
            if (i % 2 == 0)
            {
                cout << c1;
                if (c1 == 0)
                    c1++;
                else
                    c1--;
            }

            else
            {
                cout << c2;
                if (c2 == 0)
                    c2++;
                else
                    c2--;
            }
        }

        cout << endl;
    }
}

// Number/star Crown Pattern
// Main formula is in between spaces = 2*n - 2*(i+1)
// Its a combination of two function
// My code is better than striver
// after 10 due to two digits the pattern is little bit bent
// So you can use * for better pattern at n>10
void number_crown_12(int n)
{

    for (int i = 0; i < n; i++)
    {
        // For the right half
        for (int j = 1; j <= i + 1; j++)
        {
            // cout << j;
            cout << "*";
        }

        // For spaces in between
        for (int k = 0; k < (2 * n) - (2 * (i + 1)); k++)
        {
            cout << " ";
        }

        // For the right half
        for (int j = i + 1; j > 0; j--)
        {
            // cout << j;
            cout << "*";
        }

        cout << endl;
    }
}

// Increasing Number Triangle Pattern
// inner loop runs same number of times but the starting = i+1
void increasing_triangle_13(int n)
{
    int start = 1;
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < i + 1; j++)
        {
            cout << start << " ";
            // To increase the number in same line
            start++;
        }

        // To increase number only by one in next line
        start--;
        start++;
        cout << endl;
    }
}

// Getting next character of English Alphabet
// If input == z then return a otherwise increase character by 1
char incrementCharacter(char input)
{
    return (input == 'Z' ? 'A' : (char)(input + 1));
}

// Decreasing the next character
char decrementCharacter(char input)
{
    return (input == 'Z' ? 'A' : (char)(input - 1));
}
// Increasing Letter Triangle Pattern
// Need another function to increase character
void letter_triangle_14(int n)
{

    for (int i = 0; i < n; i++)
    {
        char start = 'A';

        for (int j = 0; j < i + 1; j++)
        {
            cout << start;
            start = incrementCharacter(start);
        }

        cout << endl;
    }
}

// Reverse letter triangle Pattern
// Just reversing the both loops
void reverse_letter_triangle_15(int n)
{

    for (int i = n; i > 0; i--)
    {
        char start = 'A';
        for (int j = i; j > 0; j--)
        {
            cout << start << " ";
            start = incrementCharacter(start);
        }

        cout << endl;
    }
}

// Alpha- Ramp Pattern-16
//  Difference is to increment character after we jump to next line
void alpha_ramp_pattern_16(int n)
{
    char start = 'A';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << start << " ";
        }

        start = incrementCharacter(start);
        cout << endl;
    }
}

// Alpha-Hill Pattern
// This is a centered equilateral triangle pattern
// To center any pattern u need n-i-1 spaces
void alpha_hill_pattern_17(int n)
{
    // For left spaces
    for (int i = 0; i < n; i++)
    {
        char start = 'A';

        // Extra spaces to left
        for (int k = 0; k < n - i - 1; k++)
        {
            cout << " ";
        }

        // for centered letters
        for (int j = 0; j < (2 * i + 1); j++)
        {

            if (j > i)

            {
                // This case is causing issue so i have written seperately.
                if (j == i + 1)
                {
                    start = decrementCharacter(start);
                    start = decrementCharacter(start);
                    cout << start;
                }
                else
                {
                    start = decrementCharacter(start);
                    cout << start;
                }
            }
            else
            {
                cout << start;
                start = incrementCharacter(start);
            }
        }

        // Extra spaces to right
        for (int k = 0; k < n - i - 1; k++)
        {
            cout << " ";
        }

        cout << endl;
    }
}

// Alpha Triangle Pattern - starting with the nth letter(important)
// First letter of each line is = (n-i)th letter
void alpha_triangle_pattern_18(int n)
{
    for (int i = 0; i < n; i++)
    {
        char start = 'A';

        for (int k = n - i - 1; k > 0; k--)
        {
            start = incrementCharacter(start);
        }

        for (int j = 0; j < i + 1; j++)
        {

            cout << start << " ";
            start = incrementCharacter(start);
        }

        cout << endl;
    }
}

// Systematic void pattern - club of two patterns
// I have tried it with right half and left half
void systematic_void_19(int n)
{
    // Upper half
    for (int i = n; i > 0; i--)
    {
        //    for the left half
        for (int j = i; j > 0; j--)
        {
            cout << "*";
        }

        // for the spaces in between
        for (int k = 0; k < 2 * (n - i); k++)
        {
            cout << " ";
        }

        // For the right half
        for (int j = i; j > 0; j--)
        {
            cout << "*";
        }

        cout << endl;
    }

    // Lower half
    for (int i = 0; i < n; i++)
    {
        // For the left half
        for (int j = 0; j < i + 1; j++)
        {
            cout << "*";
        }

        // for the spaces in between
        for (int k = 0; k < 2 * (n - (i + 1)); k++)
        {
            cout << " ";
        }

        // For the right half
        for (int j = 0; j < i + 1; j++)
        {
            cout << "*";
        }

        cout << endl;
    }
}

// Symmetric- butterfly pattern
// The most important is formula making for auto reversal
void symmetric_butterfly_20(int n)
{
    // For the left half
    for (int i = 0; i < (2 * n - 1); i++)
    {
        // By this approach i can reverse the loop printing
        int start;

        if (i >= n)
        {
            // We have to reverse the loop for second half
            // This formula is most important see the sum of i and j when j>n
            start = (2 * n - 1) - i;
        }
        else
            start = i + 1;

        for (int j = 0; j < start; j++)
        {

            cout << "*";
        }

        // For the spaces in between (reverse auto)
        for (int k = 0; k < abs(2 * (n - (i + 1))); k++)
        {
            cout << " ";
        }

        // For the right half
        for (int j = 0; j < start; j++)
        {
            cout << "*";
        }

        cout << endl;
    }
}

// Hollow- Rectangle Pattern
// My code uses more loops but do same task
// Wrong code see pattern21_optimal
void hollow_rect_21(int n)
{
    for (int i = 0; i < n; i++)
    {
        int start;

        if (i == 0 || i == n - 1)
        {
            start = n;
        }
        else
            start = 1;

        for (int j = 0; j < start; j++)
        {
            cout << "*";
        }

        if (i != 0 || i != n - 1)
        {
            // For spaces in between
            for (int k = 0; k < n - 2; k++)
            {
                cout << " ";
            }

            for (int j = 0; j < 1; j++)
            {
                cout << "*";
            }
        }

        cout << endl;
    }
}

// In this appraoch we print only border index
// This approach is much simple
void pattern21_optimal(int n)
{
    // outer loop for no. of rows.
    for (int i = 0; i < n; i++)
    {

        // inner loop for printing the stars at borders only.
        for (int j = 0; j < n; j++)
        {

            if (i == 0 || j == 0 || i == n - 1 || j == n - 1)
                cout << "*";

            // if not border index, print space.
            else
                cout << " ";
        }

        // As soon as the stars for each iteration are printed, we move to the
        // next row and give a line break otherwise all stars
        // would get printed in 1 line.
        cout << endl;
    }
}

// The Number Pattern (important)
// leaving due to its complexity.
void number_matrix_22(int n)
{
    for (int i = 0; i < 2 * n - 1; i++)
    {
        
        int row = i;

        for (int j = 0; j < 2 * n - 1; j++)
        {
            int toPrint = abs(n - i);

            if (j == row || i == row || j == n - (row + 1) || i == n - (row + 1))
            {
                cout << toPrint << " ";
            }
            
        }

        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    number_matrix_22(n);
    // char c;
    // cin >> c;
    // char res = decrementCharacter(c);
    // cout << res;

    return 0;
}