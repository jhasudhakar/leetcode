

class Solution {
public:
    int numTrees(int n) {
	
	if(n<3)
		return n;

	int* count = new int[n+1];
	count[0] = 1;
	count[1] = 1;
	count[2] = 2;
	for(int i=3; i<=n; i++)
	{
		int sum = 0;
		for(int pos=1; pos <=i; pos++)
		{
			sum += (count[pos-1] * count[i-pos]);	
		}
		count[i] = sum;
	}
	int ret_val = count[n];
	delete [] count;
	return ret_val;
    }
};
