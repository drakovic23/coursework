#include <stdio.h>
#include <assert.h>
#include <string.h>

//Prototypes
void swap_to_front(char str[], char *c);
void swap_to_back(char str[], char *c);
char * select_max(char str[]);
void str_sort(char str[]);

int main(void)
{
    char s1[] = "cat";
    char s2[] = "deni";
    char s3[] = "whoami";
    char s4[] = "neverhookupwhereyouvlookup";
    char s5[] = "s";

    //Asserts for select_max
    assert(select_max(s1) == &s1[2]); //return points to t
    assert(select_max(s2) == &s2[2]); //return points to n
    assert(select_max(s3) == &s3[0]); //return points to w
    assert(select_max(s4) == &s4[16]); //return points to y
    assert(select_max(s5) == &s5[0]);

    //Asserts for str_sort
    str_sort(s1);
    assert(strcmp(s1, "tca") == 0);
    str_sort(s2);
    assert(strcmp(s2, "nied") == 0);
    str_sort(s3);
    assert(strcmp(s3, "womiha") == 0);
    str_sort(s4);
    assert(strcmp(s4, "ywvvuuurrppooooonlkkhheeee") == 0);
    str_sort(s5);
    assert(strcmp(s5, "s") == 0);

    puts("All tests have passed!");
}
// str_sort(str) sorts the characters in a string in descending order
// requires: str points to a valid string that can be modified
void str_sort(char str[])
{
    int i = 0;
    while(str[i])
    {//we only need to sort str + i since any previous chars are sorted
        swap_to_front(str + i,select_max(str + i));
        i++;
    }
}

// select_max(str) returns a pointer to the character of maximal ASCII value
// in the string str (the first if there are duplicates)
// requires: str is a valid string , length(str) >= 1
char * select_max(char str[])
{
    char max = str[0];
    int i = 0;
    int loc = 0;
    while(str[i])
    {
        if(str[i] > max)
        {
            max = str[i];
            loc = i;
        }
        i++;
    }
    return &str[loc];
}

// swap_to_front(str, c) swaps the last character in the string str with the
//  character pointed to by c
// requires: str is a valid string that can be modified, length(str) >= 1
//      c points to a character in str
void swap_to_front(char str[], char *c)
{
    char temp = str[0];
    str[0] = *c;
    *c = temp;
}

// swap_to_back(str, c) swaps the last character in the string str with the
//  character pointed to by c
// requires: str is a valid string that can be modified, length(str) >= 1
//c points to a character in str
void swap_to_back(char str[], char *c)
{
    int i = 0;
    while (str[i + 1] != '\0')
    {
        i++;
    }
    char temp = str[i];
    str[i] = *c;
    *c = temp;
}