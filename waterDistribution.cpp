// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    using ip = pair<int,int>;
    ip adj[21];
    int indegree[21];
    public:
    int dfs(int src,int &ans){
        if(!adj[src].first)
            return src;
        ans=min(ans,adj[src].second);
        return dfs(adj[src].first,ans);
    }
    
    vector<vector<int>> solve(int v,int e,vector<int> a,vector<int> b,vector<int> d)
    {
        for(int i=1;i<=v;i++)
            indegree[i]=0, adj[i]={0,-1};
            
        for(int i=0;i<e;i++)
            adj[a[i]] = {b[i],d[i]},indegree[b[i]]++;
        
        vector<vector<int> >sol;
        for(int i=1;i<=v;i++){
            if(!indegree[i]){
                int ans=INT_MAX,st=0,ep;
                st=i;
                ep=dfs(i,ans);
                if(st!=ep){
    
                    sol.push_back({st,ep,ans});
                }
            }
            
        }
        return sol;
    }
};



// { Driver Code Starts.
int main()
{
	int t,n,p;
	cin>>t;
	while(t--)
    {
        cin>>n>>p;
        vector<int> a(p),b(p),d(p);
        for(int i=0;i<p;i++){
            cin>>a[i]>>b[i]>>d[i];
        }
        Solution obj;
        vector<vector<int>> answer = obj.solve(n,p,a,b,d);
        cout<<answer.size()<<endl;
        for(auto i:answer)
        {
            cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        }
        
    }
	return 0;
}  // } Driver Code Ends