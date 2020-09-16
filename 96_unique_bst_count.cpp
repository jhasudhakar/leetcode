class Solution
{
public:
    int numTrees(int n)
    {
    	int ret = 0;
    	unsigned int* count = new unsigned int [n+1];
    	for(unsigned int i=0; i<=n; i++)
    	{
    			count[i] = 0;
    	}

    	count[0] = 1;
    	count[1] = 1;
    	count[2] = 2;

    	if(n<=2) {
    		ret = count[n];
    		delete [] count;
    		return ret;
    	}

  		for(unsigned int i=3; i<=n; i++)
  		{
  			for(unsigned int j=1; j<=i; j++)
  			{
  				/*
  				left: 1 to j-1 
  				root = j;
  				right: j+1 to i;
  				*/
  				count[i] += count[1 + j-1 -1] * count[1+i - (j+1)];
  			}
  		}
  		ret = count[n];
  		delete [] count;
  		return ret;
    }
};