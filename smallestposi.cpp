#include<iostream>
using namespace std;

int missing(int* arr,int n){
    int arr1[n+1];
    int i=1;
    for(int k=0;k<n;k++){
        if(arr[k]>0 && arr[k]<=n){
            arr1[arr[k]]=true;
        }
    }
    for(i=1;i<=n;i++){
        if(!arr1[i])  break;
    }
    return (i);
}
int main(){
    int arr[8]={2, 3, -4, -6, -5, 1, -7, 8};
    int a=missing(arr,8);
    cout<<a;
}