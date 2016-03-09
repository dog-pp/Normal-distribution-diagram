#pragma once
#include <WinDef.h>

class CMyBarArray
{
public:
	CMyBarArray();

	void SetBeginPos(const POINT &pt);

	void SetColor(COLORREF clr);

	void SetPen(int fnPenStyle, int nWidth, COLORREF crColor);

	void SetRadius(UINT uiRadius);

	void SetBarMax(UINT uiBarMax);


	void Paint(CDC &dc);


		

	POINT m_ptBeginPos;

	COLORREF m_clrBar;//棒色

	COLORREF m_clrBarFrame;//棒边框颜色
	int m_iWidthBarFrame;
	int m_fnPenStyle;

	UINT m_uiBarRadius;//棒切面半径(单位:像素)
	UINT m_uiBarMax;//最多有多少棒

	UINT m_uiBarDRadius;//棒直径
	UINT m_uiWeight;//array宽度(单位:像素)
	UINT m_uiHeight;//array高度(单位:像素)
};