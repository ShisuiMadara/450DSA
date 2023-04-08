#include <bits/stdc++.h>
using namespace std;


int main(){
  int t;
  cin >> t;
 
  while(t--){
    int n;
    cin >> n;
 
    int u[n];
    for(int i = 0; i < n; i++){
      cin >> u[i];
    }
 
    vector<int> s[n+1];
    for(int i = 0; i < n; i++){
      int si;
      cin >> si;
      s[u[i]].push_back(si);
    }
 
    vector<long long> ans(n+1, 0);
 
    for(int i = 1; i <= n; i++){
      int m = s[i].size();
 
      s[i].push_back(0);
      sort(s[i].begin(), s[i].end());
      reverse(++s[i].begin(), s[i].end());
 
      vector<long long> preSum(s[i].size(), 0);
      for(int j = 1; j < s[i].size(); j++){
	        preSum[j] = preSum[j-1] + s[i][j];
      }
 
      for(int k = 1; k <= m; k++){
	    ans[k] += preSum[(m / k) * k];
      }
    }
 
    for(int k = 1; k <= n; k++){
        cout<<ans[k]<<" ";
    }
  }
}
