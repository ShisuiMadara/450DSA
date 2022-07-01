// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal// } Driver Code Ends



int countRev (string s)
{
    stack<char>st;
    
    int rev = 0;
    int n = s.length();
    for(int i = 0; i<n; ++i)
    {
        if(s[i] == '{')
        {
            st.push('{');        
        }
        else
        {
            if(st.size())
            {
                st.pop();
            }
            else
            {
                rev++;
                st.push('{');
            }
        }
    }
    
    if(st.size()%2)
    {
        return -1;
    }
    rev += st.size()/2;
    
    return rev;
}