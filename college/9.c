#include<stdio.h>
#include<malloc.h>


struct stack
{
    int size;
    int top;
    int *s;
};

void push(struct stack *st,int x);
int pop(struct stack *st);
int display(struct stack st);
int peep(struct stack *st);

int main()
{
    int x,k,y,size;
    struct stack st;
    printf("Enter the size of stack\n");
    scanf("%d",&size);
    if(size<1){
        printf("Cant create empty Stack!!! start over!!\n");
        main();
        return 0;
    }else{
    st.size=size;
    st.s=(int *)malloc(st.size*sizeof(int));
    st.top=-1;
    }

    do
    {
        printf("Select the following\n 1.push\n 2.pop\n 3.Peep\n4. Exit \n");
        scanf("%d",&x);
        switch(x){

        case 1:
        
            printf("enter the element to insert\n");
            scanf("%d",&y);
            push(&st,y);
            display(st);
            break;

        
        case 2:
        
            pop(&st);
            display(st);
            break;

        case 3:
            int abx;
            abx = peep(&st);
            if(abx==-1) {printf("Empty!!");}
            else{printf("The top element is %d",abx);}
            break;

        case 4:
        
            return 0;
            break;
        
        default:
        
            printf("Invalid input\n");
            break;
        
        }
        printf("1 to continue 0 to exit\n");
        scanf("%d",&k);
        if(k==0){ return 0; }

       
    } while (k==1);
    return 0;
    

}


void push(struct stack *st,int x)
{
    if(st->top==st->size-1)
    {
        printf("stack overflow\n");
    }
    else
    {
        st->top++;
        st->s[st->top]=x;
    }
    return ;

}

int pop(struct stack *st)
{
    int x=-1;
    if(st->top==-1)
    {
        printf("stack underflow\n");
    }
    else
    {
        x=st->s[st->top];
        st->top--;
    }
    return x;
    

}
int peep(struct stack *st){
    int x=-1;
    if(st->top==-1)
    {
        printf("stack underflow\n");
    }
    else
    {
        x=st->s[st->top];
    }
    return x;
}

int display(struct stack st)
{
    if(st.top==-1)
    {
        printf("There is no element\n");
        return 0;
    }
    printf("The elements of stack are\n");
    for(int i=st.top;i>=0;i--)
    {
        printf("%d\n",st.s[i]);
    }
    return 0;
}
