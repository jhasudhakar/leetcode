

#include <vector>
using namespace std;

class Solution {
public:
	int maxCoins(vector<int>& nums) {
		int N = nums.size();
		int **val = new int* [N];
		for(int i=0; i<N; i++)
		{
			val[i] = new int [N];
			for(int j=0; j<N; j++)
				val[i][j] = 0;
		}
		
	}
};
