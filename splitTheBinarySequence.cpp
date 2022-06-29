// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int maxSubStr(string s){
        
        int n = s.length();
        
        int cnt0 = 0, cnt1= 0;
        int ans = 0;
        
        for(int i = 0; i< n; ++i)
        {
            if(s[i] == '1')
            {
                cnt1++;
            }
            else
            
            {
                cnt0 ++;
            }
            
            if(cnt1 == cnt0)
            {
                ans ++;
                cnt1 =0;
                cnt0 = 0;
            }
        }
        
        return (cnt1 == 0 && cnt0 == 0) ? ans : -1;
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.maxSubStr(str);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends