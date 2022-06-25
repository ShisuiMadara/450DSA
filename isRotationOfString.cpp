#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD= 1000000007;



void solve()
{
    string s1, s2;
    cin>>s1>>s2;

    if(s1.length() != s2.length()) 
    {
        cout<<"NO\n"    ;
        return ;
    }

    queue<char>q1,q2;

    for(int i = 0; i< s1.length(); ++i)
    {
        q1.push(s1[i]);
    }

    for(int i = 0 ; i< s1.length(); ++i)
    {
        q2.push(s2[i]);
    }

    int n = s1.length();

    while(n--)
    {
        if(q1 == q2)
        {
            cout<<"YES\n";
            return;
        }
        
        char here = q2.front();
        q2.pop();

        q2.push(here);
    }

    cout<<"NO\n";
    return;
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
