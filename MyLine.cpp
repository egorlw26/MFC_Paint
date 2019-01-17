#include "stdafx.h"
#include "MyLine.h"


MyLine::MyLine()
{
}

void MyLine::Draw(CDC* pDC)
{
	int size = m_Objects.size();
	for (int i = 0; i < size; ++i)
	{
		CPen pen(PS_SOLID, m_Objects[i].brushSize, RGB(m_Objects[i].RGB[0], m_Objects[i].RGB[1], m_Objects[i].RGB[2]));
		CBrush* pOldBrush;
		CPen *pOldPen;

		pOldBrush = (CBrush*)pDC->SelectStockObject(NULL_BRUSH);
		pOldPen = pDC->SelectObject(&pen);

		pDC->MoveTo(m_Objects[i].startPoint);
		pDC->LineTo(m_Objects[i].endPoint);

		pDC->SelectObject(pOldBrush);
		pDC->SelectObject(pOldPen);

	}
}

void MyLine::DrawPreview(CDC * pDC, const Object& object)
{
	CPen pen(PS_SOLID, object.brushSize, RGB(object.RGB[0], object.RGB[1], object.RGB[2]));
	CBrush* pOldBrush;
	CPen *pOldPen;

	pOldBrush = (CBrush*)pDC->SelectStockObject(NULL_BRUSH);
	pOldPen = pDC->SelectObject(&pen);

	pDC->MoveTo(object.startPoint);
	pDC->LineTo(object.endPoint);

	pDC->SelectObject(pOldBrush);
	pDC->SelectObject(pOldPen);

}


MyLine::~MyLine()
{
}
