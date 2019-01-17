
// CQG_PAINTView.cpp : implementation of the CCQGPAINTView class
//

#include "stdafx.h"

// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "CQG_PAINT.h"
#endif

#include "CQG_PAINTDoc.h"
#include "CQG_PAINTView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCQGPAINTView

IMPLEMENT_DYNCREATE(CCQGPAINTView, CView)

BEGIN_MESSAGE_MAP(CCQGPAINTView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_BUTTON_LINE_TOOL, &CCQGPAINTView::OnButtonLineTool)
	ON_COMMAND(ID_BUTTON_ELLIPSE_TOOl, &CCQGPAINTView::OnButtonEllipseTool)
	ON_COMMAND(ID_BUTTON_PEN_TOOL, &CCQGPAINTView::OnButtonPenTool)
	ON_COMMAND(ID_BUTTON_RECTANGLE_TOOL, &CCQGPAINTView::OnButtonRectangleTool)
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_BUTTON_SMALL_SIZE, &CCQGPAINTView::OnButtonSmallSize)
	ON_COMMAND(ID_BUTTON_MEDIUM_SIZE, &CCQGPAINTView::OnButtonMediumSize)
	ON_COMMAND(ID_BUTTON_LARGE_SIZE, &CCQGPAINTView::OnButtonLargeSize)
	ON_COMMAND(ID_BUTTON_RED_BRUSH_COLOR, &CCQGPAINTView::OnButtonRedBrushColor)
	ON_COMMAND(ID_BUTTON_BLUE_BRUSH_COLOR, &CCQGPAINTView::OnButtonBlueBrushColor)
	ON_COMMAND(ID_BUTTON_GREEN_BRUSH_COLOR, &CCQGPAINTView::OnButtonGreenBrushColor)
	ON_COMMAND(ID_BUTTON_YELLOW_BRUSH_COLOR, &CCQGPAINTView::OnButtonYellowBrushColor)
	ON_COMMAND(ID_BUTTON_BLACK_BRUSH_COLOR, &CCQGPAINTView::OnButtonBlackBrushColor)
	ON_COMMAND(ID_BUTTON_PEN_TOOL, &CCQGPAINTView::OnButtonPenTool)
END_MESSAGE_MAP()

// CCQGPAINTView construction/destruction

CCQGPAINTView::CCQGPAINTView() noexcept
{
	// TODO: add construction code here
	m_currentTool = &m_line;
	m_LButtonPressed = false;
	m_BrushSize = 1;
	m_RGB = { 0, 0, 0 };
}

CCQGPAINTView::~CCQGPAINTView()
{
}

BOOL CCQGPAINTView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CCQGPAINTView drawing

void CCQGPAINTView::OnDraw(CDC* pDC)
{
	CCQGPAINTDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	m_line.Draw(pDC);
	m_rectangle.Draw(pDC);
	m_ellipse.Draw(pDC);
	m_pen.Draw(pDC);

	if (m_LButtonPressed && m_currentTool != &m_pen)
		m_currentTool->DrawPreview(pDC, ITool::Object(m_LButtonPoint, m_MousePoint, m_BrushSize, m_RGB));

	// TODO: add draw code for native data here
}

void CCQGPAINTView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CCQGPAINTView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CCQGPAINTView diagnostics

#ifdef _DEBUG
void CCQGPAINTView::AssertValid() const
{
	CView::AssertValid();
}

void CCQGPAINTView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCQGPAINTDoc* CCQGPAINTView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCQGPAINTDoc)));
	return (CCQGPAINTDoc*)m_pDocument;
}
#endif //_DEBUG


// CCQGPAINTView message handlers


void CCQGPAINTView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CCQGPAINTDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	m_LButtonPoint = point;
	m_LButtonPressed = true;

	if (m_currentTool == &m_pen)
	{
		m_currentTool->AddObject(ITool::Object(point, point, m_BrushSize, m_RGB));
	}

	CView::OnLButtonDown(nFlags, point);
}

void CCQGPAINTView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CCQGPAINTDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (m_currentTool != &m_pen)
		m_currentTool->AddObject(ITool::Object(m_LButtonPoint, point, m_BrushSize, m_RGB));
	m_LButtonPressed = false;

	Invalidate();
	UpdateWindow();

	CView::OnLButtonUp(nFlags, point);
}


void CCQGPAINTView::OnButtonLineTool()
{
	// TODO: Add your command handler code here
	m_currentTool = &m_line;
}


void CCQGPAINTView::OnButtonEllipseTool()
{
	// TODO: Add your command handler code here
	m_currentTool = &m_ellipse;
}


void CCQGPAINTView::OnButtonRectangleTool()
{
	// TODO: Add your command handler code here
	m_currentTool = &m_rectangle;
}

void CCQGPAINTView::OnButtonPenTool()
{
	// TODO: Add your command handler code here
	m_currentTool = &m_pen;
}


void CCQGPAINTView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	m_MousePoint = point;
	if (m_LButtonPressed)
	{
		if (m_currentTool == &m_pen)
			m_currentTool->AddObject(ITool::Object(m_pen.GetLastEndPoint(), point, m_BrushSize, m_RGB));
		Invalidate();
		UpdateWindow();
	}
	CView::OnMouseMove(nFlags, point);
}


void CCQGPAINTView::OnButtonSmallSize()
{
	// TODO: Add your command handler code here
	m_BrushSize = 1;
}


void CCQGPAINTView::OnButtonMediumSize()
{
	// TODO: Add your command handler code here
	m_BrushSize = 2;
}


void CCQGPAINTView::OnButtonLargeSize()
{
	// TODO: Add your command handler code here
	m_BrushSize = 4;
}


void CCQGPAINTView::OnButtonRedBrushColor()
{
	// TODO: Add your command handler code here
	m_RGB = { 255, 0, 0 };
}


void CCQGPAINTView::OnButtonBlueBrushColor()
{
	// TODO: Add your command handler code here
	m_RGB = { 0, 0, 255 };
}


void CCQGPAINTView::OnButtonGreenBrushColor()
{
	// TODO: Add your command handler code here
	m_RGB = { 0, 255, 0 };
}


void CCQGPAINTView::OnButtonYellowBrushColor()
{
	// TODO: Add your command handler code here
	m_RGB = { 255, 255, 0 };
}


void CCQGPAINTView::OnButtonBlackBrushColor()
{
	// TODO: Add your command handler code here
	m_RGB = { 0, 0, 0 };
}


