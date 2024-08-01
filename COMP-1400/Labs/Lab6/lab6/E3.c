#include <stdio.h>

int main(void)
{
    int num;
    puts("Please enter an integer: ");
    scanf("%d", &num);

    for(int x = 0;x < num;x++)
    {
        for(int i = 0; i <= x;i++)
        {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}