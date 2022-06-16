// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char>st;
        
        int n = x.length();
        
        if(n%2)return false;
        
        
        for(int i = 0; i< n; ++i)
        {
            if(x[i] == '(' || x[i] == '[' || x[i] == '{')
            {
                st.push(x[i]);
            }
            else
            {
                if(st.empty())return false;
                
                char here = st.top();
                st.pop();
                
                if(i == 0) return false;
                
                if(x[i] == ')' && here != '(')
                {
                    return false;
                }
                else if(x[i] == ']' && here != '[')
                {
                    return false;
                }
                else if(x[i] == '}' && here != '{')
                {
                    return false;
                }
            }
        }
        
        if(st.size())return false;
        
        return true;
    }

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends