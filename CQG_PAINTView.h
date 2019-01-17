
// CQG_PAINTView.h : interface of the CCQGPAINTView class
//

#pragma once
#include "MyLine.h"
#include "MyRectangle.h"
#include "MyEllipse.h"
#include "MyPen.h"

class CCQGPAINTView : public CView
{
protected: // create from serialization only
	CCQGPAINTView() noexcept;
	DECLARE_DYNCREATE(CCQGPAINTView)

// Attributes
public:
	CCQGPAINTDoc* GetDocument() const;


// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CCQGPAINTView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);

private:
	ITool* m_currentTool;
	MyLine m_line;
	MyRectangle m_rectangle;
	MyEllipse m_ellipse;
	MyPen m_pen;
	CPoint m_LButtonPoint;
	CPoint m_MousePoint;
	bool m_LButtonPressed;

	size_t m_BrushSize;
	std::vector<size_t> m_RGB;

public:
	afx_msg void OnButtonLineTool();
	afx_msg void OnButtonEllipseTool();
	afx_msg void OnButtonRectangleTool();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnButtonSmallSize();
	afx_msg void OnButtonMediumSize();
	afx_msg void OnButtonLargeSize();
	afx_msg void OnButtonRedBrushColor();
	afx_msg void OnButtonBlueBrushColor();
	afx_msg void OnButtonGreenBrushColor();
	afx_msg void OnButtonYellowBrushColor();
	afx_msg void OnButtonBlackBrushColor();
	afx_msg void OnButtonPenTool();
};

#ifndef _DEBUG  // debug version in CQG_PAINTView.cpp
inline CCQGPAINTDoc* CCQGPAINTView::GetDocument() const
   { return reinterpret_cast<CCQGPAINTDoc*>(m_pDocument); }
#endif

