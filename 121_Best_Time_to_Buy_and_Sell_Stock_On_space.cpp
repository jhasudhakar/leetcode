
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
		vector<int> min_at;
		min_at.push_back(prices[0]);
		int max_p = 0;
		for(int i=1; i<prices.size(); i++)
		{
			if(prices[i] < min_at[i-1]) // Cur price is lowest.
			{
				min_at.push_back(prices[i]);
			}
			else
			{
				int day_p = prices[i] - min_at[i-1];
				if(day_p > max_p)
					max_p = day_p;
				min_at.push_back(min_at[i-1]); // Laat min-val is still lower.
			}
		}
		return max_p;			
    }
};
