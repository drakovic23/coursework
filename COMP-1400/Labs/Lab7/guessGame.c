/*********************************************
 * Author: Deni Rakovic                      *
 * Date  : November 12, 2021                 *
 * Title : Lab 7                             *
 *********************************************/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    //Create new rand seed
    srand(time(0));
    //Set num to random number
    int num = rand() % 50 + 1;
    int userInput = 0;
    //Counter to keep track of attempts
    int counter = 0;

    //Start while loop and get user input
    while(userInput != num)
    {
        puts("Enter your guess (between 1 and 50)");
        scanf("%d", &userInput);

        //Check that user input is in between 1 and 50
        if(userInput < 1 || userInput > 50)
        {
            while(userInput < 1 || userInput > 50)
            {
                puts("You must enter a guess between 1 and 50, please try again:");
                scanf("%d", &userInput);
            }
        }

        //Check number and output if it's too low, high or correct
        if(userInput < num)
        {
            puts("Too low");
        }
        else if(userInput > num)
        {
            puts("Too high");
        }
        else if(userInput == num)
        {
            printf("Correct, the number was %d\n", num);
        }
        //increment counter so we know # of user attempts
        counter++;

        if(counter == 10)
        {
            //Set userInput to num to break while loop
            userInput = num;
            printf("Sorry, the number was %d\n", num);
        }

    }

    

}