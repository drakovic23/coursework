#include <stdio.h>
#include <limits.h>
#include <assert.h>

//prototypes
int collatz(int n);

int main()
{
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
        while(num < 1 || num >= INT_MAX - 1)
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