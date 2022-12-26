#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const int MOD= 1000000007;


void solve()
{
    int n,p;
    cin>>n>>p;

    vector<int>arr(n), temp(n,0);

    for(auto&c:arr)cin>>c;

    if(n == 1 || p == 0) {
        cout<<0<<'\n';
        return;
    }

    temp = arr;

    int ans = 0;
    int nz = 0;
    int nzb = 0;
    int cnt = 0;


    while(cnt != n) {
        cnt = 0;

        for(int i = 0; i< n; ++i) {
            if(arr[i] != 0) {
                cnt++;

                if(i == 0) {
                    ans += 2;
                    temp[i+1] += 2;
                    
                } else if (i == n-1) {
                    ans += 2;
                    temp[i-1] += 2;

                } else {
                    ans += 4;
                    temp[i-1] += 2;
                    temp[i+1] += 2;
                }
            }
        }

        // if(cnt == 0) {
        //     cout<<0<<'\n';
        //     return;
        // }
        p-=1;
        arr = temp;
        // for(auto&c:temp) {
        //     cout<<c<<" ";
        // }
        // cout<< " ANS HERE "<<ans<<" ";
        // cout<<endl;
        if(p == 0){
            cout<<ans<<'\n';
            return;
        }
    }


    ans += (p)*(n-2)*4 + (p)*4;
    

    cout<<ans<<endl;

}



signed main() 
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
