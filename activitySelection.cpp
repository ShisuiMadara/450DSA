// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>>arr(n);
        
        for(int i = 0; i< n; ++i)
        {
            arr[i] = {end[i], start[i]};
            
        }
        
        sort(arr.begin(), arr.end());
        
        int ans = 0;
        int here = -1;
        for(int i = 0; i< n; ++i)
        {
            if(here == -1)
            {
                here = arr[i].first;
                ans++;
            }
            else if(here < arr[i].second)
            {
                here = arr[i].first;
                ans++;
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends