#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

typedef struct student
{
    int id;
    char name[20];
} student;

bool find_id(int id, struct student arr[], int n, char * found_name);
int find_name(char * name , struct student arr[], int n, int ids[]);
void change_name(struct student * s, char * new_name);

int main()
{
    student student_array[5] = {
            {110081508,"Deni"},
            {394,"Boris"},
            {123,"Bojack"},
            {4123,"Bojack"},
            {73215,"Homer"}
    };
    char found_name[20];

    //assert find_id
    assert(find_id(4123,student_array,5,found_name) == true && strcmp(found_name,"Bojack") == 0);
    assert(find_id(110081508,student_array,5,found_name) == true && strcmp(found_name,"Deni") == 0);
    assert(find_id(11111,student_array,5,found_name) == false);
    assert(find_id(73215,student_array,5,found_name) == true && strcmp(found_name, "Homer") == 0);
    //assert find_name
    int ids[5];
    assert(find_name("Deni",student_array,5,ids) == 1 && ids[0] == 110081508);
    assert(find_name("Homer",student_array,5,ids) == 1 && ids[0] == 73215);
    assert(find_name("No",student_array,5,ids) == false);
    assert(find_name("Bojac",student_array,5,ids) == false);
    assert(find_name("Bojack",student_array,5,ids) == 2 && ids[0] == 123 && ids[1] == 4123);
    //assert change_name
    student s1 = {123,"John"};

    change_name(&s1,"Rick");
    assert(strcmp(s1.name,"Rick") == 0);
    change_name(&s1,"James");
    assert(strcmp(s1.name,"James") == 0);
    change_name(&s1, ""); //0 chars
    assert(strcmp(s1.name,"") == 0);
    change_name(&s1, "onetwothreefourfives"); //19 chars
    assert(strcmp(s1.name,"onetwothreefourfives") == 0);

    puts("All tests have passed.");

    return 0;
}
// change_name(s, new_name) renames the student s to have the name given by
// new_name
// requires: s points to a valid student that can be modified
// new_name points to a valid string of length at most 19
void change_name(struct student * s, char * new_name)
{
    strcpy(s->name, new_name);
}
// find_name(name , arr, n, ids) searches for student(s) with given name in arr;
// returns the number of students found and the array ids is updated to
// contain the id numbers of those students
// requires: arr has length n
// students in arr have unique ids
// ids points to enough memory to hold the found student ids
int find_name(char * name , struct student arr[], int n, int ids[])
{
    int student_count = 0;
    for(int i = 0;i < n;i++)
    {
        if(strcmp(name,arr[i].name) == 0) //since name has an upper bound we can use strcmp and still achieve O(n)
        {
            ids[student_count] = arr[i].id;
            student_count++;
        }
    }

    return student_count;
}
// find_id(id, arr, n, found_name) searches for a student with given id in arr;
// returns true if such a student is found and found_name is updated to
// hold the student's name; otherwise returns false
// requires: arr has length n
// students in arr have unique ids
// found_name points to enough memory to hold a name
bool find_id(int id, struct student arr[], int n, char * found_name)
{
    for(int i = 0; i < n;i++)
    {
        if(arr[i].id == id)
        {
            strcpy(found_name,arr[i].name);
            return true;
        }
    }

    return false;
}
