#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD= 1000000007;



void solve()
{
    int n,L,q;
    cin>>n>>L>>q;

    vector<int>arr(n);

    for(auto&c:arr)
    {
        cin>>c;
    }

    //s,r,c


    while(q--)
    {
        string s;
        cin>>s;

        if(s == "start")
        {
            int start, r, c;
            cin>>start>>r>>c;

            start--;

            int ans = -1;

            while(true)
            {
                
                // if(start + r >= n)
                // {
                //     break;
                // }
                for(int i = start; i< min(start+r, n); ++i)
                {
                    cout<<i<<" ";
                    if(ans == -1)
                    {
                        ans = arr[i];
                    }
                    else
                    {
                        ans = ans^arr[i];
                    }
                }
                if(start + r >=n)
                {
                    break;
                }

                start += (L-r+1);

                c--;
               

                if(c == 0)
                {
                    break;
                }
                
            }

            cout<<ans<<'\n';
        }
        else
        {
            int start, r,c;
            cin>>start>>r>>c;
            start --;
            int NEW = arr[start]^r^c;
           

            arr[start] = NEW; 

           // cout<<"NEW "<<NEW<<'\n';
        }
    }


}



int main() 
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


     ll test=1;
//cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
