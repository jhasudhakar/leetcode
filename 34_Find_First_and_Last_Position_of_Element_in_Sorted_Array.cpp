class Solution
{
	public:
	vector<int> searchRange(vector<int>& nums, int target)
	{
		vector<int> ret_vec;
		if(nums.size() == 0)
		{
			ret_vec.push_back(-1);
			ret_vec.push_back(-1);
			return ret_vec;
		}

		int start = 0, end = nums.size()-1;
		while(start < end)
		{
			int mid = (start+end)/2;
			if(nums[mid] >= target)
					end = mid;
			else
				start = mid+1;
		}
		if(nums[start] == target)
			ret_vec.push_back(start);
		else
		{
			ret_vec.push_back(-1);
			ret_vec.push_back(-1);
			return ret_vec;
		}

		//start = 0, end = nums.size()-1;
		end = nums.size()-1;
		while(start+1 < end)
		{
			int mid = (start+end)/2;
			if(nums[mid] <= target)
					start = mid;
			else
				end = mid;
		}
		if(nums[end] == target)
			ret_vec.push_back(end);
		else
			ret_vec.push_back(start);
		return ret_vec;
	}
};