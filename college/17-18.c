#include <stdio.h>
#include<stdlib.h>
#include<malloc.h>
// #include <stdbool.h>

typedef struct Node{
        struct Node* left;
        int data;
        struct Node* right;
} tree_node;

typedef struct node{
    tree_node* curr;
    struct node* next;
} stack_node;

stack_node* headS = NULL;

tree_node* root = NULL;

void stackPush(tree_node* x){
    stack_node* temp = (stack_node*)malloc(sizeof(stack_node));
    temp->curr = x;

    temp->next = NULL;

    if(headS == NULL){
        headS = temp;
        // printf("gg");
        return;
    }
    else{

    temp->next = headS;
    headS = temp;
    }
}

void stackPop(){
    if(headS == NULL){
        // printf("Underflow!!\n");
        return;}
    stack_node* temp = headS;
    headS = headS->next;
    free(temp);
}

tree_node* stackPeep(){
    if(headS == NULL){
        // printf("Underflow!!");
        return NULL;}
    return headS->curr;

}

void stackPre(tree_node* root){
    if(root==NULL){
        printf("tree Empty");
        return;
    }

    stackPush(root);
    while(headS!=NULL){
        tree_node* temp = stackPeep();
        stackPop();
        printf("%d ",temp->data);
        if(temp->right!=NULL){
            stackPush(temp->right);
        }
        if(temp->left!=NULL){
            stackPush(temp->left);
        }
    }
}
void stackPost(tree_node* root){
    if(root==NULL){
        printf("tree Empty");
        return;
    }

    tree_node* curr=root;

    while(curr!=NULL || headS!=NULL){
        if(curr!=NULL){
            stackPush(curr);
            curr=curr->left;
        }
        else{
            tree_node* temp = stackPeep()->right;
            if(temp==NULL){
                temp = stackPeep();
                stackPop();
                printf("%d ",temp->data);
                while(headS!=NULL && temp==stackPeep()->right){
                    temp = stackPeep();
                    stackPop();
                    printf("%d ",temp->data);
                }
            }
            else{
                curr=temp;
            }
        }

    }
}

void stackIn(tree_node* root){
    if(root==NULL){
        printf("tree Empty");
        return;
    }

    tree_node* curr=root;

    while(curr!=NULL || headS!=NULL){
        if(curr!=NULL){
            stackPush(curr);
            curr=curr->left;
        }
        else{
            if(headS==NULL) break;
            tree_node* temp = stackPeep();
            stackPop();
            printf("%d ",temp->data);
            curr=temp->right;
        }

    }
}
void inorder(tree_node* p){
            if(p){
                inorder(p->left);
                printf("%d ",p->data);
                inorder(p->right); 
            }
        }

        void preorder(tree_node* p){
            if(p){
                printf("%d ",p->data);
                preorder(p->left);
                preorder(p->right); 
            }
        }
        void postorder(tree_node* p){
            if(p){
                postorder(p->left);
                postorder(p->right); 
                printf("%d ",p->data);
            }
        }

void insert(int key){
            tree_node *p;
            if(root==NULL){
                tree_node* t = (tree_node*)malloc(sizeof(tree_node));
                t->data=key;   
                t->left=t->right=NULL;
                root=t;
                return;
            }

            tree_node *r= root;

            while(r!=NULL){
                p=r;
                if(key<r->data) r=r->left;
                else if(key>=r->data) r=r->right;
                else return;
            }
            tree_node* t = (tree_node*)malloc(sizeof(tree_node));;
            t->data=key;
            t->left=t->right=NULL;

            if(key<p->data)  p->left=t;
            else p->right=t;
            return;
        }
    int height(tree_node* p){
            int x,y;
            // tree_node* p = root;
            if(p!=NULL){
                x= height(p->left);
                y= height(p->right);
                return (x>y?x+1: y+1) ;
            }
            return 0;
        };

        tree_node* inPre(tree_node* p){
            if(p && p->right==NULL) return p;
            return inPre(p->right);
        };

        tree_node* inSuc(tree_node* p){
            if(p && p->left == NULL) return p;

            return inSuc(p->left);
        };

        tree_node* Delete(tree_node* p, int key){
            tree_node* q;
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

    int search(tree_node *root, int key){
        int cnt=0;
        tree_node* temp=root;
        while (temp != NULL)
        {
          if (temp->data == key)
          {
               cnt++;
               temp=temp->right;
          }
          else if (temp->data < key)
          {
               temp = temp->right;
          }
          else
          {
               temp = temp->left;
          }
    }

    return cnt;
}

    int main(){

        int tc = 1;
    //  struct node *root = NULL;
     while (tc)
     {
          int kk, alpha, beta;
          printf("\nWhat operation you want to operate on BST;\n1. INSERT\n2. DELETE \n3. TRAVERSE\n4. SEARCH\n5. EXIT\n");
          scanf("%d", &kk);
          switch (kk)
          {
          case 1:
               printf("\nWhat data yu want to input in BST\n");
               scanf("%d", &alpha);
               insert( alpha);
               printf("\nCurrent BST Inorder traversal : ");
               stackIn(root);
               printf("\n");
               break;
          case 2:
               if (root == NULL)
               {
                    printf("\nBST is Empty!!!\n");
                    break;
               }
               printf("\nWhat data yu want to delete from BST\n");
               scanf("%d", &alpha);
               if (search(root, alpha))
               {
                    root = Delete(root, alpha);
               }
               else
               {
                    printf("\nEntered input is not present in BST\n");
               }
               printf("\nCurrent BST Inorder traversal : ");
               inorder(root);
               printf("\n");
               break;
          case 3:
               if (root == NULL)
               {
                    printf("\nBST is Empty!!!\n");
                    break;
               }
               printf("\nWhat traversal you want o perform\n1. Preorder using recursion\n2. Inorder using recursion \n3. Postorder using recursion \n4. Preorder using stacks\n5. Inorder using stacks\n6. Postorder using stacks\n");
               scanf("%d", &beta);
               switch (beta)
               {
               case 1:
                    printf("\nCurrent BST preorder traversal using recursion: ");
                    stackPre(root);
                    printf("\n");
                    break;
               case 2:
                    printf("\nCurrent BST Inorder traversal using recursion: ");
                    inorder(root);
                    printf("\n");
                    break;
               case 3:
                    printf("\nCurrent BST postorder traversal using recursion: ");
                    postorder(root);
                    printf("\n");
                    break;
               case 4:
                    printf("\nCurrent BST preorder traversal using stacks: ");
                    stackPre(root);
                    printf("\n");
                    break;
               case 5:
                    printf("\nCurrent BST Inorder traversal using stacks: ");
                    stackIn(root);
                    printf("\n");
                    break;
                case 6:
                    printf("\nCurrent BST postorder traversal using stacks: ");
                    stackPost(root);
                    printf("\n");
                    break;
               default:
                    printf("\nEntered an invalid Input\n");
                    break;
               }

               break;
          case 4:
               if (root == NULL)
               {
                    printf("\nBST is Empty!!!\n");
                    break;
               }
               printf("\nWhat data you want to search in BST\n");
               scanf("%d", &alpha);
               if (search(root, alpha))
               {
                    printf("\nEntered input is present in BST %d times\n",search(root,alpha));
                    break;
               }
               else
               {
                    printf("\nPresent input is not present in BST\n");
               }
               break;
          case 5:
               tc = 0;
               printf("\nYou have exited Successfully\n");
               break;
          default:
               printf("\nEntered an invalid input\n");
               break;
          }
     }


        return 0;
    }
