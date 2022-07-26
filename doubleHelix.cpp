#include<bits/stdc++.h>
#define min_3(a,b,c) (min((a),min((b),(c))))
#define SET(a) memset(a,-1,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define CLR(a) memset(a,0,sizeof(a))
#define FILL(a,v) memset(a,v,sizeof(a))
#define PB push_back
#define PI acos(-1.0)
#define INF 1000000007
#define NINF -1000000007
#define FOR(i,a,n) for(long long i=a;i<=n;i++)
#define REP(i,n) FOR(i,0,n)
#define rep(i,n) FOR(i,0,n-1)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> vi;
typedef vector<vi> vii;
//*************BINARY SEARCH*******************
ll binary(ll a[],ll left,ll right,ll search){
    ll mid=(ll)(left+right)/2;
    if(left<=right){
    if(search == a[mid]) return mid;
    else if(search<a[mid]) return binary(a,left,mid-1,search);
    else if(search>a[mid]) return binary(a,mid+1,right,search);
    }
    return -1;
}
//*********************************************
int main() {
    while(true){
        ll n1,n2;
        cin>>n1;
        if(n1==0) break;
        ll temp_sum=0,sum_a[n1],i,a[n1],sum=0;
        rep(i,n1) {
            cin>>a[i];
            temp_sum+=a[i];
            sum_a[i]=temp_sum;
        }
        temp_sum=0;
        cin>>n2;
        ll b[n2],sum_b[n2];
        rep(i,n2) {
            cin>>b[i];
            temp_sum+=b[i];
            sum_b[i]=temp_sum;
        }
        ll prev1=0,prev2=0,first_time=0,choose1=0,choose2=0,pos=-1;
//*********************GREEDY APPROACH*********************************
        rep(i,n1){
            pos=binary(b,0,n2-1,a[i]);
            if(pos==-1) continue;
                if(pos>=0){
                        if(first_time==0){
                            first_time++;
                            choose1=sum_a[i];
                            choose2=sum_b[pos];
                        }
                        else {
                            choose1=sum_a[i]-sum_a[prev1];
                            choose2=sum_b[pos]-sum_b[prev2];
                        }
                        prev1=i;prev2=pos;
                        sum+=max(choose1,choose2);
                }
        }
        if(first_time>=1){
                choose1=sum_a[n1-1]-sum_a[prev1];
                choose2=sum_b[n2-1]-sum_b[prev2];   
        }
        else {
                choose1=sum_a[n1-1];
                choose2=sum_b[n2-1];
        }
             
        sum+=max(choose1,choose2);
//********************************************************************
        cout<<sum<<endl;
    }   
    return 0;
}