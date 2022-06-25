#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD= 1000000007;
#define int long long

void solve()
{
    int n;
    cin>>n;

    string s;
    cin>>s;

    int child = 0, adult = 0;

    for(int i = 0; i< n; ++i)
    {
        if(s[i] == '1') 
        {
            adult++;
        }
        else 
        {
            child ++;
        }
    }

    vector<int>v(n);

    for(auto&c:v)cin>>c;

   // int lower = 0, upper = 10000000000;

    int ans = -1;

    float lower = 0.0f, upper = 1e10f;
    uint32_t l = reinterpret_cast<uint32_t&>(lower), r = reinterpret_cast<uint32_t&>(upper);
    for(int i = 0; i< 200; ++i)
    {
        uint32_t guess = lower + (upper - lower) / 2;

        int correct = 0;
        int correct0 = 0, correct1 = 0;

        for(int i = 0; i< n; ++i)
        {
            if(v[i] < guess && s[i] == '0')
            {
                correct0++;
            }
            else if(v[i] >= guess && s[i] == '1')
            {
                correct1++;
            }
        }

        correct = correct0 + correct1;
        ans = max(ans, correct);

        if(correct0 - child > correct1 - adult)
        {
            upper = guess-1;
        }
        else 
        {
            lower = guess + 1;
        }
    }

    cout<<ans;
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
