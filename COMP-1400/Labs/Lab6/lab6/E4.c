#include <stdio.h>

int main(void)
{
    int num;
    puts("Please enter an integer:");
    scanf("%d", &num);

    for(int x = 1; x <= 10; x++)
    {
        printf("%d X %d = %d\n",num, x, num * x );
    }

    return 0;
}