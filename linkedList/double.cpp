#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

class Node{
    public:
        int data;
        Node *prev;
        Node *next;
};

class doubleList{
    private:
        Node* first;
        Node* last;
    public:
        doubleList(int A[],int n){
            Node *t;
            int i=0;

            first= new Node;
            first->data=A[0];
            first->prev=NULL;
            first->next=NULL;
            last=first;


            for(i=1;i<n;i++){
                t= new Node;
                t->data=A[i];
                t->next=last->next;
                t->prev=last;
                last->next=t;
                last=t;
            }

        }
        ~doubleList(){
            Node *temp=first;
            while(temp!=NULL){
                first=first->next;
                delete temp;
                temp=first;
            }
        }
        void display(){
            Node* temp=first;
            cout<<"first: "<<first->data<<"  last: "<<last->data<<endl;
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }
        void insertAtHead(int n){
            Node *temp=new Node;
            temp->data=n;
            temp->prev=NULL;
            temp->next=first;
            first->prev=temp;
            first=temp;
        }

        void insertAtTail(int n){
            Node *temp=new Node;
            temp->data=n;
            temp->next=NULL;
            temp->prev=last;
            last->next=temp;
            last=temp;
        }

        void insert(int d,int ind){
            if(ind==1){
            insertAtHead(d);
            return;
            }
            Node* temp=first;
            int i=1;
            while(i<ind-1){
                temp=temp->next;
                i++;
                }  
            if(temp->next==NULL){
                insertAtTail(d);
                return ;
            }

            Node* element= new Node;
            element->data=d;
            element->next=temp->next;
            element->prev=temp;
            temp->next = element;
            }

        int deleteAtHead(){
            Node* temp=first;
            int x=temp->data;
            temp->next->prev=NULL;
            first=temp->next;
            temp->next=NULL;
            delete temp;
            return x;
        }

        int deleteAtTail(){
            Node* temp=last;
            int x=temp->data;
            temp->prev->next=NULL;
            last=temp->prev;
            temp->prev=NULL;
            delete temp;
            return x;
        }

        int Delete(int ind){
            int x;
            if(ind==1){
                x=deleteAtHead();
                return x;
            }
            Node* temp=first;
            Node* temp2=NULL;
            int i=1;
            while(i<ind){
                temp2=temp;
                temp=temp->next;
                i++;
                }  
            if(temp->next==NULL){ 
                x=deleteAtTail();
                return x;
            }

            temp2->next=temp->next;
            temp->prev=NULL;
            temp->next->prev=temp2;
            x=temp->data;
            temp->next=NULL;
            delete temp;
            return x;
        }
};

int main()
{
    int A[]={1,2,3,4,5};
    doubleList D(A,5);
    D.display();
    D.insert(8,1);
    D.display();
    D.insert(7,7);
    D.display();
    D.insert(6,3);
    D.display();
    D.Delete(3);
    D.display();
    return 0;
} 