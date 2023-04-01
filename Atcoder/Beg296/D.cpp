#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n,m;
    cin>>n>>m;

    if(n*n < m) {
        cout<<"-1";
        return 0;
    }
    int ans = 1e18;

    for(int i = 1; i<= min(n, (int)sqrt(m) + 5); ++i) {
        if((m+i-1)/i <=n)
            ans = min(ans, ((m+i-1)/i)*i);
        
    }  

    cout<<ans;

    return 0;
}
