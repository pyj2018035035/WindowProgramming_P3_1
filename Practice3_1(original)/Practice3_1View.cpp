﻿
// Practice3_1View.cpp: CPractice31View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Practice3_1.h"
#endif

#include "Practice3_1Doc.h"
#include "Practice3_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPractice31View

IMPLEMENT_DYNCREATE(CPractice31View, CView)

BEGIN_MESSAGE_MAP(CPractice31View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CREATE()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_DESTROY()
END_MESSAGE_MAP()

// CPractice31View 생성/소멸

CPractice31View::CPractice31View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CPractice31View::~CPractice31View()
{
}

BOOL CPractice31View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CPractice31View 그리기

void CPractice31View::OnDraw(CDC* /*pDC*/)
{
	CPractice31Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}

void CPractice31View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CPractice31View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CPractice31View 진단

#ifdef _DEBUG
void CPractice31View::AssertValid() const
{
	CView::AssertValid();
}

void CPractice31View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPractice31Doc* CPractice31View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPractice31Doc)));
	return (CPractice31Doc*)m_pDocument;
}
#endif //_DEBUG


// CPractice31View 메시지 처리기


int CPractice31View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	AfxMessageBox(_T("윈도우가 생성되었습니다."), MB_OKCANCEL | MB_ICONINFORMATION);

	return 0;
}


void CPractice31View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	AfxMessageBox(_T("왼쪽 마우스를 더블클릭 했습니까?"), MB_YESNO | MB_ICONQUESTION);


	CView::OnLButtonDblClk(nFlags, point);
}


void CPractice31View::OnDestroy()
{
	CView::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	AfxMessageBox(_T("윈도우가 종료되었습니다."), MB_YESNO | MB_ICONWARNING);
}
