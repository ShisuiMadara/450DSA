#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const int MOD= 1000000007;

bool compare(pair<int,int>a, pair<int,int>b){
    if(a.second < b.second){
        return true;
    }
    if(a.second == b.second){
        if(a.first < b.second){
            return true;
        }
        return false;
    }

    return false;
}

void solve()
{
    // int n;
    // cin>>n;

    // vector<pair<int,int>>arr(n);

    // for(int i = 0; i< n; ++i){
    //     int a,b;
    //     cin>>a>>b;

    //     arr[i]= {a,b};
    // }

    // sort(arr.begin(), arr.end(), compare);

    // int ans = 0;
    // int here = -1;

    // // for(auto&c:arr){
    // //     cout<<c.first<<" "<<c.second;
    // //     cout<<endl;
    // // }

    

    // for(int i = 0; i< n; ++i){
    //     if(here <= arr[i].first){
    //         ans ++;;
    //         here = arr[i].second;
    //     }
    // }

    // cout<<ans;
    int n;
	cin >> n;
    vector<pair<int, int>> arr(n);
    
    for(int i =0 ; i< n; ++i){
        int x,y;
		cin >> x >> y;
		arr[i] = make_pair(y, x);
	}
	// sorting by ending times
	sort(arr.begin(), arr.end());

    int here = 0, ans = 0;

	for (auto &c : arr){
		if (c.second >= here)
		{
			here = c.first;
			ans++;
		}
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
