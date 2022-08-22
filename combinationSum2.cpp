class Solution {
public:
    
    
    void solve(vector<vector<int>>&fin, vector<int>&candidates,vector<int>ans, int target,int here, int index)
    {
        int n = candidates.size();
        
        if(here == target)
        {
            //sort(ans.begin(), ans.end());
            
            fin.push_back(ans);
            return;
        }
        
        if(here > target)
        {
            return;
        }
        
        if(index > n)
        {
            return;
        }
       

                for(int i = index; i<n; ++i)
                {
                     
        if((i == index) || (candidates[i] != candidates[i - 1]))
            {
                    here += candidates[i];
                    ans.push_back(candidates[i]);

                    solve(fin,candidates,ans,target, here,i+1);

                    ans.pop_back();
                    here-=candidates[i];

                }
        }
        return;
    }
    
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        //set<vector<int>>s;
        vector<vector<int>>fin;
        
        sort(candidates.begin(),candidates.end());
        
        solve(fin,candidates,{},target,0,0);
        
       
        return fin;
        
        
    }
};