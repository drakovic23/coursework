#include <stdio.h>

int main(void)
{
    int dayNum;
    puts("Please enter day number in integer: ");
    scanf("%d", &dayNum);

    switch(dayNum)
    {
        case 1:
            puts("Monday");
            break;
        case 2:
            puts("Tuesday");
            break;
        case 3:
            puts("Wednesday");
            break;
        case 4:
            puts("Thursday");
            break;
        case 5:
            puts("Friday");
            break;
        case 6:
            puts("Saturday");
            break;
        case 7:
            puts("Sunday");
            break;
        
        default:
            puts("Invalid day number");
            break;
    }

    return 0;
}