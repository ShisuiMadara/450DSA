// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    
   bool solve(string &A,string &B,string &C,int n,int m,int len,vector<vector<int>>&dp)

    {

        if(len<0) return 1;

            if(n<0) return 1; 

            if(m<0) return 1;

        if(dp[n][m]!=-1)

            return dp[n][m];

        int a=0,b=0;

        if(A[n]==C[len])

            a=solve(A,B,C,n-1,m,len-1,dp);

        if( B[m]==C[len])

            b=solve(A,B,C,n,(m-1),(len-1),dp);

        return dp[n][m]=(a or b);

    }

    bool isInterleave(string A, string B, string C) 

    {

        int n=A.length(),m=B.length(),len=C.length();

        if(n+m!=len)

            return false; 

        vector<vector<int>>dp(n,vector<int>(m,-1));

        return solve(A,B,C,n-1,m-1,len-1,dp);

    }

};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}  // } Driver Code Ends