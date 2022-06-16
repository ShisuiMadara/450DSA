// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    int countFriendsPairings(int n) 
    {   const int MOD = 1e9 + 7;
    
         vector<long long> dp(n+1,0);
        dp[0]=1;  // null subset
        dp[1]=1;  // 1 way possible
        
        for(int i=2;i<=n;i++)
        {
            dp[i]=(dp[i-1]%MOD + ((i-1)*dp[i-2])%MOD);
        }
        return dp[n]%MOD;
    }
};    
 

// { Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 
  // } Driver Code Ends