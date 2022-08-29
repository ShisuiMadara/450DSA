#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD= 1000000007;



void solve(){
    int r,c;
    cin>>r>>c;

    vector<vector<char>>arr(r,vector<char>(c));

    int trees = 0;
    for(int i = 0; i< r; ++i){
        for(int j = 0; j< c; ++j){
            
            cin>>arr[i][j];
            if(arr[i][j] == '^'){
                trees++;
            }
        }
    }

    if(trees == 0){
        cout<<"Possible\n";
        for(int i = 0; i< r; ++i){
            for(int j =0; j< c; ++j){
                cout<<".";
            }
            cout<<endl;
        }
        return;
    }

    if(r == 1 || c == 1){
        cout<<"Impossible\n";
        return;
    }

    cout<<"Possible\n";
    for(int i = 0; i< r; ++i){
        for(int j =0; j< c; ++j){
            cout<<"^";
        }
        cout<<endl;
    }

    return;
}



int main() 
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("second_friend_input.txt", "r", stdin);
    freopen("SecondFriendOutput.txt", "w", stdout);
#endif

     ll test=1;
cin>>test;
    for(int i = 1; i<=test; ++i)
    {
        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
