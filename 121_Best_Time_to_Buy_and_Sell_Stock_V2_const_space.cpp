
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
		vector<int> min_at;
		int max_p = 0;
		int min_stock_val = prices[0];
		for(int i=1; i<prices.size(); i++)
		{
			if(prices[i] < min_stock_val) // Cur price is lowest.
			{
				min_stock_val = prices[i];
			}
			else
			{
				int day_p = prices[i] - min_stock_val;
				if(day_p > max_p)
					max_p = day_p;
			}
		}
		return max_p;			
    }
};
