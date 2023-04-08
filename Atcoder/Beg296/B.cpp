#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll val(ll check){
      ll ans=(check/3)*(check/3)*3;
      for(ll i = 0; i<check%3; ++i)
            ans+=(check/3)*2+i;
      return ans*2;
}
 
void sol(){
    ll n;
    cin>>n;
    ll left=1,right=1e9+7;
    while(left<right){
      ll mid=(left+right)/2;
      if(val(mid)>=n)
            right=mid;
      else
            left=mid+1;
    }
    cout<<left<<"\n";  
}
 
int main(){
    int t;
    cin>>t;
    while(t--)
        sol();
    return 0;
}