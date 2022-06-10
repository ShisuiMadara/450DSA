class Solution{
public:	
    
    void heapify (int arr[], int n, int index)
    {
        int greater = index;
        int left = 2*index + 1;
        int right = 2*index + 2;
        
        if(left < n && arr[greater] < arr[left])
        {
            greater = left;
        }
        if(right < n && arr[greater] < arr[right]) 
        {
            greater = right;
        }
        
        if(greater != index)
        {
            swap(arr[index], arr[greater]);
            heapify(arr, n, greater);
        }
        
    }
    
    void make_max_heap(int arr[], int n)
    {
        for(int i = n/2 - 1; i>=0; i--)
        {
            heapify(arr,n,i);
        }
    }
    
    
	vector<int> kLargest(int arr[], int n, int k) {
	    
	    make_max_heap(arr, n);
	    
	    vector<int>ans;
        
        for(int i = n-1; i>=n-k; i--)
        {
            ans.push_back(arr[0]);
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
        
        return ans;
	    
	    
	}

};