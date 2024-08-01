#include <stdio.h>

int main(void)
{
 int num1; 
 int num2;
 int sum;
 
 printf("Deni Rakovic,\n110081508\n");
 printf("Enter first number: ");
 scanf("%d", &num1);
 printf("Enter second number: ");
 scanf("%d", &num2);
 sum = num1 + num2;

 puts("-----------------------------------------------------------------");
 puts("|\t\t\t\t\t\t\t\t|");
 printf("|\t\t\t %d + %d = %d\t\t\t\t|\n",num1,num2,sum);
 puts("|\t\t\t\t\t\t\t\t|");
 puts("-----------------------------------------------------------------");
 
 return 0;
}