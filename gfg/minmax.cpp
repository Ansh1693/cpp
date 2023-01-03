//#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;
int min(int n,int m){return n>m?m:n;}
int max(int n,int m){return m>n?m:n;}

int minMax(vector<int>n){
    vector <int> m;
    int a=n.size();
    if(a==1) return n[0];
    else{
        for(int i=0;i<a/2;i++){
            m[i]= i%2==0?min(n[2*i],n[2*i +1]):max(n[2*i],n[2*i +1]);
        }    
    }
    minMax(m);
    return 0;
    
}

int main(){
    int val;
    std::vector<int> vec; 
    while(std::cin >> val) {
        if(val == 0) break;
        vec.push_back(val);
    }
    int w=minMax(vec);
    cout<<w<<endl;
}
