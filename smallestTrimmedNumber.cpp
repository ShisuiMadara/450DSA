class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> res;
        
        for(vector<int> &q: queries) {
            priority_queue<pair<string,int> > pq;
            int trim = q[1];
            int k = q[0];
            for(int i = 0; i < nums.size(); i++) {
                int size = nums[i].size();
                string x = nums[i].substr(size-trim);
                pq.push({x, i});
                if(pq.size() > k)
                    pq.pop();
            }
            
            res.push_back(pq.top().second); 
        }
        
        return res;
    }
};