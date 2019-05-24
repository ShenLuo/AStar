/*
	二维地图管理
*/

#pragma once
#include "stdafx.h"
#include "../map/map2.h"
#include "../mappoint/mappoint.h"
#include "../definition/definition.h"

class Map2PointManager
{
public:
	Map2PointManager(){}
	~Map2PointManager(){}

	// A*获得某场景中两点间的路点
	void GetPointsPathByAStar(Map2* map, Position2* begin,
		Position2* end, std::vector<Position2>& path);

private:
	// 场景中是否存在改坐标
	bool IsPositionInScene(Map2* map, Position2* pos);

	// 获取某点是否为阻塞点
	bool IsPositionBlockInScene(Map2* map, Position2* pos);

	bool IsPositionOpened(std::vector<Map2Point*> posVec, Position2* pos);
	Map2Point* GetPositionOpened(std::vector<Map2Point*> posVec, Position2* pos);

	// 计算F = G + H
	void CalDistance(Map2* map, Map2Point* curPos, Map2Point* begin, Map2Point* end);

	// 
	Map2Point* GetNearestPos(std::vector<Map2Point*> posVec);

	// 
	void EraseClosePos(std::vector<Map2Point*>& posVec, Map2Point* pos);
};