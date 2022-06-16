// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        int memo[n][m];

        memset(memo, sizeof(memo), 0);

        for(int row = n-1; row >= 0; row--)
        {
            for(int col = 0; col < m; ++col)
            {
                //from each cell from the last, we either go left, or digonally up left or digonally down left
                memo[row][col] = M[row][col];

                int left = 0;

                if(col-1 >=0 )
                    left = memo[row][col-1];

                int upper_left = 0;
                if(col-1 >= 0 && row -1 >=0)
                {
                    upper_left = memo[row-1][col-1];
                }

                int lower_left = 0;

                if(col-1 >=0 && row + 1 < n)
                {
                    lower_left = memo[row+1][col-1];
                }

                memo[row][col] += (max(left, max(upper_left, lower_left)));
            }
        }

        int ans = -1;

        int mx = -1;
        for(int i = 0; i< m; ++i)
        {
            if(mx > memo[0][i])
            {
                mx = memo[0][i];
                ans = i;
            }            
        }

        return ans;
    }
};


// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}  // } Driver Code Ends