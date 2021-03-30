#include<vector>
using namespace std;

class Solution
{
public:
	void quick_sort(vector<int>& arr, int start, int end)
	{
		if(start >= end)
			return;
		int key = arr[start];
		int i = start+1;
		int j = end;
		while(i <= j)
		{
			while(i<=j && arr[i] <= key)
				i++;
			while(j>=i && arr[j] >= key)
				j--;
			if(i < j)
				swap(arr[i], arr[j]);

		}
		swap(arr[start], arr[i-1]);
		quick_sort(arr, start, i-2);
		quick_sort(arr, i, end);
	}


  vector < int >sortArray (vector < int >&nums)
  {
	if(nums.size() < 2)
		return nums;
	quick_sort(nums, 0, nums.size()-1);
	return nums;
  }
};
