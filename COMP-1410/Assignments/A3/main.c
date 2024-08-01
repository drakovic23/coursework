#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct slist * create_list();
bool insert_student(int id, char name[], struct slist * lst);
bool remove_student(int id, struct slist * lst);
char * find_student(int id, struct slist * lst);
void free_list(struct slist * lst);
void print(struct slist *head);
void merge_lists(struct slist * out, struct slist * lst1 , struct slist * lst2);
bool is_sorted(struct slist* head);
struct treenode * insert_node(char word[], int value , struct treenode * tree);
int lookup_word(char word[], struct treenode * tree);
void free_tree(struct treenode * tree);

typedef struct snode
{
    int id;
    char * name;
    struct snode * next;
} snode;

typedef struct slist
{
    snode * front;
} slist;

typedef struct treenode
{
    char word[10];
    int value;
    struct treenode * left;
    struct treenode * right;
} treenode;



int main()
{
    slist *new_list = create_list();
    assert(new_list->front == NULL);
    assert(insert_student(100,"Deni",new_list) == true);

    //printf("%s\n", new_list->front->name);
    assert(insert_student(99,"john",new_list) == true);
    //printf("%s\n", new_list->front->name);
    assert(insert_student(100,"asd",new_list) == false); //duplicate id test
    assert(insert_student(102,"Bojack",new_list) == true);
    assert(insert_student(105,"Jhonni",new_list) == true);

    slist *new_list2 = create_list();
    insert_student(106,"Harry",new_list2);
    insert_student(107,"Barry",new_list2);
    insert_student(109,"Rick James", new_list2);

    slist *out_list = create_list();
    merge_lists(out_list,new_list,new_list2);
    assert(is_sorted(out_list) == true);


    print(out_list);


    treenode * root = malloc(sizeof(treenode));
    root->left = NULL;
    root->right = NULL;
    root->value = 0;

    //insert_node("man",5,root);

    char input[100];
    puts("Please enter a sentence: ");
    //fgets(input,100,stdin);
    scanf ("%[^.]%*c", input);

    int x = 1;

    char * token = strtok(input," ");
    while(token)
    {

        if(lookup_word(token,root) > 0)
        {
            printf("%d ",lookup_word(token,root));

        }
        else
        {
            insert_node(token,x,root);
            printf("%s ", token);
            x++;
        }

        token = strtok(NULL, " ");
    }

    return 0;
}

// free_tree(tree) frees all memory associated in the tree with given root node
void free_tree(struct treenode * tree)
{
    if(tree == NULL)
        return;

    free_tree(tree->right);
    free_tree(tree->left);
    free(tree);
}

// lookup_word(word , tree) returns the numeric value associated with the given
// word in the given tree (or 0 if the word does not appear in the tree);
// tree points to the root node or is NULL (denoting an empty tree)
// requires: tree satisfies the ordering property
int lookup_word(char word[], struct treenode * tree)
{
    if(tree == NULL)
        return 0;

    if(strcmp(tree->word,word) == 0)
    {
        return tree->value;
    }

    if(strcmp(tree->word,word) > 0)
        return lookup_word(word,tree->left);
    else
        return lookup_word(word,tree->right);
}

// insert_node(word , value , tree) inserts a new node containing the given word
// and value into the tree with given root (or NULL denoting an empty tree)
// returns the root node of the tree following the insert
// requires: word is not already in the given tree
// tree satisfies the ordering property
struct treenode * insert_node(char word[], int value , struct treenode * tree)
{
    if(strcmp(word,tree->word) < 0)
    {
        if(tree->left != NULL)
            insert_node(word,value,tree->left);
        else
        {
            tree->left = malloc(sizeof(treenode));
            strcpy(tree->left->word,word);
            tree->left->value = value;
            return tree;
        }
    }
    else if(strcmp(word,tree->word) > 0)
    {
        if(tree->right != NULL)
            insert_node(word,value,tree->right);
        else
        {
            tree->right = malloc(sizeof(treenode));
            strcpy(tree->right->word,word);
            tree->right->value = value;
            return tree;
        }
    }
}

bool is_sorted(struct slist* head)
{
    snode *current_node = head->front;

    while(current_node != NULL && current_node->next != NULL)
    {
        if(current_node->id > current_node->next->id)
        {
            return false;
        }
        current_node = current_node->next;
    }
    return true;
}

// merge_lists(out, lst1 , lst2) merges the student records from lst1 and lst2
// into the list out with the students in sorted order;
// lst1 and lst2 are then freed
// requires: out starts as an empty list
void merge_lists(struct slist * out, struct slist * lst1 , struct slist * lst2)
{
    if(lst1->front == NULL && lst2->front == NULL)
        return;

    if(lst1->front->id > lst2->front->id)
    {
        out->front = lst2->front;
        snode *current_node = out->front;

        while(current_node->next != NULL)
        {
            current_node = current_node->next;
        }
        current_node->next = lst1->front;
    }else
    {
        out->front = lst1->front;

        snode *current_node = out->front;
        while(current_node->next != NULL)
        {
            current_node = current_node->next;
        }

        current_node->next = lst2->front;
    }
}

// free_list (lst) deallocates all memory associated with the given list lst
// including the memory used by the student records in the list
void free_list(struct slist * lst)
{
    snode *current_node = lst->front;
    snode *tmp;
    while(current_node != NULL)
    {
        tmp = current_node->next;
        free(current_node->name);
        free(current_node);
        current_node = tmp;
    }

    free(lst);
}

// find_student(id, lst) returns the name of the student with given id in the
// given list lst in a dynamically -allocated string (that the caller must
// free) or NULL if no student has that id
char * find_student(int id, struct slist * lst)
{
    snode *current_node = lst->front;
    while(current_node != NULL)
    {
        if(current_node->id == id)
            return current_node->name;

        current_node = current_node->next;
    }

    return NULL;
}

void print(slist *head) //used to print a list
{
    snode *current_node = head->front;
    while(current_node != NULL)
    {
        printf("%s\n", current_node->name);
        current_node = current_node->next;
    }
}

// remove_student(id, lst) attempts to remove a student with given id from the
// given list and free the memory allocated to that student; true is returned
// if successful and false otherwise
bool remove_student(int id, struct slist * lst)
{
    if(lst->front == NULL)
        return false;

    snode *current_node = lst->front;
    snode *previous_node = NULL;

    if(lst->front->id > id) // id is first node case
    {
        lst->front = lst->front->next;
        free(current_node);
        return true;
    }

    while(current_node != NULL)
    {
        if(current_node->id == id)
        {
            previous_node->next = current_node->next;
            free(current_node);

            return true;
        }
        if(current_node->next != NULL)
            previous_node = current_node;
        current_node = current_node->next;
    }
    return false;
}

// insert_student(id, name , lst) attempts to add a student with given id and
// name into the given list lst; if a student with that id is already in the
// list then return false , otherwise lst is modified and true is returned
bool insert_student(int id, char name[], struct slist * lst) //TODO: Needs to insert sorted
{
    if(lst->front == NULL) //empty list case
    {
        snode *new_node = malloc(sizeof(snode));
        assert(new_node != NULL);
        new_node->id = id;
        new_node->name = strdup(name);
        new_node->next = NULL;
        lst->front = new_node;
        return true;
    }

    if(id < lst->front->id) // id less than head, insert at front
    {
        snode *new_node = malloc(sizeof(snode));
        assert(new_node != NULL);
        new_node->id = id;
        new_node->name = strdup(name);
        new_node->next = lst->front;
        lst->front = new_node;
        return true;
    }

    snode *current_node = lst->front;
    snode *previous_node = NULL;
    while(current_node != NULL)
    {
        if(current_node->id == id)
            return false;
        if(current_node->next != NULL && current_node->next->id == id)
            return false;

        if(current_node->id > id) // id given is less than current node id
        { //need to check if there is previous node, if so insert inbetween, otherwise add to front
            snode *new_node = malloc(sizeof(snode));
            new_node->id = id;
            new_node->name = strdup(name);
            new_node->next = current_node;
            previous_node->next = new_node;
            return true;
        }
        else if(id > current_node->id && current_node->next == NULL)
        {
            snode *new_node = malloc(sizeof(snode));
            new_node->id = id;
            new_node->name = strdup(name);
            new_node->next = NULL;
            current_node->next = new_node;
            return true;
        }
        previous_node = current_node;
        current_node = current_node->next;
    }

    return false;
}
// create_list() returns an empty newly -created list of students
// note: caller must free using free_list
struct slist * create_list()
{
    slist *ret = malloc(sizeof(slist));
    ret->front = NULL;
    return ret;
}