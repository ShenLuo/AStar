/*
	��ά��ͼ��
*/

#pragma once
#include "stdafx.h"
#include "../definition/definition.h"
#include <vector>

// ��ά��ͼ��
class Map2
{
public:
	Map2();
	~Map2();

	// ��ʼ������ͨ���ĵ�ͼ��
	void InitBlockPosition(std::vector<Position2>& tempVector);

	// ��ȡĳ���Ƿ��ڵ�ͼ��
	bool GetPositionInMap(Position2& position);

	// ��ȡĳ���Ƿ�Ϊ������
	bool GetPositionBlockPosition(Position2& position);

private:
	int m_map[LENGTH][WIGTH];
};


