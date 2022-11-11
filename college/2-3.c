#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}linear_node;

linear_node* head= NULL;
linear_node* head1= NULL;

//linked list
void insertAtHead(int x);
void insertAtTail(int x);
void insert(int x,int pos);
void display();
void delete(int x);
void deleteAtHead();
void deleteAtTail();

//circular linked list
void insertAtHead1(int x);
void insertAtTail1(int x);
void insert1(int x,int pos);
void ddisplay();
void delete1(int x);
void deleteAtHead1();
void deleteAtTail1();

//operations
void linked();
void circular();



int main()
{
    int a;

    printf("Enter Your Choice\n");
    printf("1.Linked\n2.Circular\n");
    scanf("%d", &a);
    if(a==1) linked();
    else if (a==2)
    {
        circular();
    }
    else{
        printf("INVALID!");
    }
    
}


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

   if(head==NULL) {
    printf("List is empty!");
    return;
   }
    struct node *temp;
    temp=(struct node *) malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;
    struct node *temp1;
    temp1=head;
    while(temp1->next!=NULL && temp1->data!=pos)
        {
            temp1=temp1->next;
        }
        if(temp1->next==NULL && temp1->data!=pos)
        {
            display();
            printf("element not found");
            printf("\n use insertAtTail instead . . . Press 1 to execute or any other number to exit");
            int abx;
            scanf("%d",&abx);
            if(abx==1)
            {
                insertAtTail(x);
            }else{
                return ;
            }
        }
        else
        {
            temp->next=temp1->next;
            temp1->next=temp;
        }
    
}

void display(){
    if(head==NULL) printf("Empty!");
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void deleteAtHead(){
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    linear_node *temp;
    temp=head;
    head=head->next;
    free(temp);
}

void deleteAtTail(){
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    linear_node *temp;
    linear_node *temp1= NULL;
    temp=head;
    while(temp->next!=NULL)
    {   
        temp1=temp;
        temp=temp->next;
    }
    if(temp==head)
    {
        head=NULL;
    }else{
        temp1->next=NULL;
    }
    free(temp);
}

void delete(int x){
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    if(head->data==x)
    {
        deleteAtHead();
        return;
    }
    linear_node *temp;
    linear_node *temp1= NULL;
    temp=head;
    while(temp->next!=NULL && temp->data!=x)
    {
        temp1=temp;
        temp=temp->next;
    }
    if(temp->next==NULL && temp->data!=x)
    {
        printf("element not found");
        return;
    }
    else{
        if(temp==head)
        {
            head=temp->next;
        }else{
            temp1->next=temp->next;
        }

        free(temp);
    }
}


void ddisplay(){
    printf("Linked List is :: ");
    if(head1==NULL) {
        printf("Empty!\n");
        return;
    }
    struct node *temp1;
    temp1=head1;
    if(temp1->next==head1)
    {
        printf("%d ",temp1->data);
    }
    else{
    while(temp1->next!=head1)
    {
        printf("%d ",temp1->data);
        temp1=temp1->next;
    }
    printf("%d ",temp1->data);}
    printf("\n");
}

void insertAtHead1(int x){
    linear_node *temp;
    temp=(linear_node *)malloc(sizeof(linear_node));
    temp->data=x;
    temp->next=NULL;
    if(head1==NULL)
    {
        head1=temp;
        temp->next=temp;
    }
    else
    {
        linear_node *temp1=head1;
        while (temp1->next!=head1)
        {
            temp1=temp1->next;
        }
        temp->next=head1;
        temp1->next=temp;
        head1=temp;
    }
}

void insertAtTail1(int x){
    linear_node *temp;
    temp=(linear_node *)malloc(sizeof(linear_node));
    temp->data=x;
    temp->next=NULL;
    if(head1==NULL)
    {
        head1=temp;
        head1->next=head1;
    }
    else
    {
        linear_node *temp1;
        temp1=head1;
        while(temp1->next!=head1)
        {
            temp1=temp1->next;
        }
        temp1->next=temp;
        temp->next=head1;
    }
}

void insert1(int x,int pos){
    if(head1==NULL)
    {
        printf("List is empty"); 
        printf("use insertAtHead instead . . . Press 1 to execute or any other number to exit");
        int abs;
        scanf("%d",&abs);
        if(abs==1)
        {
            insertAtHead(x);
            
        }else{
            return ;
        }   
    }
    linear_node *temp;
    temp=(linear_node *)malloc(sizeof(linear_node));
    temp->data=x;
    temp->next=NULL;
        linear_node *temp1;
        temp1=head1;
        while(temp1->next!=NULL && temp1->data!=pos)
        {
            temp1=temp1->next;
        }
        if(temp1->next==NULL && temp1->data!=pos)
        {
            display();
            printf("element not found");
            printf("\n use insertAtTail instead . . . Press 1 to execute or any other number to exit");
            int abx;
            scanf("%d",&abx);
            if(abx==1)
            {
                insertAtTail(x);
            }else{
                return ;
            }
        }
        else{
        temp->next=temp1->next;
        temp1->next=temp;
        }
}

void deleteAtHead1(){
    if(head1==NULL)
    {
        printf("List is empty\n");
        return;
    }
    linear_node *temp=head1;
    linear_node *temp1=head1;
    if(head1->next==head1)
    {
        head1=NULL;
        free(temp);
    }
    else{
        while(temp1->next!=head1)
        {
            temp1=temp1->next;
        }
        temp1->next= temp->next;
        head1=head1->next;
        free(temp);
    }
}

void deleteAtTail1(){
    if(head1==NULL)
    {
        printf("List is empty\n");
        return;
    }
    linear_node *temp;
    linear_node *temp1= NULL;
    temp=head1;
    while(temp->next!=head1)
    {
        temp1=temp;
        temp=temp->next;
    }
    if(temp==head1)
    {
        head1=NULL;
    }else{
        temp1->next=head1;
    }
    free(temp);
}

void delete1(int x){
    if(head1==NULL)
    {
        printf("List is empty\n");
        return;
    }
    linear_node *temp;    
    linear_node *temp1=NULL;    
    
    temp=head1;
    while(temp->next!=head1 && temp->data!=x)
    {
        temp1=temp;
        temp=temp->next;
    }
    if(temp->next==head1 && temp->data!=x)
    {
        printf("element not found");
        return;
    }
    else if(temp->next==head1){
        temp1->next=head1;
        free(temp);
    }
    else if(temp==head1){
        temp1->next=temp->next;
        head1=temp->next;
        free(temp);
    }
    else{
        temp1->next=temp->next;
        free(temp);
    }
}



void linked(){
    // printf("Indexing from 1");
    printf("Enter Your Choice\n");
    int on = 1;
    while (on == 1)
    {
        printf("1.Traverse\n2.Insert\n3.Delete\n4.Exit\n");
        int a;
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            printf("Linked List is :: ");
            display();
            printf("\n");
            break;
        case 2:
            printf("1.At the beginning\n");
            printf("2.At the end\n");
            printf("3.At any pos\n");
            int b;
            scanf("%d", &b);
            switch(b){
                case 1:
                    printf("Enter element:");
                    int key1;
                    scanf("%d",&key1);
                    insertAtHead(key1);
            display();
                    break;
                case 2: 
                printf("Enter element:");
                    int key2;
                    scanf("%d",&key2);
                    insertAtTail(key2);
            display();
                    break;
                case 3: 
                printf("Enter position and element:\n");

                int pos, x;
            scanf("%d %d", &pos,&x);
            insert(x,pos);
            display();
            break;

            }
            break;

            
        case 3:
            printf("1.At the beginning\n");
            printf("2.At the end\n");
            printf("3.At any pos\n");
            int c;
            scanf("%d", &c);
            switch(c){
                case 1:
                    deleteAtHead();
                    display();
                    break;
                case 2: 
                
                    deleteAtTail();
                    display();
                    break;
                case 3: 
                if(head==NULL){
                    printf("Empty!\n");
                    break;
                }else{

                printf("Enter element to be deleted :\n");

                int pos;
                scanf("%d", &pos);
                delete(pos);
                display();
                break;
                }
            }
            break;
            
        case 4:
            on = 0;
            break;

        default:
            printf("Not a valid option!");
        }
    }
}
void circular(){
    printf("Indexing from 1");
    printf("Enter Your Choice\n");
    int on = 1;
    while (on == 1)
    {
        printf("1.Traverse\n2.Insert\n3.Delete\n4.Exit\n");
        int a;
        scanf("%d", &a);
        switch (a)
        {
            case 1:
                printf("Linked List is :: ");
                ddisplay();
                printf("\n");
                break;
            case 2:
                printf("1.At the beginning\n");
            printf("2.At the end\n");
            printf("3.At any pos\n");
            int b;
            scanf("%d", &b);
            switch(b){
                case 1:
                    printf("Enter element:");
                    int key1;
                    scanf("%d",&key1);
                    insertAtHead1(key1);
                    ddisplay();
                    break;
                case 2: 
                printf("Enter element:");
                    int key2;
                    scanf("%d",&key2);
                    insertAtTail1(key2);
                    ddisplay();
                    break;
                case 3: 
                printf("Enter element where to be inserted and data:\n");

                int pos, key;
                scanf("%d %d", &pos,&key);
                insert1(key,pos);
                ddisplay();
                break;
            }
            break;
            
            case 3:
                printf("1.At the beginning\n");
            printf("2.At the end\n");
            printf("3.At any pos\n");
            int c;
            scanf("%d", &c);
            switch(c){
                case 1:
                    deleteAtHead1();
                    ddisplay();
                    break;
                case 2: 
                
                    deleteAtTail1();
                    ddisplay();
                    break;
                case 3: 
                if(head1==NULL){
                    printf("Empty!\n");
                    break;
                }else{

                printf("Enter element to be deleted :\n");

                int pos;
                scanf("%d", &pos);
                delete1(pos);
                }
                ddisplay();
                break;
            }
            break;
            case 4:
                on = 0;
                break;

            default:
                printf("Not a valid option!");
        }
    }
}
