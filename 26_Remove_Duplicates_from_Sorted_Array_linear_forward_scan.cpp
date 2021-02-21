#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.size();
        int unq_val = nums[0];
        int write_pos = -1, dup_count = 0;
        const int MARKER = 10000 + 100;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == unq_val)
            {
                nums[i] = MARKER;
                dup_count++;
                if(write_pos < 0)
                    write_pos = i;
            }
            else
            {
                unq_val = nums[i];
            }
        }
        if(write_pos == -1)
            return nums.size();
        for(int i = write_pos+1; i<nums.size(); i++)
        {
            if(nums[i] != MARKER)
            {
                nums[write_pos++] = nums[i];
            }
        }
        return nums.size()-dup_count;
    }
};