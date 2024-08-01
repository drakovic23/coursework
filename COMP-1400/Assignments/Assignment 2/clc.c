#include <stdio.h> //Standard C library for input/output functions
#include <limits.h> //Defines value limits for various data types like short, char etc
#include <ctype.h> //For functions on characters, mainly used for toupper() in this program
#include <math.h> //For mathemtical operations like pow

#define MAX_USER_ARRAY 5 //For variables that user can set

//To clear the input buffer since fflush(stdin) is undefined behaviour
//because it's meant to flush output stream
void clearInputBuffer(void)
{
    int bufferStream = getchar();

    while(bufferStream != '\n' && bufferStream != EOF)
        bufferStream = getchar();
}
int main(void)
{
	char operationType;
	char globalChar[MAX_USER_ARRAY] = {'z','z','z','z','z'}; //For var that user can set in option V
    float globalNum[MAX_USER_ARRAY];
	//Output welcome message and menu
	puts("Welcome to my Command-Line Calculator (CLC)");
	puts("Developer: Deni Rakovic");
    puts("Version: 2");
    puts("Date: November 12, 2021");
	puts("----------------------------------------------------");
	puts("Please select one of the following items:");
	puts("B) - Binary Mathematical Operations such as addition and subtraction.");
	puts("U) - Unary Mathematical Operations, such as square root, and log.");
	puts("A) - Advanced Mathematical Operations, using variables, arrays.");
	puts("V) - Define variables and assign them values.");
	puts("X) - Exit");

	scanf("%c", &operationType);
    while(toupper(operationType) != 'B' && toupper(operationType) != 'U' && toupper(operationType) != 'A' &&
        toupper(operationType) != 'V' && toupper(operationType) != 'X')
        {
            puts("You must enter one of the following selections: (B , U , A , V , X)");
            scanf(" %c", &operationType);
        }

	while(toupper(operationType) != 'X')
    {
        if(toupper(operationType) == 'B')
        {
            float numOne, numTwo;
            char operationUsed;
            int inputConverted = 0;

            //Get number and operation to use
            puts("Please enter the first number:");
            //scanf will return the # of successfully converted items
            inputConverted = scanf("%f", &numOne);
            //If no successfully converted items, ask user to renter
            if(inputConverted == 0)
            {
                while(inputConverted < 1)
                {
                    clearInputBuffer();
                    puts("Invalid input, please enter a number:");
                    inputConverted = scanf("%f", &numOne);
                }
            }

            //Get operation to use
            puts("Please enter the operation ( +, - , * , / , %, ^ )");
            scanf(" %c", &operationUsed);
            //Check user input
            while(operationUsed != '+' && operationUsed != '-' && operationUsed != '*' && operationUsed != '/' &&
                operationUsed != '%' && operationUsed != '^')
                {
                    clearInputBuffer();
                    puts("Please enter one of the following: ( + , - , * , / , % , ^ )");
                    scanf(" %c", &operationUsed);
                }

            //Similar to getting num one
            puts("Please enter the second number:");
            inputConverted = scanf("%f", &numTwo);
            //If user entered in something other than number, ask for input again
            if(inputConverted == 0)
            {
                while(inputConverted < 1)
                {
                    clearInputBuffer();
                    puts("Invalid input, please enter a number:");
                    inputConverted = scanf("%f", &numTwo);
                }
            }

            //Check if division is selected and denominator is 0
            if(operationUsed == '/' && numTwo == 0)
            {
                while(numTwo == 0)
                {
                    puts("Denominator cannot be 0, please enter a positive number:");
                    scanf("%f", &numTwo);
                }
            }


            switch(operationUsed)
            {
                case '+':
                    printf("The result is %.2f\n", numOne + numTwo);
                    break;
                case '-':
                    printf("The result is %.2f\n", numOne - numTwo);
                    break;
                case '*':
                    printf("The result is %.2f\n", numOne * numTwo);
                    break;
                case '/':
                    printf("The result is %.2f\n", numOne / numTwo);
                    break;
                case '%':
                    printf("The result is %d\n", (int)numOne % (int)numTwo);
                    break;
                case '^':
                    printf("The result is %.2f\n", pow(numOne,numTwo));
                    break;
                default:
                    puts("Invalid operation used");
                    break;     
            }

        } //End of option B

        else if(toupper(operationType) == 'U')
        {
            double num;
            char unaryOp;
            int itemsConverted = 0;
            double e = 2.71828;


            puts("Please select a unary operator (S , L , E , C , F)");
            scanf(" %c", &unaryOp);
            while(toupper(unaryOp) != 'S' && toupper(unaryOp) != 'L' && toupper(unaryOp) != 'E' && 
                toupper(unaryOp) != 'C' && toupper(unaryOp) != 'F')
            {
                clearInputBuffer();
                puts("Invalid input, please try again (S , L , E , C , F)");
                scanf(" %c", &unaryOp);
            }

            //Get first number
            puts("Please enter the first number:");
            itemsConverted = scanf("%lf", &num);
            //If no items converted by scanf then ask user for input again
            while(itemsConverted < 1)
            {
                clearInputBuffer();
                puts("Invalid number, please try again: ");
                itemsConverted = scanf("%lf", &num);
            }

            //If sqrt is selected and negative number, ask for input again
            if(toupper(unaryOp) == 'S' && num < 0)
            {
                while(num < 0)
                {
                    puts("Enter a positive value: ");
                    scanf("%lf", &num);
                }
            }
            //If log is selected and negative number, ask for input again
            if(toupper(unaryOp) == 'L' && num < 0)
            {
                while(num < 0)
                {
                    puts("You cannot calculate the log of a negative, please try again: ");
                    scanf("%lf", &num);
                }
            }

            switch(toupper(unaryOp))
            {
                case 'S':
                    printf("The result is %.2lf\n" , sqrt(num));
                    break;
                case 'L':
                    printf("The result is %.2lf\n", log(num));
                    break;
                case 'E':
                    printf("The result is %g\n", pow(e,num));
                    break;
                case 'C':
                    printf("The result is %.2lf\n",  ceil(num));
                    break;
                case 'F':
                    printf("The result is %.2lf\n",  floor(num));
                    break;
            }

        }//End of option U

        else if(toupper(operationType) == 'V')
        {
            float num;
            int itemsConverted = 0;
            char varName;
            clearInputBuffer();
            puts("Please enter the name of the variable ( A single character between 'a' to 'e' ):");
            itemsConverted = scanf("%c", &varName);
            while((itemsConverted < 1 && itemsConverted > 1) || toupper(varName) > 'E')
            {
                puts("Invalid character, please enter a single character such as 'A' from A - E");
                clearInputBuffer();
                scanf("%c", &varName);
            }
            
            puts("Please enter a value to assign to the variable: ");
            itemsConverted = scanf("%f", &num);
            while(itemsConverted < 1)
            {
                clearInputBuffer();
                puts("Please enter a valid number: ");
                scanf("%f", &num);
            }

            for(int x=0;x < MAX_USER_ARRAY;x++)
            {
                if(globalChar[x] == 'z')
                {
                    globalChar[x] = varName;
                    globalNum[x] = num;
                    printf("The variable %c has been set to %.2f\n", globalChar[x], globalNum[x]);
                    break;
                }
            }
            
        }//End of option V

        else if(toupper(operationType) == 'A')
        {
            char userSelection;
            int inputConverted = 0;
            while(toupper(userSelection) != 'X')
            {
            puts("Please enter one of the following items: ( B , U , X )");
            puts("B) - Binary Mathematical Operations, such as addition and subtraction.");
            puts("U) - Unary Mathematical Operation, such as square root, and log");
            puts("X) - Exit and back to the main menu");

            inputConverted = scanf(" %c", &userSelection);
            while(inputConverted < 1 || (toupper(userSelection) != 'B' && toupper(userSelection) != 'U' && toupper(userSelection) != 'X'))
            {
                puts("Invalid input, please enter ( B , U , X )");
                clearInputBuffer();
                inputConverted = scanf(" %c", &userSelection);
            }

            if(toupper(userSelection) == 'B')
            {
                float numOne, numTwo;
                char operationUsed, varName;
                //Get number and operation to use
                puts("Please enter the first number or a variable name:");
                
                if(scanf("%f", &numOne)){

                }
                else{
                    scanf(" %c" , &varName);
                    int varExists = 0;

                    while(toupper(varName) > 'E')
                    {
                        puts("Please enter a variable name from A - E");
                        scanf(" %c", &varName);
                    }
                    //Check that var name exists
                    for(int x = 0;x < MAX_USER_ARRAY;x++)
                    {
                        if(toupper(globalChar[x]) == toupper(varName))
                        {
                            varExists = 1;
                            numOne = globalNum[x];
                        }
                    }
                    if(varExists == 0)
                        numOne = 0;
                }

                //Get operation to use
                puts("Please enter the operation ( +, - , * , / , %, ^ )");
                scanf(" %c", &operationUsed);
                //Check user input
                while(operationUsed != '+' && operationUsed != '-' && operationUsed != '*' && operationUsed != '/' &&
                    operationUsed != '%' && operationUsed != '^')
                    {
                        clearInputBuffer();
                        puts("Please enter one of the following: ( + , - , * , / , % , ^ )");
                        scanf(" %c", &operationUsed);
                    }

                    puts("Please enter the second number:");

                    if(scanf("%f", &numTwo)){}
                    else
                    {
                        scanf(" %c" , &varName);
                        int varExists = 0;
                        //Check that var name exists
                        for(int x = 0;x < MAX_USER_ARRAY;x++)
                        {
                            if(toupper(globalChar[x]) == toupper(varName))
                            {
                                varExists = 1;
                                numTwo = globalNum[x];
                            }
                        }
                        if(varExists == 0)
                            numTwo = 0;
                    }

                //Check if division is selected and denominator is 0
                if(operationUsed == '/' && numTwo == 0)
                {
                    while(numTwo == 0)
                    {
                        puts("Denominator cannot be 0 please enter a positive value or variable name:");
                        if(scanf("%f", &numTwo)){}
                        else{
                            scanf("%c", &varName);
                            int varExists = 0;
                            for(int x=0;x < MAX_USER_ARRAY;x++)
                            {
                                if(toupper(globalChar[x]) == toupper(varName))
                                {
                                    varExists = 1;
                                    numTwo = globalNum[x];
                                }
                            }
                            if(varExists == 0)
                                numTwo = 0;
                        }
                    }
                }

                switch(operationUsed)
                {
                    case '+':
                        printf("The result is %.2f\n", numOne + numTwo);
                        break;
                    case '-':
                        printf("The result is %.2f\n", numOne - numTwo);
                        break;
                    case '*':
                        printf("The result is %.2f\n", numOne * numTwo);
                        break;
                    case '/':
                        printf("The result is %.2f\n", numOne / numTwo);
                        break;
                    case '%':
                        printf("The result is %d\n", (int)numOne % (int)numTwo);
                        break;
                    case '^':
                        printf("The result is %.2f\n", pow(numOne,numTwo));
                        break;
                    default:
                        puts("Invalid operation used");
                        break;     
                }
            }
            if(toupper(userSelection) == 'U')
            {
                double num;
                char unaryOp, varName;
                double e = 2.71828;

                puts("Please select a unary operator (S , L , E , C , F)");
                scanf(" %c", &unaryOp);
                while(toupper(unaryOp) != 'S' && toupper(unaryOp) != 'L' && toupper(unaryOp) != 'E' && 
                    toupper(unaryOp) != 'C' && toupper(unaryOp) != 'F')
                {
                    clearInputBuffer();
                    puts("Invalid input, please try again (S , L , E , C , F)");
                    scanf(" %c", &unaryOp);
                }

                //Get first number
                puts("Please enter a number or a variable name:");
                if(scanf("%lf", &num)){

                }
                else{
                    scanf(" %c" , &varName);
                    while(toupper(varName) > 'E')
                    {
                        puts("Please enter a variable name from A - E");
                        scanf(" %c", &varName);
                    }
                    int varExists = 0;
                    //Check that var name exists
                    for(int x = 0;x < MAX_USER_ARRAY;x++)
                    {
                        if(toupper(globalChar[x]) == toupper(varName))
                        {
                            varExists = 1;
                            num = globalNum[x];
                        }
                    }
                    if(varExists == 0)
                        num = 0;
                }

                //If sqrt is selected and negative number, ask for input again
                if(toupper(unaryOp) == 'S' && num < 0)
                {
                    while(num < 0)
                    {
                        puts("Please enter a positive value or variable name: ");
                            if(scanf("%lf", &num)){}
                            else{
                                scanf(" %c" , &varName);
                                while(toupper(varName) > 'E')
                                {
                                    puts("Please enter a variable name from A - E");
                                    scanf(" %c" , &varName);
                                }
                                int varExists = 0;
                                //Check that var name exists
                                for(int x = 0;x < MAX_USER_ARRAY;x++)
                                {
                                    if(toupper(globalChar[x]) == toupper(varName))
                                    {
                                        varExists = 1;
                                        num = globalNum[x];
                                    }
                                }
                                if(varExists == 0)
                                    num = 0;
                            }
                    }
                }
                //If log is selected and negative number, ask for input again
                if(toupper(unaryOp) == 'L' && num < 0)
                {
                    while(num < 0)
                    {
                        puts("Please enter a positive number or variable name for the log function:");
                            if(scanf("%lf", &num)){}
                            else{
                                scanf(" %c" , &varName);

                                while(toupper(varName) > 'E')
                                {
                                    puts("Please enter a variable name from A - E");
                                    scanf(" %c" , &varName);
                                }

                                int varExists = 0;
                                //Check that var name exists
                                for(int x = 0;x < MAX_USER_ARRAY;x++)
                                {
                                    if(toupper(globalChar[x]) == toupper(varName))
                                    {
                                        varExists = 1;
                                        num = globalNum[x];
                                    }
                                }
                                if(varExists == 0)
                                    num = 0;
                            }
                    }
                }

                switch(toupper(unaryOp))
                {
                    case 'S':
                        printf("The result is %.2lf\n" , sqrt(num));
                        break;
                    case 'L':
                        printf("The result is %.2lf\n", log(num));
                        break;
                    case 'E':
                        printf("The result is %g\n", pow(e,num));
                        break;
                    case 'C':
                        printf("The result is %.2lf\n",  ceil(num));
                        break;
                    case 'F':
                        printf("The result is %.2lf\n",  floor(num));
                        break;
                }
                
            }


            }
        }//End of option A

        //Main menu
        puts("Please select your option ( B (Binary operation), U (Unary operation) , A (Advanced), V (Variables), X (Exit))");
        scanf(" %c", &operationType);
        while(toupper(operationType) != 'B' && toupper(operationType) != 'U' && toupper(operationType) != 'A' &&
            toupper(operationType) != 'V' && toupper(operationType) != 'X')
            {
                puts("You must enter one of the following selections: (B , U , A , V , X)");
                scanf(" %c", &operationType);
            }
        
    }

    //End message
    puts("      _.-'''''-._");
    puts("    .'  _     _  '.");
    puts("   /   (_)   (_)   \\");
    puts("  |  ,           ,  |");
    puts("  |  \\`.       .`/  |");
    puts("   \\  '.`'\"\"'\"`.'  /");
    puts("    '.  `'---'`  .'");
    puts("      '-._____.-'");
    puts("Thanks for using my calculator. Goodbye!");

	return 0;
}
