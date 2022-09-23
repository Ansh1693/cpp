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


class Tree{
    public:
        Node* root;
        Tree(){ root=NULL;}

        void createTree(){
            Node *p,*t;
            int x;
            queue <Node*> q;
            cout<<"Enter value of root :";
            cin>>x;
            cout<<endl;

            root= new Node;
            root->data=x;
            root->left=root->right=NULL;
            q.push(root);
            

            while(!q.empty()){
                p=q.front();
                q.pop();
                cout<<"Enter value for left:";
                cin>>x;
                cout<<endl;
                if(x!=-1){
                    t= new Node;
                    t->data=x;
                    t->left=t->right=NULL;
                    p->left=t;
                    q.push(t);
                }

                cout<<"Enter value for right:";
                cin>>x;
                cout<<endl;
                if(x!=-1){
                    t= new Node;
                    t->data=x;
                    t->left=t->right=NULL;
                    p->right=t;
                    q.push(t);
                }
            }

        }

        void preorder(Node* p){
            

            if(p){
                cout<<p->data<<"  ";
                preorder(p->left);
                preorder(p->right);
            }
        }

        void inorder(Node* p){
            if(p){
                inorder(p->left);
                cout<<p->data << " ";
                inorder(p->right); 
            }
        }

        void postorder(Node* p){
            if(p){
               
                postorder(p->left);
                postorder(p->right); 
                cout<<p->data << " ";
            
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

        int countNodes(Node* p){
            int x,y;
            // Node* p = root;
            if(p!=NULL){
                x= countNodes(p->left);
                y= countNodes(p->right);
                return x+y+1;
            }
            return 0;
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
        }

        int countLeaf(Node *p){
            int x,y;
            // Node* p = root;
            if(p!=NULL){
                x= countLeaf(p->left);
                y= countLeaf(p->right);
            if(!p->left && ! p->right) return x+y+1;
            else return x+y;
            }
            return 0;
        }

};

int main()
{
    Tree A;
    A.createTree();
    A.levelOrder(A.root);
    cout<<"\n";
    cout<<A.countNodes(A.root);
    cout<<"\n";
    cout<<A.countLeaf(A.root);
    cout<<"\n";
    cout<<A.height(A.root);
    return 0;
}
// 10
// 4 6
//2 2 3 3
//1 1 2 -1 1 2 3 -1

// 10 4 6 2 2 3 3 1 1 2 0 1 2 3 0 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1