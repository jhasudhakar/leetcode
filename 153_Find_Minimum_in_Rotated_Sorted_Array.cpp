#include <stdlib.h>
#include<vector>
using namespace std;

class Solution
{
public:
  int findMin (vector < int >&nums)
  {
	if(nums.size() == 1)
		return nums[0];
	int start = 0;
	int end = nums.size()-1;
	if(nums[0] < nums[end])
		return nums[0];
	while(end-start > 1)
	{
		int mid = (start+end)/2;
		if(nums[mid] > nums[end])
			start = mid;
		else
			end = mid;
	}
	return nums[end];
  }
};
