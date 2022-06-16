// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
       vector<int>v(n+1,0);
       
       for(int i=1;i<=n;i++)
       {
       int r1=INT_MIN,r2=INT_MIN,r3=INT_MIN;
       if(i>=x)
       r1=1+v[i-x];
       if(i>=y)
       r2=1+v[i-y];
       if(i>=z)
       r3=1+v[i-z];
       v[i]=max(max(r1,r2),r3);
       }
       if(v[n]<0)
       return 0;
       return v[n];
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends