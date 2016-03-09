#include "stdafx.h"
#include "MyPosArray.h"
#include "MyBarArray.h"
#include "MyRand.h"



CMyPosArray::CMyPosArray()
: m_uiXCount(0)
, m_uiYCount(0)
, m_uiBallRadius(0)
, m_uiBallDRadius(0)
, m_uiWeight(0)
, m_uiHeight(0)
{
	memset(pBall, 0, 500 * 500);
}

void CMyPosArray::InitFromArray(const CMyBarArray &ba)
{
	//ֻ�гߴ�仯 ���������
	if(m_uiXCount != (ba.m_uiBarMax - 2))
	{
		m_uiXCount = (ba.m_uiBarMax - 2);
		m_uiYCount = (ba.m_uiBarMax - 2);
		for(UINT ui = 0; ui < m_uiXCount; ++ui)
			for(UINT uii = 0; uii < m_uiYCount; ++uii)
				if(pBall[ui][uii])
				{
					delete pBall[ui][uii];
					pBall[ui][uii] = 0;
				}
	}

	m_uiBallRadius = (ba.m_uiBarRadius);
	m_uiBallDRadius = (m_uiBallRadius * 2);
	m_uiWeight = (m_uiXCount * m_uiBallDRadius + (m_uiXCount - 1) * m_uiBallDRadius);
	m_uiHeight = (m_uiYCount * m_uiBallDRadius + (UINT)((m_uiYCount - 1) * m_uiBallDRadius * 0.414));
	m_ptBeginPos = (ba.m_ptBeginPos);



	//�޸�����С��İ뾶����
	for(UINT ui = 0; ui < m_uiXCount; ++ui)
		for(UINT un = 0; un < m_uiYCount; ++un)
			if(register CMyBall *p = pBall[ui][un])
				p->m_uiRadius = m_uiBallRadius;



}


//�ò�����
//void CMyPosArray::SetArraySize(UINT uiX, UINT uiY)
//{
//	m_uiXCount = uiX;
//	m_uiYCount = uiY;
//
//	m_uiWeight = m_uiXCount * m_uiBallDRadius + (m_uiXCount - 1) * m_uiBallDRadius;
//	m_uiHeight = m_uiYCount * m_uiBallDRadius + (UINT)((m_uiYCount - 1) * m_uiBallDRadius * 0.414);
//
//	for(UINT ui = 0; ui < uiX; ++ui)
//		for(UINT uii = 0; uii < uiY; ++uii)
//			pBall[ui][uii] = 0;
//}
//
//void CMyPosArray::SetRadius(UINT uiRadius)
//{
//	m_uiBallRadius = uiRadius;
//	m_uiBallDRadius = uiRadius * 2;
//
//	m_uiWeight = m_uiXCount * m_uiBallDRadius + (m_uiXCount - 1) * m_uiBallDRadius;
//	m_uiHeight = m_uiYCount * m_uiBallDRadius + (UINT)((m_uiYCount - 1) * m_uiBallDRadius * 0.414);
//
//}

void CMyPosArray::SetBeginPos(const POINT &pt)
{
	m_ptBeginPos = pt;

	m_uiWeight = m_uiXCount * m_uiBallDRadius + (m_uiXCount - 1) * m_uiBallDRadius;
	m_uiHeight = m_uiYCount * m_uiBallDRadius + (UINT)((m_uiYCount - 1) * m_uiBallDRadius * 0.414);
}

CMyBall **CMyPosArray::operator [] (UINT uiX)
{
	return pBall[uiX];
}

void CMyPosArray::Add(COLORREF clr)
{
	pBall[0][0] = new CMyBall(clr, m_uiBallRadius);
}

void CMyPosArray::GoOnStep(CBarGraph &bg)
{
	CMyRand rand;

	//��һ�μ��  ���һ�� ���⴦��
	for(UINT ui = 0; ui < m_uiYCount; ++ui)
		if(pBall[m_uiXCount -1][ui])
		{
				UINT uiDestPos = ui + rand.Rand(0, 1) + 1;///////////////////////////////////////////////////////////////////
			//	uiDestPos += 1;//////////////////////////////////////////////////////////
				bg.SetMark(uiDestPos, bg.GetMark(uiDestPos) + 1);

				delete pBall[m_uiXCount -1][ui];
				pBall[m_uiXCount -1][ui] = 0;
		}





	//ѭ�����Ҵ��ڵ�С��
	for(UINT ui = m_uiXCount; ui + 1; --ui)//���ż��, ��ֹС�����ƺ���ִ���
		for(UINT uui = 0; uui <= ui; ++uui)
			if(pBall[ui][uui])
			{
				pBall[ui + 1][uui + rand.Rand(0, 1)] = pBall[ui][uui];
				pBall[ui][uui] = 0;
			}
}

void CMyPosArray::Paint(CDC &dc)
{
	UINT uiBeginX(m_ptBeginPos.x), uiBeginY(m_ptBeginPos.y);

	//ת��x, y����
	uiBeginX += 2 * m_uiBallDRadius;
	uiBeginY += (UINT)(m_uiBallDRadius * 2 * 0.707) + m_uiBallDRadius;







	//ѭ�����Ҵ��ڵ�С��
	for(UINT ux = 0; ux < m_uiXCount; ++ux)
		for(UINT uy = 0; uy <= ux; ++uy)
			if(pBall[ux][uy] != 0)
			{

		UINT uiLBeginX = uiBeginX +
			//�ж���ż
			((ux % 2) ?
			//Ϊż��

			(      m_uiWeight / 2 - m_uiBallRadius - m_uiBallDRadius  - ((ux + 1/*��������*/) / 2 - 1) * m_uiBallDRadius * 2 + uy * m_uiBallDRadius * 2     ) :
		//	((m_uiWeight + 2 * m_uiBallDRadius) / 2 - m_uiBallRadius - m_uiBallDRadius - ((uy + 1) / 2 - 1) * m_uiBallDRadius * 2 + uy * m_uiBallDRadius * 2) :
			//Ϊ����

			(      m_uiWeight / 2 - m_uiBallRadius - (ux + 1/*��������*/ - 1) / 2 * m_uiBallDRadius * 2 + uy * m_uiBallDRadius * 2    ));
			//��ȡ�м�����, �������һ���뾶, �ټ�(ui + 1 - 1) / 2 * m_uiBarDRadius * 2
		//	((m_uiWeight + 2 * m_uiBallDRadius) / 2 - m_uiBallRadius - (uy + 1 - 1) / 2 * m_uiBallDRadius * 2) + uy * m_uiBallDRadius * 2);


		UINT uiLBeginY = uiBeginY + (UINT)(ux * m_uiBallDRadius * 1.707);


		pBall[ux][uy]->Paint(dc, uiLBeginX, uiLBeginY);


			}





}