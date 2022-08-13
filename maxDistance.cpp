int Solution::maximumGap(const vector<int> &A) {
    vector<pair<int,int>> vec;
    for(int i=0;i<A.size();i++)
    {
     vec.push_back({A[i],i});
    }
    sort(vec.begin(),vec.end());
    int min_index=INT_MAX;
    int result=0;
    for(int i=0;i<A.size();i++)
    {
        min_index=min(min_index,vec[i].second);
        result=max(result,vec[i].second-min_index);
    }
    return result;
}