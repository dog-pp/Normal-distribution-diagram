#pragma once
#include "afxwin.h"


// CDlgSetting 对话框

class CDlgSetting : public CDialog
{
	DECLARE_DYNAMIC(CDlgSetting)

public:
	CDlgSetting(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgSetting();

// 对话框数据
	enum { IDD = IDD_SETTING };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
//	virtual BOOL OnInitDialog();

	UINT m_uiEditBarColorR;
	UINT m_uiEditBarColorG;
	UINT m_uiEditBarColorB;

	UINT m_uiEditBoxFrameColorR;
	UINT m_uiEditBoxFrameColorG;
	UINT m_uiEditBoxFrameColorB;

	UINT m_uiEditGraphFrameColorR;
	UINT m_uiEditGraphFrameColorG;
	UINT m_uiEditGraphFrameColorB;

	UINT m_uiEditGraphColorR;
	UINT m_uiEditGraphColorG;
	UINT m_uiEditGraphColorB;

	UINT m_uiEditGraphTextColorR;
	UINT m_uiEditGraphTextColorG;
	UINT m_uiEditGraphTextColorB;

	UINT m_uiBallSpeed;

	int m_iComboBoxLineStyle;
	CComboBox m_ComboBoxLineStyle;

	

	UINT m_uiComboBoxLineWidth;
	int m_iComboBarLineStyle;
	UINT m_uiComboBarLineWidth;
	int m_iComboGraphLineStyle;
	UINT m_iComboGraphLineWidth;
	CComboBox m_ComboBarLineStyle;
	CComboBox m_ComboGraphLineStyle;

	UINT m_uiEditBarFrameColorR;
	UINT m_uiEditBarFrameColorG;
	UINT m_uiEditBarFrameColorB;
	UINT m_uiEditBarCount;


	UINT m_uiEditBarRadius;
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);


	UINT m_uiFpsTextColorR;
	UINT m_uiFpsTextColorG;
	UINT m_uiFpsTextColorB;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
//	afx_msg void OnCbnSelchangeComboBarLineStyle();
};
