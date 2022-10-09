#include<stdio.h>
#include<stdlib.h>
struct node
{
    /*int data */
    int data;
    struct node *next;
} *head=NULL;

void insertAtHead(int x)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        temp->next=head;
        head=temp;
    }
}

void insertAtTail(int x){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        struct node *temp1;
        temp1=head;
        while(temp1->next!=NULL)
        {
            temp1=temp1->next;
        }
        temp1->next=temp;
    }
}

void insert(int x,int pos)
{

    // if(pos<0 || pos>tength())
    // {
    //     printf("Invalid index\n");
    //     return;
    // }
    if(pos==1 || head==NULL)
    {
        insertAtHead(x);
        return ;
    }
    struct node *temp;
    temp=(struct node *) malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;
        struct node *temp1;
        temp1=head;
        int i;
        while(temp1->next!=NULL && i<pos-1)
        {
            temp1=temp1->next;
            i++;
        }
        if(temp1->next==NULL)
        {
            insertAtTail(x);
            return;
        }
        else
        {
            temp->next=temp1->next;
            temp1->next=temp;
        }
    
}

void display(){
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void ddisplay(){
    struct node *temp;
    temp=head;
    while(temp->next !=head)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int tength(){
    struct node *temp;
    temp=head;
    int count=0;
    do
    {
        count++;
        temp=temp->next;
    }while(temp!=head);

    return count;
}

void dinsert(int key, int pos){
    struct node *temp;
    temp=head;
    struct node *t;
    int i;
    if(pos<0 || pos> tength())
    {
        printf("Invalid index\n");
        return;
    }

    if (pos==0){
        t= (struct node *) malloc(sizeof(struct node));
        t->data=key;
        if(head==NULL) head=t;
        else{
            while (temp->next!=head)
            {
                temp=temp->next;
            }
            temp->next=t;
            t->next=head;
            head=t;
        }
    }
    else{
        for (i=0;i<pos-1;i++){
            temp=temp->next;
        }
        t= (struct node *) malloc(sizeof(struct node));
        t->data=key;
        t->next=temp->next;
        temp->next=t;
    }
}
int main()
{
dinsert(15,1);
ddisplay();
dinsert(5,2);
ddisplay();
dinsert(10,4);
ddisplay();
dinsert(6,1);
ddisplay();
return 0;
}