#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    set<string>se;
    for(int i = 0; i<n-1; ++i) {
        string chunk = to_string(s[i]) + s[i+1];
        se.insert(chunk);
    }
    cout<<se.size()<<endl;
}


int main () {
    int t;
    cin>>t;

    while(t--) {
        solve();
    }
}