#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
		if(prices.size() <=1)
			return 0;

		int total_p = 0;
		int min = prices[0];

		for(int i=1; i<prices.size(); i++)
		{
			if(prices[i] > prices[i-1])
			{
				continue;
			}
			else
			{
				total_p += (prices[i-1] - min);
				min = prices[i];
			}
		}
		if(prices[prices.size()-1] > min)
		{
			total_p += (prices[prices.size()-1] - min);
		}
		return total_p;
    }
};
