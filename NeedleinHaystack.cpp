class Solution {
public:
    int strStr(char *haystack, char *needle) {
        unsigned int q = 373591679;
        int m = strlen(needle);
        int n = strlen(haystack);
        if (m == 0 || n == 0 || m > n) 
            return m == 0 ? 0 : -1;

        int d = 3;
        int t = haystack[0];
        int p = needle[0];
        int h = 1;

        for(int i = 1; i < m; i++) {
            h = (h*d)%q;
            p = (p*d + needle[i])%q;
            t =  (t*d + haystack[i])%q;
        }

        for(int i = 0; i <= n-m; i++) {
            if(p == t) {
                int j = 0;
                for(; j < m && needle[j] == haystack[i+j]; j++);
                if(j == m) 
                    return i;
            }

            if(i < n-m)
                t = ((t-haystack[i]*h)*d + haystack[i+m])%q;
        }

        return -1;
    }
};