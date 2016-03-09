#pragma once
#include <time.h>
#include <afxwin.h>



class CFps
{
public:
	CFps();


	void ReInit();//开始输出FPS 更新内部时间变量 输出正确的瞬间数值

	void SetBeginPos(const CPoint &pt);

	void SetTextColor(COLORREF clr);

	void Paint(CDC &dc);



	COLORREF m_clrTextColor;
	CPoint m_ptBeginPos;
	DWORD m_dwBaseTime;
};