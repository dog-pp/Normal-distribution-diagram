// 110501 ��̬�ֲ� - С��ģ��View.cpp : CMyView ���ʵ��
//

#include "stdafx.h"
#include "110501 ��̬�ֲ� - С��ģ��.h"

#include "110501 ��̬�ֲ� - С��ģ��Doc.h"
#include "110501 ��̬�ֲ� - С��ģ��View.h"

#include "MyBarArray.h"
#include "MyBarArrayFrame.h"
#include "BarGraph.h"
#include "MyPosArray.h"
#include "MyRand.h"
#include "FPS.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMyView

IMPLEMENT_DYNCREATE(CMyView, CView)

BEGIN_MESSAGE_MAP(CMyView, CView)
	ON_WM_TIMER()
	ON_WM_ERASEBKGND()
	ON_WM_PAINT()
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(IDC_SETTING, &CMyView::OnSetting)
	ON_COMMAND(ID_START, &CMyView::OnStart)
	ON_COMMAND(ID_PAUSE, &CMyView::OnPause)
END_MESSAGE_MAP()




// CMyView ����/����

CMyView::CMyView()
{	
	//��ʼ������ƶ������ṹ��
	m_moveParam.iItem = 0;
	m_moveParam.bLButtonDown = 0;



	//��ʼ�������������( == �Ի��������в���)///////////////////////////////////////////////
	//��ɫ
	m_DlgSettingParam.m_uiEditBarColorR = 255;
	m_DlgSettingParam.m_uiEditBarColorG = 0;
	m_DlgSettingParam.m_uiEditBarColorB = 0;

	//���߿�������ɫ
	m_DlgSettingParam.m_uiEditBarFrameColorR = 255;
	m_DlgSettingParam.m_uiEditBarFrameColorG = 255;
	m_DlgSettingParam.m_uiEditBarFrameColorB = 0;

	//����������
	m_DlgSettingParam.m_iComboBarLineStyle = PS_DOT;

	//���������
	m_DlgSettingParam.m_uiComboBarLineWidth = 1;


	//�����߿�ɫ
	m_DlgSettingParam.m_uiEditBoxFrameColorR = 0;
	m_DlgSettingParam.m_uiEditBoxFrameColorG = 255;
	m_DlgSettingParam.m_uiEditBoxFrameColorB = 0;

	//�����߿���������
	m_DlgSettingParam.m_iComboBoxLineStyle = PS_DASH;

	//�����������
	m_DlgSettingParam.m_uiComboBoxLineWidth = 1;


	//����ͼ�߿�ɫ
	m_DlgSettingParam.m_uiEditGraphFrameColorR = 128;
	m_DlgSettingParam.m_uiEditGraphFrameColorG = 0;
	m_DlgSettingParam.m_uiEditGraphFrameColorB = 255;

	//����ͼɫ
	m_DlgSettingParam.m_uiEditGraphColorR = 200;
	m_DlgSettingParam.m_uiEditGraphColorG = 255;
	m_DlgSettingParam.m_uiEditGraphColorB = 75;

	//����ͼ����ɫ
	m_DlgSettingParam.m_uiEditGraphTextColorR = 255;
	m_DlgSettingParam.m_uiEditGraphTextColorG = 128;
	m_DlgSettingParam.m_uiEditGraphTextColorB = 0;

	//����ͼ�߿���������
	m_DlgSettingParam.m_iComboGraphLineStyle = PS_DASHDOT;

	//����ͼ�߿��������
	m_DlgSettingParam.m_iComboGraphLineWidth = 1;



	//FPS������ɫ
	m_DlgSettingParam.m_uiFpsTextColorR = 0;
	m_DlgSettingParam.m_uiFpsTextColorG = 0;
	m_DlgSettingParam.m_uiFpsTextColorB = 0;


	//����
#ifdef _DEBUG
	m_DlgSettingParam.m_uiBallSpeed = 1000;
#else
	m_DlgSettingParam.m_uiBallSpeed = 1000;
#endif

	


	//����
	m_DlgSettingParam.m_uiEditBarCount = 10;

	//���뾶
	m_DlgSettingParam.m_uiEditBarRadius = 10;

//////////////////����������Գ�ʼ������/////////////////////////////////////////////////////////








/////////////////////////�������Ӧ��/////////////////////////////////////////////////


	//��ɫ Ӧ��
	m_barArray.SetColor(RGB(
		m_DlgSettingParam.m_uiEditBarColorR,
		m_DlgSettingParam.m_uiEditBarColorG,
		m_DlgSettingParam.m_uiEditBarColorB));


	//���߿�������ɫ Ӧ��
	//���������� Ӧ��
	//��������� Ӧ��
	m_barArray.SetPen(m_DlgSettingParam.m_iComboBarLineStyle,
		m_DlgSettingParam.m_uiComboBarLineWidth, 
		RGB(m_DlgSettingParam.m_uiEditBarFrameColorR,
		m_DlgSettingParam.m_uiEditBarFrameColorG,
		m_DlgSettingParam.m_uiEditBarFrameColorB));


	//�����߿�ɫ Ӧ��
	//�����߿��������� Ӧ��
	//����������� Ӧ��
	m_barArrayFrame.SetPen(RGB(m_DlgSettingParam.m_uiEditBoxFrameColorR, 
		m_DlgSettingParam.m_uiEditBoxFrameColorG,
		m_DlgSettingParam.m_uiEditBoxFrameColorB),
		m_DlgSettingParam.m_uiComboBoxLineWidth,
		m_DlgSettingParam.m_iComboBoxLineStyle);


	//����ͼ�߿�ɫ Ӧ��
	//����ͼɫ Ӧ��
	//����ͼ����ɫ Ӧ��
	//����ͼ�߿��������� Ӧ��
	//����ͼ�߿�������� Ӧ��
	m_barGraph.SetColor(RGB(m_DlgSettingParam.m_uiEditGraphTextColorR,
					m_DlgSettingParam.m_uiEditGraphTextColorG,
					m_DlgSettingParam.m_uiEditGraphTextColorB),
					RGB(m_DlgSettingParam.m_uiEditGraphColorR,
					m_DlgSettingParam.m_uiEditGraphColorG,
					m_DlgSettingParam.m_uiEditGraphColorB),
					RGB(m_DlgSettingParam.m_uiEditGraphFrameColorR,
					m_DlgSettingParam.m_uiEditGraphFrameColorG,
					m_DlgSettingParam.m_uiEditGraphFrameColorB),
					m_DlgSettingParam.m_iComboGraphLineWidth,
					m_DlgSettingParam.m_iComboGraphLineStyle);


	//FPS��ɫӦ��
	m_fps.SetTextColor(RGB(m_DlgSettingParam.m_uiFpsTextColorR,
		m_DlgSettingParam.m_uiFpsTextColorG,
		m_DlgSettingParam.m_uiFpsTextColorB));


	//���� Ӧ��  ��ʱ����δ���� ���ܵ���SetTimer Ӧ����OnCreate������ִ��
	//SetTimer(1, m_DlgSettingParam.m_uiBallSpeed, 0);

	
	//���� Ӧ��
	//���뾶 Ӧ��
	m_barArray.SetBarMax(m_DlgSettingParam.m_uiEditBarCount);
	m_barArray.SetRadius(m_DlgSettingParam.m_uiEditBarRadius);
	m_posArray.InitFromArray(m_barArray);
	//����ͼ��Ⱥͼ�������Խ�����չ, ���Ͳ�����Bar��ȱ仯���仯�� ����!
	m_barGraph.SetBarCount(m_DlgSettingParam.m_uiEditBarCount - 1);
	m_barGraph.SetBarWidth((UINT)(m_DlgSettingParam.m_uiEditBarRadius * 4 * 0.9));
	m_barGraph.SetSpaceWidth((UINT)(m_DlgSettingParam.m_uiEditBarRadius * 4 * 0.1));


/////////////////////////�������Ӧ�ý���/////////////////////////////////////////////////






/////////////////////////������������(�������)///////////////////////////////////////////



	m_barArray.SetBeginPos(CPoint(10, 10));//��
	m_posArray.InitFromArray(m_barArray);//��
	m_barArrayFrame.InitFromArray(m_barArray);//���߿�
	m_barGraph.SetBeginPos(CPoint(10, 400));//ͳ��ͼ
	m_fps.SetBeginPos(CPoint(600, 50));//FPS
#ifdef _DEBUG
	m_fps.ReInit();
#endif

















}

CMyView::~CMyView()
{
}

BOOL CMyView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMyView ����

void CMyView::OnDraw(CDC* /*pDC*/)
{
	CMyDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMyView ���

#ifdef _DEBUG
void CMyView::AssertValid() const
{
	CView::AssertValid();
}

void CMyView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyDoc* CMyView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyDoc)));
	return (CMyDoc*)m_pDocument;
}
#endif //_DEBUG


// CMyView ��Ϣ�������

void CMyView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMyRand ra;

	m_posArray.GoOnStep(m_barGraph);
	m_posArray.Add(RGB(ra.Rand(100, 255), ra.Rand(200, 255), ra.Rand(150, 255)));
	Invalidate();
	CView::OnTimer(nIDEvent);
}

BOOL CMyView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	UNREFERENCED_PARAMETER(pDC);
	return 1;
//	return CView::OnEraseBkgnd(pDC);
}

void CMyView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CView::OnPaint()

	//Mem DC
	CDC dcMem;
	dcMem.CreateCompatibleDC(&dc);

	//Window Rect
	CRect rt;
	GetClientRect(&rt);

	//Mem Bitmap
	CBitmap bmpMem;
	bmpMem.LoadBitmap(MAKEINTRESOURCE(IDB_BITMAP_BACKGROUND));
//	bmpMem.CreateCompatibleBitmap(&dc, rt.Width(), rt.Height());

	//ѡ���ڴ�λͼ
	CBitmap *pBmpOld = dcMem.SelectObject(&bmpMem);



	//NULL_PEN ȥ���߿�
	CPen penNull(PS_NULL, 0, COLORREF(0));
	CPen *pPenNullOld = dcMem.SelectObject(&penNull);


	//������				��ɫ	���뾶 ����
	m_barArray.Paint(dcMem);//��ʼx y����(��λ:����)

	//���߿�
	dcMem.SetBkMode(TRANSPARENT);/////////////////////////////////////////////////
	m_barArrayFrame.Paint(dcMem);

	//������ͼ
	m_barGraph.Paint(dcMem);

	//��С��
	m_posArray.Paint(dcMem);

	//��FPS
	m_fps.Paint(dcMem);


	//����DC��
	dc.BitBlt(0, 0, rt.Width(), rt.Height(),
		&dcMem, 0, 0, SRCCOPY);


	//�ͷ�NULL_PEN
	dcMem.SelectObject(pPenNullOld);

	//�ͷ��ڴ�λͼ
	dcMem.SelectObject(pBmpOld);


}

int CMyView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	SetTimer(1, m_DlgSettingParam.m_uiBallSpeed, 0);
	return 0;
}

void CMyView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_moveParam.ptBegin = point;
	m_moveParam.bLButtonDown = 1;
	if(CRect(m_barArray.m_ptBeginPos,
		CSize(m_barArray.m_uiWeight, m_barArray.m_uiHeight)
		).PtInRect(point))//�ڷ�Χ��
	{
		m_moveParam.iItem = ITEM_BAR;
		m_moveParam.ptInWnd = point - m_barArray.m_ptBeginPos;
	}

	else if(CRect(m_barGraph.m_ptBeginPos,
		CSize(m_barGraph.m_uiWidth, m_barGraph.m_ptBeginPos.y + 1000)//////////����ͼ����ȷ����Χ ����1000��
		).PtInRect(point))
	{
		m_moveParam.iItem = ITEM_GRAPH;
		m_moveParam.ptInWnd = point - m_barGraph.m_ptBeginPos;
	}

	else if(CRect(m_fps.m_ptBeginPos,
		CSize(110, 15)//////////FPSͼ����ȷ����Χ ����110, 15��
		).PtInRect(point))
	{
		m_moveParam.iItem = ITEM_FPS;
		m_moveParam.ptInWnd = point - m_fps.m_ptBeginPos;
	}
	else
		m_moveParam.iItem = 0;



	CView::OnLButtonDown(nFlags, point);
}

void CMyView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_moveParam.bLButtonDown = 0;
	CView::OnLButtonUp(nFlags, point);
}

void CMyView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	if(m_moveParam.bLButtonDown)
	{
		point -= m_moveParam.ptInWnd;
		switch(m_moveParam.iItem)
		{
			case ITEM_BAR:
				m_barArray.SetBeginPos(point);
				m_posArray.SetBeginPos(point);
				m_barArrayFrame.SetBeginPos(point);
				Invalidate();
				break;
			case ITEM_GRAPH:
				m_barGraph.SetBeginPos(point);
				Invalidate();
				break;
			case ITEM_FPS:
				m_fps.SetBeginPos(point);
				Invalidate();
			case 0:
				break;
			default:
				ASSERT(0);
		}
	}
	CView::OnMouseMove(nFlags, point);
}

void CMyView::OnSetting()
{
	// TODO: �ڴ���������������
	CDlgSetting dlg;









	//������������
	//��ɫ
	dlg.m_uiEditBarColorR = m_DlgSettingParam.m_uiEditBarColorR;
	dlg.m_uiEditBarColorG = m_DlgSettingParam.m_uiEditBarColorG;
	dlg.m_uiEditBarColorB = m_DlgSettingParam.m_uiEditBarColorB;

	//���߿�������ɫ
	dlg.m_uiEditBarFrameColorR = m_DlgSettingParam.m_uiEditBarFrameColorR;
	dlg.m_uiEditBarFrameColorG = m_DlgSettingParam.m_uiEditBarFrameColorG;
	dlg.m_uiEditBarFrameColorB = m_DlgSettingParam.m_uiEditBarFrameColorB;

	//����������
	dlg.m_iComboBarLineStyle = m_DlgSettingParam.m_iComboBarLineStyle;

	//���������
	dlg.m_uiComboBarLineWidth = m_DlgSettingParam.m_uiComboBarLineWidth;


	//�����߿�ɫ
	dlg.m_uiEditBoxFrameColorR = m_DlgSettingParam.m_uiEditBoxFrameColorR;
	dlg.m_uiEditBoxFrameColorG = m_DlgSettingParam.m_uiEditBoxFrameColorG;
	dlg.m_uiEditBoxFrameColorB = m_DlgSettingParam.m_uiEditBoxFrameColorB;

	//�����߿���������
	dlg.m_iComboBoxLineStyle = m_DlgSettingParam.m_iComboBoxLineStyle;

	//�����������
	dlg.m_uiComboBoxLineWidth = m_DlgSettingParam.m_uiComboBoxLineWidth;


	//����ͼ�߿�ɫ
	dlg.m_uiEditGraphFrameColorR = m_DlgSettingParam.m_uiEditGraphFrameColorR;
	dlg.m_uiEditGraphFrameColorG = m_DlgSettingParam.m_uiEditGraphFrameColorG;
	dlg.m_uiEditGraphFrameColorB = m_DlgSettingParam.m_uiEditGraphFrameColorB;

	//����ͼɫ
	dlg.m_uiEditGraphColorR = m_DlgSettingParam.m_uiEditGraphColorR;
	dlg.m_uiEditGraphColorG = m_DlgSettingParam.m_uiEditGraphColorG;
	dlg.m_uiEditGraphColorB = m_DlgSettingParam.m_uiEditGraphColorB;

	//����ͼ����ɫ
	dlg.m_uiEditGraphTextColorR = m_DlgSettingParam.m_uiEditGraphTextColorR;
	dlg.m_uiEditGraphTextColorG = m_DlgSettingParam.m_uiEditGraphTextColorG;
	dlg.m_uiEditGraphTextColorB = m_DlgSettingParam.m_uiEditGraphTextColorB;

	//����ͼ�߿���������
	dlg.m_iComboGraphLineStyle = m_DlgSettingParam.m_iComboGraphLineStyle;

	//����ͼ�߿��������
	dlg.m_iComboGraphLineWidth = m_DlgSettingParam.m_iComboGraphLineWidth;



	//FPS������ɫ
	dlg.m_uiFpsTextColorR = m_DlgSettingParam.m_uiFpsTextColorR;
	dlg.m_uiFpsTextColorG = m_DlgSettingParam.m_uiFpsTextColorG;
	dlg.m_uiFpsTextColorB = m_DlgSettingParam.m_uiFpsTextColorB;


	//����
	dlg.m_uiBallSpeed = m_DlgSettingParam.m_uiBallSpeed;

	


	//����
	dlg.m_uiEditBarCount = m_DlgSettingParam.m_uiEditBarCount;

	//���뾶
	dlg.m_uiEditBarRadius = m_DlgSettingParam.m_uiEditBarRadius;








	if(dlg.DoModal() == IDOK)
	{

		//�������
		//��ɫ
		m_DlgSettingParam.m_uiEditBarColorR = dlg.m_uiEditBarColorR;
		m_DlgSettingParam.m_uiEditBarColorG = dlg.m_uiEditBarColorG;
		m_DlgSettingParam.m_uiEditBarColorB = dlg.m_uiEditBarColorB;

		//���߿�������ɫ
		m_DlgSettingParam.m_uiEditBarFrameColorR = dlg.m_uiEditBarFrameColorR;
		m_DlgSettingParam.m_uiEditBarFrameColorG = dlg.m_uiEditBarFrameColorG;
		m_DlgSettingParam.m_uiEditBarFrameColorB = dlg.m_uiEditBarFrameColorB;

		//����������
		m_DlgSettingParam.m_iComboBarLineStyle = dlg.m_iComboBarLineStyle;

		//���������
		m_DlgSettingParam.m_uiComboBarLineWidth = dlg.m_uiComboBarLineWidth;


		//�����߿�ɫ
		m_DlgSettingParam.m_uiEditBoxFrameColorR = dlg.m_uiEditBoxFrameColorR;
		m_DlgSettingParam.m_uiEditBoxFrameColorG = dlg.m_uiEditBoxFrameColorG;
		m_DlgSettingParam.m_uiEditBoxFrameColorB = dlg.m_uiEditBoxFrameColorB;

		//�����߿���������
		m_DlgSettingParam.m_iComboBoxLineStyle = dlg.m_iComboBoxLineStyle;

		//�����������
		m_DlgSettingParam.m_uiComboBoxLineWidth = dlg.m_uiComboBoxLineWidth;


		//����ͼ�߿�ɫ
		m_DlgSettingParam.m_uiEditGraphFrameColorR = dlg.m_uiEditGraphFrameColorR;
		m_DlgSettingParam.m_uiEditGraphFrameColorG = dlg.m_uiEditGraphFrameColorG;
		m_DlgSettingParam.m_uiEditGraphFrameColorB = dlg.m_uiEditGraphFrameColorB;

		//����ͼɫ
		m_DlgSettingParam.m_uiEditGraphColorR = dlg.m_uiEditGraphColorR;
		m_DlgSettingParam.m_uiEditGraphColorG = dlg.m_uiEditGraphColorG;
		m_DlgSettingParam.m_uiEditGraphColorB = dlg.m_uiEditGraphColorB;

		//����ͼ����ɫ
		m_DlgSettingParam.m_uiEditGraphTextColorR = dlg.m_uiEditGraphTextColorR;
		m_DlgSettingParam.m_uiEditGraphTextColorG = dlg.m_uiEditGraphTextColorG;
		m_DlgSettingParam.m_uiEditGraphTextColorB = dlg.m_uiEditGraphTextColorB;

		//����ͼ�߿���������
		m_DlgSettingParam.m_iComboGraphLineStyle = dlg.m_iComboGraphLineStyle;

		//����ͼ�߿��������
		m_DlgSettingParam.m_iComboGraphLineWidth = dlg.m_iComboGraphLineWidth;




		//FPS������ɫ
		m_DlgSettingParam.m_uiFpsTextColorR = dlg.m_uiFpsTextColorR;
		m_DlgSettingParam.m_uiFpsTextColorG = dlg.m_uiFpsTextColorG;
		m_DlgSettingParam.m_uiFpsTextColorB = dlg.m_uiFpsTextColorB;


		//���� (�ں����жϺ��޸�)
	//	m_DlgSettingParam.m_uiBallSpeed = dlg.m_uiBallSpeed;

		


		//������޸�������Ϊ�ж�, ����ӳ����޸�Ӧ���б��޸�
		////����
		//m_DlgSettingParam.m_uiEditBarCount = dlg.m_uiEditBarCount;

		////���뾶
		//m_DlgSettingParam.m_uiEditBarRadius = dlg.m_uiEditBarRadius;




		/////////////////////////Ӧ���޸�//////////////////////////////////////////


		//��ɫ �޸�
		m_barArray.SetColor(RGB(
			m_DlgSettingParam.m_uiEditBarColorR,
			m_DlgSettingParam.m_uiEditBarColorG,
			m_DlgSettingParam.m_uiEditBarColorB));


		//���߿�������ɫ �޸�
		//���������� �޸�
		//��������� �޸�
		m_barArray.SetPen(m_DlgSettingParam.m_iComboBarLineStyle,
			m_DlgSettingParam.m_uiComboBarLineWidth, 
			RGB(m_DlgSettingParam.m_uiEditBarFrameColorR,
			m_DlgSettingParam.m_uiEditBarFrameColorG,
			m_DlgSettingParam.m_uiEditBarFrameColorB));


		//�����߿�ɫ �޸�
		//�����߿��������� �޸�
		//����������� �޸�
		m_barArrayFrame.SetPen(RGB(m_DlgSettingParam.m_uiEditBoxFrameColorR, 
			m_DlgSettingParam.m_uiEditBoxFrameColorG,
			m_DlgSettingParam.m_uiEditBoxFrameColorB),
			m_DlgSettingParam.m_uiComboBoxLineWidth,
			m_DlgSettingParam.m_iComboBoxLineStyle);


		//����ͼ�߿�ɫ �޸�
		//����ͼɫ �޸�
		//����ͼ����ɫ �޸�
		//����ͼ�߿��������� �޸�
		//����ͼ�߿�������� �޸�
		m_barGraph.SetColor(RGB(m_DlgSettingParam.m_uiEditGraphTextColorR,
						m_DlgSettingParam.m_uiEditGraphTextColorG,
						m_DlgSettingParam.m_uiEditGraphTextColorB),
						RGB(m_DlgSettingParam.m_uiEditGraphColorR,
						m_DlgSettingParam.m_uiEditGraphColorG,
						m_DlgSettingParam.m_uiEditGraphColorB),
						RGB(m_DlgSettingParam.m_uiEditGraphFrameColorR,
						m_DlgSettingParam.m_uiEditGraphFrameColorG,
						m_DlgSettingParam.m_uiEditGraphFrameColorB),
						m_DlgSettingParam.m_iComboGraphLineWidth,
						m_DlgSettingParam.m_iComboGraphLineStyle);


		//FPS������ɫ
		m_fps.SetTextColor(RGB(m_DlgSettingParam.m_uiFpsTextColorR,
			m_DlgSettingParam.m_uiFpsTextColorG,
			m_DlgSettingParam.m_uiFpsTextColorB));


		if(m_DlgSettingParam.m_uiEditBarCount != dlg.m_uiEditBarCount)
		{
			//����
			m_DlgSettingParam.m_uiEditBarCount = dlg.m_uiEditBarCount;


			//���� �޸�
			//���뾶 �޸�
			m_barArray.SetBarMax(m_DlgSettingParam.m_uiEditBarCount);
		//	m_barArray.SetRadius(m_DlgSettingParam.m_uiEditBarRadius);
			m_posArray.InitFromArray(m_barArray);
			m_barArrayFrame.InitFromArray(m_barArray);
			m_barGraph.SetBarCount(m_DlgSettingParam.m_uiEditBarCount - 1);
		//	m_barGraph.SetBarWidth((m_DlgSettingParam.m_uiEditBarRadius) * 4);
		}
		if(m_DlgSettingParam.m_uiEditBarRadius != dlg.m_uiEditBarRadius)
		{
			//���뾶
			m_DlgSettingParam.m_uiEditBarRadius = dlg.m_uiEditBarRadius;


			//���� �޸�
			//���뾶 �޸�
		//	m_barArray.SetBarMax(m_DlgSettingParam.m_uiEditBarCount);
			m_barArray.SetRadius(m_DlgSettingParam.m_uiEditBarRadius);
			m_posArray.InitFromArray(m_barArray);
			m_barArrayFrame.InitFromArray(m_barArray);
		//	m_barGraph.SetBarCount(m_DlgSettingParam.m_uiEditBarCount - 1);
			m_barGraph.SetBarWidth((UINT)(m_DlgSettingParam.m_uiEditBarRadius * 4 * 0.9));
			m_barGraph.SetSpaceWidth((UINT)(m_DlgSettingParam.m_uiEditBarRadius * 4 * 0.1));
		}


		//С���ٶ��޸�
		if(m_DlgSettingParam.m_uiBallSpeed != dlg.m_uiBallSpeed)
		{
			m_DlgSettingParam.m_uiBallSpeed = dlg.m_uiBallSpeed;
			SetTimer(1, dlg.m_uiBallSpeed, 0);
		}





		Invalidate();
	}
}

void CMyView::OnStart()
{
	// TODO: �ڴ���������������
	m_fps.ReInit();//�����ڲ���ʱ��
	SetTimer(1, m_DlgSettingParam.m_uiBallSpeed, 0);
}

void CMyView::OnPause()
{
	// TODO: �ڴ���������������
	KillTimer(1);
}
