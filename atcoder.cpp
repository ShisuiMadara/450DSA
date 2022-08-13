#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD= 1000000007;

vector<int>parent(1000000);
vector<int>sze(1000000);

void make_set(int i)
{
    parent[i] = i;
    sze[i] = 1;
}

int  find_set(int i)
{
    if(parent[i] == i)
    {
        return i;
    }
    return parent[i] = find_set(parent[i]);
}

void union_set(int i, int j, int n)
{
    i = find_set(i);
    j = find_set(j);

    if(i == j)
    {
        return;
    }

    if(i > n)
    {
        parent[j] = i;
        sze[i] += sze[j];
    }
    else if(j > n)
    {
        parent[i] = j;
        sze[j] += sze[i];
    }
    else
    {
        if(i != j)
        {
            if(sze[i] < sze[j])
            {
                swap(i,j);
            }

            parent[j] = i;
            sze[i] += sze[j];
        }
    }
    
}

void delete_set(int i, int j)
{
    parent[j] = j;
    parent[i] = i;
}

void solve()
{
    int n, m,e;
    cin>>n>>m>>e;

    for(int i = 0; i<=(n+m); ++i)
    {
        make_set(i);
    }

    vector<vector<int>>g(n+m+1);

    for(int i = 0; i < e;++i)
    {
        int u,v;
        cin>>u>>v;

        // union_set(u,v,n);
        g[u].push_back(v);
        g[v].push_back(u);
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
