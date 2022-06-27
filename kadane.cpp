#include<iostream>
using namespace std;

void maxSubArr(int* arr,int n){
    int maxSum=INT16_MIN;
    for (int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(sum>maxSum) maxSum=sum;
        }
    }
    cout<<maxSum;
}
int main(){
    int arr[8]={-2, -3, 4, -1, -2, 1, 5, -3};
    maxSubArr(arr,8);
    //cout<<sum;
}
