#include<bits/stdc++.h>
using namespace std;

vector<int>visited(10000000,0);
vector<vector<int>>g(10000000);
vector<int>parent(10000000,-1);
vector<int>ans;

bool dfs (int x, int par) {
    visited[x] = 1;
    if(par == -1) {
        par = x;
    }
    parent[x] = par;

    for(auto&c:g[x]) {
        if(!visited[c]) {
            bool here = dfs(c, x);
            if(here == true) {
                return true;
            }
        } else if (visited[c] == 1) {
            if (c == par) {
                continue;
            } else {
                int cycle_starting = c;
                
                int here = x;
               ans.push_back(cycle_starting);

                while(x != cycle_starting) {
                    ans.push_back(x);
                    x = parent[x];    
                }
                ans.push_back(cycle_starting);

                return true;
            }
        }
    }

    // visited[x] = 2;
    return false;
}


int main() {
    int n,m;
    cin>>n>>m;

    g.clear();
    visited.clear();
    

    for(int i = 0; i<m; ++i) {
        int a, b;
        cin>>a>>b;

        g[a].push_back(b);
        g[b].push_back(a);

    }

    // for(int i = 0; i<n; ++i){
    //     for(auto&d : g[i]) {
    //         cout<<d<< " ";
    //     }
    //     cout<<endl;
    // }

    for(int i =1; i<=n; ++i) {
        if(visited[i]) {
            continue;
        }
        bool here = dfs(i,-1);
        if(here == true) {
            cout<<ans.size()<<"\n";
            for(auto&c:ans) {
                cout<<c<<" ";
            }
            return 0;

        }
    }
    
    cout<<"IMPOSSIBLE";

}