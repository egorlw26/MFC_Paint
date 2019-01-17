#pragma once
#include "ITool.h"
class MyEllipse : public ITool
{
public:
	MyEllipse();
	void Draw(CDC* pDC) override;
	void DrawPreview(CDC* pDC, const Object& object) override;
	~MyEllipse();
};

