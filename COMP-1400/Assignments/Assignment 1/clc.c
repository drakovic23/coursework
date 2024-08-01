#include <stdio.h> //Standard C library for input/output functions
#include <limits.h> //Defines value limits for various data types like short, char etc.

int main(void)
{
	//Initialize variables for good practice
	char operationType;
	//Declare a variable operationUsed for operation to be used such as +
	//Output welcome message and menu
	puts("Welcome to my Command-Line Calculator (CLC)\n");
	puts("Developer: Deni Rakovic\n");
        puts("Version: 1\n");
        puts("Date: October 9, 2021\n");
	puts("----------------------------------------------------\n");
	puts("Please select one of the following items:\n");
	puts("B) - Binary Mathematical Operations such as addition and subtraction.\n");
	puts("U) - Unary Mathetmical Operations, such as square root, and log.\n");
	puts("A) - Advances Mathetmical Operations, using variables, arrays.\n");
	puts("V) - Define variables and assign them values.\n");
	puts("X) - Exit\n");

	//Start loop here on condition user input != x
	//Get selection from user
	scanf("%c", &operationType);
	printf("You have selected %c \n", operationType);
	//If user enters B then
		//Declare two integers, firstNum and secondNum
		//Get input for first number
		//Display message with possible operations (=, - etc)
		//Get input from user for operation to use (+, - etc)
		//Get input for second number
		//If operationUsed == +
		//Perform addition

		//else if operationUsed == -
		//Perform subtraction
		
		//else if operationUsed == *
		//Perform multiplication

		//else if operationUsed == /
		//Perform division

		//else if operationUsed == %
		//Perform mod
		
		//else if operationUsed == ^
		//Calculate exponentiation of firstNum to secondNum

		//else
		//output message to notify user to enter an appropriate operation symbol
	//else
	//display message we don't have enough knowledge yet to perform that operation
	return 0;
}
