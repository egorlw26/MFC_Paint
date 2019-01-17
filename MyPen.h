#pragma once
#include "MyLine.h"
class MyPen :
	public MyLine
{
public:
	MyPen();
	const CPoint& GetLastEndPoint();
	~MyPen();
};

