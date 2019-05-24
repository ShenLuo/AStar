/*
	自定义值
*/

#pragma once
#include "stdafx.h"

// 二维坐标
struct Position2
{
	Position2(int x = 0, int y = 0)
	{
		m_x = x ;
		m_y = y;
	}



	int m_x;
	int m_y;
};

// 
#define LENGTH 9
#define WIGTH  9