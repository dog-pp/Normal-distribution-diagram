#include "stdafx.h"

#include "MyBar.h"



CMyBar::CMyBar(COLORREF clr, UINT uiRadius) : m_clr(clr), m_uiRadius(uiRadius)
{
}

void CMyBar::Paint(CDC &dc, UINT uiX, UINT uiY) const
{
	//创建画刷 设置Bar颜色
	CBrush brush(m_clr);

	//画刷选入DC
	CBrush *pBrushOld = dc.SelectObject(&brush);

	//画圆
	dc.Ellipse(uiX, uiY, uiX + m_uiRadius * 2, uiY + m_uiRadius * 2);

	//释放画刷
	dc.SelectObject(pBrushOld);
}