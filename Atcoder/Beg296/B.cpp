#include <bits/stdc++.h>
using namespace std;


int main() {

    string s;
    int row = 0, col = 0;

    for(int i = 0; i< 8; ++i) {
        cin>>s;

        for(int j =0 ;j <s.length(); ++j) {
            if(s[j] == '*') {
                col = j;
                row = 8-i;
            }
        }
    }

    string here;
    char c = 'a';

    c += col;

    // cout<<row<<endl;
    // cout<<col<<endl;

    here += c;

    // cout<<here<<endl;

    here += to_string(row);

    cout<<here;
    return 0;
}