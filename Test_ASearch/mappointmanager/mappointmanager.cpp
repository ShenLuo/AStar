/*
	二维地图管理
*/

#include "stdafx.h"
#include "mappointmanager.h"

// A*获得某场景中两点间的路点
void Map2PointManager::GetPointsPathByAStar(Map2* map, 
	Position2* begin, Position2* end, std::vector<Position2>& path)
{
	if (NULL == map || NULL == begin || NULL == end)
	{
		return;
	}

	std::vector<Map2Point*> openVec;
	openVec.clear();

	std::vector<Map2Point*> closeVec;
	closeVec.clear();

	Map2Point* endPoint = new Map2Point(end->m_x, end->m_y);
	Map2Point* curPoint = new Map2Point(begin->m_x, begin->m_y);
	while (curPoint && (*curPoint != endPoint))
	{
		EraseClosePos(openVec, curPoint);
		closeVec.push_back(curPoint);

		// 上
		Position2 tempUp = Position2(curPoint->GetPosX(), curPoint->GetPosY() + 1);
		if (IsPositionInScene(map, &tempUp) && !IsPositionBlockInScene(map, &tempUp) &&
			!IsPositionOpened(openVec, &tempUp) && !IsPositionOpened(closeVec, &tempUp))
		{
			if (!IsPositionOpened(openVec, &tempUp))
			{
				Map2Point* up = new Map2Point(tempUp.m_x, tempUp.m_y);
				up->SetNextMap2Point(curPoint);
				CalDistance(map, up, curPoint, endPoint);
				openVec.push_back(up);
			}
			else
			{
				Map2Point* temp = GetPositionOpened(openVec, &tempUp);
				if (temp && (temp->GetG() > (curPoint->GetG() + 1)))
				{
					temp->SetNextMap2Point(curPoint);
					CalDistance(map, temp, curPoint, endPoint);
				}
			}
		}

		// 下
		Position2 tempDown = Position2(curPoint->GetPosX(), curPoint->GetPosY() - 1);
		if (IsPositionInScene(map, &tempDown) && !IsPositionBlockInScene(map, &tempDown) &&
			!IsPositionOpened(openVec, &tempDown) && !IsPositionOpened(closeVec, &tempDown))
		{
			if (!IsPositionOpened(openVec, &tempDown))
			{
				Map2Point* down = new Map2Point(tempDown.m_x, tempDown.m_y);
				down->SetNextMap2Point(curPoint);
				CalDistance(map, down, curPoint, endPoint);
				openVec.push_back(down);
			}
			else
			{
				Map2Point* temp = GetPositionOpened(openVec, &tempDown);
				if (temp && (temp->GetG() > (curPoint->GetG() + 1)))
				{
					temp->SetNextMap2Point(curPoint);
					CalDistance(map, temp, curPoint, endPoint);
				}
			}
		}

		// 左
		Position2 tempLeft = Position2(curPoint->GetPosX() - 1, curPoint->GetPosY());
		if (IsPositionInScene(map, &tempLeft) && !IsPositionBlockInScene(map, &tempLeft) &&
			!IsPositionOpened(openVec, &tempLeft) && !IsPositionOpened(closeVec, &tempLeft))
		{
			if (!IsPositionOpened(openVec, &tempLeft))
			{
				Map2Point* left = new Map2Point(tempLeft.m_x, tempLeft.m_y);
				left->SetNextMap2Point(curPoint);
				CalDistance(map, left, curPoint, endPoint);
				openVec.push_back(left);
			}
			else
			{
				Map2Point* temp = GetPositionOpened(openVec, &tempLeft);
				if (temp && (temp->GetG() > (curPoint->GetG() + 1)))
				{
					temp->SetNextMap2Point(curPoint);
					CalDistance(map, temp, curPoint, endPoint);
				}
			}
		}

		// 右
		Position2 tempRight = Position2(curPoint->GetPosX() + 1, curPoint->GetPosY());
		if (IsPositionInScene(map, &tempRight) && !IsPositionBlockInScene(map, &tempRight) &&
			!IsPositionOpened(closeVec, &tempRight))
		{
			if (!IsPositionOpened(openVec, &tempRight))
			{
				Map2Point* right = new Map2Point(tempRight.m_x, tempRight.m_y);
				right->SetNextMap2Point(curPoint);
				CalDistance(map, right, curPoint, endPoint);
				openVec.push_back(right);
			}
			else
			{
				Map2Point* temp = GetPositionOpened(openVec, &tempRight);
				if (temp && (temp->GetG() > (curPoint->GetG() + 1)))
				{
					temp->SetNextMap2Point(curPoint);
					CalDistance(map, temp, curPoint, endPoint);
				}
			}
		}

		curPoint = GetNearestPos(openVec);
	}

	if (*curPoint == endPoint)
	{
		path.clear();

		while (curPoint->GetNextMap2Point())
		{
			path.push_back(Position2(curPoint->GetPosX(), curPoint->GetPosY()));
			curPoint = curPoint->GetNextMap2Point();
		}

		if (curPoint)
		{
			path.push_back(Position2(curPoint->GetPosX(), curPoint->GetPosY()));
		}
	}
}

// 场景中是否存在改坐标
bool Map2PointManager::IsPositionInScene(Map2* map, Position2* pos)
{
	if (NULL == map || NULL == pos)
	{
		return false;
	}

	return map->GetPositionInMap(*pos);
}

// 获取某点是否为阻塞点
bool Map2PointManager::IsPositionBlockInScene(Map2* map, Position2* pos)
{
	if (NULL == map || NULL == pos)
	{
		return true;
	}

	return map->GetPositionBlockPosition(*pos);
}

bool Map2PointManager::IsPositionOpened(std::vector<Map2Point*> posVec, Position2* pos)
{
	for (int i = 0; i < posVec.size(); i++)
	{
		if (posVec[i] && posVec[i]->GetPosX() == pos->m_x && posVec[i]->GetPosY() == pos->m_y)
		{
			return true;
		}
	}

	return false;
}

Map2Point* Map2PointManager::GetPositionOpened(std::vector<Map2Point*> posVec, Position2* pos)
{
	for (int i = 0; i < posVec.size(); i++)
	{
		if (posVec[i] && posVec[i]->GetPosX() == pos->m_x && posVec[i]->GetPosY() == pos->m_y)
		{
			return posVec[i];
		}
	}

	return NULL;
}

void Map2PointManager::CalDistance(Map2* map,
			Map2Point* curPos, Map2Point* begin, Map2Point* end)
{
	if (NULL == curPos || NULL == begin || NULL == end)
	{
		return;
	}

	curPos->SetG(curPos->GetG() + 1);
	curPos->SetH(abs(curPos->GetPosX() - end->GetPosX()) + abs(curPos->GetPosY() - end->GetPosX()));
	curPos->SetF(curPos->GetG() + curPos->GetH());
}

Map2Point* Map2PointManager::GetNearestPos(std::vector<Map2Point*> posVec)
{
	int nearestVal = 0;
	Map2Point* nearestPoint = NULL;
	for (int i = 0; i < posVec.size(); i++)
	{
		if (posVec[i] && (posVec[i]->GetF() < nearestVal || nearestVal == 0))
		{
			nearestVal = posVec[i]->GetF();
			nearestPoint = posVec[i];
		}
	}

	return nearestPoint;
}

void Map2PointManager::EraseClosePos(std::vector<Map2Point*>& posVec, Map2Point* pos)
{
	std::vector<Map2Point*>::iterator it = posVec.begin();
	for (;it != posVec.end(); it++)
	{
		if (*it == pos)
		{
			posVec.erase(it);
			return;
		}
	}
}