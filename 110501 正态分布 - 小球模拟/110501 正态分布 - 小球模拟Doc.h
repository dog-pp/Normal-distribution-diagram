// 110501 ��̬�ֲ� - С��ģ��Doc.h : CMyDoc ��Ľӿ�
//


#pragma once


class CMyDoc : public CDocument
{
protected: // �������л�����
	CMyDoc();
	DECLARE_DYNCREATE(CMyDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~CMyDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


