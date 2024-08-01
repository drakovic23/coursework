#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

bool order(int * const a, int * const b, int * const diff);

int main()
{
    int num = 15;
    int num_two = 10;
    int difference = 0;
    assert(order(&num, &num_two, &difference) == true);

    num = 5;
    num_two = 10;
    assert(order(&num, &num_two, &difference) == false);

    num = 5;
    num_two = 5;
    assert(order(&num, &num_two, &difference) == false);

    num = 30;
    num_two = 20;
    assert(order(&num, &num_two, &difference) == true);

    order(&num, &num_two, &difference);
    printf("%d, %d, %d\n ", num, num_two, difference);

    return 0;
}

// order(a, b) orders the values pointed to by a and b so that *a <= *b;
// *diff is set to absolute value of the difference between *a and *b;
// returns true if the values were switched and false otherwise
// requires: a, b, and diff point to memory that can be modified
bool order(int * const a, int * const b, int * const diff)
{
    if(*b >= *a)
    {
        *diff = *b - *a;
        return false;

    }
    else
    {
        int temp = *a;
        *a = *b;
        *b = temp;
        *diff = *b - *a;
        return true;
    }
}
