#include<iostream>
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
		while(i<=j)
		{
			while(i<=end && nums[i] <= key)
				i++;
			while(j>=start && nums[j] >= key)
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

int main()
{
	vector<int> arr;
	arr.push_back(3);
	arr.push_back(1);

	Solution obj;
	vector<int> ret = obj.sortArray(arr);
	cout << "sorted output = ";
	for(int i=0; i<ret.size(); i++)
	{
		cout << ret[i] <<" ";
	}
	cout << endl;
	return 0;
}
