#include<stdio.h>
#include<malloc.h>

struct node
{
    float coef;
    int power;
    struct node*next;
};

struct node* create(struct node* head);
struct node* insert(struct node* head, int co,int ex);
void display(struct node* head);
void add(struct node* head1 ,struct node* head2);

int main()
{
    struct node*head=NULL;
    struct node*second=NULL;
    printf("Enter the first polynomial\n ");
    head=create(head);
    printf("Enter the second polynomial\n ");
    second=create(second);

    add(head,second);
    return 0;


}


struct node* insert(struct node* head, int co,int ex)
{
    
    struct node* temp;
    struct node* new=(struct node*)malloc(sizeof(struct node));
    new->coef=co;
    new->power= ex;
    new->next= NULL;

    if(head== NULL || ex > head->power)
    {
        new->next = head;
        head= new;
    }
    else
    {
        
        temp=head;
        while(temp->next!=NULL && temp->next->power > ex)
        {
            temp=temp->next;
        }
        if(temp->power==new->power) {
            temp->coef+=new->coef;
            free(new);
        }else{
        new->next=temp->next;
        temp->next=new;
        }
    }
    return head;


}


struct node* create(struct node* head)
{
    int n;
    int i;
    float coef;
    int power;

    printf("Enter the number of terms: \n");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter the coef for term %d: \n",i+1);
        scanf("%f",&coef);

        printf("Enter the power for term %d  \n",i+1);
        scanf("%d", &power);
        head=insert(head,coef,power);
    }
    return head;


}

void display(struct node* head)
{
    
    if(head==NULL)
    {
        printf("Enter the polynomial\n");
    }
    else
    {
        struct node*temp=head;
        while(temp!=NULL)
        {
            printf("(%.1fx^%d)" , temp->coef, temp->power);
            temp=temp->next;
            if(temp!=NULL)
            {
                printf("+");
            }
            else
            {
                printf("\n");
            }
        }
    }
}

void add(struct node* head1 ,struct node* head2)
{
    struct node* p1=head1;
    struct node* p2=head2;
    struct node*head3=NULL;
    while(p1!=NULL && p2!=NULL)
    {
        if(p1->power== p2->power)
        {
            head3=insert(head3,p1->coef + p2->coef , p1->power);
            p1=p1->next;
            p2=p2->next;
        }
        else if(p1->power >p2->power)
        {
            head3=insert(head3, p1->coef,p1->power);
            p1=p1->next;
        }
        else if(p1->power <p2->power)
        {
            head3=insert(head3, p2->coef,p2->power);
            p2=p2->next;
        }
        
    }
    while(p1!=NULL)
    {
        head3=insert(head3,p1->coef,p1->power);
        p1=p1->next;
    }
    while(p2!=NULL)
    {
        head3=insert(head3,p2->coef,p2->power);
        p2=p2->next;
    }
    printf("After addition polynomial is:\n ");
    if(head3==NULL)
    {
        printf("No polynomials to add");
    }
    else
    {
        display(head3);
    }
}