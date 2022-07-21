//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:


long long getMaxArea(long long arr[], int n)
   {
       // Your code here
       stack<long long> st;
       vector<long long> leftsmaller(n),rightsmaller(n);
       for(int i=0;i<n;i++){
           while(!st.empty() && arr[st.top()]>=arr[i]){
               st.pop();
           }
           if(st.empty()){
               leftsmaller[i]=0;
           }
           else{
               leftsmaller[i]=st.top()+1;
           }
           st.push(i);
       }
       //cout<<leftsmaller.size();
       while(!st.empty()){
           st.pop();
       }
       for(int i=n-1;i>=0;i--){
           while(!st.empty() && arr[st.top()]>=arr[i]){
               st.pop();
           }
           if(st.empty()){
               rightsmaller[i]=n-1;
           }
           else{
               rightsmaller[i]=st.top()-1;
           }
           st.push(i);
       }
       //cout<<rightsmaller.size();

       long long max_ans=0;
       for(int i=0;i<n;i++){
           max_ans=max(max_ans,(rightsmaller[i]-leftsmaller[i]+1)*arr[i]);
       }
       return max_ans;
   }
};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends