/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;


void solve()
{
  int n;
  cin>>n;
 
 vector<pair<int,int>>vp;
 long long sum=0;
  while(n--)
  {
  	int z;
  	cin>>z;
  	vector<int>v(z);
  	   for(int i=0;i<z;i++)
  	  {
  	    cin>>v[i];
  	  }
 
  	  sort(v.begin(), v.end());
      sum+=v[1];
  	  vp.push_back({v[0],v[1]});
  	
  }
 
   long long temp,ans=INT_MIN;
   sort(vp.begin(), vp.end());
  for(int i=0;i<vp.size();i++)
  {
  	temp=sum;
      temp-=vp[i].second; 
      
      temp+=vp[0].first;
 
      ans=max(ans,temp);
  }
 
  cout<<ans<<endl;
  
}
    




int main()
{
    // cout<<"Hello World";
    
    int t;
    cin>>t;
    
    while(t--)solve();

    return 0;
}
