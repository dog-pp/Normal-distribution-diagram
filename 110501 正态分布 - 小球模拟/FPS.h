#pragma once
#include <time.h>
#include <afxwin.h>



class CFps
{
public:
	CFps();


	void ReInit();//��ʼ���FPS �����ڲ�ʱ����� �����ȷ��˲����ֵ

	void SetBeginPos(const CPoint &pt);

	void SetTextColor(COLORREF clr);

	void Paint(CDC &dc);



	COLORREF m_clrTextColor;
	CPoint m_ptBeginPos;
	DWORD m_dwBaseTime;
};