#include <bits/stdc++.h>
using namespace std;


int main() {

    int n;
    cin>>n;

    string s;
    cin>>s;

    if(n == 1) {
        cout<<"Yes";
        return 0;
    }

    if(s[0] == 'M') {

        for(int i = 1; i< n; ++i) {
            if(i%2 == 1) {
                if(s[i] == 'M') {
                    cout<<"No";
                    return 0;
                }
            } else {
                if(s[i] == 'F') {
                    cout<<"No";
                    return 0;
                }
            }
        }
    }
    if(s[0] == 'F') {

        for(int i = 1; i< n; ++i) {
            if(i%2 == 1) {
                if(s[i] == 'F') {
                    cout<<"No";
                    return 0;
                }
            } else {
                if(s[i] == 'M') {
                    cout<<"No";
                    return 0;
                }
            }
        }
    }

    cout<<"Yes";
    return 0;
   
}