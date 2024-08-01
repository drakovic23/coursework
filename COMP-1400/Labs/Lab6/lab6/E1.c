#include <stdio.h>

int main(void)
{
    int userInput;
    int counter = 0;
    int sum = 0;
    int average = 0;

    while(counter < 10)
    {
        puts("Please enter an integer:");
        scanf("%d", &userInput);
        sum += userInput;
        counter++;
    }

    average = sum / 10;

    printf("Sum: %d     Average: %d\n", sum, average);

    return 0;
}