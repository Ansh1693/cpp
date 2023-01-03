#include<iostream>
using namespace std;

void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void converToWave(int* arr,int n){
    
    
    for(int i=0;i<n;i+=2){
        if(i==n-1) break;
        swap(&arr[i],&arr[i+1]);
    }
}

int main(){
    int arr[]={5,6,7,8,9,10,11,12};
    int n=sizeof(arr)/sizeof(arr[0]);
    converToWave(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"  ";
    }
}