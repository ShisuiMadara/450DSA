int Solution::maxProduct(const vector<int> &A) {
    
    int ans = A[0];
    int curMin = 1, curMax =1 ;
    
    for(int i = 0; i< A.size() ; ++i)
    {
        int temp = curMin;
        curMin = min(A[i], min(A[i] * curMin, A[i]*curMax));
        curMax = max(A[i], max(A[i] * temp, A[i]*curMax));
        
        ans = max(ans, curMax);
    }
    
    return ans;
    
    
}
