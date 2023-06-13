#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool could_eat(vector<int>&piles,int h,int speed)
    {
        int time = 0;
        for(int i=0;i<piles.size();i++)
        {   
            int here = piles[i]/speed;

            if(piles[i]%speed) here++;

            time += here;
            if(time > h) return false;
        }
        

        return true;
    }
    int minEatingSpeed(vector<int>&piles,int h) 
    {
        int left=1,right=INT_MIN;
        right = *max_element(piles.begin(), piles.end());
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(could_eat(piles,h,mid))
            {
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        return left;
    }
};
