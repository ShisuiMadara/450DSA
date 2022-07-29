//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	    int n = M;
	    int target = V;
	    
	    int dp[n+1][target+1];
	    
	    for(int i = 0; i<=n; ++i)
	    {
	        for(int j = 0; j<=target; ++j)
	        {
	            dp[i][j] = INT_MAX;
	            
	            if(j == 0)
	            {
	                dp[i][j] = 0;
	            }
	        }
	    }
	    
	    for(int  i = 0; i<=n; ++i)
	    {
	        for(int j = 0; j<=target;++j)
	        {
	            if(i == 0 || j ==0)
	            {
	                continue;
	            }
	            
	            if(j - coins[i-1] >=0 && dp[i][j-coins[i-1]] != INT_MAX)
	            {
	                dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i-1]]+1);
	            }
	            else
	            {
	                dp[i][j] = dp[i-1][j];
	            }
	        }
	    }
	    
	    if(dp[n][target] == INT_MAX)return -1;
	    return dp[n][target];
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends