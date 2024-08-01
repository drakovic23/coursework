/*********************************************
 * Author: Deni Rakovic                      *
 * Date  : November 19, 2021                 *
 * Title : Lab 9 Part A                      *
 *********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double getAreaCircle(double r);

int main(void)
{
    double radius;
    //Get radius from user
    puts("Please enter in radius: ");
    scanf("%lf", &radius);
    //Print out area
    printf("Area of circle with radius %.2lf is: %.2lf\n", radius, getAreaCircle(radius));
    return 0;
}

double getAreaCircle(double r)
{
    return M_PI * pow(r,2);
}