#include<bits/stdc++.h>
using namespace std;

void solve(int n, int arr[], int m)
{
	map<int, int> mp;
	
	for (int i = 0; i < m; i++)
		mp[arr[i]]++;
	
	vector<int> vec;
	int len = n - 1, cnt = 0;
	for (auto &u : mp)
	{
		cnt += u.second;
		while (cnt > 0)
		{
			vec.push_back(u.first);
			cnt -= len;
			len--;
		}
	}
	
	while (vec.size() < n)
		vec.push_back(vec.back());
	
	for (int i = 0; i < n; i++)
		cout << vec[i] << " ";
	cout << endl;
}
 
int32_t main()
{
	int t;
 	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		
		int m = n * (n - 1) / 2;
		int arr[m];
		for (int i = 0; i < m; i++)
			cin >> arr[i];
		
		solve(n, arr, m);
	}
 
	return 0;
}
