//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    bool isPalindrome(string s, int i , int j)
    {
        while(i<=j)
        {
            if(s[i] == s[j])
            {
                i++;
                j--;
                
            }
            else
            {
                return false;
            }
        }
        
        return true;
    }
    
    
    int recursion(string str, int i, int j, vector<vector<int>>& memo, int ans)
    {
        if(i>j)return 0;
        
        if(memo[i][j] != -1)return memo[i][j];
        
        if(isPalindrome(str,i,j)) return 0;
        
        for(int k = i; k<j; ++k)
        {
            int left, right;
            
            if(memo[i][k] != -1)
           {
               left = memo[i][k];
               
           }
           else
           {
               left =recursion(str,i,k,memo,ans) ;
           }
           
           if(memo[k+1][j] != -1)
           {
               right = memo[k+1][j];
           }
           else
           {
               right = recursion(str,k+1,j,memo,ans);
           }
            int temp =  left+ right + 1;
            ans = min(ans, temp);
        }
        
        return memo[i][j] = ans;
    }
    int palindromicPartition(string str)
    {
        int n = str.length();
        vector<vector<int>>memo(n+1,vector<int>(n+1,-1));
        
        //memset(memo,-1,sizeof(memo));
        int ans = INT_MAX;
        return recursion(str,0,n-1,memo,ans);
        
        //return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends