#include "stdafx.h"


#include "FPS.h"
#pragma comment(lib, "strsafe.lib")
#include <strsafe.h>


CFps::CFps()
: m_clrTextColor(0)
, m_dwBaseTime(0)
{
}

//��ʼ���FPS �����ڲ�ʱ����� �����ȷ��˲����ֵ
void CFps::ReInit()
{
	m_dwBaseTime = GetTickCount();
}

void CFps::SetBeginPos(const CPoint &pt)
{
	m_ptBeginPos = pt;
}

void CFps::SetTextColor(COLORREF clr)
{
	m_clrTextColor = clr;
}

void CFps::Paint(CDC &dc)
{
	COLORREF clrOldTextColor = dc.SetTextColor(m_clrTextColor);

	wchar_t wc[50];

	register DWORD dwTm = GetTickCount();
	StringCchPrintf(wc, 50, L"%f FPS", (double)1000 / (double)(dwTm - m_dwBaseTime + 1));//+1 ��Ϊ�˷�ֹ����Ϊ0!
	m_dwBaseTime = dwTm;
	dc.ExtTextOut(m_ptBeginPos.x, m_ptBeginPos.y, ETO_CLIPPED,
		&CRect(m_ptBeginPos.x, m_ptBeginPos.y, m_ptBeginPos.x + 110, m_ptBeginPos.y + 15),
		wc, lstrlen(wc), 0);

	dc.SetTextColor(clrOldTextColor);
}