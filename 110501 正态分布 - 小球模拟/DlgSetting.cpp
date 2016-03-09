// DlgSetting.cpp : 实现文件
//

#include "stdafx.h"
#include "110501 正态分布 - 小球模拟.h"
#include "DlgSetting.h"


// CDlgSetting 对话框

IMPLEMENT_DYNAMIC(CDlgSetting, CDialog)

CDlgSetting::CDlgSetting(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSetting::IDD, pParent)

	, m_uiEditBarColorR(0)
	, m_uiEditBarColorG(0)
	, m_uiEditBarColorB(0)

	, m_uiEditBoxFrameColorR(0)
	, m_uiEditBoxFrameColorG(0)
	, m_uiEditBoxFrameColorB(0)

	, m_uiEditGraphFrameColorR(0)
	, m_uiEditGraphFrameColorG(0)
	, m_uiEditGraphFrameColorB(0)

	, m_uiEditGraphColorR(0)
	, m_uiEditGraphColorG(0)
	, m_uiEditGraphColorB(0)

	, m_uiEditGraphTextColorR(0)
	, m_uiEditGraphTextColorG(0)
	, m_uiEditGraphTextColorB(0)

	, m_uiBallSpeed(0)
	, m_iComboBoxLineStyle(0)
	, m_uiComboBoxLineWidth(0)
	, m_iComboBarLineStyle(0)
	, m_uiComboBarLineWidth(0)
	, m_iComboGraphLineStyle(0)
	, m_iComboGraphLineWidth(0)
	, m_uiEditBarFrameColorR(0)
	, m_uiEditBarFrameColorG(0)
	, m_uiEditBarFrameColorB(0)
	, m_uiEditBarCount(0)

	, m_uiEditBarRadius(0)

	, m_uiFpsTextColorR(0)
	, m_uiFpsTextColorG(0)
	, m_uiFpsTextColorB(0)
{

}

CDlgSetting::~CDlgSetting()
{
}

void CDlgSetting::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);


	DDX_Text(pDX, IDC_EDIT_BAR_COLOR_R, m_uiEditBarColorR);
	DDX_Text(pDX, IDC_EDIT_BAR_COLOR_G, m_uiEditBarColorG);
	DDX_Text(pDX, IDC_EDIT_BAR_COLOR_B, m_uiEditBarColorB);

	DDX_Text(pDX, IDC_EDIT_BOX_FRAME_COLOR_R, m_uiEditBoxFrameColorR);
	DDX_Text(pDX, IDC_EDIT_BOX_FRAME_COLOR_G, m_uiEditBoxFrameColorG);
	DDX_Text(pDX, IDC_EDIT_BOX_FRAME_COLOR_B, m_uiEditBoxFrameColorB);

	DDX_Text(pDX, IDC_EDIT_GRAPH_FRAME_COLOR_R, m_uiEditGraphFrameColorR);
	DDX_Text(pDX, IDC_EDIT_GRAPH_FRAME_COLOR_G, m_uiEditGraphFrameColorG);
	DDX_Text(pDX, IDC_EDIT_GRAPH_FRAME_COLOR_B, m_uiEditGraphFrameColorB);

	DDX_Text(pDX, IDC_EDIT_GRAPH_COLOR_R, m_uiEditGraphColorR);
	DDX_Text(pDX, IDC_EDIT_GRAPH_COLOR_G, m_uiEditGraphColorG);
	DDX_Text(pDX, IDC_EDIT_GRAPH_COLOR_B, m_uiEditGraphColorB);

	DDX_Text(pDX, IDC_EDIT_GRAPH_TEXT_COLOR_R, m_uiEditGraphTextColorR);
	DDX_Text(pDX, IDC_EDIT_GRAPH_TEXT_COLOR_G, m_uiEditGraphTextColorG);
	DDX_Text(pDX, IDC_EDIT_GRAPH_TEXT_COLOR_B, m_uiEditGraphTextColorB);

	DDX_Text(pDX, IDC_EDIT_BALL_SPEED, m_uiBallSpeed);

	DDX_CBIndex(pDX, IDC_COMBO_BOX_LINE_STYLE, m_iComboBoxLineStyle);
	DDX_Control(pDX, IDC_COMBO_BOX_LINE_STYLE, m_ComboBoxLineStyle);
	DDX_Text(pDX, IDC_COMBO_BOX_LINE_WIDTH, m_uiComboBoxLineWidth);
	DDX_CBIndex(pDX, IDC_COMBO_BAR_LINE_STYLE, m_iComboBarLineStyle);
	DDX_Text(pDX, IDC_COMBO_BAR_LINE_WIDTH, m_uiComboBarLineWidth);
	DDX_CBIndex(pDX, IDC_COMBO_GRAPH_LINE_STYLE, m_iComboGraphLineStyle);
	DDX_Text(pDX, IDC_COMBO_GRAPH_LINE_WIDTH, m_iComboGraphLineWidth);
	DDX_Control(pDX, IDC_COMBO_BAR_LINE_STYLE, m_ComboBarLineStyle);
	DDX_Control(pDX, IDC_COMBO_GRAPH_LINE_STYLE, m_ComboGraphLineStyle);

	DDX_Text(pDX, IDC_EDIT_BAR_FRAME_COLOR_R, m_uiEditBarFrameColorR);
	DDX_Text(pDX, IDC_EDIT_BAR_FRAME_COLOR_G, m_uiEditBarFrameColorG);
	DDX_Text(pDX, IDC_EDIT_BAR_FRAME_COLOR_B, m_uiEditBarFrameColorB);
	DDX_Text(pDX, IDC_EDIT_BAR_COUNT, m_uiEditBarCount);

	DDX_Text(pDX, IDC_EDIT_BAR_RADIUS, m_uiEditBarRadius);


	DDX_Text(pDX, IDC_EDIT_FPS_TEXT_COLOR_R, m_uiFpsTextColorR);
	DDX_Text(pDX, IDC_EDIT_FPS_TEXT_COLOR_G, m_uiFpsTextColorG);
	DDX_Text(pDX, IDC_EDIT_FPS_TEXT_COLOR_B, m_uiFpsTextColorB);
}


BEGIN_MESSAGE_MAP(CDlgSetting, CDialog)
//	ON_CBN_SELCHANGE(IDC_COMBO1, &CDlgSetting::OnCbnSelchangeCombo1)
//ON_CBN_SELCHANGE(IDC_COMBO_BOX_LINE_STYLE2, &CDlgSetting::OnCbnSelchangeComboBoxLineStyle2)
//ON_EN_CHANGE(IDC_EDIT_BOX_FRAME_COLOR_R, &CDlgSetting::OnEnChangeEditBoxFrameColorR)
ON_WM_ERASEBKGND()
ON_WM_CTLCOLOR()
//ON_CBN_SELCHANGE(IDC_COMBO_BAR_LINE_STYLE, &CDlgSetting::OnCbnSelchangeComboBarLineStyle)
END_MESSAGE_MAP()


// CDlgSetting 消息处理程序

//void CDlgSetting::OnCbnSelchangeCombo1()
//{
//	// TODO: 在此添加控件通知处理程序代码
//}

//BOOL CDlgSetting::OnInitDialog()
//{
//	CDialog::OnInitDialog();
//
//	// TODO:  在此添加额外的初始化
//
//	m_ComboBoxLineStyle.AddString(L"实线");
//	m_ComboBoxLineStyle.AddString(L"虚线（线宽必须是1）");
//	m_ComboBoxLineStyle.AddString(L"点线（线宽必须是1）");
//	m_ComboBoxLineStyle.AddString(L"点划线（线宽必须是1）");
//	m_ComboBoxLineStyle.AddString(L"点-点-划（线宽必须是1）");
//
//	m_ComboBarLineStyle.AddString(L"实线");
//	m_ComboBarLineStyle.AddString(L"虚线（线宽必须是1）");
//	m_ComboBarLineStyle.AddString(L"点线（线宽必须是1）");
//	m_ComboBarLineStyle.AddString(L"点划线（线宽必须是1）");
//	m_ComboBarLineStyle.AddString(L"点-点-划（线宽必须是1）");
//
//	m_ComboGraphLineStyle.AddString(L"实线");
//	m_ComboGraphLineStyle.AddString(L"虚线（线宽必须是1）");
//	m_ComboGraphLineStyle.AddString(L"点线（线宽必须是1）");
//	m_ComboGraphLineStyle.AddString(L"点划线（线宽必须是1）");
//	m_ComboGraphLineStyle.AddString(L"点-点-划（线宽必须是1）");
//
//	return TRUE;  // return TRUE unless you set the focus to a control
//	// 异常: OCX 属性页应返回 FALSE
//}
//void CDlgSetting::OnCbnSelchangeComboBoxLineStyle2()
//{
//	// TODO: 在此添加控件通知处理程序代码
//}

//void CDlgSetting::OnEnChangeEditBoxFrameColorR()
//{
//	// TODO:  如果该控件是 RICHEDIT 控件，则它将不会
//	// 发送该通知，除非重写 CDialog::OnInitDialog()
//	// 函数并调用 CRichEditCtrl().SetEventMask()，
//	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
//
//	// TODO:  在此添加控件通知处理程序代码
//}

BOOL CDlgSetting::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CRect rt;
	GetClientRect(&rt);

	CDC dcMem;
	dcMem.CreateCompatibleDC(pDC);

	CBitmap bmp;
	bmp.LoadBitmap(MAKEINTRESOURCE(IDB_BITMAP_SETTINGDLG_BACKGROUND));

	CBitmap *pBmpOld = dcMem.SelectObject(&bmp);

	pDC->BitBlt(0, 0, rt.Width(), rt.Height(), &dcMem, 0, 0, SRCCOPY);

	dcMem.SelectObject(pBmpOld);
	return 1;
//	return CDialog::OnEraseBkgnd(pDC);
}

HBRUSH CDlgSetting::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何属性
	if(pWnd->GetDlgCtrlID() == IDC_STATIC)
	{
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(NULL_BRUSH);
	}
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}

//void CDlgSetting::OnCbnSelchangeComboBarLineStyle()
//{
//	// TODO: 在此添加控件通知处理程序代码
//}
