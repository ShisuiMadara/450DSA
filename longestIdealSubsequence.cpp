class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size();
        vector<int> dp(26);
        for (int i = 0; i < n; i++) {
            int val = s[i] - 'a';
            int mx = dp[val];
            for (int value = 0; value < 26; value++) {
                if (abs(val - value) <= k) {
                    mx = max(mx, dp[value] + 1);
                }
            }
            dp[val] = mx;
        }
        int sol = 0;
        for (int i : dp) {
            sol = max(sol, i);
        }
        return sol;
    }
};