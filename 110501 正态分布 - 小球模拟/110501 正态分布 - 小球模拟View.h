// 110501 正态分布 - 小球模拟View.h : CMyView 类的接口
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
protected: // 仅从序列化创建
	CMyView();
	DECLARE_DYNCREATE(CMyView)

// 属性
public:
	CMyDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
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
	int iItem;//指代当前鼠标移动的是哪个(条形统计图 球等)
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



// 生成的消息映射函数
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

#ifndef _DEBUG  // 110501 正态分布 - 小球模拟View.cpp 中的调试版本
inline CMyDoc* CMyView::GetDocument() const
   { return reinterpret_cast<CMyDoc*>(m_pDocument); }
#endif