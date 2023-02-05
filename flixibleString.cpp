#include<bits/stdc++.h>
using namespace std;
#define int   long long
//const int inf=1000000000000000000;
const int mod=998244353; 
//const int mod=1000000007;

int n,ans,k;
string a,b;
map<char,int>mp1,mp2;
 

void dfs(int replace,vector<char>&v,int index) {
    
    if(replace == k)
	{
		int res=0,cnt=0;
		for(int i=0;i<a.size();i++)
		{
			if(a[i]==b[i]||mp2[a[i]])
			{
				cnt++;
				res+=cnt;
			}
			else cnt=0;
		}
		ans=max(res,ans);
		return;
	}
	for(int i=index;i<v.size();i++)
	{
		if(!mp2[v[i]])
		{
			mp2[v[i]]=1;
			dfs(replace+1,v,i+1);
			mp2[v[i]]=0;
		}
	}

}


void solve() {
    
    ans=0;
	cin>>n>>k;
	cin>>a>>b;

	for(int i=0;i<26;i++)mp2['a'+i]=0;
	mp1.clear();

	vector<char>v;

	for(int i=0;i<n;i++)
	{
		if(!mp1[a[i]])
		{
			mp1[a[i]]++;
			v.push_back(a[i]);
		}
	}
	if(k>=v.size())
	{
		cout<<n*(n+1)/2<<endl;
		return;
	}

	dfs(0,v,0);
	cout<<ans<<endl;
    
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);



    int test=1;
    cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
