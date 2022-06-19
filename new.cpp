#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD= 1000000007;
#define int long long

int minPathSum(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> prev(n);
    
        for(int i=0;i<m;i++)
        {
            vector<int> curr(n);
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                    curr[j] = grid[i][j];
                else
                {
                    int up = grid[i][j];
                    if(i>0)
                        up += prev[j];
                    else
                        up += 1e9;

                    int left = grid[i][j];
                    if(j>0)
                        left += curr[j-1];
                    else
                        left += 1e9;

                    curr[j] = min(up,left);
                }
            }
            prev = curr;
        }

        return prev[n-1];
    }

bool isPalindrome(string S)
{
  
    string P = S;
 
    
    reverse(P.begin(), P.end());
 
    
    if (S == P) {
       
        return true;
    }
    
    else {
       
        return false;
    }
}

bool isSmaller(string str1, string str2)
{
    // Calculate lengths of both string
    int n1 = str1.length(), n2 = str2.length();
 
    if (n1 < n2)
        return true;
    if (n2 < n1)
        return false;
 
    for (int i = 0; i < n1; i++)
        if (str1[i] < str2[i])
            return true;
        else if (str1[i] > str2[i])
            return false;
 
    return false;
}
 
// Function for find difference of larger numbers
string findDiff(string str1, string str2)
{
    // Before proceeding further, make sure str1
    // is not smaller
    if (isSmaller(str1, str2))
        swap(str1, str2);
 
    // Take an empty string for storing result
    string str = "";
 
    // Calculate length of both string
    int n1 = str1.length(), n2 = str2.length();
 
    // Reverse both of strings
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
 
    int carry = 0;
 
    // Run loop till small string length
    // and subtract digit of str1 to str2
    for (int i = 0; i < n2; i++) {
        // Do school mathematics, compute difference of
        // current digits
 
        int sub
            = ((str1[i] - '0') - (str2[i] - '0') - carry);
 
        // If subtraction is less then zero
        // we add then we add 10 into sub and
        // take carry as 1 for calculating next step
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
 
        str.push_back(sub + '0');
    }
 
    // subtract remaining digits of larger number
    for (int i = n2; i < n1; i++) {
        int sub = ((str1[i] - '0') - carry);
 
        // if the sub value is -ve, then make it positive
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
 
        str.push_back(sub + '0');
    }
 
    // reverse resultant string
    reverse(str.begin(), str.end());
 
    return str;
}
 

void solve()
{
    int n;
    cin>>n;

    vector<int>arr(n);

    for(auto&c:arr)cin>>c;

    int negetiveCount = 0;

    for(int i = 0; i< n; ++i)
    {
        if(arr[i] < 0)
        {
            negetiveCount ++;
        }
    }

    int ans = 0;
    int looping = 0;
    while(true)
    {
        //assert(looping < 2*n);
        looping ++;
        
        // if(looping == 5) break;

        // for(auto&c:arr)
        // {
        //     cout<<c<< " ";
        // }

        // cout<<"----------\n";
        int here =  *min_element(arr.begin(), arr.end());


        if(negetiveCount == n)
        {
            for(int i = 0; i< n; ++i)
            {
                arr[i] += abs(here);
            }
            ans += abs(here);
            negetiveCount =0 ;

            
            continue;
        }

        int zeroCount = 0;

            for(int i = 0; i< n; ++i)
            {
                if(arr[i] == 0)
                {
                    zeroCount++;
                }
            }

            if(zeroCount == n)
            {
                cout<<ans<<'\n';
                return;
            }

        int equalCount = 0;

        for(int i = 1; i< n; ++i)
        {
            if(arr[i] == arr[0])
            {
                equalCount ++;
            }
        }

        //cout<<equalCount<<" \n ";

        if(equalCount == n-1)
        {
            ans += arr[0];

            cout<<ans<<'\n';
            return;
        }
        int index ;
        for(int i =0; i< n;++i)
        {
            if(arr[i] == here)
            {
                index = i;
                break;
            }
        }


        if(index != 0)
        {
            int neighbour = arr[index-1];

            int reduction = - arr[index]  + neighbour;
            ans += abs(reduction);
            for(int i = 0; i < index; ++i)
            {
                if(arr[i] >=0 && (arr[i] - reduction < 0))
                {
                    negetiveCount ++;
                }
                arr[i] -= reduction;
            }
        }
        if(index != n-1)
        {
            int neighbour = arr[index+1];
            
            int reduction = -arr[index] + neighbour;

            ans+= abs(reduction);
            for(int i = index+1; i < n; ++i)
            {
                if(arr[i] >=0 && (arr[i] - reduction < 0))
                {
                    negetiveCount ++;
                }
                arr[i] -= reduction;
            }
        }
    }
}

signed main() 
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


     ll test=1;
cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
