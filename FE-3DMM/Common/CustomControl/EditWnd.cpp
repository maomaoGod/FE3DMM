// EditWnd.cpp : implementation file
// Download by http://www.codefans.net

#include "stdafx.h"
#include "EditWnd.h"


/////////////////////////////////////////////////////////////////////////////
// CEditWnd
const int nMargin = 50;
#define SHIFTED 0x8000

CEditWnd::CEditWnd()
{
	m_ptCursor.y = m_ptTxtBegin.y = 0;
	m_ptTxtBegin.x = m_ptCursor.x = nMargin;
	m_strEdit = "";
	m_strSelect = "";
	m_nCharPos = 0;
	m_nShowChar = 0;
	m_nMaxShowChars = 0;
	m_nSelectBegin = 0;	
	m_nSelectEnd = 0;
	m_bLBtDown = false;
	m_ptFirst.x = m_ptFirst.y = 0;//m_ptSecond.x = m_ptSecond.y = 0;
	::memset(&m_tm, 0, sizeof(TEXTMETRIC));
	m_TxtFont.CreateFont( 14, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, OUT_TT_PRECIS, 
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, VARIABLE_PITCH | FF_SWISS,
		"宋体" );
	m_nShiftBegin = -1;
	m_iState = 0;
	m_bBkneedchange = 0;
	m_bkcolor0.clrBegin = RGB(148, 182, 225);
	m_bkcolor0.clrEnd = RGB(46, 74, 137);		// 正常背景渐变颜色

	m_bkcolor1.clrBegin = RGB(198, 186, 145);
	m_bkcolor1.clrEnd = RGB(139, 127, 66);		// 风险背景渐变颜色

	m_bkcolor2.clrBegin = RGB(200, 137, 206);
	m_bkcolor2.clrEnd = RGB(140, 63, 134);		// 错误背景渐变颜色
	
	m_bkcolor3.clrBegin = RGB(160, 160, 160);
	m_bkcolor3.clrEnd = RGB(89, 89, 89);		// 禁用背景渐变颜色
}

CEditWnd::~CEditWnd()
{
	if ( m_TxtFont.GetSafeHandle() )
		m_TxtFont.DeleteObject();
	if ( m_BmpBK.GetSafeHandle() )
		m_BmpBK.DeleteObject();
}

IMPLEMENT_DYNCREATE(CEditWnd, CWnd)

BEGIN_MESSAGE_MAP(CEditWnd, CWnd)
	//{{AFX_MSG_MAP(CEditWnd)
	ON_WM_LBUTTONDOWN()
	ON_WM_PAINT()
	ON_WM_SETFOCUS()
	ON_WM_KILLFOCUS()
	ON_WM_CHAR()
	ON_WM_GETDLGCODE()
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_CONTEXTMENU()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CEditWnd message handlers

void CEditWnd::OnLButtonDown(UINT nFlags, CPoint point) 
{	
	CWnd::OnLButtonDown(nFlags, point);
	SetFocus();
	SetCapture();
	m_nCharPos = CharFromPos(point.x);			// 从当前鼠标的位置获得对应字符的序号
	if ( m_nCharPos > m_strEdit.GetLength() )	// 修正 m_nCharPos ，确保其值不会超过字符串的长度
		m_nCharPos = m_strEdit.GetLength();

	m_ptCursor.x = PosFromChar(m_nCharPos);		// 设置光标的位置
	::SetCaretPos(m_ptCursor.x, m_ptCursor.y);

	m_bLBtDown = true;							// 设置右键按下标志位
	
	m_ptFirst = point;
	m_strSelect = "";
	m_nSelectBegin = m_nSelectEnd = 0;
	m_nShiftBegin = m_nCharPos;//-1;
	Invalidate(FALSE);
}

void CEditWnd::SetTittleUnit(CString title ,CString unit)
{
	m_strTitle = title;		// 编辑框标题
	m_strUnit = unit;		// 编辑框单位
}

void CEditWnd::OnPaint() 
{
	CPaintDC dc(this);
	CPen PenLine,*pOldPen;
	HBRUSH OldBrush;
	CRgn DrawRgn;
	CDC BKdc;
	CBitmap BmpMem, *pOldBmp;

	// 拷贝窗口所在区域的背景
	BKdc.CreateCompatibleDC(&dc);
	BmpMem.CreateCompatibleBitmap(&dc, m_rcWnd.Width(), m_rcWnd.Height());
	pOldBmp = (CBitmap *)BKdc.SelectObject(&BmpMem);
	BKdc.BitBlt(0, 0, m_rcWnd.Width(), m_rcWnd.Height(), &dc, 0, 0, SRCCOPY);

	// 设置绘制的区域
	PenLine.CreatePen(PS_SOLID, 1, RGB(135,155,200));
	pOldPen = (CPen *)BKdc.SelectObject(&PenLine);
	OldBrush = (HBRUSH)::SelectObject(BKdc.GetSafeHdc(),GetStockObject(NULL_BRUSH)); 
	BKdc.BeginPath();
	BKdc.RoundRect(m_rcWnd, CPoint(5, 5));
	BKdc.EndPath();
	DrawRgn.CreateFromPath(&BKdc);
	BKdc.SelectClipRgn(&DrawRgn, RGN_COPY);

	if ( m_BmpBK.GetSafeHandle() && m_bBkneedchange == 0)		// 判断是否设置了背景图片
	{	// 绘制背景
		CDC MemDC;
		MemDC.CreateCompatibleDC(&dc);
		CBitmap *pOldBmp = (CBitmap *)MemDC.SelectObject(&m_BmpBK);
		BKdc.BitBlt(m_rcWnd.left, m_rcWnd.top, m_rcWnd.Width(), m_rcWnd.Height(), &MemDC, 0, 0, SRCCOPY);
		MemDC.SelectObject(pOldBmp);
		MemDC.DeleteDC();
	}
	else	// 设置缺省背景
	{
		if (m_iState == 0) 
			MakeBKGround(&BKdc, m_bkcolor0.clrBegin, m_bkcolor0.clrEnd, m_rcWnd);
		else if(m_iState == 1)
			MakeBKGround(&BKdc, m_bkcolor1.clrBegin, m_bkcolor1.clrEnd, m_rcWnd);
		else if(m_iState == 2)
			MakeBKGround(&BKdc, m_bkcolor2.clrBegin, m_bkcolor2.clrEnd, m_rcWnd);
		else if(m_iState == 3)
			MakeBKGround(&BKdc, m_bkcolor3.clrBegin, m_bkcolor3.clrEnd, m_rcWnd);
		m_bBkneedchange = 0;
	}

	BKdc.SelectClipRgn(NULL, RGN_COPY);		// 恢复DC现场
	DrawRgn.DeleteObject();					// 删除区域

	BKdc.RoundRect(m_rcWnd, CPoint(5, 5));	// 绘制窗体的边框
	BKdc.SelectObject(OldBrush);

	BKdc.SelectObject(pOldPen);				// 恢复DC现场
	PenLine.DeleteObject();
	
	CFont *pOldFont;
	pOldFont = (CFont *)BKdc.SelectObject(&m_TxtFont);
	int nOldMode = BKdc.SetBkMode(TRANSPARENT);
	COLORREF clrOld = BKdc.SetTextColor(RGB(54,73,165));

	if ( m_strEdit.GetLength()>0 )		// 绘制窗体中的文本信息
	{
		//设置字体大小
		int zzz=m_strEdit.GetLength();
		CFont font;
		
		if (m_rcWnd.Width()<125)
			font.CreateFont( 18, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, OUT_TT_PRECIS, 
				CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, VARIABLE_PITCH | FF_SWISS,
				"宋体" );
		else
			font.CreateFont( 20, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, OUT_TT_PRECIS, 
				CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, VARIABLE_PITCH | FF_SWISS,
				"宋体" );

		BKdc.SelectObject(&font);

		//制造叠影效果
		CString strTemp;
		strTemp = m_strEdit.Right(m_strEdit.GetLength() - m_nShowChar);
		BKdc.TextOut(m_ptTxtBegin.x+2,m_ptTxtBegin.y+2,strTemp);
		//文字颜色接近白色
		BKdc.SetTextColor(RGB(212,212,212));
		BKdc.TextOut(m_ptTxtBegin.x+1,m_ptTxtBegin.y+1,strTemp);

		BKdc.SelectObject(&pOldFont); //设置回原来的字体大小
		BKdc.SelectObject(&m_TxtFont);
	}
	//绘制标题、单位
	if ( m_strTitle.GetLength()>0 )		// 绘制标题
	{
		BKdc.SetTextColor(RGB(50,50,50));
		BKdc.TextOut(m_rcWnd.left+5,m_rcWnd.top+5,m_strTitle);
	}
	if ( m_strUnit.GetLength()>0 )		// 绘制单位
	{
		int ul = m_strUnit.GetLength();
		m_rcWnd.Height();
		BKdc.SetTextColor(RGB(12,12,12));
		if (m_rcWnd.Width()<125)
			BKdc.TextOut(m_rcWnd.left+m_rcWnd.Width()-10*ul - 2,m_rcWnd.top+m_rcWnd.Height()-20,m_strUnit);
		else
			BKdc.TextOut(m_rcWnd.left+m_rcWnd.Width()-10*ul - 10,m_rcWnd.top+m_rcWnd.Height()-20,m_strUnit);
	}

	if ( m_strSelect.GetLength()>0 )	// 绘制被选中字符串
	{
		BLENDFUNCTION bf;
		int nBeginPosX, nEndPosX;
		
		bf.BlendOp = AC_SRC_OVER;
		bf.BlendFlags = 0;
		bf.AlphaFormat = 0;
		bf.SourceConstantAlpha=  100;

		if ( m_nSelectBegin < m_nShowChar )
			nBeginPosX = PosFromChar(m_nShowChar);
		else
			nBeginPosX = PosFromChar(m_nSelectBegin);
		nEndPosX = PosFromChar(m_nSelectEnd);
		CDC MemDC;
		CBitmap BmpMask, *pOldBmp;
		MemDC.CreateCompatibleDC(&dc);
		BmpMask.CreateCompatibleBitmap(&dc, nEndPosX-nBeginPosX, m_tm.tmHeight);
		pOldBmp = (CBitmap *)MemDC.SelectObject(&BmpMask);
		MemDC.FillSolidRect(0,0,nEndPosX-nBeginPosX, m_tm.tmHeight,RGB(0,0,0));
//		AlphaBlend(BKdc.GetSafeHdc(), nBeginPosX, m_ptTxtBegin.y, nEndPosX-nBeginPosX, m_tm.tmHeight, 
//			MemDC.GetSafeHdc(), 0, 0, nEndPosX-nBeginPosX, m_tm.tmHeight,bf);
		MemDC.SelectObject(pOldBmp);
		MemDC.DeleteDC();
		BmpMask.DeleteObject();
	}

	dc.BitBlt(0, 0,  m_rcWnd.Width(), m_rcWnd.Height(), &BKdc, 0, 0, SRCCOPY);
	BKdc.SetTextColor(clrOld);
	BKdc.SetBkMode(nOldMode);
	BKdc.SelectObject(pOldFont);
	BKdc.SelectObject(pOldBmp);
	BmpMem.DeleteObject();
	BKdc.DeleteDC();
}

BOOL CEditWnd::PreCreateWindow(CREATESTRUCT& cs) 
{
	// TODO: Add your specialized code here and/or call the base class
	cs.style |= WS_TABSTOP;			// 设置该窗体能够获得光标
	
	return CWnd::PreCreateWindow(cs);
}

void CEditWnd::OnSetFocus(CWnd* pOldWnd) 
{
	// 窗体获得焦点以后设置光标的位置
	CWnd::OnSetFocus(pOldWnd);
	::CreateCaret(m_hWnd,(HBITMAP) NULL, 0, m_tm.tmHeight);
	::SetCaretPos(m_ptCursor.x, m_ptCursor.y); 
	::ShowCaret(m_hWnd);
		
}

void CEditWnd::OnKillFocus(CWnd* pNewWnd) 
{
	CWnd::OnKillFocus(pNewWnd);		// 窗口失去焦点的时候销毁光标
	::HideCaret(m_hWnd); 
	::DestroyCaret();
		
}
void CEditWnd::GetString(CString &strWnd)
{
	strWnd = m_strEdit;
}

void CEditWnd::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{	
	static bool bSpecial = false;
	::HideCaret(m_hWnd);
	switch(nChar) {
	case 8:			// 响应用户删除操作
		{
			if ( m_strSelect.GetLength()>0 )
			{
				m_strEdit.Delete(m_nSelectBegin, m_nSelectEnd - m_nSelectBegin);
				m_strSelect = "";
				m_nCharPos = m_nSelectBegin;
				m_ptCursor.x = PosFromChar(m_nCharPos);
				m_nSelectBegin = m_nSelectEnd = 0;
				m_nShiftBegin = -1;
				Invalidate(FALSE);
			}
			else if ( m_nCharPos>0 && m_strEdit.GetLength()>0 )
			{
				const char *cText = (const char *)m_strEdit;
				if ( (unsigned char)cText[m_nCharPos-1]>127 )
				{
					m_strEdit.Delete(m_nCharPos-2,2);
					m_nCharPos -= 2;
				}
				else
				{
					m_strEdit.Delete(m_nCharPos-1);
					m_nCharPos--;
				}
				if ( m_nShowChar>0 && (unsigned char)cText[m_nShowChar-1]>127 )
					m_nShowChar -= 2;
				else
					m_nShowChar--;

				if ( m_nShowChar<0 )
					m_nShowChar = 0;
				m_ptCursor.x = PosFromChar(m_nCharPos);
				Invalidate(FALSE);
			}
		}
		break;
	default:
		{
			if ( nChar<32 )
			{					// 此处处理Ctrl+C、Ctrl+V和Ctrl+X操作
				switch(nChar) {
				case 3:
					{
						CopyString();
					}
					break;
				case 22:
					{
						PasteString();
					}
					break;
				case 24:
					{
						CutString();
					}
				}
			}
			else	// 此处进行一般输入字符的处理
			{
				if ( m_strSelect.GetLength()>0 )
				{	// 如果当前有被选中的字符串，先进行删除操作
					m_strEdit.Delete(m_nSelectBegin, m_nSelectEnd - m_nSelectBegin);
					m_strSelect = "";
					m_nCharPos = m_nSelectBegin;
				}
				m_nSelectBegin = m_nSelectEnd = 0;
				m_nShiftBegin = -1;
				m_strEdit.Insert(m_nCharPos,nChar);
				m_nCharPos++;
				if ( nChar>127 )
				{
					if ( bSpecial )
					{
						while ( m_nCharPos - m_nShowChar>m_nMaxShowChars )
							m_nShowChar++;
						m_ptCursor.x = PosFromChar(m_nCharPos);
						Invalidate(FALSE);
						bSpecial = false;
					}
					else
					{
						bSpecial = true;
					}
				}
				else
				{
					const char	*cText = (const char *)m_strEdit;
					cText += m_nShowChar;
					while ( m_nCharPos - m_nShowChar>m_nMaxShowChars )
					{
						if ( ((unsigned char)*cText)>127 && 
							((unsigned char)*(cText+1))>127 )
						{
							m_nShowChar += 2;
							cText += 2;
						}
						else
						{
							m_nShowChar++;
							cText++;
						}
					}
					m_ptCursor.x = PosFromChar(m_nCharPos);
					Invalidate(FALSE);
				}
			}
		}
		break;
	}
	::ShowCaret(m_hWnd);
	::SetCaretPos(m_ptCursor.x, m_ptCursor.y); 
	CWnd::OnChar(nChar, nRepCnt, nFlags);
}

BOOL CEditWnd::PreTranslateMessage(MSG* pMsg) 
{	
	switch(pMsg->message)
	{	// 处理键盘操作
		case WM_KEYDOWN:
			{
				switch(pMsg->wParam)
				{
					case VK_UP:
					case VK_LEFT:
						{
							int nVirtKey = GetKeyState(VK_SHIFT);
							if ( nVirtKey&SHIFTED )
							{
								if ( m_nShiftBegin<0 )
								{
									if ( m_strSelect.GetLength()>0 )
									{
										if ( m_nCharPos<m_nSelectEnd )
											m_nShiftBegin = m_nSelectEnd;
										else
											m_nShiftBegin = m_nSelectBegin;
									}
									else
									{
										m_nShiftBegin = m_nCharPos;
									}
								}
							}
							else
							{
								m_nShiftBegin = -1;
								m_strSelect = "";
							}
							::HideCaret(m_hWnd);
							const char *cText = (const char *)m_strEdit;
							if( m_nCharPos>0 )
							{
								if ( (unsigned char)cText[m_nCharPos-1]>127 )
								{
									m_nCharPos -= 2;
								}
								else
									m_nCharPos--;
							}
							while ( m_nCharPos - m_nShowChar<0 ) 
							{
								if ( (unsigned char)cText[m_nShowChar-1]>127 )
									m_nShowChar -= 2;
								else
									m_nShowChar--;
							}
							if ( nVirtKey&SHIFTED )
							{
								if ( m_nShiftBegin<m_nCharPos )
								{
									m_nSelectBegin = m_nShiftBegin;
									m_nSelectEnd = m_nCharPos;
								}
								else
								{
									m_nSelectBegin = m_nCharPos;
									m_nSelectEnd = m_nShiftBegin;
								}
								m_strSelect = m_strEdit.Mid(m_nSelectBegin, m_nSelectEnd-m_nSelectBegin);
							}
							m_ptCursor.x = PosFromChar(m_nCharPos);
							Invalidate(FALSE);
							::SetCaretPos(m_ptCursor.x, m_ptCursor.y);
							::ShowCaret(m_hWnd);
							return TRUE;
						}
					case VK_DOWN:
					case VK_RIGHT:
						{
							int nVirtKey = GetKeyState(VK_SHIFT);
							if ( nVirtKey&SHIFTED )
							{
								if ( m_nShiftBegin<0 )
								{
									if ( m_strSelect.GetLength()>0 )
									{
										if ( m_nCharPos<m_nSelectEnd )
											m_nShiftBegin = m_nSelectEnd;
										else
											m_nShiftBegin = m_nSelectBegin;
									}
									else
									{
										m_nShiftBegin = m_nCharPos;
									}
								}
							}
							else
							{
								m_nShiftBegin = -1;
								m_strSelect = "";
							}
							::HideCaret(m_hWnd);
							const char *cText = (const char *)m_strEdit;
							if( m_nCharPos<m_strEdit.GetLength() )
							{
								if ( (unsigned char)cText[m_nCharPos]>127 )
								{
									m_nCharPos += 2;
								}
								else
									m_nCharPos++;
							}				
							cText += m_nShowChar;
							while ( m_nCharPos - m_nShowChar>m_nMaxShowChars )
							{
								if ( ((unsigned char)*cText)>127 && ((unsigned char)*(cText+1))>127 )
								{
									m_nShowChar += 2;
									cText += 2;
								}
								else
								{
									m_nShowChar++;
									cText++;
								}
							}
							if ( nVirtKey&SHIFTED )
							{
								if ( m_nShiftBegin<m_nCharPos )
								{
									m_nSelectBegin = m_nShiftBegin;
									m_nSelectEnd = m_nCharPos;
								}
								else
								{
									m_nSelectBegin = m_nCharPos;
									m_nSelectEnd = m_nShiftBegin;
								}
								m_strSelect = m_strEdit.Mid(m_nSelectBegin, m_nSelectEnd-m_nSelectBegin);
							}
							m_ptCursor.x = PosFromChar(m_nCharPos);
							Invalidate(FALSE);
							::ShowCaret(m_hWnd);
							::SetCaretPos(m_ptCursor.x, m_ptCursor.y);
							return TRUE;
						}
					case VK_HOME:
						{
							int nVirtKey = GetKeyState(VK_SHIFT);
							if ( nVirtKey&SHIFTED )
							{
								if ( m_nShiftBegin<0 )
								{
									m_nSelectEnd = m_nCharPos;
									m_nShiftBegin = m_nCharPos;
								}
								else
									m_nSelectEnd = m_nShiftBegin;
								m_nSelectBegin = 0;
								m_strSelect = m_strEdit.Mid(m_nSelectBegin, m_nSelectEnd-m_nSelectBegin);
							}
							else
							{
								m_nShiftBegin = -1;
								m_strSelect = "";
								m_nSelectBegin = m_nSelectEnd = 0;
							}
							::HideCaret(m_hWnd);
							m_nCharPos = 0;
							m_nShowChar = 0;
							m_ptCursor.x = PosFromChar(m_nCharPos);
							Invalidate(FALSE);
							::ShowCaret(m_hWnd);
							::SetCaretPos(m_ptCursor.x, m_ptCursor.y);
							return TRUE;
						}
					case VK_END:
						{
							int nVirtKey = GetKeyState(VK_SHIFT);
							if ( nVirtKey&SHIFTED )
							{
								if ( m_nShiftBegin<0 )
								{
									m_nSelectBegin = m_nCharPos;
									m_nShiftBegin = m_nCharPos;
								}
								else
									m_nSelectBegin = m_nShiftBegin;
								m_nSelectEnd = m_strEdit.GetLength();
								m_strSelect = m_strEdit.Mid(m_nSelectBegin, m_nSelectEnd-m_nSelectBegin);
							}
							else
							{
								m_nShiftBegin = -1;
								m_strSelect = "";
								m_nSelectBegin = m_nSelectEnd = 0;
							}
							::HideCaret(m_hWnd);
							m_nCharPos = m_strEdit.GetLength();
							//////////////////////////////////////////////////////////////
							const char *cText = (const char *)m_strEdit;
							int nIndex = m_nCharPos-1;
							int nShowChars = 0;
							while( nShowChars<m_nMaxShowChars )
							{
								if ( (unsigned char)cText[nIndex]>127 )
								{
									nIndex -= 2;
									nShowChars += 2;
								}
								else
								{
									nIndex -= 1;
									nShowChars += 1;
								}
							}
							//////////////////////////////////////////////////////////////
							m_nShowChar = m_nCharPos - nShowChars;//m_nMaxShowChars;
							if ( m_nShowChar<0 )
								m_nShowChar = 0;
							m_ptCursor.x = PosFromChar(m_nCharPos);
							Invalidate(FALSE);
							::ShowCaret(m_hWnd);
							::SetCaretPos(m_ptCursor.x, m_ptCursor.y);
							return TRUE;
						}
					case VK_DELETE:
						{
							if ( m_strEdit.GetLength()>0 && m_nCharPos<m_strEdit.GetLength() )
							{
								const char *cText = (const char *)m_strEdit;
								if ( (unsigned char)cText[m_nCharPos]>127 )
								{
									m_strEdit.Delete(m_nCharPos,2);
								}
								else
									m_strEdit.Delete(m_nCharPos);
								Invalidate(FALSE);
							}
							break;
						}
				}
			}
			break;
	}
	return CWnd::PreTranslateMessage(pMsg);
}

UINT CEditWnd::OnGetDlgCode() 
{	
	return (CWnd::OnGetDlgCode() | DLGC_WANTCHARS );	// 此处使得CWnd能够获得OnChar()事件
}

// 创建背景的函数
void CEditWnd::MakeBKGround(CDC *pDC, COLORREF clrBegin, COLORREF clrEnd, CRect rect)
{
	CDC MemDC;
	int x1=0,y1=0;
    int x2=0,y2=0;
	int r1=GetRValue(clrBegin),g1=GetGValue(clrBegin),b1=GetBValue(clrBegin);
    int r2=GetRValue(clrEnd),g2=GetGValue(clrEnd),b2=GetBValue(clrEnd);
	MemDC.CreateCompatibleDC(pDC);

	if ( m_BmpBK.GetSafeHandle() )
		m_BmpBK.DeleteObject();
	
	m_BmpBK.CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());
	CBitmap *pOldBmp = MemDC.SelectObject(&m_BmpBK);
	while( x1<rect.Width() && y1<rect.Height() )
    {
        if( y1<rect.Height()-1 )
            y1++;
        else
            x1++;

        if( x2<rect.Width()-1 )
            x2++;
        else
            y2++;

        int r,g,b;
        int i = x1+y1;
        r = r1 + (i * (r2-r1) / (rect.Width()+rect.Height()));
        g = g1 + (i * (g2-g1) / (rect.Width()+rect.Height()));
        b = b1 + (i * (b2-b1) / (rect.Width()+rect.Height()));

        CPen p(PS_SOLID,1,RGB(r,g,b));
        CPen *oldpen = MemDC.SelectObject(&p); 

        MemDC.MoveTo(x1,y1);
        MemDC.LineTo(x2,y2);

        MemDC.SelectObject(oldpen);
		p.DeleteObject();
    }
	pDC->BitBlt(rect.left, rect.top, rect.Width(), rect.Height(), &MemDC, 0, 0, SRCCOPY);
	MemDC.SelectObject(pOldBmp);
	MemDC.DeleteDC();
}


int CEditWnd::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if ( CWnd::OnCreate(lpCreateStruct)==-1 )
		return -1;

	GetClientRect(m_rcWnd);
	CClientDC dc(this);
	CFont *pOldFont = dc.SelectObject(&m_TxtFont);
	dc.GetTextMetrics(&m_tm);
	//m_ptTxtBegin 文本输出位置
	//m_ptTxtBegin.y = m_ptCursor.y = (m_rcWnd.Height() - m_tm.tmHeight) / 2; //文本输出位于编辑框中央
	if (m_rcWnd.Height()<50)
	{
		m_ptTxtBegin.y = m_ptCursor.y = (m_rcWnd.Height() - m_tm.tmHeight - 10) ;
	}
	else
	{
		m_ptTxtBegin.y = m_ptCursor.y = (m_rcWnd.Height() - m_tm.tmHeight - 20) ;
	}
	if (m_rcWnd.Width()<125)
	{
		m_ptTxtBegin.x=10;
	}
	dc.SelectObject(pOldFont);
	m_nMaxShowChars = (m_rcWnd.Width() - nMargin) / m_tm.tmAveCharWidth;

	return 0;
}

void CEditWnd::OnSize(UINT nType, int cx, int cy) 
{
	CWnd::OnSize(nType, cx, cy);
	GetClientRect(m_rcWnd);	
	CClientDC dc(this);
	CFont *pOldFont = dc.SelectObject(&m_TxtFont);
	dc.GetTextMetrics(&m_tm);
	if (m_rcWnd.Height()<50)
	{
		m_ptTxtBegin.y = m_ptCursor.y = (m_rcWnd.Height() - m_tm.tmHeight - 10) ;
	}
	else
	{
		m_ptTxtBegin.y = m_ptCursor.y = (m_rcWnd.Height() - m_tm.tmHeight - 20) ;
	}
	if (m_rcWnd.Width()<125)
	{
		m_ptTxtBegin.x=10;
	}
	dc.SelectObject(pOldFont);
	m_nMaxShowChars = (m_rcWnd.Width() - nMargin) / m_tm.tmAveCharWidth;
	if ( m_BmpBK.GetSafeHandle() )
		m_BmpBK.DeleteObject();
}

void CEditWnd::OnContextMenu(CWnd* pWnd, CPoint point) 
{	
}

void CEditWnd::CopyString()
{
	if ( m_strSelect.GetLength()<=0 )
		return;
	if ( OpenClipboard() )
	{
		 EmptyClipboard();
		 HGLOBAL hClipboardData;
		 hClipboardData = GlobalAlloc(GMEM_DDESHARE, 
			 m_strSelect.GetLength()+1);
		 char * pchData;
		 pchData = (char*)GlobalLock(hClipboardData);
		 strcpy(pchData, LPCSTR(m_strSelect));
		 GlobalUnlock(hClipboardData);
		 SetClipboardData(CF_TEXT,hClipboardData);
		 CloseClipboard();
	}
}

void CEditWnd::PasteString()
{
	if ( OpenClipboard() ) 
	{
		if ( ::IsClipboardFormatAvailable(CF_TEXT) || 
			::IsClipboardFormatAvailable(CF_OEMTEXT) )
		{
			::HideCaret(m_hWnd);
			HANDLE hClipboardData = GetClipboardData(CF_TEXT);
			char *pchData = (char*)GlobalLock(hClipboardData);
			if ( m_strSelect.GetLength()>0 )
			{
				m_strEdit.Delete(m_nSelectBegin, m_strSelect.GetLength());
				m_nCharPos = m_nSelectBegin;
				m_strSelect = "";
			}
			m_strSelect.Format("%s", pchData);
			GlobalUnlock(hClipboardData);
			m_strEdit.Insert(m_nCharPos,(LPCTSTR)m_strSelect);
			m_nCharPos += m_strSelect.GetLength();
			const char	*cText = (const char *)m_strEdit;
			cText += m_nShowChar;
			while ( m_nCharPos - m_nShowChar>m_nMaxShowChars )
			{
				if ( ((unsigned char)*cText)>127 && 
					((unsigned char)*(cText+1)) > 127 )
				{
					m_nShowChar += 2;
					cText += 2;
				}
				else
				{
					m_nShowChar++;
					cText++;
				}
			}
			m_ptCursor.x = PosFromChar(m_nCharPos);
			Invalidate(FALSE);
			::ShowCaret(m_hWnd);
			::SetCaretPos(m_ptCursor.x, m_ptCursor.y); 
			m_strSelect = "";
		}
		CloseClipboard();
	}
}

void CEditWnd::CutString()
{
	if ( m_strSelect.GetLength() <= 0)
		return;
	m_strEdit.Delete(m_nSelectBegin, m_strSelect.GetLength());
	CopyString();
	::HideCaret(m_hWnd);
	m_nCharPos = m_nSelectBegin;
	if ( m_nShowChar>0 )
	{
		m_nShowChar -= m_strSelect.GetLength();
		if ( m_nShowChar<0 )
			m_nShowChar = 0;
	}
	m_strSelect = "";
	m_ptCursor.x = PosFromChar(m_nCharPos);
	Invalidate(FALSE);
	::ShowCaret(m_hWnd);
	::SetCaretPos(m_ptCursor.x, m_ptCursor.y);
}

void CEditWnd::OnMouseMove(UINT nFlags, CPoint point) 
{	
	if ( m_bLBtDown )
	{
		::HideCaret(m_hWnd);
		if ( m_ptFirst.x>point.x )
		{
			m_nSelectBegin = CharFromPos(point.x);
			m_nSelectEnd = CharFromPos(m_ptFirst.x);
		}
		else
		{
			m_nSelectBegin = CharFromPos(m_ptFirst.x);
			m_nSelectEnd = CharFromPos(point.x);
		}

		if ( m_nSelectEnd>m_strEdit.GetLength() )
			m_nSelectEnd = m_strEdit.GetLength();
		else if ( m_nSelectEnd<0 )
			m_nSelectEnd = 0;

		if ( m_nSelectBegin>m_strEdit.GetLength() )
			m_nSelectBegin = m_strEdit.GetLength();
		else if ( m_nSelectBegin<0 )
			m_nSelectBegin = 0;

		if ( m_nSelectEnd-m_nSelectBegin>0 )
			m_strSelect = m_strEdit.Mid(m_nSelectBegin,m_nSelectEnd-m_nSelectBegin);
		
		m_nCharPos = CharFromPos(point.x);
		if ( m_nCharPos<0 )
			m_nCharPos = 0;
		else if ( m_nCharPos>m_strEdit.GetLength() )
			m_nCharPos = m_strEdit.GetLength();
		m_ptCursor.x = PosFromChar(m_nCharPos);
		Invalidate(FALSE);

		::ShowCaret(m_hWnd);
		::SetCaretPos(m_ptCursor.x, m_ptCursor.y);
	}
	CWnd::OnMouseMove(nFlags, point);
}

void CEditWnd::OnLButtonUp(UINT nFlags, CPoint point) 
{
	m_bLBtDown = false;
	ReleaseCapture();
	CWnd::OnLButtonUp(nFlags, point);
}

int CEditWnd::PosFromChar(UINT nChar)
{
	CString strTemp = m_strEdit.Mid(m_nShowChar, nChar - m_nShowChar);
	CClientDC dc(this);
	CFont *pOldFont = dc.SelectObject(&m_TxtFont);
	//设置光标位置
	CFont font;
	font.CreateFont( 25, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, OUT_TT_PRECIS, 
	CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, VARIABLE_PITCH | FF_SWISS,
	"宋体" );
	//设置字体为大字体
	dc.SelectObject(&font);
	CSize TestSize = dc.GetTextExtent(strTemp);
	//设置回原来的小字体
	dc.SelectObject(&m_TxtFont); 
	return (nMargin + TestSize.cx);
}

int CEditWnd::CharFromPos(int nPosX)
{
	CString strTemp = m_strEdit.Mid(m_nShowChar);
	int nCharIndex = m_nShowChar;
	int nStringLen = strTemp.GetLength();
	char	TempChar[4];
	int nBeginPos = nMargin;
	CSize TxtSize;
	const char	*cText = (const char *)strTemp;
	CClientDC dc(this);
	CFont *pOldFont = dc.SelectObject(&m_TxtFont);
	while( nStringLen>0 )
	{
		if ( ((unsigned char)*cText)>127 && 
			((unsigned char)*(cText+1))>127 )
		{
			strncpy(TempChar,cText,2);
			TempChar[2] = 0;
			cText += 2;
			nStringLen -= 2;
			nCharIndex += 2;
			TxtSize = dc.GetTextExtent(TempChar,2);
		}
		else
		{
			strncpy(TempChar,cText,1);
			TempChar[1] = 0;
			cText += 1;
			nStringLen -= 1;
			nCharIndex += 1;
			TxtSize = dc.GetTextExtent(TempChar,1);
		}
		if ( nBeginPos+TxtSize.cx>nPosX )
		{
			if ( nPosX-nBeginPos<nBeginPos+TxtSize.cx-nPosX )
				nCharIndex -= strlen(TempChar);
			break;
		}
		nBeginPos += TxtSize.cx;
	}
	dc.SelectObject(pOldFont);
	return nCharIndex;	
}
