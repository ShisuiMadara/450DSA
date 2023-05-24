#include<bits/stdc++.h>
using namespace std;

#define int long long

vector<vector<pair<int,int>>>  g(10000000);
vector<int>d(10000000, 999999999999999);

void dij (int start_node, int n) {

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

    pq.push({0, start_node});
    d[start_node] = 0;

    while (!pq.empty()) {
        int v = pq.top().second;
        int d_v = pq.top().first;
        pq.pop();
        
        if (d_v > d[v])
            continue;

        for (auto edge : g[v]) {
            int to = edge.second;
            int len = edge.first;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                pq.push({d[to], to});
            }
        }
    }

    for (int i = 1; i<=n; ++i) {
        cout<<d[i]<<" ";
    }
}



signed  main() {
    int n,m;
    cin>>n>>m;

    for(int i = 0; i<m; ++i) {
        int a,b,c;
        cin>>a>>b>>c;

        g[a].push_back({c,b});
    }

    dij(1,n);
}