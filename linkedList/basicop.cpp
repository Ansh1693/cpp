#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

class Node{
    public:
        int data;
        Node *next;
};

class LinkedList{
    private:
        Node *first;
    public:
        LinkedList(){
            first=NULL;
        }
        LinkedList(int A[],int n);
        ~LinkedList(){
            Node *temp=first;
            while(temp!=NULL){
                first=first->next;
                delete temp;
                temp=first;
            }
        };

        void Display(){
            Node *temp=first;
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<endl;
        };
        // void Insert(int index,int x);
        // int Delete(int index);
        // int Length();
};

int main()
{
    int A[]={1,2,3,4,5};
    LinkedList L(A,5);
    L.Display();
    return 0;
}

LinkedList::LinkedList(int A[],int n){
    Node *last , *t;
    int i=0;

    first= new Node;
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(i=1;i<n;i++){
        t=new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }

    }



