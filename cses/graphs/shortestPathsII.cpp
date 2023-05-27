#include <bits/stdc++.h>
using namespace std;

#define int long long

int g[500][500];
int dp[500][500];

void fw (int n) {

    for(int i = 0;i<500; ++i) {
        for(int j = 0; j<500; ++j) {
            dp[i][j] = INT_MAX;
        }
    }

    for(int i = 0; i<n; ++i) {
        for(int j = 0; j<n; ++j) {
            if (i == j) {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = min(dp[i][j], g[i][j]);
        }
    }

    for(int i = 0;i<n; ++i) {
        for(int j = 0; j<n; ++j) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }


    for (int k= 0; k<n; ++k) {
        for (int i = 0; i<n; ++i) {
            for (int j = 0; j<n; ++j) {
                if (dp[i][k] != INT_MAX && dp[k][j] != INT_MAX) 
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
}


signed main() {
    int n, m, q;
    cin>>n>>m>>q;
    for(int i = 0;i<500; ++i) {
        for(int j = 0; j<500; ++j) {
            g[i][j] = INT_MAX;
        }
    }

    for (int i = 0; i<m; ++i) {
        int a, b, c;
        cin>>a>>b>>c;

        g[a][b] = c;
        g[b][a] = c;

    }

    fw(n);

    while(q--) {
        int a, b;
        cin>>a>>b;

        cout<<((dp[a][b] == INT_MAX) ? -1 : dp[a][b])<<endl;
    }
}