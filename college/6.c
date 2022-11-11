

#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void ins(); // start
void inp(); // posi
void ine(); // end
void prr(); // print
void count(); //count
void rev(); //reverse

int main(){
    bool n = true;
    while (n)
    {
        char x;
        printf("\nEnter the operation you want to perform on ll\n1. Insert at begining\n2. Inset at end\n3. Insert at a position\n4. Print all the elements in ll\n5. Count No. of Nodes\n6. Reverse Linked list\n 7. Exit\n");
        scanf("%c", &x);
        fflush(stdin);
        switch (x)
        {
        case '1':
            ins();
            break;
        case '2':
            ine();
            break;
        case '3':
            inp();
            break;
        case '4':
            prr();
            break;
        case '5':
            count();
            break;
        case '6':
            rev();
            break;
        case '7':
            n = false;
            printf("You have exited successfully");
            break;
        default:
            printf("Entered input is invalid");
            break;
        }
    }

    return 0;
}

void ins()
{
    int key;
    printf("Enter data you want to input\n");
    scanf("%d", &key);
    fflush(stdin);
    struct node *curr = (struct node *)malloc(sizeof(struct node));
    curr->data = key;
    curr->next = head;
    head = curr;
    prr();
}
void inp()
{
    if (head == NULL)
    {
        ins();
        return;
    }
    int key, posi;
    printf("\nEnter data you want to input\n");
    scanf("%d", &key);
    fflush(stdin);

    prr();
    printf("\nEnter position where after which  you want to input\n");
    scanf("%d", &posi);
    fflush(stdin);
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = key;
    struct node *curr = head;
    if (head == NULL)
    {
        printf("LL is empty so inserting in begin\n");
        ins();
        return;
    }
    while (curr != NULL && curr->data != posi)
    {
        curr = curr->next;
    }
    if (curr == NULL)
    {
        printf("Entered position is not present in LL\n");
        return;
    }
    temp->next = curr->next;
    curr->next = temp;
}
void ine()
{
    if (head == NULL)
    {
        ins();
        return;
    }
    int key;
    printf("\nEnter data you want to input\n");
    scanf("%d", &key);
    fflush(stdin);
    struct node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = key;
	temp->next = NULL;
    curr->next = temp;
    prr();
}
void prr()
{
    if (head == NULL)
    {
        printf("\nSingular LL is empty!\n");
        return;
    }

    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
void count(){
    if(head==NULL){
        printf("\nLL is empty\n");
        return;
    }
    int i = 0;
    struct node *curr = head;
    while(curr!=NULL){
        i++;
        curr = curr->next;
    }
    printf("\nNO. of elements in ll are : %d \n", i);
}
void rev(){
    if(head ==NULL){
        printf("\nLL is empt\n");
        return;
    }
    if(head->next==NULL){
        prr();
        return;
    }
    struct node *curr = head;
    struct node *prev = NULL;
    while(curr!=NULL){
        struct node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    prr();
}