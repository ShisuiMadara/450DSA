vector<int>memo(1000000,INT_MAX);

int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    
    int n = A.size();
    
    int sumFuel = 0, sumOut = 0;
    
    for(int i = 0; i<n; ++i)
    {
        sumFuel+= A[i];
        sumOut += B[i];
    }   
    
    if(sumOut > sumFuel)
    {
        return -1;
    }
    
    int ans = 0;
    int Fuel = 0;
    int i = 0;
    
    while(i < n)
    {
        Fuel += (A[i] - B[i]);
        
        if(Fuel < 0)
        {
            ans = (i+1)%n;
            Fuel = 0;
        }
        
        i++;
    }
    
    return ans;
}
