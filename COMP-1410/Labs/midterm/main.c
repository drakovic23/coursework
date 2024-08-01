#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

bool all_odd_in_array(int a[], int n, int * sum);;
int main()
{
    int sum = 0;
    int arr[5] = {1,3,5,7,9};
    int arr2[5] = {1,2,3,4,5};
    int arr3[1] = {2};

    assert(all_odd_in_array(arr,5,&sum) == true && sum == 25);
    sum = 0;
    assert(all_odd_in_array(arr2,5,&sum) == false && sum == 9);
    sum = 0;
    assert(all_odd_in_array(arr3,1,&sum) == false && sum == 0);

    return 0;
}

// all_odd_in_array(a, n, sum) returns true if all integers in the
//     array a of length n are odd; *sum is updated to the sum of the
//     odd integers in the array
// requires: sum points to memory that can be updated
bool all_odd_in_array(int a[], int n, int * sum)
{
    bool return_value = true;
    for(int x = 0; x < n; x++)
    {
        if(a[x] % 2 >= 1) //a[x] is odd
        {
            *sum += *(a+x);
        }else //a[x] is even
        {
            return_value = false;
        }
    }

    return return_value;
}
/*First we assume that the return value is true (all numbers are odd).
 * Then we iterate through the array and if a number is odd, we add it to *sum,
 * otherwise (else) it must be even and we set the return value to false since not all numbers are odd.
 * Once we are done iterating we return the boolean return_value                                       */
