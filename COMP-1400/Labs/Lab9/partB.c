/*********************************************
 * Author: Deni Rakovic                      *
 * Date  : November 19, 2021                 *
 * Title : Lab 9 Part B                      *
 *********************************************/

#include <stdio.h>
#include <math.h>

long int factorial(unsigned int num); //Prototype

int main(void)
{
    //The maximum value of an integer that we can calculate the factorial for is 20, so 21 would cause a overflow with a long int data type.
    printf("Factorial of 2: %ld\n", factorial(2));
    printf("Factorial of 3: %ld\n", factorial(3));
    printf("Factorial of 4: %ld\n", factorial(4));
    printf("Factorial of 5: %ld\n", factorial(5));
    printf("Factorial of 10: %ld\n", factorial(10));
    printf("Factorial of 15: %ld\n", factorial(15)); 
    printf("Factorial of 21: %ld\n", factorial(21)); //This causes a overflow with a long int type

    return 0;
}

long int factorial(unsigned int num)
{
    unsigned long int retValue = 1;
    int counter = num;
    //Calculate factorial
    while(counter != 0)
    {
        retValue *= counter; 
        counter--;
    }
    //Return value
    return retValue;
}