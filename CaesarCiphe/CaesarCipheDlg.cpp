
// CaesarCipheDlg.cpp : ʵ���ļ�
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


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CCaesarCipheDlg �Ի���


IMPLEMENT_DYNAMIC(CCaesarCipheDlg, CDialogEx);

CCaesarCipheDlg::CCaesarCipheDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CAESARCIPHE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pAutoProxy = NULL;
}

CCaesarCipheDlg::~CCaesarCipheDlg()
{
	// ����öԻ������Զ���������
	//  ���˴���ָ��öԻ���ĺ���ָ������Ϊ NULL���Ա�
	//  �˴���֪���öԻ����ѱ�ɾ����
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


// CCaesarCipheDlg ��Ϣ�������
// ��ʼ��
BOOL CCaesarCipheDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	inputStatic = (CStatic*)GetDlgItem(IDC_EDIT_input);
	outputStatic = (CStatic*)GetDlgItem(IDC_EDIT_output);
	key = 0;
	//��ĸƵ�ʱ��ʼ��
	alphFreq[0] = 0.08167;  alphFreq[1] = 0.01492;  alphFreq[2] = 0.02782;  alphFreq[3] = 0.04253; 
	alphFreq[4] = 0.12702;  alphFreq[5] = 0.02228;  alphFreq[6] = 0.02015;  alphFreq[7] = 0.06094;
	alphFreq[8] = 0.06966;  alphFreq[9] = 0.00153;  alphFreq[10] = 0.00772; alphFreq[11] = 0.04025;
	alphFreq[12] = 0.02406; alphFreq[13] = 0.06749; alphFreq[14] = 0.07507; alphFreq[15] = 0.01929;
	alphFreq[16] = 0.00095; alphFreq[17] = 0.05987; alphFreq[18] = 0.06327; alphFreq[19] = 0.09056;
	alphFreq[20] = 0.02758; alphFreq[21] = 0.00978; alphFreq[22] = 0.02361; alphFreq[23] = 0.00150;
	alphFreq[24] = 0.01974; alphFreq[25] = 0.00074;

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CCaesarCipheDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CCaesarCipheDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// ���û��ر� UI ʱ������������Ա���������ĳ��
//  �������Զ�����������Ӧ�˳���  ��Щ
//  ��Ϣ�������ȷ����������: �����������ʹ�ã�
//  ������ UI�������ڹرնԻ���ʱ��
//  �Ի�����Ȼ�ᱣ�������

void CCaesarCipheDlg::OnClose()
{
	if (CanExit())
		CDialogEx::OnClose();
}

// ��ȡ�ı����е�key�ַ�������ת��Ϊint��
int CCaesarCipheDlg::getKey()
{
	CString keyStr;
	GetDlgItem(IDC_EDIT_key)->GetWindowTextW(keyStr);
	if (keyStr.IsEmpty())    //���δ����key��������ʾ
	{
		MessageBox(_T("Please input key!"));
		return FALSE;
	}
	key = _ttoi(keyStr) % 26;    //��CStringת��Ϊint
	return key;
}

//��ȡinout���е��ַ�������ת��Ϊȫ��Сд
int CCaesarCipheDlg::getStr()
{
	inputStatic->GetWindowTextW(inputStr);   //��ȡCStatic�ַ�������
	inputStr.MakeLower();     //ȫ��ת��ΪСд��ĸ
	return 0;
}

// ���ܺ���
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
	//inputStr.Remove(' ');    //ȥ���ո�
	outputStatic->SetWindowTextW(inputStr);   //�����ʾ�������

	return 0;
}

// ���ܺ��������������key����
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
	outputStatic->SetWindowTextW(inputStr);  //�����ʾ�������
	return 0;
}

// �ƽ⺯��
int CCaesarCipheDlg::Crack()
{
	getStr();
	int alphAllCount = 0;    //��ĸ����
	wchar_t ch;
	int alphCount[26] = { 0 };       //��ĸ����¼  
	float alphFreCount[26];   //��ĸƵ�ʼ�¼
							  //ͳ����ĸ��
	for (int i = 0; i < inputStr.GetLength(); ++i)
	{
		ch = inputStr.GetAt(i);
		if (ch >= 'a'&&ch <= 'z')
		{
			++alphAllCount;      //����
			alphCount[ch - 'a']++;
		}
	}
	//����ÿ����ĸ���ֵ�Ƶ��
	for (int j = 0; j < 26; ++j)
	{
		alphFreCount[j] = alphCount[j] * 1.0 / alphAllCount;   //��Ҫ����*1.0��ת��Ϊ�������㣡
	}

	/* Ƥ��ɭ�������ԣ�Ѱ����ƥ���key*/

	float averFreqTemp = 10000;    //��ʱ����    
	for (int i = 0; i < 26; ++i)
	{
		float averFreq = 0;          //������¼
		for (int j = 0; j < 26; ++j)
		{
			int k = (i + j) % 26;
			averFreq += (alphFreCount[k] - alphFreq[j])*(alphFreCount[k] - alphFreq[j]) / alphFreq[j];   //��������
		}
		if (averFreq < averFreqTemp)   //�ж���С��������
		{
			averFreqTemp = averFreq;
			key = i;     //��¼��С�������ֵ�����
		}
	}
	//key = 3;
	CString keyStr;
	keyStr.Format(_T("%d"), key);    //key��ʽ��ΪCString����
	GetDlgItem(IDC_EDIT_key)->SetWindowTextW(keyStr);   //�������õ���key
														// ��ʼ���ݼ������key��������
	for (int i = 0; i < inputStr.GetLength(); ++i)
	{
		wchar_t ch = inputStr.GetAt(i);
		if (ch >= key + 'a'&&ch <= 'z')
			inputStr.SetAt(i, ch - key);
		else if (ch >= 'a'&&ch < key + 'a')
			inputStr.SetAt(i, 'z' + ch - 'a' - key + 1);
	}

	outputStatic->SetWindowTextW(inputStr);  //�����ʾ�������
	return 0;
}

BOOL CCaesarCipheDlg::CanExit()
{
	// �����������Ա�����������Զ���
	//  �������Իᱣ�ִ�Ӧ�ó���
	//  ʹ�Ի���������������� UI ����������
	if (m_pAutoProxy != NULL)
	{
		ShowWindow(SW_HIDE);
		return FALSE;
	}

	return TRUE;
}

//���ܰ�ť
void CCaesarCipheDlg::OnBnClickedBtnencrypt()
{
	Encrypt();
}

//���ܰ�ť
void CCaesarCipheDlg::OnBnClickedBtndecrypt()
{
	Decrypt();
}

//�ƽⰴť
void CCaesarCipheDlg::OnBnClickedBtncrack()
{
	Crack();
}
