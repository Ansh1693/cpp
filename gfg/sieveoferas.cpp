#include<iostream>
using namespace std;
int* prime(int n){
    int i,j;
    int* arr=new int[n];
    for(i=2;i<=n;i++){
        int check=0;
        for(j=2;j<=i/2;j++){
            if(i%j==0) {
                check=1;
                break;}            
        }
        if(check==0){
            arr[i]=i;
        }
    }
    return arr;
}
int main(){
    int n;
    cin>>n;
    int* ptr=prime(n);
    
    for(int i=0;i<n;i++){
        if(ptr[i]>1 && ptr[i]<=n){
        cout<<ptr[i]<<endl;
        }
    }
    delete[] ptr;
    return 0;
}
