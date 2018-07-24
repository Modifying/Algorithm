// 一个平面上的n个点, 找出哪条直线上的点最多.


#include <vector>
#include <map>
#include <algorithm>
#include <list>

struct Point 
{
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
	
};

int MaxPoints(std::vector<Point> &points)
{
	if (points.size() < 2)
		return points.size();

	int size = points.size();
	int ret = 0;
	for (int i = 0; i < size - 1; ++i)
	{
		int dup = 0;
		int cnt = 1;
		int max = 1;
		std::map<double, int> mp;
		for (int j = i + 1; j < size; ++j)
		{
			double x = points[i].x - points[j].x;
			double y = points[i].y - points[j].y;

			if (x == 0 && y == 0)
				++dup;
			else if (x == 0)
			{
				++cnt;
				max = std::max(cnt, max);
			}
			else
			{
				double slope = y / x;
				if (mp[slope] == 0)
					mp[slope] = 2;
				else
					++mp[slope];

				max = std::max(mp[slope], max);
			}	
		}
		ret = std::max(ret, max + dup);

	}
	return ret;
}


int main()
{
	

	return 0;
}