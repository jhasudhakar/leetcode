#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

struct edge
{
	int p1;
	int p2;
	int get_weight()
	{
		int w1 = abs(points[p1][0]-points[p2][0]) + abs(points[p1][1]-points[p2][1]);
		return w1;
	}
	bool operator<(const edge& rhs) const
	{
		int w1 = abs(points[p1][0]-points[p2][0]) + abs(points[p1][1]-points[p2][1]);
		int w2 = abs(points[rhs.p1][0]-points[rhs.p2][0]) + abs(points[rhs.p1][1]-points[rhs.p2][1]);

		return w1 < w2;
	}
};

class Solution {
public:
	int minCostConnectPoints(vector<vector<int>>& points)
	{
		int min_sum = 0;
		priority_queue<edge> min_pq;
		for(int i=0; i<points.size(); i++)
		{
			for(int j=0; j<i; j++)
			{
				min_pq.insert(edge(i, j));
			}
		}

		int total_visit = 0;
		bool is_visited* = new bool[points.size()];
		for(int i=0; i<points.size(); i++)
			is_visited[i] = false;

		while(total_visit < points.size() && min_pq.size())
		{
			edge cur_e = min_pq.top();
			min_pq.pop();
			if(is_visited[cur_e.p1] && is_visited[cur_e.p2])
				continue;

			is_visited[cur_e.p1] = true;
			is_visited[cur_e.p2] = true;
			min_sum += cur_e.get_weight();
		}
		delete [] is_visited;
		return min_sum;			

	}
};

