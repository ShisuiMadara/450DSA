#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD= 1000000007;
const int SIZE = 1000000;

vector<int>parent(SIZE);
vector<int>rnk(SIZE);
vector<int>mx(SIZE);
vector<int>mi(SIZE);
vector<int>sz(SIZE);

int find_set(int a)
{
    if(a == parent[a])
    {
        return a;
    }

    return parent[a] = find_set(parent[a]);
}


void union_set(int a, int b)
{
    a = find_set(a);
    b = find_set(b);

    if(a != b)
    {
        if(rnk[a] < rnk[b])
        {
            swap(a,b);
        }

        parent[b] = a;
        sz[a] += sz[b];
        mi[a] = min(mi[b], mi[a]);
        mx[a] = max(mx[a], mx[b]);

        if(rnk[a] == rnk[b])
        {
            rnk[a] ++;
        }
    }
}


void solve()
{
    int n, q;
    cin>>n>>q;

    for(int i = 0; i<=n; ++i)
    {
        parent[i] = i;
        rnk[i] = 0;
        mi[i] = i;
        mx[i] = i;
        sz[i] = 1;
    }

    while(q--)
    {
        string s;
        cin>>s;

        if(s == "union")
        {
            int a, b;
            cin>>a>>b;

            union_set(a,b);
        }
        else
        {
            int a;
            cin>>a;

            a = find_set(a);
            cout<<mi[a]<<" "<<mx[a]<<" "<<sz[a]<<'\n';
        }
    }

}



int main() 
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
