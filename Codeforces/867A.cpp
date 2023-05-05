
	#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ll> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        ll ans=0;
        for(int i=0;i<n-1;i++){
            ll diff=a[i]-a[i+1];
            int j=i+1;
            while(j<n && a[j]-a[j-1]==diff) j++;
            int len=j-i;
            ans+=len*(len-1)/2;
            i=j-2;
        }
    cout<<ans<<endl;
    
    }


	return 0;
}
