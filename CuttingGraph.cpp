#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD= 1000000007;
const int SIZE = 1000000;

vector<int>parent(SIZE);
vector<int>rnk(SIZE);

int find_set(int a)
{
    if(parent[a] == a)
    {
        return a;
    }

    return parent[a] = find_set(parent[a]);
}

void union_set(int a, int b)
{
    a = find_set(a);
    b = find_set(b);

    if(rnk[a] < rnk[b])
    {
        swap(a,b);

    }

    parent[b] = a;

    if(rnk[a] == rnk[b])
    {
        rnk[a] ++;
    }
}

void solve()
{
    int n,m,q;
    cin>>n>>m>>q;

    for(int i = 0; i<=n; ++i)
    {
        parent[i] = i;
        rnk[i] = 0;
    }

    for(int i = 0; i<m; ++i)
    {
        int a,b;
        cin>>a>>b;

        union_set(a,b);
    }

    while(q--)
    {
        string s;
        cin>>s;

        if(s == "ask")
        {
            int a,b;
            cin>>a>>b;

            if(find_set(a) == find_set(b))
            {
                cout<<"YES\n";
            }
            else
            {
                cout<<"NO\n";
            }
        }
        else
        {
            int a,b;
            cin>>a>>b;
            
            if(find_set(b) == a)
            {
                parent[b] = b;
            }
            else if(find_set(a) == b)
            {
                parent[a] = a;
            }
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
