//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int t[101][101];
   int solve(int arr[],int i,int j,int ans){
       if(i>=j){
           return 0;
       }
       if(t[i][j]!=-1){
           return t[i][j];
       }
       
       
       for(int k=i;k<=j-1;k++){
           int tempAns=solve(arr,i,k,ans)+solve(arr,k+1,j,ans)+arr[i-1]*arr[k]*arr[j];
           ans=min(ans,tempAns);
       }
       return t[i][j]=ans;
       
   }

   int matrixMultiplication(int N, int arr[])
   {
       int ans=INT_MAX;
       memset(t,-1,sizeof(t));
       int cost=solve(arr,1,N-1,ans);
       return cost;
   }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends