#include <map>
#include<vector>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
		vector<int> ret_nums;
        std::map<int, int> nums1_count;
        for(unsigned int i=0; i<nums1.size(); i++)
		{
			if(nums1_count.end() == nums1_count.find(nums1[i]))
				nums1_count.insert ( std::pair<int,int>(nums1[i],1) );
			else
				nums1_count[nums1[i]]++;
		}

		for(int i=0; i<nums2.size(); i++)
		{
			if(nums1_count.end() == nums1_count.find(nums2[i]) || 0 == nums1_count[nums2[i]])
				continue;
			
			nums1_count[nums2[i]]--;
			ret_nums.push_back(nums2[i]);
		}
		return ret_nums;
    }
};
