#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


void solve() {

    int n;
    cin>>n;

    int t1,t2;
    cin>>t1>>t2;

    vector<int>a(n);

    for(auto&c:a)cin>>c;

    vector<int>r1,r2;

    vector<pair<int,int>> fa (n);

    for(int i = 0; i< n; ++i) {
        fa.push_back(make_pair(a[i],i+1));
    }

    sort(fa.begin(), fa.end(), greater<pair<int,int>>());

    int time1 = t1, time2 = t2;

    int i = 0;

    while(i<n) {
        
        if(time1 <= time2)
        {
            r1.push_back(fa[i].second);
            time1 += t1;
        } else {
            r2.push_back(fa[i].second);
            time2 += t2;
            
        }
        i++;
    }
    
    cout<<r1.size()<<" ";
    for(auto&c:r1) {
        cout<<c<<" ";
    }
    cout<<"\n";

    cout<<r2.size()<<" ";
    for(auto&c:r2) {
        cout<<c<<" ";
    }
    cout<<"\n";
    
    return;
}


int main() {

    int t;
    cin>>t;

    while(t--) solve();

    return 0;
}