class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        int ans = 0;
        int n = fruits.size();
        int left = 0, right = 0;
        unordered_map<int,int>mp;
        
        while(right < n)
        {
            mp[fruits[right]]++;
            cout<<mp.size()<<" ";
            if(mp.size() <= 2)
            {
                ans = max(ans, right-left+1);
            }
            
            else if(mp.size() > 2)
            {
                while(mp.size() != 2)
                {
                    mp[fruits[left]]--;
                    if(mp[fruits[left]] == 0)
                    {
                        mp.erase(fruits[left]);
                    }
                    left++;
                    
                }
            }
            
            right++;
        }
        
        return ans;
    }
};