#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD= 1000000007;



void solve()
{
    string s;
    cin>>s;

    int n = s.length();

    vector<string>ans;

    for(int i = 0; i< (1<<n); ++i)
    {
        string here;
        for(int j = 0; j< n; ++j)
        {
            //cout<<i<<" "<<(1<<j)<<'\n';
            if(i & (1<<j))
            {
                here += s[j];
            }
        }

        ans.push_back(here);
    }

    for(auto&c:ans)
    {
        cout<<c<<'\n';
    }
}



int main() 
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
