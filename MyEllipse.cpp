#include "stdafx.h"
#include "MyEllipse.h"


MyEllipse::MyEllipse()
{
}

void MyEllipse::Draw(CDC* pDC)
{
	int size = m_Objects.size();
	for (int i = 0; i < size; ++i)
	{
		CPen pen(PS_SOLID, m_Objects[i].brushSize, RGB(m_Objects[i].RGB[0], m_Objects[i].RGB[1], m_Objects[i].RGB[2]));
		CBrush* pOldBrush;
		CPen *pOldPen;

		pOldBrush = (CBrush*)pDC->SelectStockObject(NULL_BRUSH);
		pOldPen = pDC->SelectObject(&pen);

		pDC->Ellipse(m_Objects[i].startPoint.x, m_Objects[i].startPoint.y, m_Objects[i].endPoint.x, m_Objects[i].endPoint.y);

		pDC->SelectObject(pOldBrush);
		pDC->SelectObject(pOldPen);
	}
}

void MyEllipse::DrawPreview(CDC * pDC, const Object& object)
{
	CPen pen(PS_SOLID, object.brushSize, RGB(object.RGB[0], object.RGB[1], object.RGB[2]));
	CBrush* pOldBrush;
	CPen *pOldPen;

	pOldBrush = (CBrush*)pDC->SelectStockObject(NULL_BRUSH);
	pOldPen = pDC->SelectObject(&pen);

	pDC->Ellipse(object.startPoint.x, object.startPoint.y, object.endPoint.x, object.endPoint.y);

	pDC->SelectObject(pOldBrush);
	pDC->SelectObject(pOldPen);
} 


MyEllipse::~MyEllipse()
{
}
