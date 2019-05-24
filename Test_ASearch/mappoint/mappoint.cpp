/*
	二维地图中的点
*/

#include "stdafx.h"
#include "mappoint.h"

Map2Point::Map2Point(int x, int y, Map2Point* p)
{
	m_pos_x = x;
	m_pos_y = y;
	m_pNext = p;
	m_f = 0;
	m_g = 0;
	m_h = 0;
}

Map2Point::~Map2Point()
{
	m_pNext = NULL;
}

void Map2Point::SetNextMap2Point(Map2Point* p)
{
	m_pNext = p;
}

Map2Point* Map2Point::GetNextMap2Point()
{
	return m_pNext;
}

bool Map2Point::operator == (Map2Point* point)
{
	if (m_pos_x == point->m_pos_x && m_pos_y == point->m_pos_y)
	{
		return true;
	}

	return false;
}

bool Map2Point::operator != (Map2Point* point)
{
	if (m_pos_x == point->GetPosX() && m_pos_y == point->GetPosY())
	{
		return false;
	}

	return true;
}