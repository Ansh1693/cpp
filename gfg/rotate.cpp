#include<iostream>
using namespace std;

void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void rotateArr(int* arr,int n,int d){
    for(int i=0;i<d;i++){
        for (int j=0;j<n;j++){
            if(j==n-1) continue;
            else swap(&arr[j+1],&arr[j]);
        }
    }
}


int main(){
    int arr[]={5,6,7,8,9,10,11,12};
    int n=sizeof(arr)/sizeof(arr[0]);
    rotateArr(arr,n,4);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
    
}
