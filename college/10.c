#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>



char stack[100];
char infix[100], postfix[100];
int top=-1;


int len(char *infix);
int precedence(char symbol);
void push(char c);
char pop();
int isempty();
void intopost();
void print();

int main()
{
    printf("enter the infix expression:  ");
    gets(infix);

    intopost();
    print();
    return 0;


}

int len(char *infix)
{
    int i;
    for( i=0;infix[i]!='\0';i++)
    {

    }
    //printf("the length of string is %d",i);
    return i;
    
}

int precedence(char symbol)
{
    switch(symbol)
    {
        case '^':
            return 3;
			// break;
        case '/':
        case '*':
            return 2;
			// break;
        case '+':
        case '-':
            return 1;
        default:
            return 0;    

    }
}
void push(char c)
{
    int size=100;
    if(top==size-1)
    {
        printf("Stack overflow\n");
    }
    top++;
    stack[top]=c;
}
char pop()
{
    char c;
    if(top==-1)
    {
        printf("stack underflow\n");
        return 0;
    }
    c=stack[top];
    top=top-1;
    return c;
}
int isempty()
{
    if(top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void intopost()
{
    int i,j=0;
    char symbol, next;
    for(i=0; i<len(infix); i++)
    {
        symbol=infix[i];
        switch(symbol)
        {
            case '(':
                push(symbol);
                break;
            case ')':
                while((next=pop())!='(')
                {
                    postfix[j++]=next;
                }
                break;
            case '+':
            case '-': 
            case '*': 
            case '/': 
            case '^':
                while(!isempty() && precedence(stack[top]) >= precedence(symbol))
                {
                    postfix[j++]= pop();
                }
                push(symbol);
                break;
            default:
                postfix[j++]= symbol;

        }

    }
    while(!isempty())
    {
        postfix[j++]=pop();       
    }
    postfix[j]='\0';
}

void print()
{
    int i=0;
    printf("The postfix expression is: \n");
    while(postfix[i])
    {
        if(postfix[i]=='(' || postfix[i]==')')
        {
            continue;
        }
        printf("%c", postfix[i++]);

    }
    printf("\n");
}