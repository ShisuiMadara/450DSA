/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;


void solve() {
    
    int n;
    cin>>n;
    
    int ans = 0;
    
    for(int left = 0; left < n; left++) {
        vector<int> v(n);
        for(int j = 0; j < left; j++) v[j] = j+1;
        
        for(int j = n-1, k = left+1; j >= left; j--) {v[j] = k; k++;}
        int s = 0, m = 0;
        for(int j = 0; j < n; j++) {s += (v[j]*(j+1)); m = max(m, v[j]*(j+1));}
        ans = max(ans, s-m);
    }
    cout << ans << "\n";
    
}



int main()
{
    // cout<<"Hello World";
    
    int t;
    cin>>t;
    
    while(t--)solve();

    return 0;
}
