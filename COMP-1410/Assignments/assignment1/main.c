#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <limits.h>

//prototypes
int choose(int n, int m);
int num_divisors_up_to_k(int n, int k);
bool is_prime(int n);
int collatz(int n);

int main()
{
    //asserts for choose(n,m)
    assert(choose(4,2) == 6);
    assert(choose(4,4) == 1);
    assert(choose(6,2) == 15);
    assert(choose(50,2) == 1225);

    //asserts for num_divisors_up_to_k(n,k)
    assert(num_divisors_up_to_k(9,9) == 3);
    assert(num_divisors_up_to_k(12,12) == 6);
    assert(num_divisors_up_to_k(12,12) == 6);
    assert(num_divisors_up_to_k(8,7) == 3);

    //asserts for is_prime(n)
    assert(is_prime(1) == false);
    assert(is_prime(3) == true);
    assert(is_prime(383) == true);
    assert(is_prime(40) == false);

    //asserts for collatz(n)
    assert(collatz(1) == 0);
    assert(collatz(5) == 5);
    assert(collatz(10) == 6);
    assert(collatz(25) == 23);

    int num;
    puts("Please enter an integer:");
    //Get input from user
    int inputsConverted = scanf("%d", &num);
    while(inputsConverted == 1)
    {
        while(num < 1 || num >= INT_MAX)
        {
            puts("Error: Invalid Integer");
            puts("Please enter a valid integer: ");
            inputsConverted = scanf("%d", &num);
        }
        collatz(num);
        inputsConverted = scanf("%d", &num);
    }

    //puts("Tests have passed successfully.");
    return 0;
}


// choose(n,m) returns how many ways there are to choose m items from
// a set of n items
// requires: 0 <= m and 0 <= n
int choose(int n, int m)
{
    //printf("%d, %d\n", m,n);
    //base case m > n
    if(m > n)
        return 0;
    //base case m==0 or m==n
    if(m == 0 || m == n)
        return 1;

    return choose(n - 1,m) + choose(n - 1,m - 1);
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

// collatz(n) returns the number of steps it takes to reach 1
// by repeatedly applying the Collatz mapping on n; prints each
// number in the sequence starting at n
// requires: 1 <= n
int collatz(int n)
{
    printf("%d", n);
    int count = 0;
    if(n != 1)
    {
        while (n != 1)
        {
            if (n % 2 == 0) //n is even
            {
                n /= 2;
                printf("-> %d ", n);
            } else //n is odd
            {
                n = (3 * n) + 1;
                printf("-> %d ", n);
            }
            count++;
        }
        printf("\n");
    }else
    {
        count = 0;
        printf("\n");
    }

    return count;
}


