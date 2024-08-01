#include <stdio.h> //Standard C library for input/output functions
#include <limits.h> //Defines value limits for various data types like short, char etc
#include <ctype.h> //For functions on characters, mainly used for toupper() in this program
#include <math.h> //For mathemtical operations like pow
#include <float.h>

#define MAX_USER_ARRAY 5 //For variables that user can set
#define MAX_RESULTS_ARRAY 512 //Size of results array
#define UNDEFINED_VALUE FLT_MAX //Undefined value to be used for results array

//Prototypes
void clearInputBuffer(void);
void saveResult(float result);
void printEndMessage();
void printResults();
char getMainMenuInput();
void printMainMenu();
float caseB(float numOne, float numTwo, char operator);
float caseU(float num, char operator);
void caseV(char var, float val);
float caseA(char operationType);
void caseM(int resultNumber);
void caseR();
float getVarByName(char varName);

float results[MAX_RESULTS_ARRAY]; //Global var to store results
char globalChar[MAX_USER_ARRAY] = {'z','z','z','z','z'}; //For var that user can set in option V
float globalNum[MAX_USER_ARRAY];
int storedResults = 0;

int main(void)
{
	char operationType;

    //Set results array to undefined value
    for(int x=0;x < MAX_RESULTS_ARRAY;x++)
    {
        results[x] = UNDEFINED_VALUE;
    }

	//Output welcome message and menu
	puts("Welcome to my Command-Line Calculator (CLC)");
	puts("Developer: Deni Rakovic");
    puts("Version: 3.0");
    puts("Date: November 27, 2021");
	puts("----------------------------------------------------");
	printMainMenu();
    operationType = getMainMenuInput();

	while(toupper(operationType) != 'X')
    {
        if(toupper(operationType) == 'B')
        {
            float numOne, numTwo;
            char operationUsed;
            int inputConverted = 0;
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
            printf("The result is %.2f\n", caseB(numOne,numTwo,operationUsed));

        } //End of option B

        else if(toupper(operationType) == 'U')
        {
            double num;
            char unaryOp;
            int itemsConverted = 0;

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
            printf("The result is: %.2f\n", caseU(num, unaryOp));
        }//End of option U

        else if(toupper(operationType) == 'V')
        {
            float num;
            int itemsConverted = 0;
            char varName;
            //clearInputBuffer();
            puts("Please enter the name of the variable ( A single character between 'A' to 'E' ):");
            itemsConverted = scanf(" %c", &varName);
            while((itemsConverted < 1 && itemsConverted > 1) || toupper(varName) > 'E' )
            {
                puts("Invalid character, please enter a single character between 'A' to 'E': ");
                clearInputBuffer();
                itemsConverted = scanf("%c", &varName);
            }
            
            puts("Please enter a value to assign to the variable: ");
            itemsConverted = scanf("%f", &num);
            while(itemsConverted == 0)
            {
                clearInputBuffer();
                puts("Please enter a valid number: ");
                itemsConverted = scanf("%f", &num);
            }
            caseV(varName, num);
        }//End of option V

        else if(toupper(operationType) == 'A')
        {
            char userSelection = 'z';
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
                
                if(toupper(userSelection) != 'X')
                    printf("The result is: %.2f\n", caseA(userSelection));
            }
        }//End of option A
        else if(toupper(operationType) == 'M')
        {
            if(storedResults == 0)
            {
                puts("There are no stored results in memory!");
            }
            else
            {
                char userChoice = 'z';
                int userInputResult;
                while(toupper(userChoice) != 'X')
                {
                    printf("\nNumber of results stored: %d\n", storedResults);
                    printf("Please enter a number from 0 - %d to view a result or type X to return to main menu:\n", storedResults);
                    if(scanf("%d", &userInputResult))
                    {
                        caseM(userInputResult);
                    }else if(scanf(" %c", &userChoice)){}

                }
            }
        }//End of option M
        else if(toupper(operationType) == 'R')
        {
            caseR();
        }//End of option R

        printMainMenu();
        clearInputBuffer();
        operationType = getMainMenuInput();
        
    }

    printEndMessage();
	return 0;
}

void caseM(int resultNumber)
{
    while(resultNumber > storedResults || resultNumber < 0)
    {
        printf("Please enter a valid input from 0 - %d\n", storedResults);
        clearInputBuffer();
        scanf("%d", &resultNumber);
      
    }
    if(resultNumber == 0)
    {
        printResults();
    }
    else
    {
        printf("Result: %g\n", results[resultNumber - 1]);
    }
    clearInputBuffer();
}

void caseR()
{
    //Set all elements of results array to undefined
    for(int x=0; x < MAX_RESULTS_ARRAY; x++)
    {
        results[x] = UNDEFINED_VALUE;
    }
    storedResults = 0;
    puts("Stored results have been erased from memory");
}

void caseV(char var, float val)
{
    for(int x=0;x < MAX_USER_ARRAY;x++)
    {
        //We check if globalChar[x] == var incase user wants to set existing variable to another value
        if(globalChar[x] == 'z' || globalChar[x] == var)
        {
            globalChar[x] = var;
            globalNum[x] = val;
            printf("The variable %c has been set to %.2f\n", toupper(globalChar[x]), globalNum[x]);
            break;
        }
    }
}
float caseU(float num, char operator)
{
    float returnValue = -1;
    float e = 2.71828;
    //If sqrt is selected and negative number, ask for input again
    if(toupper(operator) == 'S' && num < 0)
    {
        while(num < 0)
        {
            puts("Enter a positive value: ");
            scanf("%f", &num);
        }
    }
    //If log is selected and negative number, ask for input again
    if(toupper(operator) == 'L' && num < 0)
    {
        while(num < 0)
        {
            puts("You cannot calculate the log of a negative, please try again: ");
            scanf("%f", &num);
        }
    }
    switch(toupper(operator))
    {
        case 'S':
            returnValue = sqrt(num);
            saveResult(returnValue);
            break;
        case 'L':
            returnValue = log(num);
            saveResult(returnValue);
            break;
        case 'E':
            returnValue = pow(e,num);
            saveResult(returnValue);
            break;
        case 'C':
            returnValue = ceil(num);
            saveResult(returnValue);
            break;
        case 'F':
            returnValue = floor(num);
            saveResult(returnValue);
            break;
    }

    return returnValue;
}
float caseB(float numOne, float numTwo, char operator)
{

    //Check if division is selected and denominator is 0
    if(operator == '/' && numTwo == 0)
    {
        while(numTwo == 0)
        {
            puts("Denominator cannot be 0, please enter a positive number:");
            scanf("%f", &numTwo);
        }
    }
    float returnValue = -1;
    switch(toupper(operator))
    {
        case '+':
            returnValue = numOne + numTwo;
            saveResult(returnValue);
            break;
        case '-':
            returnValue = numOne - numTwo;
            saveResult(returnValue);
            break;
        case '*':
            returnValue = numOne * numTwo;
            saveResult(returnValue);
            break;
        case '/':
            returnValue = numOne / numTwo;
            saveResult(returnValue);
            break;
        case '%':
            returnValue = (float) ((int)numOne % (int)numTwo);
            saveResult(returnValue);
            break;
        case '^':
            returnValue = pow(numOne,numTwo);
            saveResult(returnValue);
            break;
        default:
            puts("Invalid operation used");
            break;     
    }
    return returnValue;
}

float caseA(char operationType)
{
    float returnValue = -1;
    if(toupper(operationType) == 'B')
    {
        float numOne, numTwo;
        char operationUsed, varName;

        puts("Please enter the first number or a variable name:");  
        if(scanf("%f", &numOne)){

        }
        else{
                scanf(" %c" , &varName);
                //int varExists = 0;

                while(toupper(varName) > 'E')
                {
                    puts("Please enter a variable name from A - E");
                    scanf(" %c", &varName);
                }
                numOne = getVarByName(varName);
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
                numTwo = getVarByName(varName);
            }

            if(numTwo == 0 && operationUsed == '/')
            {
                while(numTwo == 0)
                {
                    puts("Denominator cannot be 0, please enter a positive number or a variable: ");
                    if(scanf("%f", &numTwo)){}
                    else
                    {
                        scanf(" %c" , &varName);
                        numTwo = getVarByName(varName);
                    }
                }
                
            }

        returnValue = caseB(numOne,numTwo,operationUsed);
    }
    if(toupper(operationType) == 'U')
    {
        double num;
        char unaryOp, varName;

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
            num = getVarByName(varName);
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
                        num = getVarByName(varName);
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
                        num = getVarByName(varName);
                    }
            }
        }

        returnValue = caseU(num,unaryOp);      
    }

    return returnValue;
}

float getVarByName(char varName)
{
    //Check that var name exists
    int varExists = 0;
    float returnValue;
    for(int x = 0;x < MAX_USER_ARRAY;x++)
    {
        if(toupper(globalChar[x]) == toupper(varName))
        {
            varExists = 1;
            returnValue = globalNum[x];
        }
    }
    //We return 0 if variable doesn't exist
    if(varExists == 0)
        returnValue = 0;

    return returnValue;
}
void printMainMenu()
{
    puts("Please select one of the following items:");
	puts("B) - Binary Mathematical Operations such as addition and subtraction.");
	puts("U) - Unary Mathematical Operations, such as square root, and log.");
	puts("A) - Advanced Mathematical Operations, using variables, arrays.");
    puts("M) - View stored calculations from memory.");
    puts("R) - Clear Results From Memory");
	puts("V) - Define variables and assign them values.");
	puts("X) - Exit");
}

char getMainMenuInput()
{ 
    char operationType;
    scanf("%c", &operationType);
    while(toupper(operationType) != 'B' && toupper(operationType) != 'U' && toupper(operationType) != 'A' &&
        toupper(operationType) != 'V' && toupper(operationType) != 'X' && toupper(operationType) != 'M' 
        && toupper(operationType) != 'R')
        {
            puts("You must enter one of the following selections: (B , U , A , V , M, R, X)");
            scanf("%c", &operationType);
        }
    return operationType;
}

void clearInputBuffer(void)
{
    int bufferStream = getchar();

    while(bufferStream != '\n' && bufferStream != EOF)
        bufferStream = getchar();
}

//This looks for a "undefined" element in our results array and stores the given value
void saveResult(float result)
{
    for(int x=0;x<MAX_RESULTS_ARRAY;x++)
    {
        if(results[x] == UNDEFINED_VALUE)
        {
            results[x] = result;
            storedResults++;
            break;
        }
    }
}

void printResults()
{
    for(int x=0; x < MAX_RESULTS_ARRAY;x++)
    {
        if(results[x] != UNDEFINED_VALUE)
        {
            printf("Result %d: %g\n", x+1, results[x]);
        }
    }
}

void printEndMessage()
{
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
}