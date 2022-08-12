int Solution::longestSubsequenceLength(const vector<int> &A) {
    int n = A.size();
    vector<int>dp1(n), dp2(n);
    
    for(int i = 0; i<n; ++i)
    {
        dp1[i] = 1;
        for(int j = 0; j<i; ++j)
        {
            if(A[i] >  A[j])
            {
                dp1[i] =max(dp1[i], dp1[j] + 1);
            }
        }
    }
    
    for(int i = n-1; i>=0; i--)
    {
        dp2[i] = 1;
        for(int j = n-1; j>i; j--)
        {
            if(A[i] > A[j])
            {
                dp2[i] = max(dp2[i],dp2[j] +1);
            }
        }
    }
    
    int ans = INT_MIN;
    for(int i = 0; i< n; ++i)
    {
        ans = max(ans, dp1[i] + dp2[i]-1);
    }
    
    if(ans == INT_MIN)
    {
        return 0;
    }
    
    return ans;
}
