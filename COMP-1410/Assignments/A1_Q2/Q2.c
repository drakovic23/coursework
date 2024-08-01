#include <assert.h>
#include <stdbool.h>

//prototypes
int num_divisors_up_to_k(int n, int k);
bool is_prime(int n);

int main() {
    //asserts for num_divisors_up_to_k(n,k)
    assert(num_divisors_up_to_k(9,9) == 3);
    assert(num_divisors_up_to_k(12,12) == 6);
    assert(num_divisors_up_to_k(12,11) == 5);
    assert(num_divisors_up_to_k(8,7) == 3);

    //asserts for is_prime(n)
    assert(is_prime(1) == false);
    assert(is_prime(3) == true);
    assert(is_prime(383) == true);
    assert(is_prime(40) == false);
    return 0;
}

// num_divisors_up_to_k(n,k) returns the number of positive divisors
// of n that are less than or equal to k
// requires: 1 <= k <= n
int num_divisors_up_to_k(int n, int k)
{
    if(k <= 1) //stops recursion, since 1 is always a pos divisor need to return 1
        return 1;
    if(n % k == 0) //need to return 1 + recursive call of k-1 here to decrement number
        return 1 + num_divisors_up_to_k(n,k-1);

    return num_divisors_up_to_k(n,k-1);
}

// is_prime(n) returns true if n is a prime number and false otherwise
// requires: 1 <= n
bool is_prime(int n)
{
    if(num_divisors_up_to_k(n,n) == 2 && n != 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}