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
        int Length(){
            Node *temp=first;
            int count=0;
            while(temp!=NULL){
                count++;
                temp=temp->next;
            }
            return count;
        };
        int Sum(){
            Node *temp=first;
            int sum=0;
            while(temp!=NULL){
                sum+= temp->data;
                temp=temp->next;
            }
            return sum;
        };
        int max(){
            Node *temp=first;
            int max=0;
            while(temp!=NULL){
                if(temp->data>max)
                    max=temp->data;
                temp=temp->next;
            }
            return max;
        };
};

int main()
{
    int A[]={1,2,3,4,5};
    LinkedList L(A,5);
    L.Display(); 
    cout<<"Length is:"<<L.Length()<<endl<<"Sum is:"<<L.max()<<endl;
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



