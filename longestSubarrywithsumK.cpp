//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    public:
    int lenOfLongSubarr(int arr[],  int n, int k) 
    { 
        // Complete the function
        unordered_map<int, int> m;
    int prefix=0; 
    int maxlength=0;
    for(int i=0; i<n; i++){
        prefix+=arr[i];
        if(prefix==k){
            // return true;
            maxlength= max(maxlength, i + 1 ) ;
        }
        if(m.find(prefix-k)!=m.end()){
            maxlength= max(maxlength, i - (m.find(prefix-k)->second) ) ;
        }
        m.insert({prefix, i});
    }
    return maxlength;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends