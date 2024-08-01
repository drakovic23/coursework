#include <stdio.h>

int main(void)
{
    int num;
    int isPrime = 1;

    puts("Please enter an integer: ");
    scanf("%d", &num);

    if(num > 1)
    {
        for(int x=2; x < num;x++)
        {
            if(num % x == 0)
            {
                isPrime = 0;
            }
        }
    }
    
    if(isPrime == 0 || num <= 1){
        printf("%d is a composite number.\n",num);
    }
    else if(isPrime == 1)
    {
        printf("%d is a prime number.\n", num);
    }

    return 0;
}