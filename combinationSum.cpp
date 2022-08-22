class Solution {
public:
    
    void solve(vector<vector<int>> &fin, vector<int>&candidates, int target,vector<int>ans, int here, int index)
    {
        
        if(here == target)
        {
          
            fin.push_back(ans);
            return ;
        }
        
        if(here > target)
        {
            return;
        }
        
        int n = candidates.size();
        
        if(index >= n)
            
        {
            return;
        }
        
        for(int i= index; i< n; ++i)
        {
            if(here + candidates[i] <= target)
            {
                ans.push_back(candidates[i]);
                
                for(auto&c:ans)
                {
                    cout<<c<<" ";
                }
                cout<<endl;
                
                solve(fin, candidates, target, ans,here+candidates[i],i);
                
                
            ans.pop_back();
            //here -=  candidates[i];
                
            }
            
        }
        
        return;
        
        
    }
    
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target){
        
        int n = candidates.size();
        
        vector<vector<int>>fin;
        
        int index = 0;
        
        // for(int i = 0; i< n; ++i)
        // {
            solve(fin,candidates,target,{},0, index);
        // }
        
        
        
        
        return fin;
        
        
    }
};