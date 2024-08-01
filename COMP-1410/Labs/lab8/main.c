#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

struct node * create_node(char str[], struct node * left, struct node * right);
void free_tree(struct node * root);
void print_tree(struct node * root);
int height(struct node * root);
int concat_leaves(struct node * root, char * str);

typedef struct node
{
    char str[10];
    struct node * left;
    struct node * right;

} node;

int main(void)
{
    node * meat = create_node("meat", NULL, NULL);
    node * apple = create_node("apple", NULL, NULL);
    node * pear = create_node("pear", NULL, NULL);
    node * fruit = create_node("fruit", apple, pear);
    node * food = create_node("food", meat, fruit);

    assert(strcmp(meat->str, "meat") == 0);
    assert(meat->left == NULL);
    assert(meat->right == NULL);

    //assert for concat_leaves
    node *node_h = create_node("endme", NULL,NULL);
    node *node_g = create_node("G",node_h,NULL);
    node *node_d = create_node("D",NULL,node_g);
    node *node_e = create_node("EEEEE", NULL,NULL);
    node *node_b = create_node("B",node_e,NULL);
    node *node_root = create_node("A",node_b,node_d);
    char ret[100] = "";
    assert(concat_leaves(node_root,ret) == 10 && strcmp(ret,"EEEEEendme") == 0);

    char ret_2[100] = "";
    node *null_root = NULL;
    assert(concat_leaves(null_root,ret_2) == 0 && strcmp("",ret_2) == 0);

    char ret_3[100] = "";
    node *node_root2 = create_node("Beef", NULL ,NULL);
    assert(concat_leaves(node_root2,ret_3) == 4 && strcmp(ret_3,"Beef") == 0);

    char ret_4[100] = "";
    assert(concat_leaves(food,ret_4) == 13 && strcmp(ret_4,"meatapplepear") == 0);
    //assert for height using all above nodes
    assert(height(node_root) == 4);
    assert(height(null_root) == 0);
    assert(height(node_root2) == 1);
    assert(height(food) == 3);

    free_tree(node_root);
    free_tree(node_root2);
    free_tree(food);

    puts("All tests have passed");
}

// height(root) returns the height of the tree with given root
// requires: root is NULL or points to a valid tree root node
int height(struct node * root)
{
    if(root == NULL)
        return 0;

    int left_count = height(root->left);
    int right_count = height(root->right);

    return (left_count>right_count ? left_count : right_count) + 1;
}

// concat_leaves(root , str) modifies str to be a string concatenation of the
// leaf nodes of the tree with given root using an in-order traversal;
// returns the length of the concatenated string
// requires: str points to enough memory to store the output string
// root is NULL or points to a valid tree root node
int concat_leaves(struct node * root , char * str)
{
    if(root == NULL)
    {
        return 0;
    }

    if(root->left == NULL && root->right == NULL)
    {
        while(*str)
        {
            //printf("%c\n", *str);
            str++;
        }
        strcpy(str,root->str);
        return (int) strlen(root->str);
    }

    while(*str)
    {
        //printf("%c\n", *str);
        str++;
    }
    return concat_leaves(root->left,str) + concat_leaves(root->right,str);
}
// create_node(str, left , right) creates and returns a tree node containing
// given str and left/right pointers; caller must free allocated memory
// requires: left , right are NULL or point to tree nodes
// note: returns NULL if memory cannot be allocated
struct node * create_node(char str[], struct node * left, struct node * right)
{
    node * new_node = malloc(sizeof(struct node));

    if (new_node == NULL)
    {
        return NULL;
    }

    strcpy(new_node->str, str);
    new_node->left = left;
    new_node->right = right;

    return new_node;
}


// free_tree(root) frees the memory associated with the given root node and
// all of the node's children
// requires: root is NULL or the root of a tree allocated dynamically
void free_tree(struct node * root)
{
    if (root == NULL)
    {
        return;
    }

    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

// print_tree(root) prints the contents of the tree using an in-order traversal
// requires: root is NULL or points to a valid tree root node
void print_tree(struct node * root)
{
    if (root == NULL)
    {
        return;
    }

    print_tree(root->left);
    printf("%s\n", root->str);
    print_tree(root->right);
}