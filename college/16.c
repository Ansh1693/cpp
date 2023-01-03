#include <stdio.h>
#include<stdlib.h>
#include<malloc.h>

//sparse array

typedef struct node{
    int row;
    int column;
    int value;
    struct node* next;
} linear_node;

linear_node* head = NULL;

void insert(){
    int r,c;
    printf("Enter row and column: ");
    scanf("%d %d",&r,&c);
    int arr[r][c],non_zero;
    printf("\nEnter the array: ");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&arr[i][j]);
            if(arr[i][j]!=0) non_zero++;
        }
    }
    int sparse[non_zero+1][3],k=0;

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(arr[i][j]!=0) {
                sparse[k][0] = i+1;
                sparse[k][1] =j+1;
                sparse[k][2] = arr[i][j];
                k++;
            };
        }
    }



    // for(int i=0;i<r;i++){
    //     for(int j=0;j<c;j++){
    //         if(arr[i][j]!=0){
    //             linear_node* temp = (linear_node*)malloc(sizeof(linear_node));
    //             temp->row = i;
    //             temp->column = j;
    //             temp->value = arr[i][j];
    //             temp->next = NULL;

    //             if(head == NULL){
    //                 head = temp;
    //                 continue;
    //             }

    //             linear_node* temp2 = head;
    //             while(temp2->next!=NULL){
    //                 temp2 = temp2->next;
    //             }
    //             temp2->next = temp;
    //         }
    //     }
    // }

}

void print(){
    // linear_node* temp = head;
    // if(temp==NULL){
    //     printf("array doesn't have a non-zero value or it is not entered.");
    // }
    // printf("\nmRow Column Value:");
    // printf("\n");
    // while(temp!=NULL){
    //     printf(" %d    %d    %d",temp->row , temp->column , temp->value);
    //     printf("\n");
    //     temp = temp->next;
    // }
}

int main(){
    int r,c;
    printf("Enter row and column: ");
    scanf("%d %d",&r,&c);
    int arr[r][c],non_zero =0 ;
    printf("\nEnter the array: ");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&arr[i][j]);
            if(arr[i][j]!=0) non_zero++;
        }
    }
    int sparse[non_zero+1][3],k=0;
    // sparse[0][1]

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(k<=non_zero){

            if(arr[i][j]!=0) {
                sparse[k][0] = i+1;
                sparse[k][1] =j+1;
                sparse[k][2] = arr[i][j];
                k++;
            };
            }
        }
    }

    printf("ROW COLUMN VALUE\n");
    if(non_zero>0){

    for(int i=0;i<non_zero;i++){
        for(int j=0;j<3;j++){
            // scanf("%d",&arr[i][j]);


            printf(" %d      ",sparse[i][j]);
            // if(arr[i][j]!=0) non_zero++;
        }

        printf("\n");
    }
    }else{
        printf("No non-zero elements");
    }
    return 0;
}