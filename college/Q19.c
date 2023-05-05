#include<stdio.h>
#include<stdlib.h>

int flag = 0; //for search condition not found

/***************BFS*******************/
struct queue
{
    int data;
    struct queue* link;
};

struct queue* front = NULL;
struct queue* rear = NULL; 

struct stack
{
    int data;
    struct stack* link;
};

struct stack* top = NULL;

void enqueue(int x)
{
   if(rear == NULL)
    {
        rear = malloc(sizeof(struct queue));
        rear -> data = x;
        rear -> link = NULL;
        front = rear;
    }
    else
    {
        struct queue* temp = malloc(sizeof(struct queue));
        temp -> data = x;
        rear -> link = temp;
        rear = rear -> link;
        rear -> link = NULL;
    }
}

int notEmpty()
{
    if(front == NULL && rear == NULL)
    {
         return 0;
    }
    else
    {
         return 1;
    }
}

int dequeue()
{   
    int element = front -> data; 
    struct queue* temp = front;
    if(front == rear)
    {
         front = NULL;
         rear = NULL;
    }
    else
    {
         front = front -> link;
    }
    free(temp);
    return element;
}

int search(int nodes[], int size, int data)
{
    int index;
    for (index = 0; index < size; index++)
    {
        if(nodes[index] == data)
        {
            flag = 1;
            return index;
        }
    }
    if(flag == 0)
    {
        return 0;
    }
}

void BFS(int size, int graph[size][size], int nodes[size], int visited[size])
{
    int i,start, start_index;
    for(i = 0; i < size; i++)
    {
        visited[i] = 0;
    }
    start_input : printf("\nEnter the node you want to start with : ");
    scanf("%d", &start);
    flag = 0;
    start_index = search(nodes, size, start);
    if(flag ==  1)
    {
        printf("%d", nodes[start_index]);
        visited[start_index] = 1;
        enqueue(start_index);
        while(notEmpty())
        {
            int node = dequeue();
            for(i = 0; i < size; i++)
            {
                if(graph[node][i] == 1 && visited[i] == 0)
                {
                    printf("\t -> \t");
                    printf("%d", nodes[i]);
                    visited[i] = 1;
                    enqueue(i);
                }
            }
        }
    }
    else
    {
        printf("\nEntered node not found in graph, try again.");
        goto start_input;
    }
}

/****************DFS****************/

void push(int x)
{
    if(top == NULL)
    {
        top = malloc(sizeof(struct stack));
        top -> data = x;
        top -> link = NULL;
    }
    else
    {
        struct stack* temp = malloc(sizeof(struct stack));
        temp -> data = x;
        temp -> link = top;
        top = temp;
    }
}

int pop()
{
    int element;
    element = top -> data;
    struct stack* temp = top;
    top = top -> link;
    free(temp);
    return element;
}

void DFS(int size,int graph[size][size], int nodes[size], int visited[size])
{
    int i,start, start_index;
    for(i = 0; i < size; i++)
    {
        visited[i] = 0; 
    } 
    start_input : printf("\nEnter the node you want to start with : ");
    scanf("%d", &start);
    flag = 0;
    start_index = search(nodes, size, start);
    if(flag ==  1)
    {
        visited[start_index] = 1;
        push(start_index);
        while(top != NULL)
        {
            int node = pop();
            printf("\t -> \t");
            printf("%d", nodes[node]);
            for(i = 0; i < size; i++)
            {
                if(graph[node][i] == 1 && visited[i] == 0)
                {
                    visited[i] = 1;
                    push(i);
                }
            }
        }
    }
    else
    {
        printf("\nEntered node not found in graph, try again.");
        goto start_input;
    }
}

/*********************/
int main()
{
    int size,max_edges,i,j,node, other_node, x,y,opt,index,start;
    char ans;
    size_input : printf("\nEnter the no. of nodes of the graph : ");
    scanf("%d", &size);
    if(size < 1)
    {
        printf("\nSize cannot be less than 1, try again.");
        goto size_input;
    }
    int graph[size][size],visited[size], nodes[size];
    for(i = 0; i < size; i++)
    {
        printf("\nEnter the %d node of the graph (NO duplicate nodes): ", i+ 1);
        scanf("%d", &nodes[i]);
        visited[i] = 0;
        for(j = 0; j < size; j++)
        {
            graph[i][j] = 0;
        }
    }
    max_edges = ((size * size) - size) / 2;
    printf("\nEnter the edges in pairs, only once for a edge as the graph is undirected.)");
    for(i = 0; i < max_edges; i++)
    {
        edge_input : printf("\n\nEnter the starting node : ");
        scanf("%d", &node);
        printf("\nEnter the ending node : ");
        scanf("%d", &other_node);
        x = search(nodes, size, node);
        if(flag != 0)
        {
            y = search(nodes, size, other_node);
            if(flag != 0)
            {
                if(x != y)
                {
                    graph[x][y] = 1;
                    graph[y][x] = 1;
                }
                if(i != max_edges - 1)
                {
                    more_edge : printf("\nWant to add more edges ? press y for yes n for No : ");
                    scanf("%c", &ans);
                    printf("\n%c", ans);
                    if(ans == 'y' || ans == 'Y')
                    {

                    }
                    else if(ans == 'n' || ans == 'N')
                    {
                        break;
                    }
                    else
                    {
                        printf("\nWrong input, try again");
                        goto more_edge;
                    }
                }
                else
                {
                    printf("\nNo more edges can't be entered, press enter to continue.");
                }
            }
            else 
            {
                printf("\nEntered element not found in the graph, try again.");
                goto edge_input;
            }
        }
        else
        {
            printf("\nEntered element not found in the graph, try again.");
            goto edge_input;
        }
    }
    menu : printf("\nTRAVERSAL ON GRAPH");
    printf("\n\nSelect a option : ");
    printf("\n1. BFS TRAVERSAL");
    printf("\n2. DFS TRAVERSAL");
    printf("\n3. EXIT");
    printf("\nEnter your choice : ");
    scanf("%d", &opt);
    switch(opt)
    {
        case 1:
                BFS(size,graph,nodes,visited);
                goto menu;
        case 2:
                DFS(size,graph,nodes,visited);
                goto menu;
        case 3:
                return 0;
        default: 
                printf("\nWrong input, try again");
                goto menu;
    }
}