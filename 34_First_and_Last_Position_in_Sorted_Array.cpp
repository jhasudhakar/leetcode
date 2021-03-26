// 26-march-2021
#include<vector>
using namespace std;

class Solution
{
public:

  int binarySearch(vector < int >&nums, int start, int end, int target)
  {
	while(start != end)
	{
		int mid = (start+end)/2;
		if(nums[mid] > target)
			end = mid-1;
		else if(nums[mid] < target)
			start = mid+1;
		else
			end = mid;
	}
	return start;

  }
  
  vector < int > searchRange (vector < int >&nums, int target)
  {
	vector<int> ret;
	if(nums.size() == 0)
	{
		ret.push_back(-1);
		ret.push_back(-1);
		return ret;
	}
	int start = 0;
	int end = nums.size()-1;
	int left_pos = binarySearch(nums, start, end, target);
	if(nums[left_pos] != target)
	{
		ret.push_back(-1);
		ret.push_back(-1);
		return ret;
	}

	int right_pos = -1;
	right_pos = binarySearch(nums, left_pos, end, target+1);
	if(nums[right_pos] != target)
		right_pos--;
	ret.push_back(left_pos);
	ret.push_back(right_pos);
	return ret;
  }
};
