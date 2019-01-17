#pragma once
#include "ITool.h"
class MyRectangle : public ITool
{
public:
	MyRectangle();
	void Draw(CDC* pDC) override;
	void DrawPreview(CDC* pDC, const Object& object) override;
	~MyRectangle();
};

