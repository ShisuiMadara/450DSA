// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    void heapify(int arr [], int n, int index)
    {
        int larger = index;
        int left = 2*index + 1;
        int right = 2*index + 2;
        
        if(left < n && arr[left] > arr[larger])
        {
            larger = left;
        }
        if(right < n && arr[right] > arr[larger])
        {
            larger = right;
        }
        if(larger != index)
        {
            //cout<<"HI";
            swap(arr[larger], arr[index]);
            
            heapify(arr, n, larger);
        }
    }
    
    void make_max_heap(int arr[], int n)
    {
        for(int i = n/2 - 1; i >= 0; i--)
        {
            heapify(arr, n, i);
        }
    }
    
    vector<int> max_of_subarrays(vector<int>arr, int n, int k) 
    {
        
        int ptr = k-1;
        int lower = 0;
        
        
        vector<int>ans;
        while(ptr < n)
        {
            int here [k];
           
            int j = 0;
            for(int i = lower; i <= ptr; ++i)
            {
                here[j] = arr[i];
            }
            make_max_heap(here, k);
            
            
            ans.push_back(here[0]);
            ptr++;
            lower++;
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}  // } Driver Code Ends