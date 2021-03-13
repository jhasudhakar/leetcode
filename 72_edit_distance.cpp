#include <climits>
#include <string>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2)
	{
		int N1 = word1.size();
		int N2 = word2.size();
		
		if(N1 == 0 || N2 == 0)
			return (N1>N2 ? N1:N2);	

		int** val = new int* [N1+1];
		for(int i=0; i<=N1; i++)
		{
			val[i] = new int[N2+1];
			for(int j=0; j<=N2; j++)
				val[i][j] = 1000;
		}

		val[0][0] = 0;
		for(int i=1; i<=N1; i++)
			val[i][0] = i;
		for(int i=1; i<=N2; i++)
			val[0][i] = i;

		for(int i=1; i<=N1; i++)
		{
			for(int j=1; j<=N2; j++)
			{
				int tmp = 1+ val[i][j-1];
				if(1+val[i-1][j] < tmp)
				{
					tmp = 1+val[i-1][j];
				}

				int tmp2 = val[i-1][j-1];
				if(word1[i-1] != word2[j-1])
					tmp2++;
				if(tmp2 < tmp)
					tmp = tmp2;

				val[i][j] = tmp;
			}
		}
		int ret_val = val[N1][N2];
		for(int i=0; i<=N1; i++)
			delete [] val[i];
		delete [] val;
		return ret_val;
    }

};
