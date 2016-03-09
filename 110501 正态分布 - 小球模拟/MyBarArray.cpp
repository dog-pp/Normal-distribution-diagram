#include "stdafx.h"
#include "MyBarArray.h"
#include "MyBar.h"


CMyBarArray::CMyBarArray()
		: m_clrBar(0), m_uiBarRadius(0), m_uiBarMax(0)
		, m_uiBarDRadius(0)
		, m_uiWeight(0)
		, m_uiHeight(0)
		, m_clrBarFrame(0)//棒边框颜色
		, m_iWidthBarFrame(0)
		, m_fnPenStyle(0)
{
}

void CMyBarArray::SetColor(COLORREF clr)
{
	m_clrBar = clr;
}

void CMyBarArray::SetPen(int fnPenStyle, int nWidth, COLORREF crColor)
{
	m_clrBarFrame = crColor;
	m_iWidthBarFrame = nWidth;
	m_fnPenStyle = fnPenStyle;
}




void CMyBarArray::SetRadius(UINT uiRadius)
{
	m_uiBarRadius = uiRadius;
	m_uiBarDRadius = uiRadius * 2;

	m_uiWeight = m_uiBarMax * m_uiBarDRadius + (m_uiBarMax - 1) * m_uiBarDRadius;
	m_uiHeight = m_uiBarMax * m_uiBarDRadius + (UINT)((m_uiBarMax - 1) * m_uiBarDRadius * 0.707);
}

void CMyBarArray::SetBarMax(UINT uiBarMax)
{
	m_uiBarMax = uiBarMax;

	m_uiWeight = m_uiBarMax * m_uiBarDRadius + (m_uiBarMax - 1) * m_uiBarDRadius;
	m_uiHeight = m_uiBarMax * m_uiBarDRadius + (UINT)((m_uiBarMax - 1) * m_uiBarDRadius * 0.707);
}

void CMyBarArray::SetBeginPos(const POINT &pt)
{
	m_ptBeginPos = pt;

	m_uiWeight = m_uiBarMax * m_uiBarDRadius + (m_uiBarMax - 1) * m_uiBarDRadius;
	m_uiHeight = m_uiBarMax * m_uiBarDRadius + (UINT)((m_uiBarMax - 1) * m_uiBarDRadius * 0.707);
}

void CMyBarArray::Paint(CDC &dc)
{
	CPen pen(m_fnPenStyle, m_iWidthBarFrame, m_clrBarFrame);
	CPen *pPenOld = dc.SelectObject(&pen);


	UINT uiBeginX = m_ptBeginPos.x, uiBeginY = m_ptBeginPos.y;



	//初始化小Bar
	CMyBar bar(m_clrBar, m_uiBarRadius);


	//循环每一行, 进行绘制
	for(UINT ui = 1/*0不输出最上面的球*/; ui < m_uiBarMax; ++ui)
	{

		//计算当前行的起始x, y坐标

		UINT uiLBeginX = uiBeginX +
			//判断奇偶
			((ui % 2) ?
			//为偶数

			
			(m_uiWeight / 2 - m_uiBarRadius - m_uiBarDRadius - ((ui + 1) / 2 - 1) * m_uiBarDRadius * 2) :
			//为奇数

			//先取中间坐标, 再向左减一个半径, 再减(ui + 1 - 1) / 2 * m_uiBarDRadius * 2
			(m_uiWeight / 2 - m_uiBarRadius - (ui + 1 - 1) / 2 * m_uiBarDRadius * 2));


		UINT uiLBeginY = uiBeginY + (UINT)(ui * m_uiBarDRadius * 1.707);




		//每行中循环每一个球, 进行绘制
		for(UINT uui = 0; uui <= ui; ++uui, uiLBeginX += 2 * m_uiBarDRadius)
			bar.Paint(dc, uiLBeginX, uiLBeginY);


	}



	dc.SelectObject(pPenOld);

}