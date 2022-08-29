#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD= 1000000007;



void solve()
{
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
                cout<<arr[i][j];
            }
            cout<<endl;
        }
        return;
    }

    if(r == 1 || c == 1){
        cout<<"Impossible\n";
        return;
    }

    for(int i = 0; i< r; ++i){
        for(int j = 0; j<c; ++j){
            if(arr[i][j] == '.'){
                arr[i][j] = '^';
            }
        }
    }

    for(int i = 0; i< r; ++i){
        for(int j = 0; j< c; ++j){
            
            int cnt = 0;

            if(i-1 >= 0){
                if(arr[i-1][j] == '^'){
                    cnt ++;
                }
            }
            if(j-1 >= 0){
                if(arr[i][j-1] == '^'){
                    cnt ++;
                }
            }
            if(i+1 < r){
                if(arr[i+1][j] == '^'){
                    cnt ++;
                }
            }
            if(j+1 < c){
                if(arr[i][j+1] == '^'){
                    cnt ++;
                }
            }

            if(cnt < 2){
                cout<<"Impossible\n";
                cout<<i<<" "<<j<<'\n';
            }
        }
    }

    cout<<"Possible\n";
    for(int i = 0; i< r; ++i){
            for(int j =0; j< c; ++j){
                cout<<arr[i][j];
            }
            cout<<endl;
        }
        return;

}



int main() 
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

     ll test=1;
    cin>>test;
    for(int i = 1; i<=test; ++i)
    {
        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
