#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

class Node{
    public:
        Node* left;
        int data;
        Node* right;

};

class bst{
    private:
    
    public:
        Node* root;
        bst(){root= NULL;}

        void inorder(Node* p){
            if(p){
                inorder(p->left);
                cout<<p->data << " ";
                inorder(p->right); 
            }
        }

        void levelOrder(Node* p){
            queue<Node*> q;
            q.push(p);
            q.push(NULL);

            while(!q.empty()){
                Node *temp=q.front();
                q.pop();

                if(temp==NULL){
                    cout<<endl;
                    if(!q.empty()){
                        q.push(NULL);
                    }
                }else{

                cout<<temp->data<< " ";

                if(temp->left){
                    q.push(temp->left);
                }

                if(temp->right){
                    q.push(temp->right);
                }
                } 
            }
        }

        void insert(int key){
            Node *p,*t;
            if(root==NULL){
                t= new Node;
                t->data=key;   
                t->left=t->right=NULL;
                root=t;
                return;
            }
            Node *r= root;

            while(r!=NULL){
                p=r;
                if(key<r->data) r=r->left;
                else if(key>r->data) r=r->right;
                else return;

            }
            t=new Node;
            t->data=key;
            t->left=t->right=NULL;

            if(key<p->data)  p->left=t;
            else p->right=t;
            return;
        }
};

int main()
{
    bst A;
    A.insert(10);
    A.insert(8);
    A.insert(15);
    A.insert(7);
    A.insert(5);
    A.insert(18);
    A.insert(17);
    A.insert(25);
    A.inorder(A.root);
    A.levelOrder(A.root);
    return 0;
}