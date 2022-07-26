#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD= 1000000007;



void solve()
{
    int n,cows;
    cin>>n>>cows;

    vector<int>arr(n);

    for(auto&c:arr)cin>>c;

    sort(arr.begin(),arr.end());

    int low = 0, upper = arr[n-1];
    int ans = -1;
    while(low <= upper)
    {
        int guess = (upper+low)/2;
        int cnt = 0;

        int pos = arr[0];
        cnt = 1;
        for(int i = 1; i< n; ++i)
        {
            if(arr[i]-pos >= guess)
            {
                pos = arr[i];
                cnt++;
            }
        }

        if(cnt>=cows)
        {
            low = guess+1;
            ans = guess;
           // cout<<ans<<" ";
        }
        else
        {
            upper = guess-1;
        }
    }

    cout<<ans<<'\n';
    return;

}



int main() 
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

     ll test=1;
    cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
