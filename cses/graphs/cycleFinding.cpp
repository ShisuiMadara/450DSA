#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> g(100000);
const int INF = 1000000000;
vector<int>d(10000000,INT_MAX);

bool solve(int n)
{
    vector<int> d(n);
    int x;
    for (int i = 0; i < n; ++i) {
        x = -1;
        for (int j =0 ; j< g[i].size(); ++j) {

            if (d[i] + g[i][j].second < d[g[i][j].first]) {
                d[g[i][j].first] = d[i] +d[g[i][j].second] ;
                x = g[i][j].first;
            }
        }
    }

    if(x == -1) {
        cout<<"NO";
        return false;
    } 
        
        
    return true;
    
}



int main() {

    int n, m; 
    cin>>n>>m;

    for(int i = 0; i<m; ++ i) {
        int a, b, c;
        cin>>a>>b>>c;

        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }

    solve(n) ? (cout<< "YES") : (cout<<"NO");

}