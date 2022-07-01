// { Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

 // } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        int n = str1.length();
        
        if(n != str2.length()) return 0;
        
        map<char,int>mp1,mp2;\
        
        map<char,char>ord;
        
        for(int i = 0; i< n; ++i)
        {
            mp1[str1[i]]++;
            mp2[str2[i]]++;
            
            if(ord.find(str1[i]) != ord.end())
            {
                if(str2[i] != ord[str1[i]])
                {
                    return 0;
                }
            }
            else
            {
                ord[str1[i]] = str2[i];
            }
            if(mp1[str1[i]] != mp2[str2[i]])
            {
                return 0;
            }
        }
        
        return 1;
    }
};

// { Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}  // } Driver Code Ends