#include<bits/stdc++.h>
using namespace std;

vector<int>visited(10000000,0);
vector<int>team (10000000,-1);
vector<vector<int>>g(10000000);

bool dfs (int x, int parent_team) {

    visited[x] = 1;
    if (parent_team == team[x]) {
        return false;
    }
    if (parent_team == 0) {
        team[x] = 1;
    }else if (parent_team == 1) {
        team[x] = 2;
    } else {
        team[x] = 1;
    }
    // cout<<"HERE\n";
    // cout<<team[x]<<" "<<parent_team<<"\n";

    for (auto&c:g[x]) {
        if(!visited[c]) {
            bool here = dfs(c, team[x]);
            if(!here) {
                return here;
            }
        } else {
            if (team[x] == team[c]) {
                return false;
            }
        }
    }

    return true;

}



int main() {
    int n,m;
    cin>>n>>m;

    team.clear();
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

    for(int i = 1; i<=n; ++i) {

        if(!visited[i]) {
            bool here = dfs(i,0);
            if (!here) {
                cout<<"IMPOSSIBLE\n";
                return 0;
            }
        }
    }   

    
    for(int i = 1;i<=n; ++i) {
        cout<<team[i]<<" ";
    }
    return 0;
        

    cout<<"IMPOSSIBLE";
    return 0;



}