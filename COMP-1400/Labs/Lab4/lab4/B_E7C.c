#include <stdio.h>

int main(void)
{
 int num1; 
 int num2;
 int sumAddition;
 int sumSubtraction;
 int sumMultiplication;
 int sumDivision;
 
 printf("Deni Rakovic,\n110081508\n");
 printf("Enter first number: ");
 scanf("%d", &num1);
 printf("Enter second number: ");
 scanf("%d", &num2);

 sumAddition = num1 + num2;
 sumSubtraction = num2 - num1;
 sumMultiplication = num1 * num2;
 sumDivision = num1 / num2;

 puts("-----------------------------------------------------------------");
 puts("|\t\t\t\t\t\t\t\t|");
 printf("|\t\t\t %d + %d = %d\t\t\t\t|\n",num1,num2,sumAddition);
 printf("|\t\t\t %d - %d = %d\t\t\t\t|\n",num1,num2,sumSubtraction);
 printf("|\t\t\t %d * %d = %d\t\t\t\t|\n",num1,num2,sumMultiplication);
 printf("|\t\t\t %d / %d = %d\t\t\t\t|\n",num1,num2,sumDivision);
 puts("|\t\t\t\t\t\t\t\t|");
 puts("-----------------------------------------------------------------");
 
 return 0;
}