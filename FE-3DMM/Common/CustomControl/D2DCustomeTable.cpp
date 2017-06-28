// D2DButton.cpp : 实现文件
//

#include "stdafx.h"
#include "D2DCustomeTable.h"
#include <math.h>

// CD2DCustomeTable

IMPLEMENT_DYNAMIC(CD2DCustomeTable, CWnd)

	CD2DCustomeTable::CD2DCustomeTable() :m_pD2dFactory(NULL), m_pD2dRenderTarget(NULL)
{
	RegisterButtonClass();

	m_bInitSucceed = false;
	nButtonCount = 4;
	m_bTracking = false;
	m_LeftButtonDownIndex = -1;
	CreateDevIndependentResource();
}

CD2DCustomeTable::~CD2DCustomeTable()
{
	ReleaseDevDependentResource();
	ReleaseDevIndependentResource();
}


BEGIN_MESSAGE_MAP(CD2DCustomeTable, CWnd)
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_CREATE()
	ON_WM_MOUSELEAVE()
	ON_WM_KILLFOCUS()
	ON_WM_CAPTURECHANGED()
END_MESSAGE_MAP()



// CD2DCustomeTable 消息处理程序

HRESULT CD2DCustomeTable::CreateDevIndependentResource()
{
	HRESULT hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &m_pD2dFactory);
	hr = DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED,
		__uuidof(IDWriteFactory),
		reinterpret_cast<IUnknown**>(&m_pWriteFactory)
		);


	hr = m_pWriteFactory->CreateTextFormat(L"楷体",NULL,DWRITE_FONT_WEIGHT_EXTRA_BOLD,
		DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, 17.0, L"en_chs", &m_pWriteTextFormat);

	hr = m_pWriteTextFormat->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
	hr = m_pWriteTextFormat->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);
	return hr;
}

HRESULT CD2DCustomeTable::CreateDevDependentResource()
{
	HRESULT hr = S_OK;
	if (!m_pD2dRenderTarget)
	{
		CRect rect;
		GetClientRect(&rect);
		hr = m_pD2dFactory->CreateHwndRenderTarget(D2D1::RenderTargetProperties(), D2D1::HwndRenderTargetProperties(GetSafeHwnd(), D2D1::SizeU(rect.Width(), rect.Height())), &m_pD2dRenderTarget);

		if (SUCCEEDED(hr))
		{
			hr = m_pD2dRenderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::DodgerBlue), &m_pSolidNormalBrush);
			hr = m_pD2dRenderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Yellow), &m_pSolidHoverBrush);
			hr = m_pD2dRenderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::GhostWhite), &m_pSolidPushBrush);

		}

		InitializeGradientBrush();
	}

	return hr;
}

void CD2DCustomeTable::OnPaint()
{
	if (!IsIconic())
	{
		DrawCustomeButton();

		ValidateRect(NULL);
	}

	CWnd::OnPaint();
}

BOOL CD2DCustomeTable::Create(CWnd* pParentWnd, const RECT &rect, UINT nID, DWORD dwStyle)
{
	dwStyle |= WS_CHILDWINDOW;
	BOOL nResult = CWnd::Create(CUSTOME_GUICTRL, NULL, dwStyle, rect, pParentWnd, nID);

	return nResult;
}

BOOL CD2DCustomeTable::RegisterButtonClass()
{
	WNDCLASS wndcls;
	HINSTANCE hInst = AfxGetInstanceHandle();

	if (!(::GetClassInfo(hInst, CUSTOME_GUICTRL, &wndcls)))
	{
		memset(&wndcls, 0, sizeof(WNDCLASS));

		wndcls.hInstance = hInst;
		wndcls.lpfnWndProc = ::DefWindowProc;
		wndcls.hCursor = NULL; //LoadCursor(NULL, IDC_ARROW);
		wndcls.hIcon = 0;
		wndcls.lpszMenuName = NULL;
		wndcls.hbrBackground = (HBRUSH) ::GetStockObject(WHITE_BRUSH);
		wndcls.style = CS_DBLCLKS;
		wndcls.cbClsExtra = 0;
		wndcls.cbWndExtra = 0;
		wndcls.lpszClassName = CUSTOME_GUICTRL;

		if (!RegisterClass(&wndcls))
		{
			//  AfxThrowResourceException();
			return FALSE;
		}
	}

	return TRUE;
}

void CD2DCustomeTable::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);

	// TODO:  在此处添加消息处理程序代码

	//m_bTracking = false;
	if (m_pD2dRenderTarget)
	{
		CRect rect;
		GetClientRect(&rect);

		HRESULT hr = m_pD2dRenderTarget->Resize(D2D1::SizeU(cx, cy));

		ResizeButtonPos();

		ChangeGradientBrush();
		m_pD2dRenderTarget->BeginDraw();

		m_pD2dRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::MidnightBlue));

		ID2D1PathGeometry * pTempGeometry = NULL;
		for (UINT i = 0; i < nButtonCount; i++)
		{
			m_ButtonMap.Lookup(i, pTempGeometry);
			m_pD2dRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
			m_pD2dRenderTarget->DrawGeometry(pTempGeometry, m_pSolidNormalBrush);

		}

		m_pD2dRenderTarget->EndDraw();
	}


}


BOOL CD2DCustomeTable::CheckMouseMove(CPoint &pt, UINT &uIndex)
{
	BOOL bResult = FALSE;
	BOOL bContainPoint = FALSE;

	for (int i = 0; i < m_ButtonMap.GetCount(); i++)
	{
		ID2D1PathGeometry *pTempGeometry = NULL;
		m_ButtonMap.Lookup(i, pTempGeometry);
		HRESULT hr = pTempGeometry->FillContainsPoint(D2D1::Point2F(static_cast<FLOAT>(pt.x), static_cast<FLOAT>(pt.y)), D2D1::Matrix3x2F(1,0,0,1,0,0), &bContainPoint);
		//bContainPoint = PtInRegion(m_pRgn[i], pt.x, pt.y);
		if (SUCCEEDED(hr))
		{
			if (bContainPoint)
			{
				bResult = TRUE;
				uIndex = i;

				return bResult;
			}

		}
	}

	return bResult;
}


void CD2DCustomeTable::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	BOOL bContainPoint = FALSE;
	UINT nIndex = 0;


	FLOAT dpiX, dpiY;
	m_pD2dFactory->GetDesktopDpi(&dpiX, &dpiY);
	point.x = static_cast<LONG>(point.x * 96 / dpiX);
	point.y = static_cast<LONG>(point.y * 96 / dpiY);

	bContainPoint = CheckMouseMove(point, nIndex);
	if (bContainPoint)
	{
		ID2D1PathGeometry * pTempGeometry = NULL;
		CD2DItem *pTempItem = NULL;
		for (int i = 0; i < m_ButtonMap.GetCount(); i++)
		{
			m_ItemMap.Lookup(i, pTempItem);
			UINT uMask = pTempItem->GetItemState();
			if (uMask&ITEM_HOVERED)
			{
				if (i == nIndex)
				{
					//return;
				}
				else
				{
					pTempItem->SetItemState(ITEM_NORMAL);
				}
			}
			else if (uMask&ITEM_NORMAL)
			{
				if (i == nIndex)
				{
					pTempItem->SetItemState(ITEM_HOVERED);
				}
			}
			else if (uMask&ITEM_PUSHUED)
			{
				//do nothing
			}
			else //disabled
			{
				//do nothing
			}

		}

		DrawCustomeButton();

	}
	else
	{
		CD2DItem *pTempItem = NULL;
		for (int i = 0; i < m_ButtonMap.GetCount(); i++)
		{
			m_ItemMap.Lookup(i, pTempItem);
			UINT uMask = pTempItem->GetItemState();
			if (uMask&ITEM_HOVERED)
			{
				pTempItem->SetItemState(ITEM_NORMAL);

			}
			else if (uMask&ITEM_NORMAL)
			{
			}
			else if (uMask&ITEM_PUSHUED)
			{
				//do nothing
			}
			else //disabled
			{
				//do nothing
			}

		}

		DrawCustomeButton();
	}

	if (!m_bTracking)
	{
		TRACKMOUSEEVENT tme;
		tme.cbSize = sizeof(tme);
		tme.hwndTrack = m_hWnd;
		tme.dwFlags = TME_LEAVE | TME_HOVER;
		tme.dwHoverTime = 1;
		m_bTracking = _TrackMouseEvent(&tme)?true:false;
	}
	CWnd::OnMouseMove(nFlags, point);
}


void CD2DCustomeTable::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	BOOL bContainPoint = FALSE;
	UINT nIndex = 0;


	FLOAT dpiX, dpiY;
	m_pD2dFactory->GetDesktopDpi(&dpiX, &dpiY);
	point.x = static_cast<LONG>(point.x * 96 / dpiX);
	point.y = static_cast<LONG>(point.y * 96 / dpiY);

	bContainPoint = CheckMouseMove(point, nIndex);
	if (bContainPoint)
	{
		m_LeftButtonDownIndex = nIndex;
	}
	else
	{
		m_LeftButtonDownIndex = -1;
	}

	CWnd::OnLButtonDown(nFlags, point);
}

void CD2DCustomeTable::OnLButtonUp(UINT nFlags, CPoint point)
{
	BOOL bContainPoint = FALSE;
	UINT nIndex = 0;


	FLOAT dpiX, dpiY;
	m_pD2dFactory->GetDesktopDpi(&dpiX, &dpiY);
	point.x = static_cast<LONG>(point.x * 96 / dpiX);
	point.y = static_cast<LONG>(point.y * 96 / dpiY);

	bContainPoint = CheckMouseMove(point, nIndex);
	if (bContainPoint && (nIndex == m_LeftButtonDownIndex))
	{
		//Draw Button State
		CD2DItem *pTempItem = NULL;
		for (int i = 0; i < m_ButtonMap.GetCount(); i++)
		{
			m_ItemMap.Lookup(i, pTempItem);
			UINT uMask = pTempItem->GetItemState();
			if (uMask&ITEM_HOVERED)
			{
				if (i == nIndex)
				{
					pTempItem->SetItemState(ITEM_PUSHUED);
				}
				else
				{
					pTempItem->SetItemState(ITEM_NORMAL);
				}
			}
			else if (uMask&ITEM_NORMAL)
			{
				if (i == nIndex)
				{
					pTempItem->SetItemState(ITEM_PUSHUED);
				}
			}
			else if (uMask&ITEM_PUSHUED)
			{
				if (i == nIndex)
				{

				}
				else
				{
					pTempItem->SetItemState(ITEM_NORMAL);
				}
			}
			else //disabled
			{
				//do nothing
			}

		}

		DrawCustomeButton();

		SendMessageToParent(nIndex, NM_CLICK);
	}
	else
	{

	}

}


BOOL CD2DCustomeTable::InitializeButtonPos()
{
	CRect rect;
	GetWindowRect(&rect);
	ScreenToClient(&rect);

	FLOAT dpiX, dpiY;
	m_pD2dFactory->GetDesktopDpi(&dpiX, &dpiY);

	int nWidth = static_cast<int>(rect.Width()*96/dpiX);
	int nHeight = static_cast<int>(rect.Height()*96/dpiY);

	int nWidthPerButton = nWidth / (nButtonCount+1);

	int nStartPos = nWidthPerButton / 3*2;
	ID2D1PathGeometry *pTempGeometry = NULL;
	CD2DItem * pTempItem = NULL;
	for (UINT n = 1; n <= nButtonCount; n++)
	{
		ID2D1GeometrySink *pTempSink = NULL;
		HRESULT hr = S_FALSE;
		if (NULL != m_pD2dFactory)
		{
			hr = m_pD2dFactory->CreatePathGeometry(&pTempGeometry);
			if (SUCCEEDED(hr))
			{
				m_ButtonMap.SetAt(n-1, pTempGeometry);

				hr = pTempGeometry->Open(&pTempSink);
				if (SUCCEEDED(hr))
				{
					pTempSink->SetFillMode(D2D1_FILL_MODE_WINDING);
					pTempSink->BeginFigure(D2D1::Point2F(static_cast<FLOAT>(rect.left+nStartPos+nWidthPerButton*(n-1)), 0.0f), D2D1_FIGURE_BEGIN_FILLED);

					D2D1_POINT_2F points[3] = {
						D2D1::Point2F(static_cast<FLOAT>(rect.left+nStartPos+nWidthPerButton*n), 0.0f),
						D2D1::Point2F(static_cast<FLOAT>(rect.left+nWidthPerButton-nStartPos + nWidthPerButton*n),static_cast<FLOAT>(nHeight)),
						D2D1::Point2F(static_cast<FLOAT>(rect.left+nWidthPerButton - nStartPos + nWidthPerButton*(n-1)),static_cast<FLOAT>( nHeight))
					};

					pTempItem = new CD2DItem();
					if (NULL != pTempItem)
					{
						POINT pt[4];
						pt[0].x = rect.left + nStartPos + nWidthPerButton*(n - 1), pt[0].y = 0;
						pt[1].x = rect.left + nStartPos + nWidthPerButton*n, pt[1].y = 0;
						pt[2].x = rect.left + nWidthPerButton - nStartPos + nWidthPerButton*n, pt[2].y = nHeight;
						pt[3].x = rect.left + nWidthPerButton - nStartPos + nWidthPerButton*(n - 1), pt[3].y = nHeight;

						pTempItem->SetItemCoordinate(pt);
						pTempItem->SetItemIndex(n - 1);
						if(n == 1)
							pTempItem->SetItemState(ITEM_PUSHUED);
						else
							pTempItem->SetItemState(ITEM_NORMAL);
						m_ItemMap.SetAt(n - 1, pTempItem);
					}

					pTempSink->AddLines(points, 3);

					pTempSink->EndFigure(D2D1_FIGURE_END_CLOSED);

					hr = pTempSink->Close();

					SafeRelease(&pTempSink);
				}		
			}
		}
	}

	return TRUE;
}

BOOL CD2DCustomeTable::ResizeButtonPos()
{
	CRect rect;
	GetWindowRect(&rect);
	ScreenToClient(&rect);

	FLOAT dpiX, dpiY;
	m_pD2dFactory->GetDesktopDpi(&dpiX, &dpiY);

	int nWidth = static_cast<int>(rect.Width() * 96 / dpiX);
	int nHeight = static_cast<int>(rect.Height() * 96 / dpiY);


	int nWidthPerButton = nWidth / (nButtonCount + 1);

	int nStartPos = nWidthPerButton / 3 * 2;
	ID2D1PathGeometry *pTempGeometry = NULL;

	for (int i = 0; i < m_ButtonMap.GetCount(); i++)
	{
		m_ButtonMap.Lookup(i, pTempGeometry);
		if (NULL != pTempGeometry)
			SafeRelease(&pTempGeometry);
	}

	CD2DItem *pTempItem = NULL;

	for (UINT n = 1; n <= nButtonCount; n++)
	{
		ID2D1GeometrySink *pTempSink = NULL;
		HRESULT hr = S_FALSE;
		if (NULL != m_pD2dFactory)
		{
			hr = m_pD2dFactory->CreatePathGeometry(&pTempGeometry);
			if (SUCCEEDED(hr))
			{
				m_ButtonMap.SetAt(n - 1, pTempGeometry);

				hr = pTempGeometry->Open(&pTempSink);
				if (SUCCEEDED(hr))
				{
					pTempSink->SetFillMode(D2D1_FILL_MODE_WINDING);
					pTempSink->BeginFigure(D2D1::Point2F(static_cast<FLOAT>(nStartPos + nWidthPerButton*(n - 1)), 0.0f), D2D1_FIGURE_BEGIN_FILLED);

					D2D1_POINT_2F points[3] = {
						D2D1::Point2F(static_cast<FLOAT>(nStartPos + nWidthPerButton*n), 0.0f),
						D2D1::Point2F(static_cast<FLOAT>(nWidthPerButton - nStartPos + nWidthPerButton*n), static_cast<FLOAT>(nHeight)),
						D2D1::Point2F(static_cast<FLOAT>(nWidthPerButton - nStartPos + nWidthPerButton*(n - 1)), static_cast<FLOAT>(nHeight))
					};

					m_ItemMap.Lookup(n - 1, pTempItem);
					if (NULL != pTempItem)
					{
						POINT pt[4];
						pt[0].x = nStartPos + nWidthPerButton*(n - 1), pt[0].y = 0;
						pt[1].x = nStartPos + nWidthPerButton*n, pt[1].y = 0;
						pt[2].x = nWidthPerButton - nStartPos + nWidthPerButton*n, pt[2].y = nHeight;
						pt[3].x = nWidthPerButton - nStartPos + nWidthPerButton*(n - 1), pt[3].y = nHeight;

						pTempItem->SetItemCoordinate(pt);
					}

					pTempSink->AddLines(points, 3);

					pTempSink->EndFigure(D2D1_FIGURE_END_CLOSED);

					hr = pTempSink->Close();

					SafeRelease(&pTempSink);
				}

			}
		}
	}

	return TRUE;
}

int CD2DCustomeTable::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	InitializeButtonPos();
	//InitializeGradientBrush();
	CreateDevDependentResource();
	Invalidate();

	return 0;
}


void CD2DCustomeTable::OnMouseLeave()
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	CD2DItem *pTempItem = NULL;
	UINT uMask = 0;
	for (UINT i = 0; i < nButtonCount; i++)
	{
		m_ItemMap.Lookup(i, pTempItem);
		uMask = pTempItem->GetItemState();
		switch (uMask)
		{
		case ITEM_HOVERED:
			pTempItem->SetItemState(ITEM_NORMAL);
			break;
		case ITEM_NORMAL:
			break;
		case ITEM_PUSHUED:
			break;
		case ITEM_DISABLED:
			break;
		}
	}

	m_bTracking = false;

	DrawCustomeButton();
	CWnd::OnMouseLeave();
}


void CD2DCustomeTable::OnKillFocus(CWnd* pNewWnd)
{
	CWnd::OnKillFocus(pNewWnd);

	// TODO:  在此处添加消息处理程序代码
}


void CD2DCustomeTable::OnCaptureChanged(CWnd *pWnd)
{
	// TODO:  在此处添加消息处理程序代码

	CWnd::OnCaptureChanged(pWnd);
}


LRESULT CD2DCustomeTable::SendMessageToParent(UINT nIndex, int nMessage) const
{
	if (!IsWindow(m_hWnd))
		return 0;
	TBNOTIFY tbNotify;
	tbNotify.hdr.code = nMessage;
	tbNotify.hdr.hwndFrom = m_hWnd;
	tbNotify.hdr.idFrom = GetDlgCtrlID();
	tbNotify.iItem = nIndex;


	NMHDR nmhdr;
	nmhdr.code = nMessage;
	nmhdr.hwndFrom = m_hWnd;
	nmhdr.idFrom = GetDlgCtrlID();


	CWnd *pOwner = GetParent();
	if (pOwner && pOwner->m_hWnd)
		return pOwner->SendMessage(WM_NOTIFY, (WPARAM)tbNotify.hdr.idFrom, (LPARAM)&tbNotify);
	else
		return 0;
}

void CD2DCustomeTable::DrawCustomeButton()
{
	CD2DItem * pTempItem = NULL;
	ID2D1PathGeometry *pTempGeometry = NULL;
	ID2D1RadialGradientBrush *pTempRadicalBrush = NULL;
	D2D1_RECT_F textLayoutRect;
	POINT *pTempPoint;
	m_pD2dRenderTarget->BeginDraw();

	m_pD2dRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::SteelBlue/*MidnightBlue*/));
	for (UINT i = 0; i < nButtonCount; i++)
	{
		m_ItemMap.Lookup(i, pTempItem);
		m_ButtonMap.Lookup(i, pTempGeometry);
		if (pTempItem->GetItemState()&ITEM_NORMAL)
		{
			m_pD2dRenderTarget->DrawGeometry(pTempGeometry, m_pSolidNormalBrush);
		}
		else if (pTempItem->GetItemState()&ITEM_HOVERED)
		{
			m_HoverRadicalGradientBrushMap.Lookup(i, pTempRadicalBrush);
			m_pD2dRenderTarget->FillGeometry(pTempGeometry, pTempRadicalBrush);
		}
		else if (pTempItem->GetItemState()&ITEM_PUSHUED)
		{
			m_PushedRadicalGradientBrushMap.Lookup(i, pTempRadicalBrush);
			m_pD2dRenderTarget->FillGeometry(pTempGeometry, pTempRadicalBrush);
		}
		else //Disabled
		{

		}
		pTempRadicalBrush = NULL;

		pTempPoint = pTempItem->GetItemCoordinate();
		textLayoutRect.left = static_cast<FLOAT>(pTempPoint[0].x);
		textLayoutRect.right = static_cast<FLOAT>(pTempPoint[2].x);
		textLayoutRect.top = static_cast<FLOAT>(pTempPoint[1].y);
		textLayoutRect.bottom = static_cast<FLOAT>(pTempPoint[2].y);

		USES_CONVERSION;

		m_pD2dRenderTarget->DrawText(A2CW((LPCSTR)(pTempItem->GetItemName())), pTempItem->GetItemName().GetLength()/2, m_pWriteTextFormat, textLayoutRect, m_pSolidHoverBrush);
	}

	m_pD2dRenderTarget->EndDraw();
}

BOOL CD2DCustomeTable::InitializeGradientBrush()
{
	BOOL bResult = FALSE;
	ID2D1RadialGradientBrush *pTempBrush = NULL;
	ID2D1GradientStopCollection *pGradientNormalCollection = NULL;
	ID2D1GradientStopCollection *pGradientHoverCollectionn = NULL;
	ID2D1GradientStopCollection *pGradientPushedCollection = NULL;
	CD2DItem *pTempItem = NULL;
	POINT *pTempPoint = NULL;
	POINT startPoint;
	float radius = 0.0f;
	D2D1_GRADIENT_STOP normalGradientStops[4];
	D2D1_GRADIENT_STOP hoverGradientStops[4];
	D2D1_GRADIENT_STOP pushedGradientStops[4];

	normalGradientStops[0].color = D2D1::ColorF(D2D1::ColorF::BlanchedAlmond, 0.5f);
	normalGradientStops[0].position = 0.0f;
	normalGradientStops[1].color = D2D1::ColorF(D2D1::ColorF::Orange, 0.7f);
	normalGradientStops[1].position = 0.4f;
	normalGradientStops[2].color = D2D1::ColorF(D2D1::ColorF::PowderBlue, 0.8f);
	normalGradientStops[2].position = 0.7f;
	normalGradientStops[3].color = D2D1::ColorF(D2D1::ColorF::DeepSkyBlue, 1.0f);
	normalGradientStops[3].position = 1.0f;

	hoverGradientStops[0].color = D2D1::ColorF(D2D1::ColorF::DeepPink, 1.0f);
	hoverGradientStops[0].position = 0.0f;
	hoverGradientStops[1].color = D2D1::ColorF(D2D1::ColorF::Magenta, 0.8f);
	hoverGradientStops[1].position = 0.2f;
	hoverGradientStops[2].color = D2D1::ColorF(D2D1::ColorF::SlateBlue, 0.7f);
	hoverGradientStops[2].position = 0.6f;
	hoverGradientStops[3].color = D2D1::ColorF(D2D1::ColorF::MidnightBlue, 0.3f);
	hoverGradientStops[3].position = 1.0f;

	pushedGradientStops[0].color = D2D1::ColorF(D2D1::ColorF::Blue, 1.0f);
	pushedGradientStops[0].position = 0.0f;
	pushedGradientStops[1].color = D2D1::ColorF(D2D1::ColorF::DeepSkyBlue, 0.8f);
	pushedGradientStops[1].position = 0.4f;
	pushedGradientStops[2].color = D2D1::ColorF(D2D1::ColorF::DodgerBlue, 0.7f);
	pushedGradientStops[2].position = 0.7f;
	pushedGradientStops[3].color = D2D1::ColorF(D2D1::ColorF::MidnightBlue, 0.5f);
	pushedGradientStops[3].position = 1.0f;

	HRESULT hr = S_FALSE;
	hr = m_pD2dRenderTarget->CreateGradientStopCollection(normalGradientStops, 4, D2D1_GAMMA_2_2,
		D2D1_EXTEND_MODE_CLAMP, &pGradientNormalCollection);
	hr = m_pD2dRenderTarget->CreateGradientStopCollection(hoverGradientStops, 4, D2D1_GAMMA_1_0,
		D2D1_EXTEND_MODE_CLAMP, &pGradientHoverCollectionn);
	hr = m_pD2dRenderTarget->CreateGradientStopCollection(pushedGradientStops, 4, D2D1_GAMMA_2_2,
		D2D1_EXTEND_MODE_CLAMP, &pGradientPushedCollection);

	if (SUCCEEDED(hr))
	{
		for (UINT i = 0; i < nButtonCount; i++)
		{
			m_ItemMap.Lookup(i, pTempItem);
			pTempPoint = pTempItem->GetItemCoordinate();
			startPoint.x = (pTempPoint[1].x + pTempPoint[3].x) / 2;
			startPoint.y = (pTempPoint[1].y + pTempPoint[3].y) / 2;

			radius = sqrtf(pow(static_cast<float>((startPoint.x - pTempPoint[1].x)), 2) + pow(static_cast<float>((startPoint.y - pTempPoint[1].y)), 2));

			hr = m_pD2dRenderTarget->CreateRadialGradientBrush(
				D2D1::RadialGradientBrushProperties(
				D2D1::Point2F(static_cast<FLOAT>(startPoint.x), static_cast<FLOAT>(startPoint.y)), D2D1::Point2F(0.0f, 0.0f), radius, radius),
				pGradientNormalCollection, &pTempBrush);

			m_NormalRadicalGradientBrushMap.SetAt(i, pTempBrush);

			pTempBrush = NULL;
			hr = m_pD2dRenderTarget->CreateRadialGradientBrush(
				D2D1::RadialGradientBrushProperties(
				D2D1::Point2F(static_cast<FLOAT>(startPoint.x), static_cast<FLOAT>(startPoint.y)), D2D1::Point2F(0.0f, 0.0f), radius, radius),
				pGradientHoverCollectionn, &pTempBrush);
			m_HoverRadicalGradientBrushMap.SetAt(i, pTempBrush);

			pTempBrush = NULL;
			hr = m_pD2dRenderTarget->CreateRadialGradientBrush(
				D2D1::RadialGradientBrushProperties(
				D2D1::Point2F(static_cast<FLOAT>(startPoint.x), static_cast<FLOAT>(startPoint.y)), D2D1::Point2F(0.0f, 0.0f), radius, radius),
				pGradientPushedCollection, &pTempBrush);
			m_PushedRadicalGradientBrushMap.SetAt(i, pTempBrush);

			pTempBrush = NULL;
		}

		bResult = TRUE;
	}


	return bResult;
}

BOOL CD2DCustomeTable::ChangeGradientBrush()
{

	ID2D1RadialGradientBrush *pTempBrush = NULL;
	for (UINT i = 0; i < nButtonCount; i++)
	{
		m_NormalRadicalGradientBrushMap.Lookup(i, pTempBrush);
		SafeRelease(&pTempBrush);
		m_HoverRadicalGradientBrushMap.Lookup(i, pTempBrush);
		SafeRelease(&pTempBrush);
		m_PushedRadicalGradientBrushMap.Lookup(i, pTempBrush);
		SafeRelease(&pTempBrush);
	}

	InitializeGradientBrush();

	return TRUE;
}

BOOL CD2DCustomeTable::InitializeButtonName(CStringArray &nameArray, int nCount /* = 4 */)
{
	CD2DItem *pTempItem = NULL;
	for (UINT i = 0; i < nButtonCount; i++)
	{
		m_ItemMap.Lookup(i, pTempItem);
		pTempItem->SetItemName(nameArray.GetAt(i));
	}

	return TRUE;
}

HRESULT CD2DCustomeTable::ReleaseDevIndependentResource()
{
	SafeRelease(&m_pD2dFactory);
	SafeRelease(&m_pWriteFactory);

	ID2D1PathGeometry *tempPath = NULL;
	for (int i = 0; i < m_ButtonMap.GetCount(); i++)
	{
		m_ButtonMap.Lookup(i, tempPath);

		SafeRelease(&tempPath);
	}

	m_ButtonMap.RemoveAll();

	return 0;
}

HRESULT CD2DCustomeTable::ReleaseDevDependentResource()
{
	SafeRelease(&m_pD2dRenderTarget);
	SafeRelease(&m_pSolidNormalBrush);
	SafeRelease(&m_pSolidHoverBrush);
	SafeRelease(&m_pSolidPushBrush);

	ID2D1RadialGradientBrush* pTempBrush = NULL;
	for (int i = 0; i < m_NormalRadicalGradientBrushMap.GetCount(); i++)
	{
		m_NormalRadicalGradientBrushMap.Lookup(i, pTempBrush);
		SafeRelease(&pTempBrush);
	}

	m_NormalRadicalGradientBrushMap.RemoveAll();

	for (int i = 0; i < m_HoverRadicalGradientBrushMap.GetCount(); i++)
	{
		m_HoverRadicalGradientBrushMap.Lookup(i, pTempBrush);
		SafeRelease(&pTempBrush);
	}
	m_NormalRadicalGradientBrushMap.RemoveAll();

	for (int i = 0; i < m_PushedRadicalGradientBrushMap.GetCount(); i++)
	{
		m_PushedRadicalGradientBrushMap.Lookup(i, pTempBrush);
		SafeRelease(&pTempBrush);
	}
	m_PushedRadicalGradientBrushMap.RemoveAll();

	CD2DItem *pTempItem = NULL;
	for (int i = 0; i < m_ItemMap.GetCount(); i++)
	{
		m_ItemMap.Lookup(i, pTempItem);
		if (NULL != pTempItem)
		{
			delete pTempItem;
			pTempItem = NULL;
		}
	}

	return 0;
}