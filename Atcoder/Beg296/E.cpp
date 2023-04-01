#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<bool> visited(n+1, false);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            int slow = i, fast = i;
            while (true) {
                slow = a[slow];
                fast = a[a[fast]];
                if (slow == fast) {
                    break;
                }
            }
            int len = 0;
            do {
                visited[slow] = true;
                slow = a[slow];
                len++;
            } while (slow != fast);
            ans += len;
        }
    }
    cout << ans << endl;
    return 0;
}