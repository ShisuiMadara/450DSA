//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    
    long long int inversionCount(long long arr[], long long n)
    {
        multiset<int> set1;
    set1.insert(arr[0]);
  
    int invcount = 0; 
  
    multiset<int>::iterator itset1;
  

    for (int i=1; i<n; i++)
    {
     
        set1.insert(arr[i]);
  
        itset1 = set1.upper_bound(arr[i]);
 
        invcount += distance(itset1, set1.end());
    }
     return invcount;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends