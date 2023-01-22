#include<bits/stdc++.h>

using namespace std;

#define int   long long
#define pb push_back
#define ppb pop_back
#define ll long long
//const int inf=1000000000000000000;
const int mod=998244353; 
//const int mod=1000000007;

void solve() {
    int n;
    cin>>n;

    int a, b;

    cin>>a>>b;

    string a1, b1;
    a1 = to_string(a);
    b1 = to_string(b);

    for(int i = 0; i< min(a1.length(), b1.length()); ++i) {
        if(a1[i] > b1[i]) {
            swap(a1[i],b1[i]);
        }
    }

    a = stoll(a1);
    b = stoll(b1);

    cout<<((a%mod)*(b%mod))%mod<<'\n';
}

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);



    ll test=1;
//cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
