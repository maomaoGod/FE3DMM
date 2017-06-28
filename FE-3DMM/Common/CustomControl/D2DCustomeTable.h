#pragma once

#include <Windows.h>
#include <d2d1.h>
#include <dwrite.h>
#pragma comment(lib, "d2d1.lib")
#pragma comment(lib, "Dwrite.lib")
// CD2DCustomeTable

#define  CUSTOME_GUICTRL  _T("CustomeGui")
#define  ITEM_NORMAL      0x01
#define  ITEM_PUSHUED     0x02
#define  ITEM_DISABLED    0x04
#define  ITEM_HOVERED     0x08


template<class Interface>
inline void SafeRelease( Interface **ppInterfaceToRelease)
{
	if (*ppInterfaceToRelease != NULL)
	{
		(*ppInterfaceToRelease)->Release();

		(*ppInterfaceToRelease) = NULL;
	}
}

class CD2DItem
{
     //private members:
private:
	UINT m_uItemIndex;
	UINT m_uItemState;
	D2D1_COLOR_F m_CurrentColor;
	CString m_ItemName;
	POINT pt[4];
	//public members
public:

	//private member funcs
private:

	//public member funcs
public:
	CD2DItem()
	{
		m_CurrentColor = D2D1::ColorF(0, 0, 0, 1.0);
		m_uItemIndex = 0;
		m_uItemState = ITEM_NORMAL;
		m_ItemName = _T("");
		memset(pt, 0, sizeof(POINT) * 4);
	}
	~CD2DItem()
	{

	}

	CD2DItem(const CD2DItem& d2dItem)
	{
		m_uItemIndex = d2dItem.GetItemIndex();
		m_uItemState = d2dItem.GetItemState();
		m_CurrentColor = d2dItem.GetItemColor();
		m_ItemName = d2dItem.GetItemName();
		SetItemCoordinate(d2dItem.GetItemCoordinate());
	}

	CD2DItem& operator=(const CD2DItem& d2dItem) 
	{
		if (this == &d2dItem)
			return *this;

		m_uItemIndex = d2dItem.GetItemIndex();
		m_uItemState = d2dItem.GetItemState();
		m_CurrentColor = d2dItem.GetItemColor();
		m_ItemName = d2dItem.GetItemName();
		SetItemCoordinate(d2dItem.GetItemCoordinate());
		return *this;
	}

	void SetItemState(UINT state)
	{
		m_uItemState = state;
	}

	void SetItemCurrentColor(D2D1_COLOR_F color)
	{
		m_CurrentColor = color;
	}
	void SetItemIndex(UINT index)
	{
		m_uItemIndex = index;
	}
	void SetItemName(CString itemName)
	{
		m_ItemName = itemName;
	}
	void SetItemCoordinate(POINT temp[4])
	{
		for (int i = 0; i < 4; i++)
		{
			pt[i].x = temp[i].x;
			pt[i].y = temp[i].y;
		}
	}


	UINT GetItemState() const
	{
		return m_uItemState;
	}

	UINT GetItemIndex() const
	{
		return m_uItemIndex;
	}

	D2D1_COLOR_F GetItemColor() const
	{
		return m_CurrentColor;
	}
	POINT * GetItemCoordinate() const
	{
		return (POINT*)pt;
	}
	CString GetItemName() const
	{
		return m_ItemName;
	}

};

class CD2DCustomeTable : public CWnd
{
	DECLARE_DYNAMIC(CD2DCustomeTable)

public:
	CD2DCustomeTable();
	virtual ~CD2DCustomeTable();
	
private:
	HRESULT CreateDevIndependentResource();
	HRESULT ReleaseDevIndependentResource();
	HRESULT CreateDevDependentResource();
	HRESULT ReleaseDevDependentResource();

	BOOL RegisterButtonClass();
	BOOL InitializeButtonPos();
	BOOL ResizeButtonPos();
	BOOL CheckMouseMove(CPoint &pt, UINT &uIndex);
	LRESULT SendMessageToParent(UINT nIndex,int nMessage) const;
	void DrawCustomeButton();
	BOOL InitializeGradientBrush();
	BOOL ChangeGradientBrush();
public:
	BOOL  Create(CWnd *pParentWnd, const RECT &rect, UINT nID, DWORD dwStyle= WS_VISIBLE);
	void  InitializeButtonSize(const UINT &nButton)
	{
		nButtonCount = nButton;
	}
	BOOL  InitializeButtonName(CStringArray &nameArray, int nCount = 4);
private:

	//DevIndepedent
	ID2D1Factory * m_pD2dFactory;
	IDWriteFactory *m_pWriteFactory;
	CMap<UINT, UINT, ID2D1PathGeometry*, ID2D1PathGeometry*> m_ButtonMap;

	//DevDependent
	ID2D1HwndRenderTarget* m_pD2dRenderTarget;
	CMap<UINT, UINT, ID2D1RadialGradientBrush*, ID2D1RadialGradientBrush*> m_NormalRadicalGradientBrushMap;
	CMap<UINT, UINT, ID2D1RadialGradientBrush*, ID2D1RadialGradientBrush*> m_HoverRadicalGradientBrushMap;
	CMap<UINT, UINT, ID2D1RadialGradientBrush*, ID2D1RadialGradientBrush*> m_PushedRadicalGradientBrushMap;
	ID2D1SolidColorBrush *m_pSolidNormalBrush;
	ID2D1SolidColorBrush *m_pSolidHoverBrush;
	ID2D1SolidColorBrush *m_pSolidPushBrush;

	IDWriteTextFormat *m_pWriteTextFormat;
	CMap<UINT, UINT, CD2DItem*, CD2DItem*> m_ItemMap;
	bool m_bInitSucceed;
	UINT nButtonCount;
	bool m_bTracking;
	int m_LeftButtonDownIndex;
protected:
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPaint();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

	afx_msg void OnMouseLeave();
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnCaptureChanged(CWnd *pWnd);
};


