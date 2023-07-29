#include<bits/stdc++.h>
using namespace std;

#define int long long 

map<int,int>mp1;
map<int,int>mp2;

bool check(int guess) {

    int num_sellers =0 ;
    int num_buyers = 0;

    for(auto&c:mp1){
        if(c.first <= guess) {
            num_sellers += c.second;
        } 
    }

     for(auto&c:mp2){
        if(c.first >= guess) {
            num_buyers += c.second;
        } 
    }

    // printf("Guess was %d, num_sellers was %d, num_buyers was %d \n", guess, num_sellers, num_buyers);

    return (num_sellers >= num_buyers);
}


signed main() {
    int n,m;
    cin>>n>>m;

    vector<int>sellers(n);
    vector<int>buyers(m);

    for(auto&c:sellers)cin>>c;

    for(auto&c:buyers)cin>>c;

    for(int i = 0; i<n; ++i) {
        mp1[sellers[i]] ++;
    }

    for(int i = 0; i<m; ++i) {
        mp2[buyers[i]] ++;
    }

    
    int right = max(*max_element(sellers.begin(), sellers.end()), *max_element(buyers.begin(), buyers.end()));

    int left = 0;

    int guess = (right + left)/2;
    int ans = -1;

    while(left <= right)
    {
        guess = (right+left)/2;
      

         if(check(guess)) {
            right = guess -1;
            ans = guess;
        } else {
            left = guess+1;
        }
    }

    // assert(ans != INT_MAX);

    cout<<ans;
   


    return 0; 
}