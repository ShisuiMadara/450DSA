class Solution
{
    public:
    //Function to merge k sorted arrays.
    
    
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        vector<int>final;
        
        for(int i = 0; i< k; ++i)
        {
            final.push_back(arr[0][i]);
        }
        for(int i = 1; i< k; ++i)
        {
            int ptr1 = 0,ptr2= 0;
            
            vector<int>temp;
            while(ptr1 < final.size() && ptr2 < k)
            {
                if(final[ptr1] < arr[i][ptr2])
                {
                    temp.push_back(final[ptr1]);
                    ptr1++;
                }
                else
                {
                    temp.push_back(arr[i][ptr2]);
                    ptr2++;
                }
            }
            
            for(int j = ptr1; j< final.size(); ++j)
            {
                temp.push_back(final[j]);
            }
            
            for(int j = ptr2; j< k; ++j)
            {
                temp.push_back(arr[i][j]);
                
            }
            
            final.clear();
            for(int j = 0; j< temp.size(); ++j)
            {
                final.push_back(temp[j]);
            }
        }
        
        return final;
    }
};
