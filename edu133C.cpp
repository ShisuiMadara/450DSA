 #include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD= 1000000007;
#define int long long

int bfs (int i, int j, vector<vector<int>>&arr, vector<vector<int>>&visited)
{
    int n = arr.size();
    int m = arr[0].size();

    if(i < 0 || j<0 || i>=n || j>=m)
    {
        return INT_MAX;
    }

    if(i == n-1 && j == m-1)
    {
        return 0;
    }
    visited[i+1][j] = 1;
    int ans = min(ans, arr[i+1][j] + bfs(i+1, j, arr, visited));
    visited[i+1][j] = 0;


}


void solve()
{
   
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
