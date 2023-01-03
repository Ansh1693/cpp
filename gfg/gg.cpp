#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int count(string s, char c)
{
    
    int res = 0;
    
    for (int i=0;i<s.length();i++)
 
        
        if (s[i] == c)
            res++;
 
    return res;
}

int main() {
	// your code goes here
	int t;cin>>t;
	while(t--){
        int n;cin>>n;
	    string a,b;
	    cin>>a;
	    cin>>b;
	    char arr[n];
	    int count=0;
	    for(int i=0;i<n;i++){
            //cout<<a;
	        if(a[i]==b[i]){
                //cout<<a;
                continue;
	        }
            else{
                //cout<<a;
	            if(find(arr ,arr+n,b[i])!=arr+n){
                    continue;
                }
                else{
                    count++;
                    arr[i]=b[i];
                }}
	    }
        cout<<count<<endl;
	}
	return 0;
}
