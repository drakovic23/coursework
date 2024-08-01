#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

struct strnode * create_node(char str[], struct strnode * next);
struct strnode * free_node(struct strnode * node);
void concat_nodes(struct strnode * head , char * str);

typedef struct strnode
{
    char str[5];
    struct strnode * next;
} strnode;

int main()
{

    strnode* C=create_node("sea",NULL);
    strnode* B=create_node("bee",C);
    strnode* A=create_node("Ayy",B);

    assert(C->next==NULL);
    assert(B->next==C);
    assert(A->next==B);

    assert(strcmp(A->str,"Ayy")==0);

    assert(free_node(A)==B);
    assert(free_node(B)==C);
    assert(free_node(C)==NULL);


    //concat_node asserts
    char str1[50];
    char str2[50];
    char str3[50] = "";

    strnode *node1 = create_node("Game", NULL);
    strnode *node2 = create_node("a", node1);
    strnode *node3 = create_node("Play", node2);
    strnode *node4 = create_node("Lets", node3);

    concat_nodes(node4,str1);
    assert(strcmp(str1,"Lets Play a Game") == 0);

    strnode *node5 = create_node("NoNext",NULL);
    concat_nodes(node5,str2);
    assert(strcmp(str2,"NoNext") == 0);

    strnode *node6 = NULL;
    concat_nodes(node6,str3);
    assert(strcmp(str3,"") == 0);

    //free our nodes
    strnode *free_me = node4;
    while(free_me != NULL)
    {
        free_me = free_node(free_me);
    }
    free_node(node5);

    //A - Z
    char first_letter = 'A';
    strnode *head = NULL;
    strnode *temp = NULL;
    strnode *current_node = NULL;

    for(int x = 0; x < 26; x++)
    {
        current_node = create_node(&first_letter, NULL);

        if(x == 0)
        {
            temp = current_node;
            head = temp;
        }
        else
        {
            temp->next = current_node;
            temp = current_node;
        }
        first_letter++;
    }

    char ret[30];
    concat_nodes(head,ret);
    assert(strcmp(ret,"A B C D E F G H I J K L M N O P Q R S T U V W X Y Z") == 0);

    //free nodes used for A-Z
    free_me = head;
    while(free_me != NULL)
    {
        free_me = free_node(free_me); //FREEDOM!
    }

    puts("All tests passed");
}


void concat_nodes(struct strnode * head , char * str)
{
    if(head == NULL)
        return;

    strnode * current_node = head;
    unsigned int len = strlen(current_node->str);

    strcpy(str,current_node->str);

    if(current_node->next == NULL)
        return;

    strcpy(&str[len], " "); // add space
    len++;// inc len for added space
    current_node = current_node->next;
    while(1)
    {
        strcpy(&str[len],current_node->str);
        len += strlen(current_node->str);

        if(current_node->next == NULL)
        {
            break;
        }

        strcpy(&str[len], " ");
        len++;

        current_node = current_node->next;
    }
}

// create_node(str, next) creates a strnode containing the string str
//  and given next pointer; caller must free allocated memory using free_node
// requires: str has length at most 4
//      next is NULL or points to a strnode
// note: returns NULL if memory cannot be allocated
struct strnode * create_node(char str[], struct strnode * next)
{
    struct strnode * new_node= malloc(sizeof(struct strnode));

    if(new_node==NULL)
    {
        return NULL;
    }

    strcpy(new_node->str,str);
    new_node->next = next;

    return new_node;
    //O(1)
}

// free_node(node) frees the memory associated with the given node; returns a
//  pointer to the next node in the list previously headed by the given node
// requires: node is a valid strnode allocated dynamically
struct strnode * free_node(struct strnode * node)
{
    //O(1)
    struct strnode * nextnode = node->next;
    free(node);

    return nextnode;
}