#include<iostream>
using namespace std;

int point(int* arr,int n){
    for(int i=0;i<n;i++){
        int sum1=0,sum2=0;
        for(int k=0;k<i;k++) {sum1+=arr[k];}
        for(int j=i+1;j<n;j++){sum2+=arr[j];}
        if(sum1==sum2){
            return i+1;
        }
    }
    return -1;
}

int main(){
    int n=5;
    int arr[5]={10,2,4,9,3};
    int a=point(arr,5);
    cout<<a<<endl;
    }