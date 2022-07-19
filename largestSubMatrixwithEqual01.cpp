#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD= 1000000007;

pair<int,int> largest(vector<int>arr[], vector<int>temp)
{
    int m = temp.size();

    int sum = 0;
    int mxLen = 0;
    unordered_map<int,int>mp;
    //want to make sum 0
    int start = -1;
    int end = -1;
    for(int i = 0; i< m; ++i)
    {
        sum += temp[i];

        if(temp[i] == 0 && mxLen == 0)
        {
            mxLen = 1;
            start = i;
            end = i;
        }

        if(sum == 0)
        {
            if(mxLen < i+1)
            {
                mxLen = i+1;
                start = 0;
                end = i;
            }
        }

        if(mp.find(sum) != mp.end())
        {
            if(mxLen < i- mp[sum])
            {
                mxLen = i-mp[sum];
                start = mp[sum];
                end = i;
            }
        }
        else
        {
            mp[sum] = i;
        }
    }

    //cout<<mxLen<<" "<<end<<" "<<'\n';
    return {mxLen, end};

    
}


int sumZero(int n, int m, vector<int>arr[])
{
    int mxArea = 0;

    for(int i = 0; i < n; ++i)
    {
        vector<int>temp(m,0);

        for(int dummy = i; dummy <n; ++dummy)
        {
            for(int j = 0; j< m; ++j)
            {
                temp[j] = temp[j] + arr[dummy][j];
            }

            // for(auto&c:temp)
            // {
            //     cout<<c<<" ";

            // }
            // cout<<'\n';

            pair<int,int>here = largest(arr, temp);

            int len = here.first;
            int ending = here.second;

            mxArea = max(mxArea, (dummy - i + 1)*(len));
        }
    }

    return mxArea;
}

void solve()
{
   int n,m;
   cin>>n>>m;

   vector<int>arr[n];

   for(int i = 0; i< n ;++i)
   {
    for(int j = 0; j <m; ++j)
    {
        int x;
        cin>>x;

        if(x == 0)
        {
            x = -1;
        }
        arr[i].push_back(x);
    }
   } 

   int largestArea = sumZero(n, m, arr);
   cout<<largestArea<<'\n';
}



int main() 
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

     ll test=1;
//cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
