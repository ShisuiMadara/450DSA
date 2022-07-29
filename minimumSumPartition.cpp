//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{

  public:
  
    vector<int> isSubsetSum(int arr[], int n, int sum){
        
        vector<int> res;
        
        bool dp[n + 1][sum + 1];
        
        dp[0][0] = true;
        
        for(int j = 1; j < sum + 1; j++)
            dp[0][j] = false;
            
        for(int i = 0; i < n + 1; i++)
            dp[i][0] = true;
            
        for(int i = 1; i < n + 1; i++)
            for(int j = 1; j < sum + 1; j++){
                
                if(j >= arr[i - 1])
                    dp[i][j] = dp[i -1][j - arr[i - 1]] || dp[i -1][j];
                
                else
                    dp[i][j] = dp[i - 1][j];
            }
            
        
        for(int j = 0; j <= ( sum)/2; j++){
            
            if(dp[n][j])
                res.push_back(j);
        }
        
        return res;
    }
    
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    
	    int range = accumulate(arr, arr + n, 0);
	    
	    vector<int> res = isSubsetSum(arr, n, range);
	    int res_n = res.size();
	    int mn = INT_MAX;
	    
	    for(int i = 0; i < res_n; i++){
	        
	        mn = min(mn, range - (2 * res[i]));
	    }
	    
	    return mn;
	    
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends