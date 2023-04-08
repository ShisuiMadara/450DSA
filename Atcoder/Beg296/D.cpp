#include <bits/stdc++.h>
using namespace std;

long long choose(int n, int k) {
    long long res = 1;
    for (int i = 1; i <= k; i++) {
        res *= n - i + 1;
        res /= i;
    }
    return res;
}

long long countNumbers(long long n) {
    if (n < 10) return n; // base case
    int k = log10(n) + 1; // number of digits in n
    long long ans = 0;
    // count numbers with k identical digits
    ans += 9;
    // count numbers with k - 1 identical digits and 1 different digit
    ans += 9 * (k - 1);
    // count numbers with k - 2 identical digits and 2 different digits
    for (int i = 2; i <= k - 1; i++) {
        ans += 10 * choose(k, i) * pow(9, k - i - 1);
    }
    // count numbers with 1 identical digit and k - 1 different digits
    ans += 9 * choose(k, 2);
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        cout << countNumbers(n) << endl;
    }
    return 0;
}