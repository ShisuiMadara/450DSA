 #include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD= 1000000007;
#define int long long


void solve()
{
    int n;
    cin>>n;

    vector<int>arr(n);

    for(int i = 0; i<n; ++i)
    {
        arr[i] = i+1;
    }

    int i = 0;
    int j = 1;
    cout<<n<<'\n';
    
    for(auto&c:arr)
        {
            cout<<c<<" ";
        }
        cout<<"\n";

    while(arr[n-1] == n)
    {
        swap(arr[i], arr[j]);
        i++;
        j++;
        for(auto&c:arr)
        {
            cout<<c<<" ";
        }
        cout<<"\n";
        
    }
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
