#include <bits/stdc++.h>
using namespace std;


int main() {

    int n;
    cin>>n;

    int m = n;

    list<int>a;

  
    a.push_back(n);

    n = n-1;
    int turn = 1;
    while(n >= 1) {
        if(turn%2) {
            a.push_back(n);
            n-=1;
        }else {
            a.push_front(n);
            n-=1;
        }
        turn++;
    }

    vector<int>ans;

    
    for(auto&c:a){
        for(int i = 0; i<c; ++i) {
            ans.push_back(c);
        }
    }

    for(auto&c:ans)cout<<c<<" ";

    return 0;

    
}