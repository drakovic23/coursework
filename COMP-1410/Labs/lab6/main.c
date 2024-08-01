#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

//prototypes
struct student * create_student(int id, char * name);
bool change_name(struct student * s, char * new_name);
void free_student(struct student * s);

typedef struct student
{
    int id;
    char * name;
} student;

int main()
{

    student *s1 = create_student(10342,"Agent Smith");
    student *s2 = create_student(110081508,"Deni");
    student *s3 = create_student(234, "Morpheus");
    //create_student asserts
    assert(strcmp(s1->name,"Agent Smith") == 0 && s1->id == 10342);
    assert(strcmp(s2->name,"Deni") == 0 && s2->id == 110081508);
    assert(strcmp(s3->name,"Morpheus") == 0 && s3->id == 234);

    //change_name function call
    change_name(s1,"Neo");
    change_name(s2,"Spoon Boy");
    change_name(s3, "Trinity");
    //assert for change_name
    assert(strcmp(s1->name,"Neo") == 0);
    assert(strcmp(s2->name, "Spoon Boy") == 0);
    assert(strcmp(s3->name, "Trinity") == 0);


    //free memory
    free_student(s1);
    free_student(s2);
    free_student(s3);

    return 0;
}

// create_student(id, name) creates a new student record with given id and name;
// allocates memory to store structure and name (must free with free_student)
// and returns NULL if memory allocation fails
// requires: name points to a valid string
struct student * create_student(int id, char * name)
{
    student *ret = malloc(sizeof(student));
    if(ret == NULL)
        return NULL;

    ret->name = malloc(strlen(name) * sizeof(char));
    if(ret->name == NULL)
    {
        free(ret);
        return NULL;
    }

    ret->id = id;
    ret->name = name;

    return ret;
}

// change_name(s, new_name) renames the student s to have the name given by
// new_name; allocates memory to hold new_name (caller must free)
// returns true when the name was successfully changed
// requires: s points to a valid student and new_name points to a valid string
bool change_name(struct student * s, char * new_name)
{
    free(s->name);
    s->name = malloc(strlen(new_name) * sizeof(char));
    if(s->name == NULL)
    {
        free(s->name);
        return false;
    }

    s->name = new_name;
    return true;
}

// free_student(s) frees the memory associated with the student record s
// requires: s is a student record created using dynamic memory allocation
void free_student(struct student * s)
{
    free(s->name);
    free(s);
}

