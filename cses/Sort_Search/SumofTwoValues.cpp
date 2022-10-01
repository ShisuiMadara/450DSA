#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const int MOD= 1000000007;

void solve() {
	int n, x; 
    cin >> n >> x;
	vector<int> a(n);

	map<int, int> mp;
	
    for(auto&c:a)cin>>c;

	for (int i = 0; i < n; i++) {
		if(mp.count(x - a[i])){
			cout << i + 1 << " " << mp[x - a[i]] << "\n";
			return;
		}
		mp[a[i]] = i + 1;
	}
	cout << "IMPOSSIBLE" << '\n';
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
