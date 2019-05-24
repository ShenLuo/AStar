/*
	二维地图类
*/

#pragma once
#include "stdafx.h"
#include "../definition/definition.h"
#include <vector>

// 二维地图类
class Map2
{
public:
	Map2();
	~Map2();

	// 初始化不可通过的地图点
	void InitBlockPosition(std::vector<Position2>& tempVector);

	// 获取某点是否在地图中
	bool GetPositionInMap(Position2& position);

	// 获取某点是否为阻塞点
	bool GetPositionBlockPosition(Position2& position);

private:
	int m_map[LENGTH][WIGTH];
};


