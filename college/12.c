#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

int binary(int arr[],int high , int low , int key){
    if(low>high) return -1;
    int mid = (low+high)/2;
    if(arr[mid]==key) return mid;
    if(arr[mid]>key) return binary(arr,mid-1,low,key);
    if(arr[mid]<key) return binary(arr,high,mid+1,key);
}

int main(){
    int n;
    printf("Enter the number of elements in the array : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array : ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int key;
    printf("Enter the key to be searched : ");
    scanf("%d",&key);
    
    int index = binary(arr,n-1,0,key);
    if (index!=-1)
    {
        printf("The key is found at index %d from the left",index+1);
    }
    else
    {
        printf("The key is not found");
    }
    // int arr[]={1,2,3,4,5,6,7,8};
    // int key = 5;
    // int n = sizeof(arr)/sizeof(arr[0]);
    return 0;
}