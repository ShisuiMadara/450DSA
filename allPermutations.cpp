// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public: 
	    set<string>ans;
	
	    void permute(string str, int l, int r)
	    {
	        if(l == r)
	        {
	            ans.insert(str);
                return;            
	        }
	        
	        for(int i = l; i<=r; ++i)
	        {
    	        swap(str[l], str[i]);
    	        
    	        permute(str, l+1, r);
    	        
    	        swap(str[l], str[i]);
	        }
	    }
	    
		vector<string>find_permutation(string S)
		{
		    int n = S.length();
		    
		    permute(S, 0, n-1);
		    
		    vector<string>f;
		    
		    for(auto&c:ans)
		    {
		        f.push_back(c);
		    }
		    
		    return f;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends