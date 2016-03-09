#include "stdafx.h"
#include "BarGraph.h"
#include <WinDef.h>
#include <strsafe.h>
#pragma comment(lib, "strsafe.lib")


CBarGraph::CBarGraph() : m_uiBarCount(0), m_uiWidth(0)
, m_uiBarWidth(0)
, m_uiSpaceWidth(0)
, m_uiCut(1)
{
}

void CBarGraph::SetBarCount(UINT uiCount)
{
	m_uiBarCount = uiCount;
	memset(m_uiMark, 0, uiCount * sizeof(UINT));

	m_uiWidth = m_uiBarWidth * m_uiBarCount + m_uiSpaceWidth * (m_uiBarCount - 1);

	m_uiCut = 1;
}

void CBarGraph::SetMark(UINT uiIndex, UINT uiMark)
{
	ASSERT(uiIndex <= m_uiBarCount);
	ASSERT(uiIndex > 0);
	m_uiMark[uiIndex - 1] = uiMark;
}

UINT CBarGraph::GetMark(UINT uiIndex)
{
	return m_uiMark[uiIndex - 1];
}

void CBarGraph::SetBarWidth(UINT uiWidth)
{
	m_uiBarWidth = uiWidth;
	m_uiWidth = m_uiBarWidth * m_uiBarCount + m_uiSpaceWidth * (m_uiBarCount - 1);
}

void CBarGraph::SetSpaceWidth(UINT uiWidth)
{
	m_uiSpaceWidth = uiWidth;
	m_uiWidth = m_uiBarWidth * m_uiBarCount + m_uiSpaceWidth * (m_uiBarCount - 1);
}

void CBarGraph::SetBeginPos(const POINT &pt)
{
	m_ptBeginPos = pt;
}

void CBarGraph::SetColor(COLORREF clrText, COLORREF clrRect, COLORREF clrPen,
			  int iPenWidth, int fnPenStyle)
{
	m_clrText = clrText;
	m_clrRect = clrRect;
	m_clrPen = clrPen;
	m_iPenWidth = iPenWidth;
	m_fnPenStyle = fnPenStyle;
}


void CBarGraph::Paint(CDC &dc)
{
	//���ñ�
	CPen pen(m_fnPenStyle, m_iPenWidth, m_clrPen);
	CPen *pPenOld = dc.SelectObject(&pen);

	//���û�ˢ
	CBrush brush(m_clrRect);
	CBrush *pBrushOld = dc.SelectObject(&brush);

	//����������ɫ
	dc.SetTextColor(m_clrText);


	CRect rt;
	for(UINT ui = 0; ui < m_uiBarCount; ++ui)
	{
		rt.left = m_ptBeginPos.x+ ui * (m_uiBarWidth + m_uiSpaceWidth);
		rt.top = m_ptBeginPos.y;
		rt.right = rt.left + m_uiBarWidth;
		if(m_uiMark[ui] > 300 * m_uiCut)//����ѹ������
			m_uiCut *= 2;
		rt.bottom = rt.top + m_uiMark[ui] / m_uiCut;//����, �Ա�ѹ��������
		dc.Rectangle(rt);

		//׼���������
		wchar_t wc[100];
		StringCchPrintf(wc, 100, L"%d", m_uiMark[ui]);
		int iLen = lstrlen(wc);
		CSize sz = dc.GetTextExtent(wc,iLen);

		//���¸���rt
		rt.left = rt.left + m_uiBarWidth / 2 - sz.cx / 2;
		rt.top = rt.bottom + 5;
		rt.right = rt.left + sz.cx;
		rt.bottom = rt.top + sz.cy;

		//�������
		dc.ExtTextOut(rt.left,
			rt.top, ETO_CLIPPED, &rt, wc, iLen, 0);

	}









	//��ԭ��ˢ
	dc.SelectObject(pBrushOld);

	//��ԭ��
	dc.SelectObject(pPenOld);
}