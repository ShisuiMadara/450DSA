#include <bits/stdc++.h>
using namespace std ;


void solve() {
    string s;
    cin>>s;

    int n = s.length();
    string a, b;

    int h = n/2;

    if(n%2) {
        a = s.substr(0,h);
        b = s.substr(h, n);
    }else{
        a = s.substr(0, h);
        b = s.substr(h, n);
    }

        int A, B;
        A = stoi(a);
        B = stoi(b);

        // cout<<A<<" "<<B;

        if(A >= B || b[0] == '0') {
            int e = a.length();

            for(int i = e-1; i>=0; i--) {
                if(a[i] == '0') {
                    b = a[i] + b;

                }else {
                    if(i == 0) {
                        cout<<-1<<endl;
                        return;
                    }
                    b = a[i] + b;
                    a = a.substr(0,i);
                    break;
                }
            }
        }


    cout<<a<<" "<<b<<endl;
}


int main() {

    int t;
    cin>>t;

    while(t--) solve();
}