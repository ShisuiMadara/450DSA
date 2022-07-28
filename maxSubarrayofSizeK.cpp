//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        int left = 0, right = K-1;
        
        long long  here = 0;
        int f = 0;
        
        for(int i = 0; i< K; ++i)
        {
            here += Arr[i];
        }
        
        
        long long ans  = INT_MIN;
        
        while(right < N)
        {
            ans = max(ans, here);
            left++;
            right++;
            
            if(right < N)
            {
                here -= Arr[left-1];
                here += Arr[right];
            }
        }
        
        //ans = max(ans, here);
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends