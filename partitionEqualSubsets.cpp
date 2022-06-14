// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        long long sum = 0;
        
        for(int i = 0; i< N; ++i)
        {
            sum += arr[i];
        }
        
        if(sum%2) return 0;
        
        long long target = sum / 2;
        
        vector<bool>possible(target + 1, false);
        
        possible[0] = true;
        
        for(int i = 0; i < N; ++i)
        {
            for(int j = target; j>= 0; j--)
            {
                if(j- arr[i] >=0)
                {
                    possible[j] = possible[j- arr[i]] || possible[j];
                }
            }
        }
        
       
        if(possible[target])return 1;
        
        return 0;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends