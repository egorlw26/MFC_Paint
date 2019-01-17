#include "stdafx.h"
#include "MyPen.h"


MyPen::MyPen()
{
}

const CPoint & MyPen::GetLastEndPoint()
{
	// TODO: insert return statement here
	return m_Objects[m_Objects.size() - 1].endPoint;
}


MyPen::~MyPen()
{
}
