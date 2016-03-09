#pragma once

#include "WinDef.h"


class CMyBar
{
public:
	CMyBar(COLORREF clr, UINT uiRadius);

	void Paint(CDC &dc, UINT uiX, UINT uiY) const;



	COLORREF m_clr;
	UINT m_uiRadius;
};