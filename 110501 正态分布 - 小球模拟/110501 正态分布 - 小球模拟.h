// 110501 ��̬�ֲ� - С��ģ��.h : 110501 ��̬�ֲ� - С��ģ�� Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMyApp:
// �йش����ʵ�֣������ 110501 ��̬�ֲ� - С��ģ��.cpp
//

class CMyApp : public CWinApp
{
public:
	CMyApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMyApp theApp;