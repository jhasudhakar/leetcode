#include<string>
using namespace std;

class Solution {
	public:
	int longestCommonSubsequence(string text1, string text2)
	{
		int N1 = text1.size();
		int N2 = text2.size();
		if(N1 == 0 || N2 == 0)
			return 0;

		int** lcs = new int* [N1+1];
		for(int i=0; i<=N1; i++)
			lcs[i] = new int [N2+1];
		for(int i=0; i<=N1; i++)
		{
			lcs[i][0] = 0;
		}
		for(int i=0; i<=N2; i++)
		{
			lcs[0][i] = 0;
		}
		for(int i=1; i<=N1; i++)
		{
			for(int j=1; j<=N2; j++)
			{
				int val = lcs[i-1][j-1];
				if(text1[i-1] == text2[j-1])
					val++;
				if(lcs[i][j-1] > val)
					val = lcs[i][j-1];
				if(lcs[i-1][j] > val)
					val = lcs[i-1][j];

				lcs[i][j] = val;
			}

		}
		int ret_val = lcs[N1][N2];
		for(int i=0; i<=N1; i++)
			delete [] lcs[i];
		delete [] lcs;
		return ret_val;
	}
};
