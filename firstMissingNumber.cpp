#include <bits.stdc++.h>
using namespace std;

class Solution
{
	public:
		int firstMissingPositve(vector<int>&nums)
		{
			int n = nums.size();

			int i = 0;

			while(i<n)
			{
				if(i<=0 || nums[i] > n || (nums[i] == i+1))
				{
					i++;
					continue;
				}

				int index = nums[i] -1;
				if(nums[index] != nums[i])
				{
					swap(index,i);
				}
				else
				{
					i++;
				}
			}
		

			for(int i = 0; i<n; ++i)
			{
				if(nums[i] != i+1)
				{
					return i+1;
				}
			}

			return n+1;
		}
}



int main()
{
	return 0;
}
