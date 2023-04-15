#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll helper (string s) {
    ll count=0;
    ll max=-1;
    int n = s.length();

    if(s[0] == s[n-1] && s[0] == '1') {
        count++;
    }

    for(int i=0;i<s.length();i++){
        if(s[i]=='1'){
            count++;
        }
        else{
            if(count>max){
                max=count;
            }
            count=0;
        }
    }
    if(count>max){
        max=count;
    }
    return max;
}

void solve() {
    string s;
    cin>>s;

    int n = s.length();

    if (n == 1) {
        if(s[0] == '0') {
            cout<<0<<"\n";
            return;
        }

        cout<<1<<'\n';
        return;
    }


    ll here = helper(s);

    ll ans = here;

    if(here == n ) {
        cout<<here*here<<endl;
        return;
    }

    for(int i = 0; i<n; ++i) {
        ans = max(ans, (here-i)*(i+1));
    }

    cout<<ans<<"\n";
    
    

}


int main() {

    int t;
    cin>>t;

    while(t--){
        solve();
    }
    return 0;
}