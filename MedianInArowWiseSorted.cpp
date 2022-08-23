//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int r, int c){
        
        int i = 0;
        
        int cnt = 0 ;
        
        int total = r*c;
        
        total = total/2;
        
        vector<int>v;
        
        for(int i = 0; i< r; i++)
        {
            for(int j = 0; j< c; ++j)
            {
                v.push_back(matrix[i][j]);
            }
            //i++;
        }
        
        sort(v.begin(), v.end());
        
        return v[total];
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}
// } Driver Code Ends