// 110501 正态分布 - 小球模拟View.cpp : CMyView 类的实现
//

#include "stdafx.h"
#include "110501 正态分布 - 小球模拟.h"

#include "110501 正态分布 - 小球模拟Doc.h"
#include "110501 正态分布 - 小球模拟View.h"

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




// CMyView 构造/析构

CMyView::CMyView()
{	
	//初始化鼠标移动参数结构体
	m_moveParam.iItem = 0;
	m_moveParam.bLButtonDown = 0;



	//初始化所有输出属性( == 对话框中所有参数)///////////////////////////////////////////////
	//棒色
	m_DlgSettingParam.m_uiEditBarColorR = 255;
	m_DlgSettingParam.m_uiEditBarColorG = 0;
	m_DlgSettingParam.m_uiEditBarColorB = 0;

	//棒边框线条颜色
	m_DlgSettingParam.m_uiEditBarFrameColorR = 255;
	m_DlgSettingParam.m_uiEditBarFrameColorG = 255;
	m_DlgSettingParam.m_uiEditBarFrameColorB = 0;

	//棒线条类型
	m_DlgSettingParam.m_iComboBarLineStyle = PS_DOT;

	//棒线条宽度
	m_DlgSettingParam.m_uiComboBarLineWidth = 1;


	//容器边框色
	m_DlgSettingParam.m_uiEditBoxFrameColorR = 0;
	m_DlgSettingParam.m_uiEditBoxFrameColorG = 255;
	m_DlgSettingParam.m_uiEditBoxFrameColorB = 0;

	//容器边框线条类型
	m_DlgSettingParam.m_iComboBoxLineStyle = PS_DASH;

	//容器线条宽度
	m_DlgSettingParam.m_uiComboBoxLineWidth = 1;


	//条形图边框色
	m_DlgSettingParam.m_uiEditGraphFrameColorR = 128;
	m_DlgSettingParam.m_uiEditGraphFrameColorG = 0;
	m_DlgSettingParam.m_uiEditGraphFrameColorB = 255;

	//条形图色
	m_DlgSettingParam.m_uiEditGraphColorR = 200;
	m_DlgSettingParam.m_uiEditGraphColorG = 255;
	m_DlgSettingParam.m_uiEditGraphColorB = 75;

	//条形图字体色
	m_DlgSettingParam.m_uiEditGraphTextColorR = 255;
	m_DlgSettingParam.m_uiEditGraphTextColorG = 128;
	m_DlgSettingParam.m_uiEditGraphTextColorB = 0;

	//条形图边框线条类型
	m_DlgSettingParam.m_iComboGraphLineStyle = PS_DASHDOT;

	//条形图边框线条宽度
	m_DlgSettingParam.m_iComboGraphLineWidth = 1;



	//FPS文字颜色
	m_DlgSettingParam.m_uiFpsTextColorR = 0;
	m_DlgSettingParam.m_uiFpsTextColorG = 0;
	m_DlgSettingParam.m_uiFpsTextColorB = 0;


	//球速
#ifdef _DEBUG
	m_DlgSettingParam.m_uiBallSpeed = 1000;
#else
	m_DlgSettingParam.m_uiBallSpeed = 1000;
#endif

	


	//棒数
	m_DlgSettingParam.m_uiEditBarCount = 10;

	//棒半径
	m_DlgSettingParam.m_uiEditBarRadius = 10;

//////////////////所有输出属性初始化结束/////////////////////////////////////////////////////////








/////////////////////////输出属性应用/////////////////////////////////////////////////


	//棒色 应用
	m_barArray.SetColor(RGB(
		m_DlgSettingParam.m_uiEditBarColorR,
		m_DlgSettingParam.m_uiEditBarColorG,
		m_DlgSettingParam.m_uiEditBarColorB));


	//棒边框线条颜色 应用
	//棒线条类型 应用
	//棒线条宽度 应用
	m_barArray.SetPen(m_DlgSettingParam.m_iComboBarLineStyle,
		m_DlgSettingParam.m_uiComboBarLineWidth, 
		RGB(m_DlgSettingParam.m_uiEditBarFrameColorR,
		m_DlgSettingParam.m_uiEditBarFrameColorG,
		m_DlgSettingParam.m_uiEditBarFrameColorB));


	//容器边框色 应用
	//容器边框线条类型 应用
	//容器线条宽度 应用
	m_barArrayFrame.SetPen(RGB(m_DlgSettingParam.m_uiEditBoxFrameColorR, 
		m_DlgSettingParam.m_uiEditBoxFrameColorG,
		m_DlgSettingParam.m_uiEditBoxFrameColorB),
		m_DlgSettingParam.m_uiComboBoxLineWidth,
		m_DlgSettingParam.m_iComboBoxLineStyle);


	//条形图边框色 应用
	//条形图色 应用
	//条形图字体色 应用
	//条形图边框线条类型 应用
	//条形图边框线条宽度 应用
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


	//FPS颜色应用
	m_fps.SetTextColor(RGB(m_DlgSettingParam.m_uiFpsTextColorR,
		m_DlgSettingParam.m_uiFpsTextColorG,
		m_DlgSettingParam.m_uiFpsTextColorB));


	//球速 应用  此时窗口未创建 不能调用SetTimer 应用在OnCreate函数里执行
	//SetTimer(1, m_DlgSettingParam.m_uiBallSpeed, 0);

	
	//棒数 应用
	//棒半径 应用
	m_barArray.SetBarMax(m_DlgSettingParam.m_uiEditBarCount);
	m_barArray.SetRadius(m_DlgSettingParam.m_uiEditBarRadius);
	m_posArray.InitFromArray(m_barArray);
	//条形图宽度和间隔还可以进行扩展, 但就不能随Bar宽度变化而变化了 不好!
	m_barGraph.SetBarCount(m_DlgSettingParam.m_uiEditBarCount - 1);
	m_barGraph.SetBarWidth((UINT)(m_DlgSettingParam.m_uiEditBarRadius * 4 * 0.9));
	m_barGraph.SetSpaceWidth((UINT)(m_DlgSettingParam.m_uiEditBarRadius * 4 * 0.1));


/////////////////////////输出属性应用结束/////////////////////////////////////////////////






/////////////////////////其他属性设置(输出坐标)///////////////////////////////////////////



	m_barArray.SetBeginPos(CPoint(10, 10));//棒
	m_posArray.InitFromArray(m_barArray);//球
	m_barArrayFrame.InitFromArray(m_barArray);//棒边框
	m_barGraph.SetBeginPos(CPoint(10, 400));//统计图
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
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMyView 绘制

void CMyView::OnDraw(CDC* /*pDC*/)
{
	CMyDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMyView 诊断

#ifdef _DEBUG
void CMyView::AssertValid() const
{
	CView::AssertValid();
}

void CMyView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyDoc* CMyView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyDoc)));
	return (CMyDoc*)m_pDocument;
}
#endif //_DEBUG


// CMyView 消息处理程序

void CMyView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMyRand ra;

	m_posArray.GoOnStep(m_barGraph);
	m_posArray.Add(RGB(ra.Rand(100, 255), ra.Rand(200, 255), ra.Rand(150, 255)));
	Invalidate();
	CView::OnTimer(nIDEvent);
}

BOOL CMyView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	UNREFERENCED_PARAMETER(pDC);
	return 1;
//	return CView::OnEraseBkgnd(pDC);
}

void CMyView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CView::OnPaint()

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

	//选入内存位图
	CBitmap *pBmpOld = dcMem.SelectObject(&bmpMem);



	//NULL_PEN 去掉边框
	CPen penNull(PS_NULL, 0, COLORREF(0));
	CPen *pPenNullOld = dcMem.SelectObject(&penNull);


	//画背景				棒色	棒半径 棒数
	m_barArray.Paint(dcMem);//起始x y坐标(单位:像素)

	//画边框
	dcMem.SetBkMode(TRANSPARENT);/////////////////////////////////////////////////
	m_barArrayFrame.Paint(dcMem);

	//画条形图
	m_barGraph.Paint(dcMem);

	//画小球
	m_posArray.Paint(dcMem);

	//画FPS
	m_fps.Paint(dcMem);


	//画到DC上
	dc.BitBlt(0, 0, rt.Width(), rt.Height(),
		&dcMem, 0, 0, SRCCOPY);


	//释放NULL_PEN
	dcMem.SelectObject(pPenNullOld);

	//释放内存位图
	dcMem.SelectObject(pBmpOld);


}

int CMyView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	SetTimer(1, m_DlgSettingParam.m_uiBallSpeed, 0);
	return 0;
}

void CMyView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_moveParam.ptBegin = point;
	m_moveParam.bLButtonDown = 1;
	if(CRect(m_barArray.m_ptBeginPos,
		CSize(m_barArray.m_uiWeight, m_barArray.m_uiHeight)
		).PtInRect(point))//在范围内
	{
		m_moveParam.iItem = ITEM_BAR;
		m_moveParam.ptInWnd = point - m_barArray.m_ptBeginPos;
	}

	else if(CRect(m_barGraph.m_ptBeginPos,
		CSize(m_barGraph.m_uiWidth, m_barGraph.m_ptBeginPos.y + 1000)//////////条型图不好确定范围 就用1000了
		).PtInRect(point))
	{
		m_moveParam.iItem = ITEM_GRAPH;
		m_moveParam.ptInWnd = point - m_barGraph.m_ptBeginPos;
	}

	else if(CRect(m_fps.m_ptBeginPos,
		CSize(110, 15)//////////FPS图不好确定范围 就用110, 15了
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
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_moveParam.bLButtonDown = 0;
	CView::OnLButtonUp(nFlags, point);
}

void CMyView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

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
	// TODO: 在此添加命令处理程序代码
	CDlgSetting dlg;









	//加载所有属性
	//棒色
	dlg.m_uiEditBarColorR = m_DlgSettingParam.m_uiEditBarColorR;
	dlg.m_uiEditBarColorG = m_DlgSettingParam.m_uiEditBarColorG;
	dlg.m_uiEditBarColorB = m_DlgSettingParam.m_uiEditBarColorB;

	//棒边框线条颜色
	dlg.m_uiEditBarFrameColorR = m_DlgSettingParam.m_uiEditBarFrameColorR;
	dlg.m_uiEditBarFrameColorG = m_DlgSettingParam.m_uiEditBarFrameColorG;
	dlg.m_uiEditBarFrameColorB = m_DlgSettingParam.m_uiEditBarFrameColorB;

	//棒线条类型
	dlg.m_iComboBarLineStyle = m_DlgSettingParam.m_iComboBarLineStyle;

	//棒线条宽度
	dlg.m_uiComboBarLineWidth = m_DlgSettingParam.m_uiComboBarLineWidth;


	//容器边框色
	dlg.m_uiEditBoxFrameColorR = m_DlgSettingParam.m_uiEditBoxFrameColorR;
	dlg.m_uiEditBoxFrameColorG = m_DlgSettingParam.m_uiEditBoxFrameColorG;
	dlg.m_uiEditBoxFrameColorB = m_DlgSettingParam.m_uiEditBoxFrameColorB;

	//容器边框线条类型
	dlg.m_iComboBoxLineStyle = m_DlgSettingParam.m_iComboBoxLineStyle;

	//容器线条宽度
	dlg.m_uiComboBoxLineWidth = m_DlgSettingParam.m_uiComboBoxLineWidth;


	//条形图边框色
	dlg.m_uiEditGraphFrameColorR = m_DlgSettingParam.m_uiEditGraphFrameColorR;
	dlg.m_uiEditGraphFrameColorG = m_DlgSettingParam.m_uiEditGraphFrameColorG;
	dlg.m_uiEditGraphFrameColorB = m_DlgSettingParam.m_uiEditGraphFrameColorB;

	//条形图色
	dlg.m_uiEditGraphColorR = m_DlgSettingParam.m_uiEditGraphColorR;
	dlg.m_uiEditGraphColorG = m_DlgSettingParam.m_uiEditGraphColorG;
	dlg.m_uiEditGraphColorB = m_DlgSettingParam.m_uiEditGraphColorB;

	//条形图字体色
	dlg.m_uiEditGraphTextColorR = m_DlgSettingParam.m_uiEditGraphTextColorR;
	dlg.m_uiEditGraphTextColorG = m_DlgSettingParam.m_uiEditGraphTextColorG;
	dlg.m_uiEditGraphTextColorB = m_DlgSettingParam.m_uiEditGraphTextColorB;

	//条形图边框线条类型
	dlg.m_iComboGraphLineStyle = m_DlgSettingParam.m_iComboGraphLineStyle;

	//条形图边框线条宽度
	dlg.m_iComboGraphLineWidth = m_DlgSettingParam.m_iComboGraphLineWidth;



	//FPS字体颜色
	dlg.m_uiFpsTextColorR = m_DlgSettingParam.m_uiFpsTextColorR;
	dlg.m_uiFpsTextColorG = m_DlgSettingParam.m_uiFpsTextColorG;
	dlg.m_uiFpsTextColorB = m_DlgSettingParam.m_uiFpsTextColorB;


	//球速
	dlg.m_uiBallSpeed = m_DlgSettingParam.m_uiBallSpeed;

	


	//棒数
	dlg.m_uiEditBarCount = m_DlgSettingParam.m_uiEditBarCount;

	//棒半径
	dlg.m_uiEditBarRadius = m_DlgSettingParam.m_uiEditBarRadius;








	if(dlg.DoModal() == IDOK)
	{

		//保存更改
		//棒色
		m_DlgSettingParam.m_uiEditBarColorR = dlg.m_uiEditBarColorR;
		m_DlgSettingParam.m_uiEditBarColorG = dlg.m_uiEditBarColorG;
		m_DlgSettingParam.m_uiEditBarColorB = dlg.m_uiEditBarColorB;

		//棒边框线条颜色
		m_DlgSettingParam.m_uiEditBarFrameColorR = dlg.m_uiEditBarFrameColorR;
		m_DlgSettingParam.m_uiEditBarFrameColorG = dlg.m_uiEditBarFrameColorG;
		m_DlgSettingParam.m_uiEditBarFrameColorB = dlg.m_uiEditBarFrameColorB;

		//棒线条类型
		m_DlgSettingParam.m_iComboBarLineStyle = dlg.m_iComboBarLineStyle;

		//棒线条宽度
		m_DlgSettingParam.m_uiComboBarLineWidth = dlg.m_uiComboBarLineWidth;


		//容器边框色
		m_DlgSettingParam.m_uiEditBoxFrameColorR = dlg.m_uiEditBoxFrameColorR;
		m_DlgSettingParam.m_uiEditBoxFrameColorG = dlg.m_uiEditBoxFrameColorG;
		m_DlgSettingParam.m_uiEditBoxFrameColorB = dlg.m_uiEditBoxFrameColorB;

		//容器边框线条类型
		m_DlgSettingParam.m_iComboBoxLineStyle = dlg.m_iComboBoxLineStyle;

		//容器线条宽度
		m_DlgSettingParam.m_uiComboBoxLineWidth = dlg.m_uiComboBoxLineWidth;


		//条形图边框色
		m_DlgSettingParam.m_uiEditGraphFrameColorR = dlg.m_uiEditGraphFrameColorR;
		m_DlgSettingParam.m_uiEditGraphFrameColorG = dlg.m_uiEditGraphFrameColorG;
		m_DlgSettingParam.m_uiEditGraphFrameColorB = dlg.m_uiEditGraphFrameColorB;

		//条形图色
		m_DlgSettingParam.m_uiEditGraphColorR = dlg.m_uiEditGraphColorR;
		m_DlgSettingParam.m_uiEditGraphColorG = dlg.m_uiEditGraphColorG;
		m_DlgSettingParam.m_uiEditGraphColorB = dlg.m_uiEditGraphColorB;

		//条形图字体色
		m_DlgSettingParam.m_uiEditGraphTextColorR = dlg.m_uiEditGraphTextColorR;
		m_DlgSettingParam.m_uiEditGraphTextColorG = dlg.m_uiEditGraphTextColorG;
		m_DlgSettingParam.m_uiEditGraphTextColorB = dlg.m_uiEditGraphTextColorB;

		//条形图边框线条类型
		m_DlgSettingParam.m_iComboGraphLineStyle = dlg.m_iComboGraphLineStyle;

		//条形图边框线条宽度
		m_DlgSettingParam.m_iComboGraphLineWidth = dlg.m_iComboGraphLineWidth;




		//FPS字体颜色
		m_DlgSettingParam.m_uiFpsTextColorR = dlg.m_uiFpsTextColorR;
		m_DlgSettingParam.m_uiFpsTextColorG = dlg.m_uiFpsTextColorG;
		m_DlgSettingParam.m_uiFpsTextColorB = dlg.m_uiFpsTextColorB;


		//球速 (在后面判断后修改)
	//	m_DlgSettingParam.m_uiBallSpeed = dlg.m_uiBallSpeed;

		


		//下面的修改因还需作为判断, 因此延迟在修改应用中被修改
		////棒数
		//m_DlgSettingParam.m_uiEditBarCount = dlg.m_uiEditBarCount;

		////棒半径
		//m_DlgSettingParam.m_uiEditBarRadius = dlg.m_uiEditBarRadius;




		/////////////////////////应用修改//////////////////////////////////////////


		//棒色 修改
		m_barArray.SetColor(RGB(
			m_DlgSettingParam.m_uiEditBarColorR,
			m_DlgSettingParam.m_uiEditBarColorG,
			m_DlgSettingParam.m_uiEditBarColorB));


		//棒边框线条颜色 修改
		//棒线条类型 修改
		//棒线条宽度 修改
		m_barArray.SetPen(m_DlgSettingParam.m_iComboBarLineStyle,
			m_DlgSettingParam.m_uiComboBarLineWidth, 
			RGB(m_DlgSettingParam.m_uiEditBarFrameColorR,
			m_DlgSettingParam.m_uiEditBarFrameColorG,
			m_DlgSettingParam.m_uiEditBarFrameColorB));


		//容器边框色 修改
		//容器边框线条类型 修改
		//容器线条宽度 修改
		m_barArrayFrame.SetPen(RGB(m_DlgSettingParam.m_uiEditBoxFrameColorR, 
			m_DlgSettingParam.m_uiEditBoxFrameColorG,
			m_DlgSettingParam.m_uiEditBoxFrameColorB),
			m_DlgSettingParam.m_uiComboBoxLineWidth,
			m_DlgSettingParam.m_iComboBoxLineStyle);


		//条形图边框色 修改
		//条形图色 修改
		//条形图字体色 修改
		//条形图边框线条类型 修改
		//条形图边框线条宽度 修改
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


		//FPS字体颜色
		m_fps.SetTextColor(RGB(m_DlgSettingParam.m_uiFpsTextColorR,
			m_DlgSettingParam.m_uiFpsTextColorG,
			m_DlgSettingParam.m_uiFpsTextColorB));


		if(m_DlgSettingParam.m_uiEditBarCount != dlg.m_uiEditBarCount)
		{
			//棒数
			m_DlgSettingParam.m_uiEditBarCount = dlg.m_uiEditBarCount;


			//棒数 修改
			//棒半径 修改
			m_barArray.SetBarMax(m_DlgSettingParam.m_uiEditBarCount);
		//	m_barArray.SetRadius(m_DlgSettingParam.m_uiEditBarRadius);
			m_posArray.InitFromArray(m_barArray);
			m_barArrayFrame.InitFromArray(m_barArray);
			m_barGraph.SetBarCount(m_DlgSettingParam.m_uiEditBarCount - 1);
		//	m_barGraph.SetBarWidth((m_DlgSettingParam.m_uiEditBarRadius) * 4);
		}
		if(m_DlgSettingParam.m_uiEditBarRadius != dlg.m_uiEditBarRadius)
		{
			//棒半径
			m_DlgSettingParam.m_uiEditBarRadius = dlg.m_uiEditBarRadius;


			//棒数 修改
			//棒半径 修改
		//	m_barArray.SetBarMax(m_DlgSettingParam.m_uiEditBarCount);
			m_barArray.SetRadius(m_DlgSettingParam.m_uiEditBarRadius);
			m_posArray.InitFromArray(m_barArray);
			m_barArrayFrame.InitFromArray(m_barArray);
		//	m_barGraph.SetBarCount(m_DlgSettingParam.m_uiEditBarCount - 1);
			m_barGraph.SetBarWidth((UINT)(m_DlgSettingParam.m_uiEditBarRadius * 4 * 0.9));
			m_barGraph.SetSpaceWidth((UINT)(m_DlgSettingParam.m_uiEditBarRadius * 4 * 0.1));
		}


		//小球速度修改
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
	// TODO: 在此添加命令处理程序代码
	m_fps.ReInit();//更新内部的时间
	SetTimer(1, m_DlgSettingParam.m_uiBallSpeed, 0);
}

void CMyView::OnPause()
{
	// TODO: 在此添加命令处理程序代码
	KillTimer(1);
}
