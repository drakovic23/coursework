/*********************************************
 * Author: Deni Rakovic                      *
 * Date  : November 19, 2021                 *
 * Title : Lab 9 Part C                      *
 *********************************************/

#include <stdio.h>

unsigned long int decimalToBinary(unsigned int num);

int main(void)
{
    unsigned int num;
    puts("Enter in a number to convert: ");
    scanf("%d", &num);
    printf("%ld\n", decimalToBinary(num));

    return 0;
}

unsigned long int decimalToBinary(unsigned int num)
{
    unsigned long int binaryNum[512];
    int counter = 0; //So we know how many elements are set in binaryNum
    //Convert the decimal value to binary
    while(num != 0)
    {
        binaryNum[counter] = num % 2;
        num /= 2;
        counter++;
    }
    
    unsigned long int retValue = 0; //Our return value
    //Backwards for loop because our array has the binary number from top to bottom
    for(int x = counter - 1; x > -1;x--)
    {
        //Append digits
        retValue = (retValue * 10) + binaryNum[x];
    }
    //Return value
    return retValue;

}