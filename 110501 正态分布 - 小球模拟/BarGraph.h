#pragma once

#include <WinDef.h>

class CBarGraph
{
public:
	CBarGraph();

	void SetBarCount(UINT uiCount);

	void SetMark(UINT uiIndex, UINT uiMark);

	UINT GetMark(UINT uiIndex);

	void SetBarWidth(UINT uiWidth);

	void SetSpaceWidth(UINT uiWidth);

	void SetBeginPos(const POINT &pt);

	void Paint(CDC &dc);

	void SetColor(COLORREF clrText = RGB(255, 255, 0),
		COLORREF clrRect = RGB(255, 255, 255),
		COLORREF clrPen = 0,
		int iPenWidth = 1, int fnPenStyle = PS_SOLID);


	POINT m_ptBeginPos;

	COLORREF m_clrText, m_clrRect, m_clrPen;
	int m_iPenWidth;
	int m_fnPenStyle;

	UINT m_uiBarCount;
	UINT m_uiBarWidth;//���Ŀ��
	UINT m_uiWidth;//�ܿ�
	UINT m_uiSpaceWidth;//������϶���
	UINT m_uiMark[1000];
	UINT m_uiCut;//��������ʱ, ���Ե���, ��ʼΪ1
};