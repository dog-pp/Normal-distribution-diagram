// 110501 ��̬�ֲ� - С��ģ��Doc.cpp : CMyDoc ���ʵ��
//

#include "stdafx.h"
#include "110501 ��̬�ֲ� - С��ģ��.h"

#include "110501 ��̬�ֲ� - С��ģ��Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMyDoc

IMPLEMENT_DYNCREATE(CMyDoc, CDocument)

BEGIN_MESSAGE_MAP(CMyDoc, CDocument)
END_MESSAGE_MAP()


// CMyDoc ����/����

CMyDoc::CMyDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CMyDoc::~CMyDoc()
{
}

BOOL CMyDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CMyDoc ���л�

void CMyDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}


// CMyDoc ���

#ifdef _DEBUG
void CMyDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMyDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMyDoc ����
