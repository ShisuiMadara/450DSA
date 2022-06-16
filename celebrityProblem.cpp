// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
   public:
   //Function to find if there is a celebrity in the party or not.
   int celebrity(vector<vector<int> >& M, int n) 
   {
       stack<int> st;
       for(int i=0; i<n; i++)
           st.push(i);
       
       while(st.size() > 1)
       {
           int first = st.top();
           st.pop();
           
           int second = st.top();
           st.pop();

           if(M[first][second] == 1)
               st.push(second);
           else
               st.push(first);
               
       }
       
       int C = st.top();
       int c = 0;
       
       for(int i=0; i<n; i++)
       {
           if(M[i][C] == 1 && i != C)
               c++;
           if(M[C][i] == 1 && i != C)
                return -1;
              
       }
       if(c == n-1)
           return C;
       return -1;
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
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends