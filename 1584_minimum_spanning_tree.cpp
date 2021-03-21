#include <queue>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

struct edge
{
	int p1, p2;
	int x1, y1;
	int x2, y2;
	edge(int point1, int point2, int v1, int v2, int v3, int v4)
	{
		p1 = point1;
		p2 = point2;

		x1 = v1, y1 = v2;
		x2 = v3, y2 = v4;
	}
	int get_weight() const
	{
		int w1 = abs(x1-x2)+ abs(y1-y2);
		return w1;
	}
	bool operator<(const edge& rhs) const
	{
		int w1 = this->get_weight();
		int w2 = rhs.get_weight();

		return w1 > w2;
	}
};

class Solution {
public:
	int minCostConnectPoints(vector<vector<int> >& points)
	{
		int min_sum = 0;
		priority_queue<edge> min_pq;
		for(int i=0; i<points.size(); i++)
		{
			for(int j=0; j<i; j++)
			{
				min_pq.push(edge(i, j, points[i][0], points[i][1], points[j][0], points[j][1]));
			}
		}

		int total_visit = 0;
		bool* is_visited = new bool[points.size()];
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

