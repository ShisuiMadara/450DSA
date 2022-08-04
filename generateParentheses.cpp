class Solution {
public:
    
    unordered_map<string,int>mp;
    
    
    bool isGood(string s)
    {
        int n = s.length();
        
        stack<char>st;
        
        for(int i = 0; i<n; ++i)
        {
            if(s[i] == '(')
            {
                st.push('(');
            }
            else
            {
                if(st.empty()) return false;
                
                st.pop();
                
            }
        }
        
        if(st.size()) return false;
        return true;
    }
    void recursion(string s, int n)
    {
        
        if(mp[s] == 1 || mp[s] == -1)
        {
            return;
        }
        
        if(isGood(s))
        {
            mp[s] = 1;
        }
        else
        {
            mp[s] = -1;
        }
        
        for(int i = 0; i<n; ++i)
        {
            if(s[i] == '(')
            {
                s[i] = ')';
                
                recursion(s,n);
                
                s[i] = '(';
            }
            else
            {
                s[i] = '(';
                
                recursion(s,n);
                
                s[i] = ')';
            }
        }
    }
        
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s;
        for(int i = 0; i<n; ++i)
        {
            s += '(';
        }
        
        for(int i =0;i<n; ++i)
        {
            s+=')';
        }
        
        recursion(s,2*n);
        
        for(auto&c:mp)
        {
            if(c.second == 1)
            {
                ans.push_back(c.first);
            }
        }
        
        return ans;
    }
};