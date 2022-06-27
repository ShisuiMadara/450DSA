// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int maxSubstring(string s)
	{
	    int n = s.length();
	    
	    vector<int>arr(n);
	    
	    for(int i = 0; i < n; ++i)
	    {
	        if(s[i] == '1')
	        {
	            arr[i] = -1;
	        }
	        else
	        {
	            arr[i] = 1;
	        }
	    }
	    int localMaxima = -2;
	    int maximum = INT_MIN;
	    
	    for(int i =0; i< n; ++i)
	    {
	        localMaxima = max(arr[i], localMaxima + arr[i]);
	        
	        maximum= max(maximum, localMaxima);
	    }
	    
	    return maximum;
	    
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends