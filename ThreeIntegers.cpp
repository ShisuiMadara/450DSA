#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD= 0000000007;
#define int long long



void solve()
{
    vector<int> v(3);

    for(auto&c:v)cin>>c;

    sort(v.begin(), v.end());

    int ans = 0;

    while(true)
    {
        if(v[1] == v[0] && v[0] == v[2])
        {
            ans += v[1];
            break;
        }

        if(v[0] > v[1])
        {
            int diff = v[0] - v[1];

            v[0] -= diff;
            v[2] -= diff;

            ans += diff;
            continue;
        }

        if(v[0] < v[1])
        {
            int diff = v[1] - v[0];

            v[0] -= diff;
            v[2] -= diff;

            ans += diff;
            continue;
        }

        if(v[0] == v[1])
        {
            if(v[2] == 2*v[1])
            {
                ans += v[2];
                break;
            }

            int lower = 0;
            int upper = v[2];

            while(lower < upper)
            {
                int k = lower + (upper - lower)/2;
                
                if(v[1] - k >= 0 && ((v[1] - k) == (v[2] - 2*k)))
                {
                    //cout<<"HERE";
                    ans += 2*k;
                    ans += abs(v[1] - k);
                    cout<<ans<<'\n';
                    return;
                  
                }

                if((v[2] - 2*k)-(v[1] - k) < 0)
                {
                    upper = k;
                }
                else 
                {
                    lower = k+1;
                }

            }
            for(int k = 0; k< v[2]; ++k)
            {
                
            }

            cout<<-1<<'\n';
            return;
        }

    }

    cout<<ans<<'\n';
    


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
