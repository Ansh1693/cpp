#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

class Stack{
    public:
        int *arr;
        int top;
        int size;
    //functions

        Stack(int size){
            this->size=size;
            arr= new int[size];
            top=-1;
        }

        void push(int n){
            if(size-top>1){
                top++;
                arr[top]=n;
            }else{
                cout<<"Stack Overflow!!!"<<endl;;
            }

        }

        int pop(){
            int x=-1;
            if(top>-1){
                x=arr[top];
                top--;
            }else{
                cout<<"Stack Underflow!!"<<endl;
            }

            return x;
        }

        int peek(){
            if(top>=0 && top<size){
                return arr[top];
            }else{
                cout<<"Stack is empty!!!"<<endl;
                return -1;
            }
        }

        bool isEmpty(){
            if(top==-1) return true;
            else return false;
        }

};

class Node{
    public:
        int data;
        Node* next;
};

class Stack2{
    private:
        Node* top;
    public:
        Stack2(){
           
            top=NULL;
        }

        void push(int n){
            Node* temp=new Node;
            if(temp==NULL) cout<<"overflow!!"<<endl;
            else{
                temp->data=n;
                temp->next=top;
                top=temp;
            }
        }

        void pop(){
            if(top==0) cout<<"underflow"<<endl;
            else{
                Node* temp=top;
                top=temp->next;
                temp->next=NULL;
                delete temp;
            }
        }

        int peek(){
            if(top==NULL){
                return -1;
            }else{
                return top->data;
            }
        }


};

int main()
{
    Stack2 s;
    // s.push(1);
    // cout<<s.peek()<<endl;
    // s.push(2);
    // cout<<s.peek()<<endl;
    // s.push(3);
    // cout<<s.peek()<<endl;
    // s.push(4);
    // cout<<s.peek()<<endl;
    // s.push(5);
    // cout<<s.peek()<<endl;
    // // s.push(5);
    // // cout<<s.peek()<<endl;
    // s.pop();
    // cout<<s.peek()<<endl;
    // s.pop();
    // cout<<s.peek()<<endl;
    // s.pop();
    // cout<<s.peek()<<endl;
    // s.pop();
    // cout<<s.peek()<<endl;
    // s.pop();
    // cout<<s.peek()<<endl;
    // s.pop();
    
    
    

    return 0;
}