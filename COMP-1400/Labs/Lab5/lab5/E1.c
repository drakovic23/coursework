#include <stdio.h>

int main(void)
{
    int num_1;
    int num_2;

    printf("Please enter two numbers: ");
    scanf("%d %d", &num_1, &num_2);

    printf("Remainder of %d divided by %d is %d\n", num_1, num_2, num_1 % num_2);

    return 0;
}