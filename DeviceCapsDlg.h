// DeviceCapsDlg.h : header file
//

#pragma once


// CDeviceCapsDlg dialog
class CDeviceCapsDlg : public CDialog
{
// Construction
public:
	CDeviceCapsDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_DEVICECAPS_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnSetfocusEdit1();
	afx_msg void OnEnChangeEdit1();
};
