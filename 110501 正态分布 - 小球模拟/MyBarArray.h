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

	COLORREF m_clrBar;//��ɫ

	COLORREF m_clrBarFrame;//���߿���ɫ
	int m_iWidthBarFrame;
	int m_fnPenStyle;

	UINT m_uiBarRadius;//������뾶(��λ:����)
	UINT m_uiBarMax;//����ж��ٰ�

	UINT m_uiBarDRadius;//��ֱ��
	UINT m_uiWeight;//array���(��λ:����)
	UINT m_uiHeight;//array�߶�(��λ:����)
};