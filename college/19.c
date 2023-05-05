#include <stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
    int data;
    struct node *next;
};

struct node *llfront = NULL, *llrear = NULL;

void llenqueue(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node *));
    temp->data = item;
    temp->next = NULL;
    if (llfront == NULL)
    {
        llfront = temp;
        llrear = temp;
        return;
    }
    llrear->next = temp;
    llrear = temp;
}


void lldequeue()
{
    if (llfront == NULL)
    {
        return;
    }
    struct node *temp = llfront;
    llfront = llfront->next;
    if (llfront == NULL)
    {
        llrear = NULL;
    }

    free(temp);
}

int llfr()
{
    if (! llfront)
    {
        return -1; 
    }
    return llfront->data;
}



struct AdjListNode {
	int dest;
	struct AdjListNode* next;
};

struct AdjList {
	struct AdjListNode* head;
};

struct Graph {
	int V;
	struct AdjList* array;
};

struct AdjListNode* newAdjListNode(int dest)
{
	struct AdjListNode* newNode
		= (struct AdjListNode*)malloc(
			sizeof(struct AdjListNode));
	newNode->dest = dest;
	newNode->next = NULL;
	return newNode;
}

struct Graph* createGraph(int V)
{
	struct Graph* graph
		= malloc(sizeof(struct Graph));
	graph->V = V;

	graph->array = (struct AdjList*)malloc(
		(V+1) * sizeof(struct AdjList));

	int i;
	for (i = 1; i <=V; ++i)
		graph->array[i].head = NULL;

	return graph;
}

void addEdge(struct Graph* graph, int src, int dest)
{
	struct AdjListNode* check = NULL;
	struct AdjListNode* newNode = newAdjListNode(dest);

	if (graph->array[src].head == NULL) {
		newNode->next = graph->array[src].head;
		graph->array[src].head = newNode;
	}
	else {

		check = graph->array[src].head;
		while (check->next != NULL) {
			check = check->next;
            if(check->dest == dest) break;
		}
        if(check->dest != dest){

		    check->next = newNode;
        }
	}

	// newNode = newAdjListNode(src);
	// if (graph->array[dest].head == NULL) {
	// 	newNode->next = graph->array[dest].head;
	// 	graph->array[dest].head = newNode;
	// }
	// else {
	// 	check = graph->array[dest].head;
	// 	while (check->next != NULL) {
	// 		check = check->next;
	// 	}
	// 	check->next = newNode;
	// }

}

void printGraph(struct Graph* graph)
{
	int v;
	for (v = 1; v <=graph->V; ++v) {
		struct AdjListNode* pCrawl = graph->array[v].head;
		printf("\n Adjacency list of vertex %d\n head ", v);
		while (pCrawl) {
			printf("-> %d", pCrawl->dest);
			pCrawl = pCrawl->next;
		}
		printf("\n");
	}
}

void bfs(struct Graph* graph , int n){
    int visited[n+1];
    for(int i=0;i<=n;i++){
        visited[i]=0;
    }
    int s;
    printf("Enter the source vertex: ");
    scanf("%d",&s);
    if(s>n || s<=0) {printf("Invalid source!!");return ;}
    visited[s]=1;
    llenqueue(s);
    while(llfront){
        int u = llfr();
        printf("%d ",u);
        lldequeue();
        struct AdjListNode* pCrawl = graph->array[u].head;
        while (pCrawl) {
            if(visited[pCrawl->dest]==0){
                visited[pCrawl->dest]=1;
                llenqueue(pCrawl->dest);
            }
            pCrawl = pCrawl->next;
        }
    }
}
void dfsSup(struct Graph* graph, int vis[], int src){
    struct AdjListNode* pCrawl = graph->array[src].head;
    vis[src]=1;
    printf("%d ",src);
    while (pCrawl) {
        if(vis[pCrawl->dest]==0){
            dfsSup(graph,vis,pCrawl->dest);
        }
        pCrawl = pCrawl->next;
    }

}
void dfs(struct Graph* graph, int n){
    int vis[n+1] ;
    for(int i=0;i<=n;i++){
        vis[i]=0;
    }
    int s;
    printf("Enter the source vertex: ");
    scanf("%d",&s);
    if(s>n || s<=0) {printf("Invalid source!!");return ;}
    dfsSup(graph,vis,s);
}

int main(){
    int con;
    printf("Type of Graph\n 1. Undirected Graph \n 2. Directed Graph \n");
    scanf("%d",&con);

    int n,m;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d",&n,&m);

    struct Graph* graph =  createGraph(n);

    int u , v;
    printf("Enter %d edges: ",m);
    for(int i=0;i<m;i++){
        scanf("%d %d",&u,&v);
        addEdge(graph,u,v);        
        if(con==1){
            addEdge(graph,v,u);
        }
    }
    while(1){
        int ch;
        printf("\nEnter choice: \n 1. print adjaceny list \n 2. BFS Traversal \n 3. DFS Traversal \n 4. Exit");
        scanf("%d",&ch);
        switch(ch){
            case 1: 
                printf("\n Here is the graph list . . . \n");
                printGraph(graph);
                break;
            case 2: 
                printf("\n Here is the BFS graph traversal . . . \n ->");

                bfs(graph,n);
                break;
            case 3: 
                printf("\n Here is the DFS graph traversal . . . \n ->");
                dfs(graph,n);
                break;
            case 4: exit(0);
            default: printf("Invalid choice");
        }
    }


    return 0;

}


  