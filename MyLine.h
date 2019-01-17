#pragma once
#include "ITool.h"
#include <vector>
class MyLine : public ITool
{
public:
	MyLine();
	void Draw(CDC* pDC) override;
	void DrawPreview(CDC* pDC, const Object& object) override;
	~MyLine();

};

