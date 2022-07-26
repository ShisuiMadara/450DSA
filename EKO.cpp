#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD= 1000000007;

#define int long long

void solve()
{
    int n,k;
    cin>>n>>k;

    vector<int>arr(n);

    for(auto&c:arr)cin>>c;

    sort(arr.begin(), arr.end());

    int low = 0, high = arr[n-1];

    int ans = -1;

    while(low <= high)
    {
        int guess = low + (high-low)/2;
        int here = 0;
        for(int i = 0; i< n; ++i)
        {
            if(arr[i] > guess)
            {
                here += (arr[i] - guess);
            }
        }
        if(here == k)
        {
            ans = guess;
            
        }
        if(here < k)
        {
            high = guess-1;
        }
        else
        {
            low = guess+1;
        }
    }

    cout<<min(ans,low)<<'\n';
    return;    
}



signed main() 
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


     ll test=1;
//cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
