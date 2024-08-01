/*********************************************
 * Author: Deni Rakovic                      *
 * Date  : November 15, 2021                 *
 * Title : Lab 8 Part A                      *
 *********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    unsigned int n;
    puts("Please enter a value:");
    scanf("%d", &n);
    //Declare array with size of n
    unsigned int numArray[n];
    int swaps = -1;
    //Create new seed
    srand(time(0));

    //Set elements in numArray to a random number
    for(int x=0;x < n;x++)
    {
        numArray[x] = rand() % 1000;
    }

    clock_t start = clock();
    while(1)
    {
        swaps = 0;
        for(int x=0;x < n; x++)
        {
            //Swap elements if [x] > [x+1]
            if(numArray[x] > numArray[x+1])
            {
                long int temp = numArray[x+1];
                numArray[x+1] = numArray[x];
                numArray[x] = temp;
                swaps++;
            }
        }
        //If we pass through array and swaps == 0 then we know array is sorted
        if(swaps == 0)
            break;
    }
    //Get time spent in loop
    clock_t end = clock();
    double timeSpent = (double)(end-start) / CLOCKS_PER_SEC;
    //Print out array
    for(int x = 0; x < n; x++)
    {
        if(x < n -1)
            printf("%d, ", numArray[x]);
        else //So we don't print comma after last element
            printf("%d \n", numArray[x]);
    }
    printf("\nTime spent processing: %f seconds\n", timeSpent);

    return 0;
}