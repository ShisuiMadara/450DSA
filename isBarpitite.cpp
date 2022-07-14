#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	    
	    vector<int>visited(V,0);
	    vector<int>color(V,-1);
	    
	    queue<int>q;
	    
	    q.push(0);
	    color[0]=0;
	    
	    for(int i = 0; i< V; ++i)
	    {
	        if(!visited[i])
	        {
	            q.push(i);
	            color[i] = 0;
	        }
    	    while(!q.empty())
    	    {
    	        int here = q.front();
    	        q.pop();
    	        
    	        visited[here] = 1;
    	        
    	        for(auto&c:adj[here])
    	        {
    	            if(color[c] == -1)
    	            {
    	                color[c] = 1-color[here];
    	            }
    	            else if(color[c] == color[here])
    	            {
    	                return false;
    	            }
    	            else 
    	            {
    	                continue;
    	            }
    	            if(!visited[c])
    	            {
    	                q.push(c);
    	            }
    	        }
    	    }
    	    
	    }
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends