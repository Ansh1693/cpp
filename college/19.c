// #include <stdio.h>
// #include<stdlib.h>
// #include<malloc.h>
// #include <stdbool.h>

// typedef struct graph_node{
//     int data;
    
//     struct graph_node* next;
// } graph_node;

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int key;
    struct node *left, *right;
};

struct node *newNode(int x)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = x;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(struct node *root)
{
    struct node *temp = root;

    if (temp != NULL)
    {
        inorder(temp->left);
        printf("%d->", temp->key);
        inorder(temp->right);
    }
}
void preorder(struct node *root)
{
    struct node *temp = root;
    if (temp != NULL)
    {
        printf("%d -> ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node *root)
{
    struct node *temp = root;
    if (temp != NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        printf("%d -> ", temp->key);
    }
}

struct node *insert(struct node *node, int key)
{
    if (node == NULL)
    {
        return newNode(key);
    }

    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else
    {
        node->right = insert(node->right, key);
    }

    return node;
}

struct node *minValueNode(struct node *node)
{
    struct node *current = node;

    while ( current->left != NULL)
        current = current->left;

    return current;
}

struct node *deleteNode(struct node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }

    if (key < root->key)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = deleteNode(root->right, key);
    }

    else
    {

        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node *temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
int search(struct node *root, int number)
{
    if (root == NULL)
    {
        return -1;
    }
    else if (number == root->key)
    {
        return root->key;
    }
    else if (number < root->key)
    {
        return search(root->left, number);
    }
    else if (number > root->key)
    {
        return search(root->right, number);
    }
}

int main()
{
    struct node *root = NULL;
    bool on = true;
    while (on)
    {
        printf("\n1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Search\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");
        printf("\n");

        int choice;
        printf("Enter your choice : ");
        scanf("%d", &choice);
        printf("\n");
        if (choice == 5)
        {
            on = false;
            continue;
        }
        switch (choice)
        {
        case 1:
            printf("Enter the key to insert : ");
            int add;
            scanf("%d", &add);
            root = insert(root, add);

            printf("BST traversal:");
            inorder(root);
            // printf('\n');
            break;
        case 2:
            printf("Enter the key to delete : ");
            int del;
            scanf("%d", &del);
            root = deleteNode(root, del);
            printf("Deletion sucessfull\n");
            printf("BST traversal:");
            inorder(root);
            // printf('/n');
            break;
        case 3:
            printf("Enter the key to search : ");
            int ser;
            scanf("%d", &ser);
            int find = -1;

            find = search(root, ser);
            if (find == -1)
            {
                printf("key is not present in tree\n");
            }
            else
            {
                printf("key is present in tree\n");
            }
            break;
        case 4:
            printf("\n1. inorder\n");
            printf("2. preorder\n");
            printf("3. postorder\n");
            int ch;
            printf("Enter your choice : ");
            scanf("%d", &ch);
            if (ch == 1)
            {
                inorder(root);
            }
            else if (ch == 2)
            {
                preorder(root);
            }
            else
            {
                postorder(root);
            }
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
    
}
