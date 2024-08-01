#include <stdio.h>

int main(void)
{
    int num_1, num_2, num_3, max, min;

    printf("Please enter your first number: ");
    scanf("%d", &num_1);    
    printf("Please enter your second number: ");
    scanf("%d", &num_2);
    printf("Please enter your third number: ");
    scanf("%d", &num_3);

    if(num_1 > num_2)
    {
        max = num_1;
        if(num_2 > num_3)
        {
            min = num_3;
        }
        else
        {
            min = num_2;
            if(num_3 > num_1)
            {
                max = num_3;
            }
        }
    }
    else if(num_2 > num_1)
    {
        max=num_2;
        if(num_1 > num_3)
        {
            min = num_3;
        }
        else
        {
            min = num_1;
            if(num_3 > num_2)
            {
                max = num_3;
            }
        }

    }
    else if(num_3 > num_2)
    {
        max=num_3;
        if(num_1 > num_2)
        {
            min = num_2;
        }
        else{
            min = num_1;
            if(num_2 > num_3)
            {
                max = num_2;
            }
            
        }

    }

    printf("The largest number is %d, and the smallest number is %d\n", max, min);

    return 0;
}