#include "stdafx.h"
#include "MyBarArrayFrame.h"





CMyBarArrayFrame::CMyBarArrayFrame()
	: m_ptOrigin(0)
	, m_ptTo1(0)
	, m_ptTo2(0)
	, m_clr(0)
	, m_iWidth(0)
	, m_fnPenStyle(0)
{
}

void CMyBarArrayFrame::InitFromArray(const CMyBarArray &arr)
{
	//														微调 使始点向上
	m_ptBeginPos = arr.m_ptBeginPos;
	m_ptOrigin = CPoint(arr.m_uiWeight / 2, (int)-1.414 * (arr.m_uiBarRadius + 4));
	m_ptTo1 = CPoint(-8, arr.m_uiHeight - arr.m_uiBarRadius);
	m_ptTo2 = CPoint(arr.m_uiWeight + 8, arr.m_uiHeight - arr.m_uiBarRadius);
}

void CMyBarArrayFrame::SetBeginPos(const POINT &pt)
{
	m_ptBeginPos = pt;
}

void CMyBarArrayFrame::SetPen(COLORREF clr, int iWidth, int fnPenStyle)
{
	m_clr = clr;
	m_iWidth = iWidth;
	m_fnPenStyle = fnPenStyle;
}


void CMyBarArrayFrame::Paint(CDC &dc)
{
	//选画笔样式
	CPen pen(m_fnPenStyle, m_iWidth, m_clr);
	CPen *pPenOld = dc.SelectObject(&pen);

	CPoint ptBase = m_ptBeginPos;

	dc.MoveTo(m_ptOrigin + ptBase);
	dc.LineTo(m_ptTo1 + ptBase);

	dc.MoveTo(m_ptOrigin + ptBase);
	dc.LineTo(m_ptTo2 + ptBase);

	//还原笔样式
	dc.SelectObject(pPenOld);
}