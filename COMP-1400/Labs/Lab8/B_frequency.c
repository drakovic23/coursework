/*********************************************
 * Author: Deni Rakovic                      *
 * Date  : November 15, 2021                 *
 * Title : Lab 8 Part B                      *
 *********************************************/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{   
    //Declare array and new seed for rand    
    int x[30];
    srand(time(0));

    //Generate random numbers and set values to all elements of x
    for(int n=0;n < 30; n++)
    {
        x[n] = rand() % 20;
    }
    //Get input from user
    puts("Enter a number between 0 - 20: ");
    int num;
    scanf("%d", &num);
    //If user input is outside of range then ask for input again
    while(num > 20 || num < 0)
    {
        puts("Invalid value, please enter a number between 0 and 20: ");
        scanf("%d", &num);
    }

    //Get frequency of given number
    int freq = 0;
    for(int n=0;n < 30; n++)
    {
        if(num == x[n])
            freq++;
    }

    //Output array
    for(int n=0;n < 30; n++)
    {
        if(n < 30 - 1)
            printf("%d, ", x[n]);
        else
            printf("%d \n", x[n]);
    }
    //Output frequency
    printf("Frequency of %d is %d\n", num, freq);

    return 0;
}