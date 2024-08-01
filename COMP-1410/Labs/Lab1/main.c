#include <stdio.h>
#include <assert.h>

int digit_sum_iterative(int n);
int digit_sum_recursive(int n);

int main(void)
{
    //Iterative asserts
    assert(digit_sum_iterative(1234) == 10);
    assert(digit_sum_iterative(12345) == 15);
    assert(digit_sum_iterative(0) == 0);
    assert(digit_sum_iterative(5) == 5);
    assert(digit_sum_iterative(999999999) == 81);
    //Recursive asserts
    assert(digit_sum_recursive(1234) == 10);
    assert(digit_sum_recursive(12345) == 15);
    assert(digit_sum_recursive(5) == 5);
    assert(digit_sum_recursive(0) == 0);
    assert(digit_sum_recursive(999999999) == 81);
    puts("All tests completed successfully!");
}

// digit_sum_iterative(n) returns the decimal sum of the digits in n
// requires: 0 <= n < 10ˆ9
// note: implemented using iteration
int digit_sum_iterative(int n)
{
    int sum = 0;
    while(n != 0)
    {
        sum += n % 10;
        n = n / 10;
    }

    return sum;
}
// digit_sum_recursive(n) returns the decimal sum of the digits in n
// requires: 0 <= n < 10ˆ9
// note: implemented using recursion
// base case: n <= 0
// recursive: when n !=0 function calls itself
int digit_sum_recursive(int n)
{
    if(n <= 0)
        return 0;
    return (n % 10) + digit_sum_recursive(n / 10);
}
