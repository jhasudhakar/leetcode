
#include <vector>
using namespace std;

class Solution {

public:
	vector<int> sortArray(vector<int>& nums)
	{
		if(nums.size() <2)
			return nums;
		quicksort(nums, 0, nums.size()-1);
		return nums;
	}

	void quicksort(vector<int>& nums, int start, int end)
	{
		if(start >=end)
			return;
		int key = nums[start];
		int i = start+1;
		int j = end;
		while(i<j)
		{
			while(nums[i] <= key && i <=end)
				i++;
			while(nums[j] >= key && j>=start)
				j--;
			if(i < j)
			{
				std::swap(nums[i], nums[j]);
			}
		}
		std::swap(nums[start], nums[i-1]);
		quicksort(nums, start, i-2);
		quicksort(nums, i, end);
	}

};
