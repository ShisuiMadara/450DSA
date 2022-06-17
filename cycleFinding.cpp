// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int current, int prev, vector<int>adj[], int visited [])
    {
        for(auto&c:adj[current])
        {
            if(c != prev)
            {
                if(visited[c])
                {
                    return true;
                }
                else
                {
                    visited[c] = 1;
                    
                    dfs(c, current, adj, visited);
                }
            }
        }
        
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        
        int n = V+1;
        int visited[n];
        
        memset(visited, 0, sizeof(visited));
        
        if(dfs(0, -1, adj, visited)) return 1;
        
        return 0;
        
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends