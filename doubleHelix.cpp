#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD= 1000000007;
#define int long long


void solve()
{
    
        int n1,n2;
        cin>>n1;
        if(n1 == 0)
        {
            return;
        }
        vector<int>arr1(n1);
        

        for(auto&c:arr1)cin>>c;

        cin>>n2;
        vector<int>arr2(n2);

        for(auto&c:arr2)cin>>c;

        vector<int>pre1(n1), pre2(n2);
        
        int sum = 0;
    
        for(int i =0; i<n1; ++i)
        {
            sum += arr1[i];
            pre1[i] = sum;
        }
        sum = 0;

        for(int i = 0; i<n2; ++i)
        {
            sum += arr2[i];
            pre2[i] = sum;
        }

        vector<int>intersections;

        for(int i = 0; i<min(n1,n2);++i)
        {
            if(arr1[i] == arr2[i])
            {
                intersections.push_back(i);
            }
        }

        int ans = 0;

        ans += max(pre1[intersections[0]], pre2[intersections[0]]);
        for(int i = 1; i< intersections.size(); ++i)
        {
            ans += max(pre1[intersections[i]]-pre1[intersections[i-1]], pre2[intersections[i]]-pre2[intersections[i-1]]);

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
