#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
    string s;
    cin>>s;

    int n = s.length() ;

    if(n == 1) {
        if(s[0] == '^') {
            cout<<1<<"\n";
        }
        else {
            cout<<2<<"\n";
        }

        return;
    }

    
    
    queue<char>q;

    for(int i = 0; i<n; ++i) {
        q.push(s[i]);
    }

    char prev = '#';
    int ans = 0;

    while(!q.empty()) {
        char here = q.front();

        if(here == '^') {
            prev = '^';
            q.pop();
            continue;
        }

        if(here == '_') {
            if(prev == '^') {
                prev = '_';
                // cout<<"Here "<<" ";
                q.pop();

                if(q.empty()) {
                    ans ++;
                }
                continue;
            }
            if(prev == '_') {
                prev = '^';
                // cout<<"HERE "<<" ";
                ans ++;
             
                continue;
            }
            if(prev == '#') {
                prev = '_';
                ans ++;
                q.pop();
                continue;
            }
        }
        
    }
    cout<<ans<<'\n';
}


int main() {

    int t;
    cin>>t;

    while(t--){
        solve();
    }
    return 0;
}