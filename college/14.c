#include<stdio.h>
#include<malloc.h>

struct circular_queue{
    int size;
    int front;
    int rear;
    int *q;
};

typedef struct QueueL
{
    int data;
    struct QueueL *next;
}QueueL;

QueueL* frontL=NULL;
QueueL* rearL=NULL;


void enqueueL(int val){
    if(frontL == NULL){
        QueueL* temp = (QueueL*)malloc(sizeof(QueueL));
        temp->data = val;
        temp->next = temp;
        frontL = temp;
        rearL = temp;
        printf("\n\t\t\t INSERTION SUCCESSFULL\n");
        return;
    }
    QueueL* temp = frontL;
    while((temp->next->data)!=frontL->data){
        temp = temp->next;
    }
    QueueL* sudo = (QueueL*)malloc(sizeof(QueueL));
    sudo->data = val;
    temp->next = sudo;
    sudo->next = frontL;
    rearL = sudo;
    printf("\n\t\t\t INSERTION SUCCESSFULL\n");
    return;
}


int dequeueL(QueueL* headC){
    QueueL* temp;
    QueueL* ptr;
    int ans;
    if(frontL == NULL){
        printf("\n\t\t\t QUEUE IS EMPTY\n");
        printf("\n\t\t\t FURTHER DELETION NOT POSSIBLE\n");
        return -1;
    }
    else if(frontL->next == frontL){
        ans = frontL->data;
        frontL = NULL;
        rearL = NULL;
        free(frontL);
    }
    else{
        temp = frontL;
        ans = temp->data;
        while(temp->next!=frontL){
            ptr = temp;
            temp = temp->next;
        }
        temp = temp->next;
        frontL = temp->next;
        ptr = ptr->next;
        ptr->next = temp->next;
        temp->next = NULL;
        free(temp);
    }
    printf("\n\t\t DELETION SUCCESSFUL");
    return ans;
}

void traverseL(QueueL* frontL){
    QueueL * temp = frontL;
    if(temp == NULL){
        printf("OOPS!!\n");
        printf("The QUEUE is EMPTY\n");
        return;
    }
    else{
        printf("The created QUEUE  is\n\n\t\t");
        do{
            printf("| %d |",temp->data);
            temp = temp->next;
        }while(frontL!=temp);
        printf("\n");
    }
}

int FrontL(QueueL *frontL){
    if(frontL == NULL)
        return -1;
    else 
        return frontL->data;
}


void enqueue(struct circular_queue *q,int x);
int dequeue(struct circular_queue *q);
void display(struct circular_queue q);
int peep(struct circular_queue *q);

int main()
{
    int x,k,y,size;
    struct circular_queue q;
    printf("Enter the size of queue\n");
    scanf("%d",&size);
    if(size<1){
        printf("Cant create empty Queue!!! start over!!\n");
        main();
        return 0;
    }else{
        printf("1. Using Arrays\n 2. Using Linked List\n");
        scanf("%d",&k);
        if(k==1){
            q.size=size;
    q.q=(int *)malloc(q.size*sizeof(int));
    q.front=q.rear=-1;
    do
    {
        printf("Select the following\n 1.enqueue\n 2.dequeue\n 3.Peep\n4. Exit \n");
        scanf("%d",&x);
        switch(x){

        case 1:
        
            printf("enter the element to insert\n");
            scanf("%d",&y);
            enqueue(&q,y);
            display(q);
            break;

        
        case 2:
        
            dequeue(&q);
            display(q);
            break;

        case 3:
            int abx;
            abx = peep(&q);
            if(abx==-1) {printf("Empty!!");}
            else{printf("The top element is %d",abx);}
            break;

        case 4:
            return 0;
        }
    } while (x!=4);

        }else{
            do
    {
        printf("Select the following\n 1.enqueue\n 2.dequeue\n 3.Peep\n4. Exit \n");
        scanf("%d",&x);
        switch(x){

        case 1:
        
            printf("enter the element to insert\n");
            scanf("%d",&y);
            enqueueL(y);
            display(q);
            break;

        
        case 2:
        
            dequeueL(&frontL);
            traverseL(&frontL);
            break;

        case 3:
            int abx;
            abx = FrontL(&frontL);
            if(abx==-1) {printf("Empty!!");}
            else{printf("The top element is %d",abx);}
            break;

        case 4:
            return 0;
            
        }
    } while (x!=4);

        }
    }


    
    
}

void enqueue(struct circular_queue *q,int x)
{
    if((q->rear+1)%q->size==q->front)
    {
        printf("Queue is full");
    }
    else
    {
        q->rear=(q->rear+1)%q->size;
        q->q[q->rear]=x;
        
    }
}

int dequeue(struct circular_queue *q)
{
    int x=-1;
    if(q->front==q->rear)
    {
        printf("Queue is empty");
    }
    else
    {
        q->front=(q->front+1)%q->size;
        x=q->q[q->front];
    }
    return x;
}

void display(struct circular_queue q)
{
    int i;
    for(i=q.front+1;i<=q.rear;i++)
    {
        printf("%d ",q.q[i]);
    }
    printf("\n");
}

int peep(struct circular_queue *q)
{
    int x=-1;
    if(q->front==q->rear)
    {
        printf("Queue is empty");
    }
    else
    {
        x=q->q[q->front+1];
    }
    return x;
}
