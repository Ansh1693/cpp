#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void display(int *arr,int n){
    cout<<"Elements of array are: "<<endl;
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

void add(int *arr,int x,int &len){
    arr[len]=x;
    len++;
}

void insert(int *arr,int x,int pos,int &len){
    for(int i=len;i>=pos;i--){
        arr[i]=arr[i-1];
    }
    arr[pos]=x;
    len++;
}

void deleteEle(int *arr,int pos,int &len){
    for(int i=pos;i<len;i++){
        arr[i]=arr[i+1];
    }
    len--;
}

int main(){
    int size=10;
    // cout<<"Enter size of array: ";
    // cin>>size;
    // int *arr=new int[size];
    // int len;
    // cout<<"Enter number of elements: ";
    // cin>>len;
    // cout<<"Enter elements: "<<endl;
    // for(int i=0;i<len;i++){
    //     cin>>arr[i];
    // }
    // int x;
    // cout<<"Enter an element to be added: ";
    // cin>>x;
    int arr[10]={1,2,3,4,5};
    int len=5;
    deleteEle(arr,4,len);
    // cout<<len;
    display(arr,len);

    return 0;
}