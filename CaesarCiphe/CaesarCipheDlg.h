
// CaesarCipheDlg.h : 头文件
//

#pragma once

class CCaesarCipheDlgAutoProxy;


// CCaesarCipheDlg 对话框
class CCaesarCipheDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCaesarCipheDlg);
	friend class CCaesarCipheDlgAutoProxy;

// 构造
public:
	CCaesarCipheDlg(CWnd* pParent = NULL);	// 标准构造函数
	virtual ~CCaesarCipheDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CAESARCIPHE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
private: 
	CStatic *inputStatic, *outputStatic;   //CStatic对象指针
	CString inputStr;      //输入的字符串
	int key;            //密钥key
	int getKey();       //获取key
	float alphFreq[26];
	int getStr();      //获取输入框的文本   
	int Encrypt();      //加密输出到文本框
	int Decrypt();      //解密输出到文本框
	int Crack();        //破解输出到文本框
protected:
	CCaesarCipheDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnencrypt();
	afx_msg void OnBnClickedBtndecrypt();
	afx_msg void OnBnClickedBtncrack();
};
