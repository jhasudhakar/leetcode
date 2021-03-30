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
		bool* is_added = new bool [points.size()];
		int* weights = new int [points.size()];
		int* src = new int [points.size()];
		for(int i=0; i<points.size(); i++)
		{
			src[i] = points.size() +1;
			weights[i] = 5 * 1000000;
			is_added[i] = false;
		}

		is_added[0] = true;
		int node_count = 1;
		src[0] = 0;
		for(int i=1; i<points.size(); i++)
		{
			weights[i] = abs(points[0][0] - points[i][0]) + abs(points[0][1] - points[i][1]);
			src[i] = 0;
		}
		while(node_count < points.size())
		{
			int min_weight = 5 * 1000000;
			int next_v = points.size() +1;
			for(int i=0; i<points.size(); i++)
			{
				if(is_added[i] == true)
					continue;
				if(weights[i] < min_weight)
				{
					min_weight = weights[i];
					next_v = i;
				}
			}
			is_added[next_v] = true;
			node_count++;
			for(int i=0; i<points.size(); i++)
			{
				if(is_added[i]) continue;
				int tmp_w = abs(points[next_v][0] - points[i][0]) + abs(points[next_v][1] - points[i][1]);
				if(tmp_w < weights[i])
				{
					src[i] = next_v;
					weights[i] = tmp_w;
				}
			}
		}

		for(int i=0; i<points.size(); i++)
		{
			min_sum += abs(points[i][0] - points[src[i]][0]) + abs(points[i][1] - points[src[i]][1]);
		}
		return min_sum;			
	}
};

int main()
{
	vector< vector<int> > points;
	// [[2,-3],[-17,-8],[13,8],[-17,-15]]
	vector<int> p1{2, -3};
	vector<int> p2{-17, -8};
	vector<int> p3{13, 8};
	vector<int> p4{-17, -15};
	points.push_back(p1);
	points.push_back(p2);
	points.push_back(p3);
	points.push_back(p4);

	Solution obj;
	int cost = 	obj.minCostConnectPoints(points);
	cout <<"Min cost = " << cost << endl;
	return 0;

}
