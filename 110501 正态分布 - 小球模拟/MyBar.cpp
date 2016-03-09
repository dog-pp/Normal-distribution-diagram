#include "stdafx.h"

#include "MyBar.h"



CMyBar::CMyBar(COLORREF clr, UINT uiRadius) : m_clr(clr), m_uiRadius(uiRadius)
{
}

void CMyBar::Paint(CDC &dc, UINT uiX, UINT uiY) const
{
	//������ˢ ����Bar��ɫ
	CBrush brush(m_clr);

	//��ˢѡ��DC
	CBrush *pBrushOld = dc.SelectObject(&brush);

	//��Բ
	dc.Ellipse(uiX, uiY, uiX + m_uiRadius * 2, uiY + m_uiRadius * 2);

	//�ͷŻ�ˢ
	dc.SelectObject(pBrushOld);
}