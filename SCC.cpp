// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	
	void dfs(int node, vector<int>&visited, stack<int>&st,vector<int>adj[])
	{
	    visited[node] = 1;
	    
	    for(auto&c:adj[node])
	    {
	        if(!visited[c])
	        {
	            dfs(c,visited,st,adj);
	        }
	    }
	    
	    st.push(node);
	}
	
	void dfs2(int node, vector<int>&visited, vector<int>adj[])
	{
	    visited[node] = 1;
	    
	    //cout<<"DONE "<<node<<'\n';
	    
	    for(auto&c:adj[node])
	    {
	        if(!visited[c])
	        dfs2(c,visited,adj);
	    }
	}
	
    int kosaraju(int V, vector<int> adj[])
    {
        vector<int>visited(V,0);
        stack<int>st;
        
        for(int i = 0; i< V; ++i)
        {
            if(!visited[i])
                dfs(i,visited,st,adj);
        }
        
        for(int i = 0; i< V; ++i)
        {
            visited[i] = 0;
            
        }
        
        // for(int i = 0; i<V; ++i)
        // {
        //     for(int j  = 0; j< adj[i].size(); ++j)
        //     {
        //         if(i == j)
        //         {
        //             continue;
        //         }
        //         if(adj[i][j])adj[i][j] = 0;
        //         else adj[i][j] = 1;
        //     }
        // }
        
        vector<int>trans[V];
        
        for(int i = 0; i< V; ++i)
        {
            for(auto&c:adj[i])
            {
                trans[c].push_back(i);
            }
        }
        int ans = 0;
        
        
        while(!st.empty())
        {
            
            int here = st.top();
            st.pop();
            //cout<<"HERE "<<here<<'\n';
            if(!visited[here])
            {
                dfs2(here,visited,trans);
                ans ++;
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends