#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD= 1000000007;



void solve(){
    
    int n,k;
    cin>>n>>k;

    vector<int>arr(n);



    for(auto&c:arr)cin>>c;

    vector<int>target(n);

    for(auto&c:target)cin>>c;

    int i = 0;

    if(k == 0){
        cout<<"NO\n";
        return;
    }

    map<int,int>mp;

    for(int i = 0; i<n; ++i){
        mp[target[i]] = i;
    }

    vector<int>visited(n,0);
    int cnt = 0;

    int currentIndex = -1;

    int chunks = 0;
    //int time = 0;
    while(cnt != n){
      //  time++;

        //assert(time < 10);

        if(!visited[mp[arr[i]]]){
            currentIndex = mp[arr[i]];
            //cout<<"CURRENT INDEX IS "<<currentIndex;
        }else{
            i++;
            i%=n;
            continue;
        }

        int temp = i;

        while(currentIndex<n){
            //cout<<currentIndex<<" ";
            if(visited[currentIndex]){
                break;
            }
            if(arr[temp] != target[currentIndex]){
                break;
            }

            visited[currentIndex] = 1;
            cnt++;
            currentIndex++;
            temp++;

        }
        
        //cout<<cnt<<'\n';
        chunks++;
        //cout<<"CHUNKS TILL NOW "<<chunks<<'\n';
    }

    //cout<<"CHUNKS ARE "<<chunks<<"\n";

    if(chunks <= 2){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }

}



int main() 
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("consecutive_cuts_chapter_1_validation_input.txt", "r", stdin);
    freopen("consecutive_cuts_ch_1_output.txt", "w", stdout);
#endif

     ll test=1;
cin>>test;
    for(int i = 1; i<=test; ++i)
    {
        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
