/*
	二维地图中的点
*/

#pragma once
#include "stdafx.h"

class Map2Point
{
public:
	Map2Point(int x = 0, int y = 0, Map2Point* p = NULL);
	~Map2Point();

	//
	int GetPosX(){return m_pos_x;}
	int GetPosY(){return m_pos_y;}

	// 
	int GetF(){return m_f;}
	int SetF(int f){return m_f = f;}

	int GetG(){return m_g;}
	int SetG(int g){return m_g = g;}

	int GetH(){return m_h;}
	int SetH(int h){return m_h = h;}

	void SetNextMap2Point(Map2Point* p);
	Map2Point* GetNextMap2Point();
	 
	bool operator == (Map2Point* point);
	bool operator != (Map2Point* point);


private:
	int m_pos_x;
	int m_pos_y;
	int m_f;
	int m_g;
	int m_h;

	Map2Point* m_pNext;
};

