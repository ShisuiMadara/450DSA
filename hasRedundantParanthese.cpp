#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD= 1000000007;



void solve()
{
    string str;
    cin>>str;

    stack<char>st;

    for (auto& ch : str) {
 
        // if current character is close parenthesis ')'
        if (ch == ')') {
            char top = st.top();
            st.pop();
 
            // If immediate pop have open parenthesis '('
            // duplicate brackets found
            bool flag = true;
 
            while (!st.empty() and top != '(') {
 
                // Check for operators in expression
                if (top == '+' || top == '-' ||
                    top == '*' || top == '/')
                    flag = false;
 
                // Fetch top element of stack
                top = st.top();
                st.pop();
            }
 
            // If operators not found
            if (flag == true)
            {
                cout<<"YES\n";
                return;

            }
        }
 
        else
            st.push(ch); // push open parenthesis '(',
                  // operators and operands to stack
    }

    cout<<"NO\n";
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
