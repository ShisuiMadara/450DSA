// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  
  pair<int,int> isThere(vector<vector<int>>a, vector<int>temp)
  {
      int m = temp.size();
      int n = a.size();
      
      int maxLen = -1;
      int sum = 0;
      int start, end;
      
      unordered_map<int,int>mp;
      
      for(int i = 0; i< m; ++i)
      {
            sum += temp[i];
            
            if(temp[i] == 0 && maxLen == -1)
            {
                //taking that particular element
                maxLen = 1;
                start = i;
                end = i;
            }
            
            if(sum == 0)
            {
                if(i+1 > maxLen)
                {
                    start = 0;
                    end = i;
                    maxLen = i+1;
                }
            }
            
            if(mp.find(sum) != mp.end())
            {
                if(maxLen < i-mp[sum])
                {
                    start = mp[sum];
                    end = i;
                    maxLen = i-mp[sum];
                }
            }
            else
            {
                mp[sum] = i;    
            }
      }
      
      if(maxLen > 0)
      {
          return {maxLen, end};
      }
      return {0,-1};
  }
            
  vector<vector<int>> sumZeroMatrix(vector<vector<int>> a){
      
      int n = a.size();
      int m = a[0].size();
      
      int mxArea = -1;
      int left = -1,right = -1,up = -1,down = -1;
      
      for(int i = 0; i< n; ++i)
      {
          int dummy;
          vector<int>temp(m,0);
          for(dummy = i; dummy < n; ++dummy)
          {
              for(int j = 0; j< m; ++j)
              {
                  temp[j] += a[dummy][j];
              }
              
              pair<int,int>here = isThere(a, temp);
              
              int maxLen = here.first;
              int ending = here.second;
              
              if(((dummy-i+1)*maxLen) >= mxArea && maxLen > 0)
              {
                  //cout<<"HI BOIS";
                  mxArea = (dummy-i)*maxLen;
                  up = i;
                  down = dummy;
                  left = ending - maxLen +1;
                  right = ending;
              }
          }
      }
      
      vector<vector<int>>ans;
      
      
      if(mxArea == -1)
      {
          ans = {{-1}};
          return ans;
      }
      
    //   cout<<up<<" "<<down<<" "<<left<<" "<<right<<'\n';
    //   cout<<"----------------\n";
      for(int i = up; i<=down; ++i)
      {
          vector<int>here;
          for(int j = left; j<=right; ++j)
          {
              here.push_back(a[i][j]);
          }
          ans.push_back(here);
          
      }
      
      return ans;
  }
};


// { Driver Code Starts.




int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        
        vector<vector<int>> a(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> ans = ob.sumZeroMatrix(a);
        if(ans.size() == 0){
            cout<<-1<<endl;
        }
        else{
            for(int i=0;i<ans.size();i++){
                for(int j=0;j<ans[0].size();j++){
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
        }
    }
    return 0;
}  // } Driver Code Ends