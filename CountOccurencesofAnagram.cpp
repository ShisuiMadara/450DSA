//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    vector<int>freq(26,0);
	    vector<int>target(26,0);
	    
	    
	    int k = pat.length();
	    int n = txt.length();
	    
	    for(int i = 0; i<k;++i)
	    {
	        target[pat[i]-'a']++;
	    }
	    for(int i= 0; i< k; ++i)
	    {
	        freq[txt[i]-'a']++;
	    }
	    
	    int left = 0, right = k-1;
	    int ans = 0;
	    while(right < n)
	    {
	        if(target == freq)
	        {
	            ans ++;
	        }
	        freq[txt[left]-'a']--;
	        left++;
	        right++;
	        if(right < n)
	            freq[txt[right]-'a']++;
	    }
	    
	    return ans;`
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends