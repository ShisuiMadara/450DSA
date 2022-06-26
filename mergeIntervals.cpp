class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
vector<vector<int>>ans;
sort(intervals.begin(),intervals.end());
stack<vector <int>> s;
s.push(intervals[0]);
for(int i=1;i<intervals.size();i++)
{
int start1=s.top()[0];
int end1=s.top()[1];
int start2=intervals[i][0];
int end2=intervals[i][1];

        if(end1<start2)
        {
            s.push(intervals[i]);
        }
        else
        {
            s.pop();
            end1=max(end1,end2);
            s.push({start1,end1});
        }
    }
    while(!s.empty())
    {
        ans.push_back({s.top()[0],s.top()[1]});
        s.pop();
    }
    sort(ans.begin(),ans.end());
    return ans;
    }
};