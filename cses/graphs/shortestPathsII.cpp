#include <bits/stdc++.h>
using namespace std;
 
 
typedef long long ll;
const int MAX_N = 1e4 +10;
const ll INF = 1e18;
int n;
 
ll dist[MAX_N][MAX_N];
 
void floyd()
{
 
  for(int step = 1; step<=n; ++step)
  {
    for(int from = 1; from<=n; ++from)
    {
      for(int to = 1; to<=n; ++to)
      {
        if(dist[from][step] < INF && dist[step][to] < INF )
        {
          dist[from][to] = min(dist[from][to], dist[from][step] + dist[step][to]);
        }
      }
    }
  }
}
 
 
 
int main()
{
  int m;
  cin>>n>>m;
  int q;
  cin>>q;
  for(int i = 1; i<=n; ++i)
  {
    for(int j = 1; j<=n; ++j)
    {
      dist[i][j] = INF;
    }
  }
 
  for(int i = 0; i<m; ++i)
  {
    ll a,b,c;
    cin>>a>>b>>c;
 
    dist[a][a] = 0;
    dist[b][b] = 0;
    dist[a][b] = min(dist[a][b], c);
    dist[b][a] = min(dist[b][a], c);
    
  }
 
  floyd();
 
  while(q--)
  {
    int a,b;
    cin>>a>>b;
 
    if(dist[a][b] < INF)
    {
      cout<<dist[a][b]<<'\n';
    }
    else
    {
      cout<<-1<<'\n';
    }
  }
 
  return 0;
  
}