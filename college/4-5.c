#include <stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node* prev;
    int x;
    struct node* next;
} linear_node;



linear_node *head=NULL;
linear_node *head1=NULL;

//double linked list
void insertAtHead(int x);
void insertAtTail(int x);
void insert(int x,int pos,int pos1);
void display();
void delete(int x);
void deleteAtHead();
void deleteAtTail();
int count(int x);

//circular double linked list
void insertAtHead1(int x);
void insertAtTail1(int x);
void insert1(int x,int pos);
void display1();
void delete1(int x);
void deleteAtHead1();
void deleteAtTail1();
int count1(int x);

//operations
void linked();
void circular();

//main
int main()
{
    int a;

    printf("Enter Your Choice\n");
    printf("1.Linked\n2.Circular\n");
    scanf("%d", &a);
    if(a==1) linked();
    else if(a==2) circular();
    else{
        printf("INVALID!");
    }
    
    return 0;}

void insertAtHead(int x)
{
    linear_node *temp;
    temp=(linear_node *)malloc(sizeof(linear_node));
    temp->x=x;
    temp->next=NULL;
    temp->prev=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
    
}

void insertAtHead1(int x){
    linear_node *temp;
    temp=(linear_node *)malloc(sizeof(linear_node));
    temp->x=x;
    temp->next=temp;
    temp->prev=temp;
    if(head1==NULL)
    {
        head1=temp;
        // head1->next=head1;
        // head1->prev=head1;
    }
    else if(head1->next==head1)
    {
        head1->next=temp;
        head1->prev=temp;
        temp->next=head1;
        temp->prev=head1;
        head1=temp;

    }
    else
    {
        temp->next=head1;
        head1->prev->next=temp;
        head1->prev=temp;
        head1=temp;
    }
}


void insertAtTail(int x){
    linear_node *temp;
    temp=(linear_node *)malloc(sizeof(linear_node));
    temp->x=x;
    temp->next=NULL;
    temp->prev=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        linear_node *temp1;
        temp1=head;
        while(temp1->next!=NULL)
        {
            temp1=temp1->next;
        }
        temp1->next=temp;
        temp->prev=temp1;
    }
    
}

void insertAtTail1(int x){
    linear_node *temp;
    temp=(linear_node *)malloc(sizeof(linear_node));
    temp->x=x;
    temp->next=NULL;
    temp->prev=NULL;
    if(head1==NULL)
    {
        head1=temp;
        head1->next=head1;
        head1->prev=head1;
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
        temp->prev=temp1;
        temp->next=head1;
        head1->prev=temp;
    }
}

void insert(int x,int pos,int pos1){
    if(head==NULL)
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
    temp->x=x;
    temp->next=NULL;
    temp->prev=NULL;
        linear_node *temp1;
        temp1=head;
        while(temp1->next!=NULL)
        {
            if(temp1->x==pos)
            {
                pos1 -=1;
            }
            if(pos1==0)
            {
                break;
            }
            temp1=temp1->next;
        }
        if(temp1->next==NULL && temp1->x!=pos)
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
        temp->prev=temp1;
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
            insertAtHead1(x);
            
        }else{
            return ;
        }
    }
    linear_node *temp;
    temp=(linear_node *)malloc(sizeof(linear_node));
    temp->x=x;
    temp->next=NULL;
    temp->prev=NULL;
        linear_node *temp1;
        temp1=head1;
        while(temp1->next!=head1 && temp1->x!=pos )
        {
            temp1=temp1->next;
        }
        if(temp1->next==head1 && temp1->x!=pos)
        {
            display1();
            printf("element not found");
            printf("\n use insertAtTail instead . . . Press 1 to execute or any other number to exit");
            int abx;
            scanf("%d",&abx);
            if(abx==1)
            {
                insertAtTail1(x);
            }else{
           
            }
        }
        else{
            temp->next=temp1->next;
            temp->next->prev=temp;
            temp1->next=temp;
            temp->prev=temp1;
        }
}

void display(){
    printf("Linked List is :: ");
    if(head==NULL) printf("Empty!");
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->x);
        temp=temp->next;
    }
    printf("\n");
}

void display1(){
    printf("Linked List is :: ");
    if(head1==NULL) {
        printf("Empty!\n");
        return;
    }
    struct node *temp1;
    temp1=head1;
    if(temp1->next==head1)
    {
        printf("%d ",temp1->x);
    }
    else{
    while(temp1->next!=head1)
    {
        printf("%d ",temp1->x);
        temp1=temp1->next;
    }
    printf("%d ",temp1->x);}
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
    head->prev=NULL;
    free(temp);
}

void deleteAtHead1(){
    if(head1==NULL)
    {
        printf("List is empty\n");
        return;
    }
    linear_node *temp;
    temp=head1;
    head1->prev->next=head1->next;
    head1->next->prev=head1->prev;
    head1=head1->next;
    free(temp);
}

void deleteAtTail(){
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    linear_node *temp;
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    // printf("%d",temp->x);
    temp->prev->next=NULL;
    if(temp==head)
    {
        head=NULL;
    }
    free(temp);
}

void deleteAtTail1(){
    if(head1==NULL)
    {
        printf("List is empty\n");
        return;
    }
    linear_node *temp;
    temp=head1;
    while(temp->next!=head1)
    {
        temp=temp->next;
    }
    temp->prev->next=head1;
    head1->prev=temp->prev;
    if(temp==head1)
    {
        head1=NULL;
    }
    free(temp);
}

void delete(int x){
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    linear_node *temp;
    temp=head;
    while(temp->next!=NULL && temp->x!=x)
    {
        temp=temp->next;
    }
    if(temp->next==NULL && temp->x!=x)
    {
        printf("element not found");
        return;
    }
    else{
        if(temp==head)
        {
            head=temp->next;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
    }
}

void delete1(int x){
    if(head1==NULL)
    {
        printf("List is empty\n");
        return;
    }
    linear_node *temp;
    temp=head1;
    while(temp->next!=head1 && temp->x!=x)
    {
        temp=temp->next;
    }
    if(temp->next==head1 && temp->x!=x)
    {
        printf("element not found");
        return;
    }
    else{
        printf("%d",temp->prev->x);
        if(temp==head1)
        {
            head1=temp->next;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
    }
    return ;
}

int count(int x){
    if(head==NULL)
    {
        printf("List is empty\n");
        return 0;
    }
    linear_node *temp;
    temp=head;
    int count=0;
    while(temp!=NULL)
    {
        if(temp->x==x)
        {
            count++;
        }
        temp=temp->next;
    }
    return count;
}

int count1(int x){
    if(head==NULL)
    {
        printf("List is empty\n");
        return 0;
    }
    linear_node *temp;
    temp=head;
    int count=0;
    while(temp->next!=NULL)
    {
        if(temp->x==x)
        {
            count++;
        }
        temp=temp->next;
    }
    return count;
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
                if(head==NULL){
                    printf("List is empty\n");
                    break;
                }
                printf("Enter element where to be inserted and data:\n");

                int pos, key;
                scanf("%d %d", &pos,&key);
                if(count(pos)>1 )
                {
                    printf("Element present %d times: After which to be inserted.\n", count(pos));
                    int pos1;
                    scanf("%d", &pos1);
                    insert(key, pos,pos1);
                }
                else{
                insert(key,pos, 1);
                }
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
    // printf("Indexing from 1");
    printf("Enter Your Choice\n");
    int on = 1;
    while (on == 1)
    {
        printf("1.Traverse\n2.Insert\n3.Delete\n4. Exit\n");
        int a;
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            printf("Linked List is :: ");
            display1();
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
                    display1();
                    break;
                case 2: 
                printf("Enter element:");
                    int key2;
                    scanf("%d",&key2);
                    insertAtTail1(key2);
                    display1();
                    break;
                case 3: 
                printf("Enter element where to be inserted and data:\n");

                int pos, key;
                scanf("%d %d", &pos,&key);
                insert1(key,pos);
                display1();
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
                    display1();
                    break;
                case 2: 
                
                    deleteAtTail1();
                    display1();
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
                display1();
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
