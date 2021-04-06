#include<assert.h>
#include <stdlib.h>
#include<vector>
using namespace std;

class Solution
{
public:
  bool search (vector < int >&nums, int target)
  {
	if(nums.size() == 0)
		return false;

  	int start = 0;
	int end = nums.size()-1;
	int last = end;
	int seq = 0;
	if(target == nums[end])
		return true;
	else if(target > nums[end])
		seq = 1;
	else
		seq = 2;
	while(end-start > 1)
	{
		int mid = (start+end)/2;
		if(nums[mid] == target)
			return true;
		if(nums[mid] > nums[last] && seq == 1)
		{
			if(nums[mid] > target)
				end = mid;
			else
				start = mid;
		}
		else if(nums[mid] > nums[last] && seq == 2)
		{
			start = mid;
		}
		else if(nums[mid] < nums[last] && seq == 1)
		{
			end = mid;
		}
		else if(nums[mid] < nums[last] && seq == 2)
		{
			if(nums[mid] > target)
				end = mid;
			else
				start = mid;
		}
		else if(nums[mid] == nums[last] && seq == 1)
		{
			if(nums[start] != target)
				start++;
			else
				return true;
		}
		else if(nums[mid] == nums[last] && seq == 2)
		{
			if(nums[end] == target)
				return true;
			else
				end--;
		}
		else 
		{
			assert(false);
		}
	}

	if(target == nums[start] || target == nums[end])
		return true;
	else
		return false;
  }
};
