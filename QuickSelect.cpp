class Solution {
public:
    int quick_select(vector<int>& nums, int k){
        mt19937_64 rd(time(0)); 
        int pivot=nums[rd()%nums.size()];
        vector<int> L, M, R;
        for(int x:nums){
            if (x>pivot) L.push_back(x);
            else if (x<pivot) R.push_back(x);
            else M.push_back(x);
        }
        if (k<=L.size()) return quick_select(L, k); 
        int lm=L.size()+M.size();
        if (lm<k) return quick_select(R, k-lm);
        return pivot; 
    }

    int findKthLargest(vector<int>& nums, int k) {
        return quick_select(nums, k);
    }
};
