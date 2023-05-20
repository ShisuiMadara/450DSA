#include <bits/stdc++.h>
using namespace std;

int find (vector<int>&arr, int target) {

    for(int i = 0; i<arr.size(); ++i) {
        if( arr[i] == target ) {
            return i;
        }
    }
}


void solve() {
    int n;
    cin>>n;

    vector<int>arr(n);

    for(auto&c:arr)cin>>c;
    int r = -1;

    if(arr[0] == n) {
        r = find(arr,n-1);
    } else {
        r = find(arr,n);
    }
    int here = -1;
    int l = 0;
    cout<<r<<'\n';

    for(int i = r-1; i>=0; i--) {
        if(here == -1) {
            here = arr[i];
            continue;
        }
        if(arr[i] > here) {
            here = arr[i];
            continue;
        } else {
            l = i+1;
            break;
        }
    }
    cout<<l<<" ";
    cout<<"here"<<endl;
    vector<int>ans(n);
    int ptr = 0;

    for(int i = r; i<n; ++i) {
        ans[ptr] = arr[i];
        ptr++;
    }

    for(int i= r-1; i>=l; i--) {
        ans[ptr] = arr[i];
        ptr++;
    }

    for(int i = 0; i<l; i++) {
        ans[ptr] = arr[i];
        ptr++;
    }

    for(auto&c:ans)cout<<c<<" ";

    cout<<endl;
    return;
}



int main() {
    int t;
    cin>>t;

    while(t--){
        solve();
    }
}