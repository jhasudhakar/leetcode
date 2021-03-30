#include<vector>
using namespace std;

class Solution
{
public:
  void 	merge_sort(vector<int>& arr, int start, int end)
  {
	if(start >= end)
		return;
	int mid = (start+end)/2;
	merge_sort(arr, start, mid);
	merge_sort(arr, mid+1, end);
	int* buff = new int[1+end-start];
	int n1 = start;
	int n2 = mid+1;
	int n3 = 0;
	while(n1 <=mid && n2 <=end)
	{
		if(arr[n1] <= arr[n2])
			buff[n3++] = arr[n1++];
		else
			buff[n3++] = arr[n2++];
	}
	while(n1<=mid)
		buff[n3++] = arr[n1++];

	while(n2<=end)
		buff[n3++] = arr[n2++];
	for(int i=0; i<=end-start; i++)
	{
		arr[start+i] = buff[i];
	}
	return;
  } 

  vector < int >sortArray (vector < int >&nums)
  {
	if(nums.size() == 0)
		return nums;
	merge_sort(nums, 0, nums.size()-1);
	return nums;
  }
};
