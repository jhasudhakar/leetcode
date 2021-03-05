#include <climits>
#include<vector>
using namespace std;


class Solution
{
	public:
    int lengthOfLIS(vector<int>& nums)
	{
		if(nums.size() <2)
			return nums.size();
		int* count = new int [nums.size()+1];
		for(int i=0; i<=nums.size(); i++)
			count[i] = 1;

		count[0] = 0;
		for(int i=1; i<=nums.size(); i++)
		{
			for(int j=1; j<i; j++)
			{
				if(nums[j-1] >= nums[i-1])
					continue;

				if(count[j] + 1 > count[i])
					count[i] = 1+ count[j];
			}
		}
		int ret_val = count[nums.size()];
		delete [] count;
		return ret_val;
	}
};
