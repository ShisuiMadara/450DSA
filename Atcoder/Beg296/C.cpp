#include <bits/stdc++.h>
using namespace std;

#define int long long


signed main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    sort(h.rbegin(), h.rend());  // sort zombies in decreasing order of health
    priority_queue<int, vector<int>, greater<int>> pq;  // heap to store number of attacks needed for each zombie
    for (int i = 0; i < n; i++) {
        pq.push(ceil(h[i] / (double) b));
    }
    int attacks = 0;
    while (!pq.empty()) {
        int num_attacks = pq.top();  // number of attacks needed for next zombie
        pq.pop();
        if (num_attacks > attacks) {  // if this zombie hasn't been attacked enough yet
            int remaining_attacks = num_attacks - attacks;
            attacks += remaining_attacks;
            pq.push(ceil((h[0] - attacks * a) / (double) b));  // decrease health of all zombies and update heap
        }
    }
    cout << attacks << endl;
    return 0;
}
