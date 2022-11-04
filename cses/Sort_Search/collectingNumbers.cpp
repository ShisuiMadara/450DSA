#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const int MOD= 1000000007;


void solve()
{
    int n;
    cin>>n;

    vector<int>arr(n);

    for(auto&c:arr)cin>>c;

    int cnt = 1;

    if(n == 0) {
        cout<<cnt;
        return;
    }

    int min = arr[0];

    for(int i = 1; i< n; ++i) {
        if(arr[i] < min) {
            cnt ++;
        }
        min = arr[i];
    }


    cout<<cnt;
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
