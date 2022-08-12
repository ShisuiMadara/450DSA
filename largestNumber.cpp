
bool comp(string a, string b)
{
    return a+b > b+a;
}
string Solution::largestNumber(const vector<int> &A) {
    
    int n = A.size();
    
    vector<string>arr(n);
    //int maxLen = 0;
    for(int i = 0; i<n; ++i)
    {
        arr[i] = to_string(A[i]);
        //maxLen = max(maxLen, arr[i].length());
    }
    
    sort(arr.begin(), arr.end(), comp);
    
    string ans;
    
    for(auto&c:arr)
    {
        ans += c;
    }
    int start = 0;
    int j=0;
    while(true)
    {
        if(ans[j] == '0')
        {
            j++;
            continue;
        }
        else
        {
            ans = ans.substr(j, ans.length());
            break;
        }
    
    }
    
    if(ans.length() == 0)
    {
        ans = "0";
    }
    
    return ans;
}
