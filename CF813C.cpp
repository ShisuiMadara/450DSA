#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD= 1000000007;
#define int long long

void solve()
{
    int n;
    cin>>n;

    vector<int>arr(n);

    for(auto&c:arr)cin>>c;

    int i = n-1;
    map<int,int>mp;

    for(int j= 0; j< n; ++j)
    {
        mp[arr[j]] ++;
    }   

    // for(auto&c:arr)cout<<c<<" ";
    int ans = 0;

    map<int,int>GONE;

    
    while(true)
    {
        i = n-1;
        while(i>0)
        {
            if(arr[i]>=arr[i-1])
            {
                i--;
            }
            else
            {
                break;
            }
        }

        if(i == 0)
        {
            cout<<ans<<'\n';
            return;
        }


        set<int>gone;

        for(int j = 0; j<i; ++j)
        {
            //cout<<"INSERTED "<<arr[j]<<" ";
// for(auto&c:mp)
        // {
        //     cout<<c.first<< " "<<c.second<<'\n';
        // }

        // for(auto&c:gone )
        // {
        //     cout<<c<<" ";
        // }
        
            if(arr[j] == 0)
            {
                continue;
            }
            mp[arr[j]]--;
            if(mp[arr[j]] == 0)
            {
                mp.erase(arr[j]);
            }
            gone.insert(arr[j]);
            if(!GONE[arr[j]])
            {
                //cout<<"DONE "<<arr[j]<<" ";
                ans++;
            }
            GONE[arr[j]]+=1;
            arr[j]= 0;
            
            
        }

        // for(auto&c:mp)
        // {
        //     cout<<c.first<< " "<<c.second<<'\n';
        // }

        // for(auto&c:gone )
        // {
        //     cout<<c<<" ";
        // }
        
        int flag = 1;

        //cout<<"GONE SIZE "<<gone.size()<<" ";
        //ans += gone.size();

        for(auto&c:gone)
        {
            if(mp[c])
            {
                flag = 0;
                for(int j = i; j<n; ++j)
                {
                    if(arr[j] == c)
                    {
                        arr[j] = 0;
                        mp[c]--;
                    }
                }
            }
        }

        //cout<<"FLAG "<<flag<<'\n';

        if(flag)
        {
            cout<<ans<<'\n';
            return;
        }
        
    }


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