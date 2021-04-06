#include <stdlib.h>

#include<vector>
using namespace std;

class Solution
{
public:
	int search(vector<int>& nums, int target)
	{
		int start = 0;
		int end = nums.size()-1;
		int mid = end;
		if(nums.size() == 1)
		{
			if(nums[0] == target)
				return 0;
			else
				return -1;
		}

		if(nums[0] > nums[end]) {
		while(end-start > 1)
		{
			int mid = (start+end)/2;
			if(nums[mid] > nums[end])
				start = mid;
			else
				end = mid;
		}
		if(start+1 == end)
		{
			if(nums[start] > nums[end])
				mid = start;
			else if(nums[start] < nums[end])
				mid = end;
			else
				mid = end;
		}
		}
		if(nums[0] <= target)
		{
			for(int i=0; i<=mid; i++)
			{
				if(nums[i] == target)
					return i;
			}
			return -1;
		}
		else
		{
			for(int i=mid+1; i<nums.size(); i++)
			{
				if(nums[i] == target)
					return i;
			}
			return -1;
		}
	}
};
