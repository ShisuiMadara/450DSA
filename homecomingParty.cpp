#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD= 1000000007;



void solve()
{
    int n;
    cin>>n;

    vector<int>arr(n);

    for(auto&c:arr)cin>>c;

    vector<int>ans(n,0);

    for(int i = 0; i< n; ++i)
    {
        for(int j = 0; j<n; ++j)
        {
            if(i!=j)
            {
                if(arr[i]%arr[j] == 0 && arr[j] %arr[i] == 0)
                {
                    ans[i] ++;
                }
            }
        }
    }

    for(auto&c:ans)
    {
        cout<<c<< " ";
    }
    return ;
    
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
