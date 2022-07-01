// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    
    public:
    int transfigure (string s, string t)
    {
    	int n = s.length();
    	
    	if(n != t.length())return -1;
    	
    	int i = n-1;
    	int j = n-1;
    	
    	int ans = 0;
    	
    	map<char,int>mp;
    	
    	for(int i = 0; i< n; ++i)
    	{
    	    mp[s[i]]++;
    	    mp[t[i]]--;
    	}
    	
    	for(auto&c:mp)
    	{
    	    if(c.second != 0)
    	    {
    	        return -1;
    	    }
    	}
    	
    	while(i>=0)
    	{
    	    if(s[i] == t[j])
    	    {
    	        i--;
    	        j--;
    	        continue;
    	    }
    	    else
    	    {
    	        ans++;
    	        i--;
    	    }
    	}
    	
    	return ans;
    }
};

// { Driver Code Starts.


int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution obj;
        cout << obj.transfigure (A, B) << endl;
    }
}  // } Driver Code Ends