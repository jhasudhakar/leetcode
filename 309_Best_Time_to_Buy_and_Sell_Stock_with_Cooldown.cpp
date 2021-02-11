#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if(prices.size() < 2)
			return 0;

		int* max_p_0 = new int[prices.size()];
		int* max_p_1 = new int[prices.size()];
		/*
		for(int i=0; i<prices.size(); i++)
		{
			max_p_0[i] = 0;
		}
		
		for(int i=0; i<prices.size(); i++)
		{
			max_p_1[i] = 0;
		}
		*/
		max_p_0[0] = max_p_1[1] = 0;

		for(int n=1; n<prices.size(); n++)
		{
			max_p_0[n] = max(max_p_1[n-1], max_p_0[n-1]);
			max_p_1[n] = prices[n]> prices[0]? prices[n]-prices[0]:0;
			for(int i=1; i<n;i++)
			{
				int profit = 0;
				if(prices[n] > prices[i])
					profit = prices[n] - prices[i];
				max_p_1[n] = max(max_p_1[n], profit + max_p_0[i-1]);
			}
		}
		int ret_val =  max(max_p_0[prices.size()-1], max_p_1[prices.size()-1]);
		delete []  max_p_0;
		delete [] max_p_1;
		return ret_val;
    }
};
