#include <stdio.h>

int main(void)
{
    int year;

    printf("Please enter a number: ");
    scanf("%d", &year);

    if(year % 100 == 0)
    {
        if(year % 400 == 0)
        {
            printf("%d is a leap year\n", year);
        }
        else
        {
            printf("%d is a common year\n", year);
        }
    }else if(year % 4 == 0){
        printf("%d is a leap year\n", year);
    }else{
        printf("%d is a common year\n", year);
    }

    return 0;
}