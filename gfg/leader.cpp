#include<iostream>
using namespace std;

int* leader(int* arr, int n){
    int* lead=new int[n];
    for(int i=0;i<n;i++){
        int check=0;
        for(int j=i;j<n;j++){
            if(arr[i]<arr[j]) check=1;
        }
        if(check==0) lead[i]=arr[i];
    }
    return lead;
}
int main(){
    int arr[]={8,10,6,4,2,1};
    int* ptr=leader(arr,6);
    for(int i=0;i<6;i++) {
        if(ptr[i]>0 && ptr[i]<=INT16_MAX){
        cout<<ptr[i]<<endl;
        }
        }
    delete[] ptr;
    return 0;
}