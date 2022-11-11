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

        int height(Node* p){
            int x,y;
            // Node* p = root;
            if(p!=NULL){
                x= height(p->left);
                y= height(p->right);
                return (x>y?x+1: y+1) ;
            }
            return 0;
        };

        Node* inPre(Node* p){
            if(p && p->right==NULL) return p;
            return inPre(p->right);
        };

        Node* inSuc(Node* p){
            if(p && p->left == NULL) return p;

            return inSuc(p->left);
        };

        Node* Delete(Node* p, int key){
            Node* q;
            if(p==NULL) return NULL;
            
            if(p->left==NULL && p->right==NULL){
                if(p==root) root=NULL;
                
                free(p);
                return NULL;
            }

            if(p->data>key) p->left=Delete(p->left, key);

            else if(p->data<key) p->right= Delete(p->right, key);

            else{
                if(height(p->left)> height(p->right)){
                    q= inPre(p->left);
                    p->data=q->data;
                    p->left=Delete(p->left, q->data);
                }else{
                    q= inSuc(p->right);
                    p->data=q->data;
                    p->right=Delete(p->right, q->data);
                }
            };
            return p;

        };

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
    cout<<"\n";
    A.levelOrder(A.root);
    cout<<"\n";

    A.Delete(A.root,10);
    A.inorder(A.root);
    cout<<"\n";
    A.levelOrder(A.root);
    // A.inorder(A.root);

    return 0;
}