#include <bits/stdc++.h>
using namespace std;


void solve(){
	int n;
	cin>>n;
	int k;
	cin>>k;

	vector<int>types(n);
	for(auto&c:types){
		cin>>c;
	}

	map<int,int>mp;

	for(int i = 0; i<n; ++i){
		mp[types[i]]++;
		if(mp[types[i]]>2){
			cout<<"NO\n";
			return;
		}
	}

	vector<int>cap(2,k);

	if(mp.size() > 2*k){
		cout<<"NO\n";
		return ;
	}
	cout<<"YES\n";
	return;
}



int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("second_hands_input.txt", "r", stdin);
	freopen("secondHandOutput.txt", "w", stdout);
#endif

	int t;
	cin>>t;

	//cout<<t<<'\n';

	for(int i = 1; i<= t; ++i){
		cout<<"Case #"<<i<<": ";
		solve();
	}

	return 0;
}

