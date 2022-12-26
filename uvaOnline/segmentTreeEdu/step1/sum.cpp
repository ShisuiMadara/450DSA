#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const int MOD= 1000000007;

int tree[4*100000];

void build_tree (int a[], int v, int left, int right) {

    if(left == right) {
        tree[v] = a[left];
    } else {

        int mid = (left + right)/2;
        build_tree(a,v*2, left, mid);
        build_tree(a, v*2+1, mid+1, right);

        tree[v] = tree[2*v+1] + tree[2*v];
    }
}

int sum (int v, int left, int right, int ql, int qr) {
    if(ql > qr) {
        return 0;
    }
    if(left == ql && right == qr) {
        return tree[v];
    }

    int mid = (left + right)/2;

    return sum(2*v, left, mid, ql, min(qr,mid)) + sum(2*v+1, mid+1,right,max(ql,mid+1),qr);

}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        tree[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        tree[v] = tree[v*2] + tree[v*2+1];
    }
}

void solve()
{
    int n,q;
    cin>>n>>q;

    int a[n];
    for(int i = 0; i< n; ++i) {
        cin>>a[i];
    }

    build_tree(a,0,0,n);

    while(q--) {
        int type;
        cin>>type;

        if(type == 1) {
            int index, val;
            cin>>index>>val;

            update(index,0,n-1,index,val);
        } else {
            int l,r;
            cin>>l>>r;

            cout<<sum(0,0,n-1,l,r)<<endl;
        }
    }

}



signed main() 
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


    ll test=1;
    //cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
