#include<stdlib.h>
#include<vector>
#include<algorithm>
using namespace std;

struct ival
{
	int num;
	bool  is_end;
	ival(int _num, bool _is_end)
	{
		num = _num;
		is_end = _is_end;
	}
	bool operator<(struct ival& that)
	{
		if(num < that.num)
			return true;
		else if(num > that.num)
			return false;
		else
		{
			if(is_end == false)
				return true;
			else
				return false;
		}
	}
};

class Solution
{
public:
  vector < vector < int > >merge (vector < vector < int > >&intervals)
  {
	vector< vector<int> > ret_vec;
	vector<struct ival> vec;
	for(int i=0; i<intervals.size(); i++)
	{
		struct ival tmp1(intervals[i][0], false);
		struct ival tmp2(intervals[i][1], true);
		vec.push_back(tmp1);
		vec.push_back(tmp2);
	}
	sort(vec.begin(), vec.end());
	int start = -1; //vec[0].num;
	int start_end_counter = 0;
	for(int i=0; i<vec.size(); i++)
	{
		if(vec[i].is_end == false) // start marker
		{
			if(start_end_counter == 0)
			{
				start = vec[i].num;
			}
			start_end_counter++;
			continue;
		}
		else // End marker.
		{
			start_end_counter--;
			if(start_end_counter == 0)
			{
				vector<int> buf;
				buf.push_back(start);
				buf.push_back(vec[i].num);
				ret_vec.push_back(buf);
			}
		}
	}

	return ret_vec;
  }
};
