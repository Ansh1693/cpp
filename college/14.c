#include<stdio.h>
#include<malloc.h>

struct circular_queue{
    int size;
    int front;
    int rear;
    int *q;
};

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
    q.size=size;
    q.q=(int *)malloc(q.size*sizeof(int));
    q.front=q.rear=-1;
    }

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
