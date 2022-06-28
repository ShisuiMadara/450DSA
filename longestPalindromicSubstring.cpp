// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    string longestPalin (string str) {
        int n = str.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        // store the starting index of longest palindrome
        int start_idx = 0;
        // store the length of longest palindrome
        int length = 0;
        // fill the dp table
        for (int gap = 0; gap < n; gap++)
        {
            for (int start = 0; start + gap < n; start++)
            {
                int end = start + gap;
                // if only a single character
                if (gap == 0)
                {
                    dp[start][end] = true;
                }
                // if the substring consist of only 2 character
                else if (gap == 1)
                {
                    if (str[start] == str[end])
                    {
                        dp[start][end] = true;
                    }
                }
                else
                {
                    if (str[start] == str[end])
                    {
                        dp[start][end] = dp[start + 1][end - 1];
                    }
                }
                // Update the result
                if (dp[start][end])
                {
                    length = gap + 1;

                    start_idx = start;
                }
            }
        }
        if(length == 1)
        {
            return str.substr(0,1);
        }
        return str.substr(start_idx, length);
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
