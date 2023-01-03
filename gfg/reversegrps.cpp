#include<iostream>
using namespace std;

void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void reverseingroups(int* arr,int n,int k){
    for(int i=0;i<((k)/2);i++){
        swap(&arr[i],&arr[k-1-i]);
    }
    for(int i=0;i<(n-k)/2;i++){
        swap (&arr[k+i],&arr[n-1-i]);
    }   
}


int main(){
    int n=4;
    int arr[4]={12,13,14,15};
    reverseingroups(arr,n,3);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}