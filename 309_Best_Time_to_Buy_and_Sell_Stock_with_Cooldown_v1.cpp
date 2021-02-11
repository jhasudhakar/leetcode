#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2)
            return 0;
        int** profits = new int* [prices.size()];
        for(int i=0; i<prices.size(); i++)
        {
            profits[i] = new int [prices.size()];
        }

        for(int start = 0; start<prices.size(); start++)
        {
            for(int end = start; end<prices.size(); end++)
            {
                if(prices[end] <= prices[start])
                {
                    profits[start][end] = 0;
                }
                else
                {
                    profits[start][end] = prices[end] - prices[start];
                }
            }
        }

        int* max_p_0 = new int[prices.size()];
        for(int i=0; i<prices.size(); i++)
        {
            max_p_0[i] = 0;
        }

        int* max_p_1 = new int[prices.size()];
        for(int i=0; i<prices.size(); i++)
        {
            max_p_1[i] = 0;
        }

        max_p_0[0] = max_p_1[1] = 0;

        for(int n=1; n<prices.size(); n++)
        {
            max_p_0[n] = max(max_p_1[n-1], max_p_0[n-1]);
            max_p_1[n] = profits[0][n];
            for(int i=1; i<n;i++)
            {
                max_p_1[n] = max(max_p_1[n], profits[i][n] + max_p_0[i-1]);
            }
        }
        return max(max_p_0[prices.size()-1], max_p_1[prices.size()-1]);
    }
};

