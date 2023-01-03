#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

class Array{
    private:
        int *A;
        int size;
        int len;
        void swap(int *a,int *b){
            int temp=*a;
            *a=*b;
            *b=temp;
        }
    public:
        Array(){
            size=10;
            len=0;
            A=new int[size];
        }
        Array(int n){
            size=n;
            A=new int[n];
            len=0;
        }
        ~Array(){
            delete[] A;
        }
        void append(int n){
            if(len==size){
                int *temp=new int[size*2];
                for(int i=0;i<size;i++){
                    temp[i]=A[i];
                }
                delete[] A;
                A=temp;
                size*=2;
            }
            A[len++]=n;
        }
        void display(){
            for(int i=0;i<len;i++){
                cout<<A[i]<<" ";
            }
            cout<<endl<<len;
            cout<<endl;
        }
        void sort(){
            for(int i=0;i<len;i++){
                for(int j=i+1;j<len;j++){
                    if(A[i]>A[j]){
                        swap(&A[i],&A[j]);
                    }
                }
            }
        }
        void reverse(){
            for(int i=0;i<len/2;i++){
                swap(&A[i],&A[len-i-1]);
            }
        }
        void Delete(int ind){
            int *temp=new int[len-1];
            int k=0;
            for(int i=0;i<len;i++){
                if(A[i]!=A[ind]){
                    temp[k++]=A[i];
                }
            }
            delete[] A;
            A=temp;
            len--;
        }
        void insert(int pos, int x){
            if(len+1<=size){
                for(int i=len;i>=pos;i--){
                    A[i]=A[i-1];
                }
                A[pos-1]=x;
            }
        }
        int LinearSearch(int key){

            for(int i=0;i<len;i++){
                if(A[i]==key){
                    return i;
                }
            }
            return -1;
        }
        
        int BinarySearch(int key){
            int low=0;
            int high=len-1;
            while(low<=high){
                int mid=(low+high)/2;
                if(A[mid]==key){
                    return mid;
                }
                else if(A[mid]<key){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }

        int Get(int ind){
            return A[ind];
        }
        void Set(int ind, int x){
            A[ind]=x;
        }

        int Max(){
            int max=A[0];
            for(int i=1;i<len;i++){
                if(A[i]>max){
                    max=A[i];
                }
            }
            return max;
        }

        int Min(){
            int min=A[0];
            for(int i=1;i<len;i++){
                if(A[i]<min){
                    min=A[i];
                }
            }
            return min;
        }

        int Sum(){
            int sum=0;
            for(int i=0;i<len;i++){
                sum+=A[i];
            }
            return sum;
        }

        float avg(){
            int sum=0;
            for(int i=0;i<len;i++){
                sum+=A[i];
            }
            return sum/len;
        }

        void InsertSort(int x){
            int i=len-1;
            while(A[i]>x){
                A[i+1]=A[i];
                i--;
            }
            A[i+1]=x;
        }

        int isSorted(){
            for(int i=0;i<len-1;i++){
                if(A[i]>A[i+1]){
                    return 0;
                }
            }
            return 1;
        }

        void Rearrange(){
            int i=0,j=len-1;
            while(i<j){
                if(A[i]>0 && A[j]<0){
                    swap(&A[i],&A[j]);
                }
                else if(A[i]<0){
                    i++;
                }
                else{
                    j--;
                }
            }
        }   


        Array* merge(Array arr2){
            int i=0,j=0,k=0;
            Array *arr3=new Array(len+arr2.len);
            while (i<len && j<arr2.len){
                if(A[i]<arr2.A[j]){
                    arr3->A[k++]=A[i++];
                }else{
                    arr3->A[k++]=arr2.A[j++];
                }
            }
            for(;i<len;i++){
                arr3->A[k++]=A[i];
            }
            for(;j<arr2.len;j++){
                arr3->A[k++]=arr2.A[j];
            }
            arr3->len=k;
            return arr3;
        }

        Array* Union(Array arr2){
            int i=0,j=0,k=0;
            Array *arr3=new Array(len+arr2.len);
            while (i<len && j<arr2.len){
                if(A[i]<arr2.A[j]){
                    arr3->A[k++]=A[i++];
                }else if(A[i]>arr2.A[j]){
                    arr3->A[k++]=arr2.A[j++];
                }else if(A[i]==arr2.A[j]){
                    arr3->A[k++]=A[i++];
                    j++;
                }
            }
            for(;i<len;i++){
                arr3->A[k++]=A[i];
            }
            for(;j<arr2.len;j++){
                arr3->A[k++]=arr2.A[j];
            }
            arr3->len=k;
            return arr3;
        }

        Array* Diff(Array arr2){
            int i=0,j=0,k=0;
            Array *arr3=new Array(len+arr2.len);
            while (i<len && j<arr2.len){
                if(A[i]<arr2.A[j]){
                    arr3->A[k++]=A[i++];
                }else if(A[i]>arr2.A[j]){
                    j++;
                }else{
                    i++;
                    j++;
                }
            }
            for(;i<len;i++){
                arr3->A[k++]=A[i];
            }
            
            arr3->len=k;
            return arr3;
        }

        Array* Inter(Array arr2){
            int i=0,j=0,k=0;
            Array *arr3=new Array(len+arr2.len);
            while (i<len && j<arr2.len){
                if(A[i]<arr2.A[j]) i++;
                else if (A[i]>arr2.A[j]) j++;
                else{
                    arr3->A[k++]=A[i++];
                    j++;
                }
            }
            arr3->len=k;
            return arr3;
        }
        
};

int main()
{
    Array *arr1=new Array(10);
    arr1->append(4);
    arr1->append(5);
    arr1->append(6);
    arr1->append(8);
    arr1->append(9);
    arr1->append(12);
    Array *arr2=new Array(10);
    arr2->append(3);
    arr2->append(5);
    arr2->append(7);
    arr2->append(10);
    arr2->append(11);
    arr2->append(15);
    Array *arr3=arr1->Union     (*arr2);
    arr3->display();

    // arr1.sort(arr1,arr1+arr1->len);
    return 0;
}