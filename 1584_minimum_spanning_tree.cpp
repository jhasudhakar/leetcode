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
		int* group_id = new int[points.size()];
		for(int i=0; i<points.size(); i++)
		{
			group_id[i] = i;
		}

		while(total_visit < points.size() && min_pq.size())
		{
			edge cur_e = min_pq.top();
			min_pq.pop();
			if(group_id[cur_e.p1] == group_id[cur_e.p2])
				continue;

			cout <<"Edge between points " << cur_e.p1 <<" and " << cur_e.p2 << "\t";
			cout <<"Group p1 = " << group_id[cur_e.p1] <<", Group p2 = " << group_id[cur_e.p2] << endl;

			int min_group_id = min(group_id[cur_e.p1], group_id[cur_e.p2]);
			int to_change = max(group_id[cur_e.p1], group_id[cur_e.p2]);
			if(min_group_id == group_id[cur_e.p1])
			{
				for(int i=0; i<points.size(); i++)
				{
					if(group_id[i] == to_change)
					{
						cout << " Changing the group-id of " << i << " to " << min_group_id << endl;
						group_id[i] = min_group_id;
					}
				}
			}
			else
			{
				for(int i=0; i<points.size(); i++)
				{
					if(group_id[i] == to_change)
					{
						cout << " Changing the group-id of " << i << " to " << min_group_id << endl;
						group_id[i] = min_group_id;
					}
				}
			}

			min_sum += cur_e.get_weight();
			total_visit++;
		}
		delete [] group_id;
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
