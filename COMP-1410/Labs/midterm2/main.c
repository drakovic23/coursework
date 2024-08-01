#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

bool all_odd_digits (int n);

int main()
{
    assert(all_odd_digits(157935) == true);
    assert(all_odd_digits(337799112) == false);
    assert(all_odd_digits(3) == true);
    puts("Tests have passed successfully!!");
    return 0;
}

// all_odd_digits(n) returns true if all the digits in n are odd
// requires: 0 <= n < 10ˆ9
bool all_odd_digits (int n)
{
    if(n == 0) //base case
        return true;
    if( (n % 10) % 2 >= 1) //digit is odd
    {
        return true + all_odd_digits(n / 10);
    }
    else //digit is even
    {
        return false;
    }
}

/* First we check our first base case which is n == 0 and return true
 * Next we take the last digit of n and check if it is odd
 * if the last digit is odd then we return true + a recursive call of n less the last digit.
 * If the above check is false then we know the digit is even and immediately return false as we don't have to check
 * the rest of the digits. */