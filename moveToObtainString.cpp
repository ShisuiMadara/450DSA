class Solution {
public:
    bool canChange(string start, string target) {
        
        int n = start.length();
        
        queue<pair<char,int>>ord,ord1;
        
        for(int i = 0; i <n; ++i)
        {
            if(start[i] != '_')
            {
                ord.push({start[i],i});
                ord1.push({start[i],i});
            }
        }
        
        queue<pair<char,int>>tarOrd;
        
        for(int i = 0; i< n; ++i)
        {
            if(target[i] != '_')
            {
                if(target[i] != ord.front().first)
                {
                    //.tarOrd.push({target[i],i});
                    //cout<<target[i]<<" "<<ord.top()<<"\n";
                    return false;
                }
                tarOrd.push({target[i],i});
                ord.pop();
            }
        }
        
        if(ord.size())
        {
            return false;
        }
        
        while(ord1.size())
        {
            pair<char,int>p1,p2;
            
            p1= ord1.front();
            p2 = tarOrd.front();
            
            tarOrd.pop();
            ord1.pop();
            
            if(p1.first == 'L')
            {
                if(p2.second > p1.second)
                {
                    cout<<"L REASON\n";
                    return false;
                }
            }
            if(p1.first == 'R')
            {
                if(p2.second < p1.second)
                {
                    cout<<p2.second<<" "<<p1.second<<" \n";
                    cout<<"R REASON\n";
                    return false;
                }
            }
            
        }
        
        return true;
        
    }
};