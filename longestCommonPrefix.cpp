class Solution {
public:
    unsigned int hs = 3797;
    int maxSz = 200, len;
    vector <unsigned int> F, H[200];

    unsigned int seg(vector <unsigned int> &h, int x, int y) {
        return h[y] - h[x - 1] * F[y - x + 1];
    }

    bool ans_me(int sz) {
        for (int i = 0; i < len; i++) {
            if (seg(H[0], 1, sz) != seg(H[i], 1, sz)) return false;
        }

        return true;
    }

    string longestCommonPrefix(vector<string>& strs) {
        len = strs.size();

        F.push_back(1);
        for (int i = 0; i < len; i++) {
            maxSz = min(maxSz, int(strs[i].size()));
            H[i].push_back(0);
            for (int j = 0; j < strs[i].size(); j++) {
                if (strs[i][0] != strs[0][0]) return "";
                H[i].push_back(H[i][j] * hs + strs[i][j]);
            }
        }

        for (int i = 1; i <= maxSz + 1; i++) F.push_back(F[i - 1] * hs);

        int low = 1, high = maxSz, res = 0;
        while(low <= high) {
            int mid = (low + high) >> 1;

            if (ans_me(mid)) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return strs[0].substr(0, res);
    }
};