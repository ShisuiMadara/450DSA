#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD= 1000000007;
#define int long long


void solve()
{
    int n, from,to;
    cin>>n>>from>>to;

    vector<int>arr1(n/2);
    vector<int>arr2;

    long long ans = 0;
    for(int i = 0; i<n/2; ++i)
    {
        int x;
        cin>>x;

        arr1[i] = x;
    }

    for(int i = 0; i< n-n/2; ++i)
    {
        int x;
        cin>>x;

        arr2.push_back(x);
    }

    vector<int>subsetSums1, subsetSums2;

    long long here1 = pow(2, n/2);

    for(int i = 0; i< here1; ++i)
    {
        long long sum = 0;

        for(int j = 0; j< n/2; ++j)
        {
            if(i & (1<<j))
            {
                sum += arr1[j];
            }
        }
        subsetSums1.push_back(sum);
    }

    long long here2 = pow(2, n-n/2);

    for(int i = 0; i< here2; ++i)
    {
        long long sum = 0;

        for(int j = 0; j< n-n/2; ++j)
        {
            if(i & (1<<j))
            {

                sum += arr2[j];
            }
        }
        subsetSums2.push_back(sum);
    }

    sort(subsetSums1.begin(), subsetSums1.end());
    sort(subsetSums2.begin(), subsetSums2.end());

    for(int i = 0; i < subsetSums1.size(); ++i)
    {
        auto lower = lower_bound(subsetSums2.begin(), subsetSums2.end(), from - subsetSums1[i]);
        auto upper = upper_bound(subsetSums2.begin(), subsetSums2.end(), to-subsetSums1[i]);

        ans += (upper-lower);
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
