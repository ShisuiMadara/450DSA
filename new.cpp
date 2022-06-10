#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD= 1000000007;

const int MOS = 1e5;



void sub_subSize( int n, int v, vector<int>tree [], int subSize [])
{
    int vis[n] = {0}, par[n] = {0}, dist[n] = {0};
    queue<int> q;
    q.push(v);
    vis[v] = 1, par[v] = -1, dist[v] = 0;
    vector<int> nodes[n];
    nodes[0].push_back(v);
    while(!q.empty())
    {
        int ver = q.front();
        q.pop();
        for(auto j : tree[ver])
            if(!vis[j])
                q.push(j), vis[j] = 1, dist[j] = 1 + dist[ver], par[j] = ver, nodes[dist[j]].push_back(j);
    }
    
    for(int i = 0;i<n;i++)
        subSize[i] = 1;
        
    for(int i=n-1;i>0;i--)
        for(auto j : nodes[i])
            subSize[par[j]]+=subSize[j];
    
}
void solve()
{
    int n;
    cin>>n;

    vector<int>tree[n+1];
int subSize[n+1];
    
    
    for(int i = 0; i< n+1; ++i)
    {
        subSize[i] = 0;
    }

    for(int i = 0; i< n-1; ++i)
    {
        int a,b;
        cin>>a>>b;
        a--, b--;
        tree[a].push_back(b);
        tree[b].push_back(a);

    }

    sub_subSize(n,0, tree, subSize);
   
    //getSize(1, tree, subSize);

    for(int i = 0; i< n; ++i)
    {
        subSize[i] --;
    }

    
    int ans = 0;

    vector<int>depth[n+1];

    queue<int>q;

    q.push(0);
    int dep = 0;

    depth[0].push_back(0);
    dep ++;
    vector<int>visited(n,0);
    vector<int>boo;
    while(!q.empty())
    {
        int here = q.front();
        q.pop();
        visited[here] = 1;
        vector<int>children;

        for(auto&c:tree[here] )
        {
            if(!visited[c])
                children.push_back(c);
        }

        int l = -1;
        int sav = -1;

        for(auto&c:children)
        {
            if(subSize[c] > l)
            {
                l = subSize[c];
                sav = c;
            }
        }

        for(auto&c: children)
        {
            if(c != sav && !visited[c])
            {
                q.push(c);
            }
        }

        // cout<< sav<<'\n';
        
        if(sav != -1)
        boo.push_back(sav);
    }
    
    for(auto&c:boo)
    {
        ans += subSize[c];
    }
    cout<<ans<<'\n';

}


int main() 
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


     ll test=1;
    cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
