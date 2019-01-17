#pragma once
#include "stdafx.h"
#include <vector>
class ITool
{
public:
	ITool()
	{};
	struct Object
	{
		Object(CPoint sp, CPoint ep, size_t bs, std::vector<size_t> rgb)
		{
			startPoint = sp;
			endPoint = ep;
			brushSize = bs;
			RGB = rgb;
		}
		CPoint startPoint;
		CPoint endPoint;
		size_t brushSize;
		std::vector<size_t> RGB;

	}; //structute, that contains parameters of object
	virtual void Draw(CDC* pDC) = 0; //to draw all of the objects for this tool
	virtual void DrawPreview(CDC* pDC, const Object& triple) = 0; //draw while moving mouse
	void AddObject(const Object& object) { m_Objects.push_back(object); }
	~ITool()
	{};
protected:
	std::vector<Object> m_Objects;
};