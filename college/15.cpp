//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    void MakeZeros(vector<vector<int>> &a) {
        int n= a.size();
        int m = a[0].size();
        // cout<<m;
        vector<vector<int>>  fog(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]==0){
                    int sum = a[i-1][j]+a[i+1][j]+a[i][j-1]+a[i][j+1] ;
                    
                    fog[i][j]=sum;
                    fog[i+1][j]=0;
                    fog[i-1][j]=0;
                    fog[i][j-1]=0;
                    fog[i][j+1]=0;
                }else{
                    if((i>0 &&!a[i-1][j] )|| (i<n-1 && !a[i+1][j] )||  (j>0 && !a[i][j-1] )|| (j<m-1 && !a[i][j+1])) continue;
                    else fog[i][j] = a[i][j];
                }
            }
        }
        
        a=fog;
        // Code here
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		ob.MakeZeros(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cout << matrix[i][j] <<" ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends