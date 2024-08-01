#include <stdio.h>

int main(void)
{
    long int ISBN;
    long int temp;
    int digit;
    int sum = 0;

    printf("Enter the first twelve digits of ISBN-13: ");
    scanf("%12ld", &ISBN);
    temp = ISBN;

    for(int x = 0; x < 12;x++)
    {
        digit = temp % 10;
        temp = temp / 10;
        if(x % 2 == 0)
        {
            sum += digit * 3;
        }
        else if (x % 2 > 0)
        {
            sum += digit;
        }
    }

    int remainder = sum % 10;
    int answer = 10 - remainder;

    printf("The check digit for ISBN %ld, is %d \n", ISBN, answer);

    return 0;
}