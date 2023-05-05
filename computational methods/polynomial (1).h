#include<bits/stdc++.h>
using namespace std;

class Polynomial{
    public:
        int size;
        // vector<int>coeff;
        int *arr;

        Polynomial(int size){
            this->size = size;
            arr = new int[size];
        }
        void insert(){
            for(int i=0;i<=size;i++){
                cout<<"Enter coefficient of Power "<<i<<" : ";
                cin>>arr[i];
                // int co;
                // cin>>co;
                // coeff.push_back(co);
            }
        }
        void print(){
            for(int i=size;i>=0;i--){
                // cout<<"Power "<<i<<" : "<<coeff[i]<<endl;
                // cout<<"Power "<<i<<" : "<<arr[i]<<endl;
                if(i==0) cout<<arr[i]<<endl;
                else cout<<arr[i]<<"x^"<<i<<" + ";
            }
        }
        void addConstant(int num){
            arr[0] += num;
        }
        void subtConstant(int num){
            arr[0] -= num;
        }
        void addPoly(){
            cout<<"Current Polynomial"<<endl;
            this->print();
            
            cout<<"Enter coefficient to add for"<<endl;
            for(int i=0;i<=size;i++){
                cout<<"x^"<<i<<": ";
                int num; cin>>num;
                arr[i]+=num;
            }

            cout<<"New Polynomial"<<endl;
            this->print();
        }
        void findDerivative(int x){
            cout<<"Current Polynomial"<<endl;
            this->print();
            cout<<endl;
            int derivative = 0;
            for(int i=size;i>0;i--){
                derivative += (i * arr[i]*pow(x,(i-1)));
            }
            cout<<"The derivative of given polynomial for given x is: "<<derivative<<endl;
        }
};