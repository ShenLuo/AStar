/*
	二维地图类
*/

#include "stdafx.h"
#include "map2.h"

Map2::Map2()
{
	for (int i = 0; i < LENGTH; i++)
	{
		for (int j = 0; j < WIGTH; j++)
		{
			m_map[i][j] = 0;
		}
	}
}

Map2::~Map2()
{

}

// 初始化不可通过的地图点
void Map2::InitBlockPosition(std::vector<Position2>& tempVector)
{
	for (int i = 0; i < tempVector.size(); i ++)
	{
		if ((tempVector[i].m_x >=0 && tempVector[i].m_x < LENGTH) &&
			tempVector[i].m_y >= 0 && tempVector[i].m_y < WIGTH)
		{
			m_map[tempVector[i].m_x][tempVector[i].m_y] = 1;
		}
	}
}

// 获取某点是否在地图中
bool Map2::GetPositionInMap(Position2& position)
{
	if ((position.m_x >=0 && position.m_x < LENGTH) &&
		position.m_y >= 0 && position.m_y < WIGTH)
	{
		return true;
	}

	return false;
}

// 获取某点是否为阻塞点
bool Map2::GetPositionBlockPosition(Position2& position)
{
	if ((position.m_x >=0 && position.m_x < LENGTH) &&
		position.m_y >= 0 && position.m_y < WIGTH)
	{
		return m_map[position.m_x][position.m_y] == 1;;
	}

	return true;
}