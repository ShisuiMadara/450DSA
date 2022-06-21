class Solution {
public:

	vector<int> visited;

	void dfs(int node,vector<int> adj[]){
		visited[node] = 1;
		for(int child : adj[node]){
			if(!visited[child]){
				dfs(child,adj);
			}
		}
	}

	int makeConnected(int n, vector<vector<int>>& connections) {
		if(connections.size() < n-1){  
			return -1;
		}
		vector<int> adj[n];
		for(int i=0;i<connections.size();i++){
			int u = connections[i][0];
			int v = connections[i][1];
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		int components = 0;
		visited.resize(n);
		for(int i=0;i<n;i++){
			if(!visited[i]){
				++components; 
				dfs(i,adj);
			}
		}
		return components - 1; 
	}
};