// DeviceCapsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DeviceCaps.h"
#include "DeviceCapsDlg.h"
#include ".\devicecapsdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CDeviceCapsDlg dialog



CDeviceCapsDlg::CDeviceCapsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDeviceCapsDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDeviceCapsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDeviceCapsDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CDeviceCapsDlg message handlers

BOOL CDeviceCapsDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	CDC* dialogDC = GetDC ();
	int horzRes			= dialogDC->GetDeviceCaps (HORZRES);
	int vertRes			= dialogDC->GetDeviceCaps (VERTRES);
	int horzSize		= dialogDC->GetDeviceCaps (HORZSIZE);
	int vertSize		= dialogDC->GetDeviceCaps (VERTSIZE);
	int logPixelsX		= dialogDC->GetDeviceCaps (LOGPIXELSX);
	int logPixelsY		= dialogDC->GetDeviceCaps (LOGPIXELSY);
	double calcPixelsX	= static_cast<double> (horzRes) / static_cast<double> (horzSize) * 25.4;
	double calcPixelsY	= static_cast<double> (vertRes) / static_cast<double> (vertSize) * 25.4;
	CString deviceCapsStr;
	char tempStr[256];
	sprintf (tempStr, "Resolution: %d x %d\r\n",		horzRes, vertRes);
	deviceCapsStr += tempStr;
	sprintf (tempStr, "Size: %d mm x %d mm\r\n",		horzSize, vertSize);
	deviceCapsStr += tempStr;
	sprintf (tempStr, "Logical DPI: %d x %d\r\n",		logPixelsX, logPixelsY);
	deviceCapsStr += tempStr;
	sprintf (tempStr, "Calculated DPI: %f x %f\r\n",	calcPixelsX, calcPixelsY);
	deviceCapsStr += tempStr;
	CEdit* pEditMessage = (CEdit*) GetDlgItem(IDC_EDIT1);
	pEditMessage->SetWindowText (static_cast<LPCTSTR> (deviceCapsStr));

	return FALSE;  // return TRUE  unless you set the focus to a control
}

void CDeviceCapsDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDeviceCapsDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDeviceCapsDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

