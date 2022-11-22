
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct Stack
{
	int top;
	unsigned capacity;
	int* array;
};


struct Stack* createStack( unsigned capacity )
{
	struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));

	if (!stack) return NULL;

	stack->top = -1;
	stack->capacity = capacity;
	stack->array = (int*) malloc(stack->capacity * sizeof(int));

	if (!stack->array) return NULL;

	return stack;
}

int isEmpty(struct Stack* stack)
{
	return stack->top == -1 ;
}

int peek(struct Stack* stack)
{
	return stack->array[stack->top];
}

int pop(struct Stack* stack)
{
	if (!isEmpty(stack))
		return stack->array[stack->top--] ;
	return -999;
}

void push(struct Stack* stack,int op)
{
	stack->array[++stack->top] = op;
}



int evaluatePostfix(char* exp)
{
struct Stack* stack = createStack(strlen(exp));
	
	int i;

	
	if (!stack) return -1;

	for (i = 0; exp[i]; ++i)
	{
		
		if(exp[i]==' ')continue;
		
		
		else if (isdigit(exp[i]))
		{
			int num=0;
			
			while(isdigit(exp[i]))
			{
			num=num*10 + (int)(exp[i]-'0');
				i++;
			}
			i--;
			
			push(stack,num);
		}
		
		else
		{	
			if((!isalpha(exp[i]))){

			int val1 = pop(stack);
			int val2 = pop(stack);
			if(val1!= -999 && val2!= -999){
			// printf("%d %d \n", val1 , val2);

			switch (exp[i])
			{
			case '+': push(stack, val2 + val1); break;
			case '-': push(stack, val2 - val1); break;
			case '*': push(stack, val2 * val1); break;
			case '/': push(stack, val2/val1); break;
			
			}
			}else{
				// if(!isalpha)
				push(stack,val1);
				push(stack,val2);
			}
			}else{
				printf("gg");
				return -999;
			}
		}
	}
	if(stack->top==0) {
	return pop(stack);
	}
	return pop(stack);
}


int main()
{
	char exp[] = " ";
	printf ("Enter the postfix expression: ");
	gets(exp);
	// printf("%s",exp);
	if(evaluatePostfix(exp)==-999){
		printf("Invalid Expression");
	}else{
	printf ("Value of expression is %d", evaluatePostfix(exp));
	} 
	
	// printf ("%d", evaluatePostfix(exp));
	return 0;
}

