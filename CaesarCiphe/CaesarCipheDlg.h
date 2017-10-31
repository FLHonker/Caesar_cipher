
// CaesarCipheDlg.h : ͷ�ļ�
//

#pragma once

class CCaesarCipheDlgAutoProxy;


// CCaesarCipheDlg �Ի���
class CCaesarCipheDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCaesarCipheDlg);
	friend class CCaesarCipheDlgAutoProxy;

// ����
public:
	CCaesarCipheDlg(CWnd* pParent = NULL);	// ��׼���캯��
	virtual ~CCaesarCipheDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CAESARCIPHE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
private: 
	CStatic *inputStatic, *outputStatic;   //CStatic����ָ��
	CString inputStr;      //������ַ���
	int key;            //��Կkey
	int getKey();       //��ȡkey
	float alphFreq[26];
	int getStr();      //��ȡ�������ı�   
	int Encrypt();      //����������ı���
	int Decrypt();      //����������ı���
	int Crack();        //�ƽ�������ı���
protected:
	CCaesarCipheDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// ���ɵ���Ϣӳ�亯��
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
