pair<long long, long long> getMinMax(long long a[], int n) {
    long long mi,mx;
    mi = LLONG_MAX;
    mx = LLONG_MIN;
    
    for(int i = 0; i< n; ++i)
    {
        if(a[i] > mx)
        {
            mx = a[i];
        }
        if(a[i] < mi)
        {
            mi = a[i];
        }
    }
    return {mi, mx};
}