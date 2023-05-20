#include<bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin>>n;

    vector<int>v(n);

    for(auto&c:v)cin>>c;

    sort(v.begin(), v.end());
    if(v[0] == 1) {
        cout<<"YES\n";
        return;
    }
    bool isEven = false;
    bool isOdd = false;

    map<int,int>mp;


    for(int i = 0; i<n;++i) {
        if(isEven) {
            if(isOdd) {
                cout<<"YES\n";
                return;
            }
            if (v[i]%2) {
                cout<<"NO\n";
                return;
            }
        }
        if(v[i]%2 == 0) {
            isEven = true;
        }else {
            isOdd = true;
        }
    }

    cout<<"YES\n";
    return;
}


int main() {
    int t;
    cin>>t;

    while(t--){
        solve();
    }
}