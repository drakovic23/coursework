#include <stdio.h>

int main(void)
{
    int num_1;

    printf("Please enter a number: ");
    scanf("%d", &num_1);

    if(num_1 % 2 == 0)
    {
        printf("%d is a even number\n", num_1);
    }
    else if (num_1 % 2 > 0)
    {
        printf("%d is an odd number\n", num_1);
    }

    return 0;
}