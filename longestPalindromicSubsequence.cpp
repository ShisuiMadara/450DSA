// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

// class Solution{
//   public:
//     int longestPalinSubseq(string s) {
        
//         int n = s.length();
        
//         int dp[n+1][n+1];
        
//         string s2;

//         for(int i = n-1; i>=0; i--)
//         {
//             s2 += s[i];
//         }

//         for(int i = 1; i<=n; ++i)
//         {
//             for(int j = 1; j<=n; ++j)
//             {
//                 dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

//                 if(s[i-1] == s2[j-1])
//                 {
//                     dp[i][j] = dp[i-1][j-1] + 1;
//                }
//             }
//         }

//         return dp[n][n];

//     }
// };

class Solution{
  public:
    int longestPalinSubseq(string str) {
        
    int n = str.length();
        
    int i, j, cl;
    int L[n][n];  
    
    
    for (i = 0; i < n; i++)
      L[i][i] = 1;
    
    
    for (cl=2; cl<=n; cl++)
    {
        for (i=0; i<n-cl+1; i++)
        {
            j = i+cl-1;
            if (str[i] == str[j] && cl == 2)
               L[i][j] = 2;
            else if (str[i] == str[j])
               L[i][j] = L[i+1][j-1] + 2;
            else
               L[i][j] = max(L[i][j-1], L[i+1][j]);
        }
    }
    
    return L[0][n-1];
    
    }
};

// { Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends