// 110501 ��̬�ֲ� - С��ģ��View.h : CMyView ��Ľӿ�
//


#pragma once

#include "MyBarArray.h"
#include "MyBarArrayFrame.h"
#include "BarGraph.h"
#include "MyPosArray.h"
#include "FPS.h"

#include "DlgSetting.h"

class CMyView : public CView
{
protected: // �������л�����
	CMyView();
	DECLARE_DYNCREATE(CMyView)

// ����
public:
	CMyDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMyView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif



public:
	CMyBarArray m_barArray;
	CBarGraph m_barGraph;
	CMyPosArray m_posArray;
	CMyBarArrayFrame m_barArrayFrame;
	CFps m_fps;


struct MOVE_PARAM
{
#define ITEM_BAR			1
#define ITEM_GRAPH			2
#define ITEM_FPS			3
	int iItem;//ָ����ǰ����ƶ������ĸ�(����ͳ��ͼ ���)
	CPoint ptBegin, ptInWnd;
	BOOL bLButtonDown;
}m_moveParam;


struct DLG_STRRING_PARAM
{
	UINT m_uiEditBarColorR;
	UINT m_uiEditBarColorG;
	UINT m_uiEditBarColorB;

	UINT m_uiEditBoxFrameColorR;
	UINT m_uiEditBoxFrameColorG;
	UINT m_uiEditBoxFrameColorB;

	UINT m_uiEditGraphFrameColorR;
	UINT m_uiEditGraphFrameColorG;
	UINT m_uiEditGraphFrameColorB;

	UINT m_uiEditGraphColorR;
	UINT m_uiEditGraphColorG;
	UINT m_uiEditGraphColorB;

	UINT m_uiEditGraphTextColorR;
	UINT m_uiEditGraphTextColorG;
	UINT m_uiEditGraphTextColorB;

	UINT m_uiBallSpeed;
	int m_iComboBoxLineStyle;


	UINT m_uiComboBoxLineWidth;


	int m_iComboBarLineStyle;
	UINT m_uiComboBarLineWidth;
	int m_iComboGraphLineStyle;
	UINT m_iComboGraphLineWidth;

	UINT m_uiEditBarFrameColorR;
	UINT m_uiEditBarFrameColorG;
	UINT m_uiEditBarFrameColorB;

	UINT m_uiEditBarCount;

	UINT m_uiEditBarRadius;

	UINT m_uiFpsTextColorR;
	UINT m_uiFpsTextColorG;
	UINT m_uiFpsTextColorB;
}m_DlgSettingParam;



// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);





	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnPaint();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnSetting();
	afx_msg void OnStart();
	afx_msg void OnPause();
};

#ifndef _DEBUG  // 110501 ��̬�ֲ� - С��ģ��View.cpp �еĵ��԰汾
inline CMyDoc* CMyView::GetDocument() const
   { return reinterpret_cast<CMyDoc*>(m_pDocument); }
#endif