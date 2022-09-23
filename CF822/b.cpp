#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const int MOD= 1000000007;


void solve()
{
    int n;  
    cin>>n;

    if(n == 1){
        cout<<1<<'\n';
        return;
    }
    for(int i = 1; i<= n; ++i){

        int j = i;

        if(j == 1){
            cout<<1<<'\n';
            continue;
        }
        if(j == 2){
            cout<< "1 1\n";
            continue;
        }

        cout<<1<<" ";
        for(int k = 1; k<j-1; ++k){
            cout<<0<<" ";
        }
        cout<<1<<" ";
        cout<<'\n';
        
    }

    return;

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
