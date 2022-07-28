//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
    queue<int>q;
    
    for(int i = 0; i< K; ++i)
    {
        if(A[i] < 0)
        {
            q.push(i);
        }
    }
    
    int left  =0, right = K-1;
    vector<long long>ans;
    
    while(right < N)
    {
        if(q.empty())
        {
            ans.push_back(0);
            left++;
            right++;
            if(A[right]<0)
            {
                q.push(right);
            }
            continue;
        }
        int here = q.front();
        
        
        if(here >= left)
        {
            ans.push_back(A[here]);
        }
        else
        {
            ans.push_back(0);
        }
        
        left++;
        right++;
        
        if(A[right]<0)
        {
            q.push(right);
        }
        while(q.front() < left && !q.empty())
        {
            q.pop();
        }
    }
    
    return ans;
 }