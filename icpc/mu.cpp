#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=105;
int dx,dy,n,ans;
int x[N],y[N];
bool vis[N];
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>dx>>dy>>n;
    for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        int mx=x[i],my=y[i],dis=(mx-dx)*(mx-dx)+(my-dy)*(my-dy);
        for(int j=1;j<=n;j++){
            if(vis[j]||(mx-x[j])*(mx-x[j])+(my-y[j])*(my-y[j])>=dis) continue;
            vis[j]=1;
            int cnt=2;
            int A=mx-x[j],B=my-y[j],C=A*mx+B*my;
            for(int k=1;k<=n;k++){
                if(vis[k]) continue;
                int dis=(x[k]-mx)*(x[k]-mx)+(y[k]-my)*(y[k]-my);
                if(A*x[k]+B*y[k]==C&&dis<=(mx-dx)*(mx-dx)) cnt++,vis[k]=1;
            }
            ans+=cnt*(cnt-1)/2;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
