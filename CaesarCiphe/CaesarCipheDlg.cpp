
// CaesarCipheDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CaesarCiphe.h"
#include "CaesarCipheDlg.h"
#include "DlgProxy.h"
#include "afxdialogex.h"
#include <string>
#include <iostream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()

};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCaesarCipheDlg 对话框


IMPLEMENT_DYNAMIC(CCaesarCipheDlg, CDialogEx);

CCaesarCipheDlg::CCaesarCipheDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CAESARCIPHE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pAutoProxy = NULL;
}

CCaesarCipheDlg::~CCaesarCipheDlg()
{
	// 如果该对话框有自动化代理，则
	//  将此代理指向该对话框的后向指针设置为 NULL，以便
	//  此代理知道该对话框已被删除。
	if (m_pAutoProxy != NULL)
		m_pAutoProxy->m_pDialog = NULL;
}

void CCaesarCipheDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCaesarCipheDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_CLOSE()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Btn_encrypt, &CCaesarCipheDlg::OnBnClickedBtnencrypt)
	ON_BN_CLICKED(IDC_Btn_decrypt, &CCaesarCipheDlg::OnBnClickedBtndecrypt)
	ON_BN_CLICKED(IDC_Btn_crack, &CCaesarCipheDlg::OnBnClickedBtncrack)
END_MESSAGE_MAP()


// CCaesarCipheDlg 消息处理程序
// 初始化
BOOL CCaesarCipheDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	inputStatic = (CStatic*)GetDlgItem(IDC_EDIT_input);
	outputStatic = (CStatic*)GetDlgItem(IDC_EDIT_output);
	key = 0;
	//字母频率表初始化
	alphFreq[0] = 0.08167;  alphFreq[1] = 0.01492;  alphFreq[2] = 0.02782;  alphFreq[3] = 0.04253; 
	alphFreq[4] = 0.12702;  alphFreq[5] = 0.02228;  alphFreq[6] = 0.02015;  alphFreq[7] = 0.06094;
	alphFreq[8] = 0.06966;  alphFreq[9] = 0.00153;  alphFreq[10] = 0.00772; alphFreq[11] = 0.04025;
	alphFreq[12] = 0.02406; alphFreq[13] = 0.06749; alphFreq[14] = 0.07507; alphFreq[15] = 0.01929;
	alphFreq[16] = 0.00095; alphFreq[17] = 0.05987; alphFreq[18] = 0.06327; alphFreq[19] = 0.09056;
	alphFreq[20] = 0.02758; alphFreq[21] = 0.00978; alphFreq[22] = 0.02361; alphFreq[23] = 0.00150;
	alphFreq[24] = 0.01974; alphFreq[25] = 0.00074;

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCaesarCipheDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCaesarCipheDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCaesarCipheDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// 当用户关闭 UI 时，如果控制器仍保持着它的某个
//  对象，则自动化服务器不应退出。  这些
//  消息处理程序确保如下情形: 如果代理仍在使用，
//  则将隐藏 UI；但是在关闭对话框时，
//  对话框仍然会保留在那里。

void CCaesarCipheDlg::OnClose()
{
	if (CanExit())
		CDialogEx::OnClose();
}

// 获取文本框中的key字符串对象并转化为int型
int CCaesarCipheDlg::getKey()
{
	CString keyStr;
	GetDlgItem(IDC_EDIT_key)->GetWindowTextW(keyStr);
	if (keyStr.IsEmpty())    //如果未输入key，弹框提示
	{
		MessageBox(_T("Please input key!"));
		return FALSE;
	}
	key = _ttoi(keyStr) % 26;    //将CString转化为int
	return key;
}

//获取inout框中的字符串对象并转化为全部小写
int CCaesarCipheDlg::getStr()
{
	inputStatic->GetWindowTextW(inputStr);   //获取CStatic字符串对象
	inputStr.MakeLower();     //全部转化为小写字母
	return 0;
}

// 加密函数
int CCaesarCipheDlg::Encrypt()
{
	getStr();
	if(getKey()==FALSE)
		return -1;
	for (int i = 0; i < inputStr.GetLength(); ++i)
	{
		wchar_t ch = inputStr.GetAt(i);
		if (ch >= 'a'&&ch <= 'z' - key)
			inputStr.SetAt(i, ch + key);
		else if (ch > 'z' - key&&ch <= 'z')
			inputStr.SetAt(i, (ch - 'a' + key) % 26 + 'a');    //(ch-'a'+key)%26+'a'   //'a' + ch - 'z' + key - 1
	}
	//inputStr.Remove(' ');    //去除空格
	outputStatic->SetWindowTextW(inputStr);   //结果显示到输出框

	return 0;
}

// 解密函数，根据输入的key解密
int CCaesarCipheDlg::Decrypt()
{
	getStr();
	if (getKey() == FALSE)
		return -1;
	for (int i = 0; i < inputStr.GetLength(); ++i)
	{
		wchar_t ch = inputStr.GetAt(i);
		if (ch >= key + 'a'&&ch <= 'z')
			inputStr.SetAt(i, ch - key);
		else if (ch >= 'a'&&ch < key + 'a')
			inputStr.SetAt(i, 'z' + ch - 'a' - key + 1);
	}
	outputStatic->SetWindowTextW(inputStr);  //结果显示到输出框
	return 0;
}

// 破解函数
int CCaesarCipheDlg::Crack()
{
	getStr();
	int alphAllCount = 0;    //字母总数
	wchar_t ch;
	int alphCount[26] = { 0 };       //字母数记录  
	float alphFreCount[26];   //字母频率记录
							  //统计字母数
	for (int i = 0; i < inputStr.GetLength(); ++i)
	{
		ch = inputStr.GetAt(i);
		if (ch >= 'a'&&ch <= 'z')
		{
			++alphAllCount;      //计数
			alphCount[ch - 'a']++;
		}
	}
	//计算每个字母出现的频率
	for (int j = 0; j < 26; ++j)
	{
		alphFreCount[j] = alphCount[j] * 1.0 / alphAllCount;   //不要忘记*1.0，转换为浮点运算！
	}

	/* 皮尔森卡方测试，寻找最匹配的key*/

	float averFreqTemp = 10000;    //临时卡方    
	for (int i = 0; i < 26; ++i)
	{
		float averFreq = 0;          //卡方记录
		for (int j = 0; j < 26; ++j)
		{
			int k = (i + j) % 26;
			averFreq += (alphFreCount[k] - alphFreq[j])*(alphFreCount[k] - alphFreq[j]) / alphFreq[j];   //卡方计算
		}
		if (averFreq < averFreqTemp)   //判断最小卡方出现
		{
			averFreqTemp = averFreq;
			key = i;     //记录最小卡方出现的索引
		}
	}
	//key = 3;
	CString keyStr;
	keyStr.Format(_T("%d"), key);    //key格式化为CString对象
	GetDlgItem(IDC_EDIT_key)->SetWindowTextW(keyStr);   //输出计算得到的key
														// 开始根据计算出的key解密密文
	for (int i = 0; i < inputStr.GetLength(); ++i)
	{
		wchar_t ch = inputStr.GetAt(i);
		if (ch >= key + 'a'&&ch <= 'z')
			inputStr.SetAt(i, ch - key);
		else if (ch >= 'a'&&ch < key + 'a')
			inputStr.SetAt(i, 'z' + ch - 'a' - key + 1);
	}

	outputStatic->SetWindowTextW(inputStr);  //结果显示到输出框
	return 0;
}

BOOL CCaesarCipheDlg::CanExit()
{
	// 如果代理对象仍保留在那里，则自动化
	//  控制器仍会保持此应用程序。
	//  使对话框保留在那里，但将其 UI 隐藏起来。
	if (m_pAutoProxy != NULL)
	{
		ShowWindow(SW_HIDE);
		return FALSE;
	}

	return TRUE;
}

//加密按钮
void CCaesarCipheDlg::OnBnClickedBtnencrypt()
{
	Encrypt();
}

//解密按钮
void CCaesarCipheDlg::OnBnClickedBtndecrypt()
{
	Decrypt();
}

//破解按钮
void CCaesarCipheDlg::OnBnClickedBtncrack()
{
	Crack();
}
