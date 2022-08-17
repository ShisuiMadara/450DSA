class Solution {
public:
    
    void backtrack(map<int,string>&mp, int ptr, string &digits, vector<string>&ans, string canBe)
    {
        
        if(ptr == digits.length())
        {
            ans.push_back(canBe);
            return;
        }
        
        int here = digits[ptr]-'0';
        
        for(auto&c:mp[here])
        {
            canBe += c;
            
            backtrack(mp,ptr+1,digits,ans,canBe);
            
            canBe.pop_back();
        }
    }
    
    
    vector<string> letterCombinations(string digits) {
        
        map<int,string>mp;
        
        if(digits == "")
        {
            return {};
        }
        char th = 'a';
        
        mp[2] = "abc";
         mp[3] = "def";
         mp[4] = "ghi";
         mp[5] = "jkl";
         mp[6] = "mno";
         mp[7] = "pqrs";
         mp[8] = "tuv";
         mp[9] = "wxyz";
        mp[1] = "";
        mp[0]= " ";
        
        for(auto&c:mp)
        {
            cout<<c.first<<" "<<c.second<<'\n';
        }
        
        int n = digits.size();
        
        int ptr = 0;
        vector<string>ans;
        
        backtrack(mp, ptr,digits,ans,"");
        
        return ans;
    }
};