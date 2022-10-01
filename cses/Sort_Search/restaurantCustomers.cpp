#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const int MOD= 1000000007;


void solve()
{
	int n;
	cin >> n;
	vector<pair<int, int>> arr;
	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;
		arr.push_back({start, 1});
		arr.push_back({end, -1});
	}

	sort(arr.begin(), arr.end());

	int here = 0;
	int ans = 0;
	for (auto& t : arr) {
		here += t.second;
		ans = max(ans, here);
	}

	cout << ans;

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
