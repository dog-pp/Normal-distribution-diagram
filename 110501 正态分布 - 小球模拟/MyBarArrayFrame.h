#pragma once
#include "MyBarArray.h"
#include "afxwin.h"

class CMyBarArrayFrame
{
public:
	CMyBarArrayFrame();


	void Paint(CDC &dc);

	void SetBeginPos(const POINT &pt);

	void SetPen(COLORREF clr, int iWidth, int fnPenStyle);

	void InitFromArray(const CMyBarArray &arr);


	POINT m_ptBeginPos;

	CPoint m_ptOrigin;
	CPoint m_ptTo1;
	CPoint m_ptTo2;
	COLORREF m_clr;
	int m_iWidth;
	int m_fnPenStyle;
};