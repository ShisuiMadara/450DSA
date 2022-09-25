#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const int MOD= 1000000007;



float check(float guess, float ans, vector<float>&pos, vector<float>&tim, int n){

    float temp = 0.0f;

    for(int i = 0; i< n; ++i){
        temp += abs(pos[i] - guess);        
        temp += tim[i];
    }

    //cout<<"TEMP IS "<<temp<<" and ANS is "<<ans<<'\n';

    return min(temp, ans);
}


void solve()
{
    int n;
    cin>>n;

    float ans = 10000000000.0f;

    float fin ;

    vector<float>pos(n), tim(n);

    for(auto&c:pos)cin>>c;

    for(auto&c:tim)cin>>c;

    float l = *min_element(pos.begin(), pos.end()), r = *max_element(pos.begin(), pos.end());

    for (int i = 0; i < 300 && l + 0.0000001 < r; ++i){
        float mid = 0.5f * (l + r);

        //cout<<"MID IS "<<mid<<'\n';
        int f = 0;

        float here = check(mid, ans,pos, tim, n);
        if(here == ans){
            f = 1;
            
        }else{
            fin = mid;
        }

        ans = min(ans,here);

        if (f){
            r = mid+1;
        }
        else{
            l = mid-1;
        }

        
    }

    cout<<fin<<'\n';
}



signed main() 
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


     ll test=1;
cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
