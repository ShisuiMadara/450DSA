#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const int MOD= 1000000007;


void solve()
{
  int n,ans=3 ;
  cin >> n ;
  vector<int>a(n),b(n);

  for(int &x:a) {
    cin >> x;
    x--;
  }

  for(int i=0;i<n;i++)
    b[a[i]]=i ;

  for(int i=1;i<n;i++) {
    ans+=b[i]<b[i-1];
  }

  cout << ans  ;

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
