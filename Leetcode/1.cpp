#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
char check(char a,char b){
    if(a==b) return '0';
    else return '1';
}
int solve(string s , int n ,int k){
    int cnt1=0,cnt2=1;
    char l1='0',l2='1';
    for(int i=0;i<n-1;i++){
        //1
        l1= check(s[i],l1);
        if(l1=='1') cnt1++;
        //2
        l2= check(s[i],l2);
        if(l2=='1') cnt2++;
    }

    return cnt1>cnt2 ? cnt1: cnt2;

}   
int main()
{
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string s;
        cin>>s;
        cout<<solve(s,n,0)<<endl;
    }
    return 0;
}