#pragma once
#include "MyBall.h"
#include "WinDef.h"
#include "MyBarArray.h"
#include "BarGraph.h"

class CMyPosArray
{
public:
	CMyPosArray();

	void InitFromArray(const CMyBarArray &ba);

	void SetBeginPos(const POINT &pt);

	CMyBall **operator [] (UINT uiX);

	void Add(COLORREF clr);

	void GoOnStep(CBarGraph &bg);

	void Paint(CDC &dc);



	POINT m_ptBeginPos;

	UINT m_uiXCount;//x和y与BarArray里的不同, 它们独立表示小球可在的位置范围
	UINT m_uiYCount;
	UINT m_uiBallRadius;
	UINT m_uiBallDRadius;
	UINT m_uiWeight;
	UINT m_uiHeight;
	CMyBall *pBall[500][500];
};