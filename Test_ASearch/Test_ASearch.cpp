// Test_ASearch.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "map/map2.h"
#include "definition/definition.h"
#include "mappointmanager/mappointmanager.h"
#include <vector>

int _tmain(int argc, _TCHAR* argv[])
{
	Map2 map = Map2();
	std::vector<Position2> temp;
	temp.clear();
	//temp.push_back(Position2(1,2));
	temp.push_back(Position2(1,2));
	temp.push_back(Position2(3,1));
	temp.push_back(Position2(2,3));
	map.InitBlockPosition(temp);

	std::vector<Position2> path;
	Map2PointManager map2PointManager = Map2PointManager();
	map2PointManager.GetPointsPathByAStar(&map,&Position2(1,0), &Position2(3,3), path);

	for (int i = 0; i < path.size(); i++)
	{
		printf("posx = %d, posy = %d\n", path[i].m_x, path[i].m_y);
	}

	getchar();
	return 0;
}



