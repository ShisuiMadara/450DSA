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
    
    
    vector<int>a(n);
    
    for(auto&cd:a)cin>>cd;
    
    sort(a.begin(), a.end());
    
    if(a[0] == a[n-1]) {
        cout<<-1<<"\n";
        return;
    }
    
    vector<int>b, c;
    
    b.push_back(a[0]);
    int i = 1;
    for(i = 1; i<n; ++i) {
        if(a[i] != a[i-1]) break;
        
        b.push_back(a[i]);
    }
    
    for(int j = i; j<n; ++j) {
        c.push_back(a[j]);
    }
    cout<<b.size()<<" "<<c.size()<<endl;
    for(auto&d:b)cout<<d<<" ";
    
    cout<<endl;
    
    for(auto&d:c)cout<<d<<" ";
    cout<<endl;
    
}



int main()
{

    int t;
    cin>>t;
    
    while(t--)solve();

    return 0;
}
