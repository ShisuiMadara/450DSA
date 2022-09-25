#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const int MOD= 1000000007;


void solve()
{
    string s;
    cin>>s;

    string tar = s;

    reverse(tar.begin(), tar.end());

    char here = '9';
    map<char,int>mp;


    for(auto&c:tar){
        if(c<= here){

            mp[c] ++;
            here = c;
        }else{
            if(c != '9'){
                mp[c+1]++;
            }
            else{
                mp['9']++;
            }
        }
    }

    string ans = "";

    for(auto&c:mp){
        while(c.second--){
            ans += c.first;
        }
    }

    cout<<ans<<'\n';
    
    // sort(tar.begin(), tar.end());

    // int n = s.length();

    // int f = 0;

    // char here = 'w';


    // for(int i = 0; i<n; ++i){
    //     if(s[i] == tar[i]){
    //         continue;
    //     }else{
    //         if(f == 0){
    //             if(here == 'w'){
    //                 here = tar[i];
    //                 continue;
    //             }
    //             if(here == tar[i]){
    //                 continue;
    //             }
    //             f = 1;
    //         }

    //         if(tar[i] == '9'){
    //             continue;
    //         }
    //         tar[i] += 1;
    //     }
    // }

    // cout<<tar<<'\n';

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
