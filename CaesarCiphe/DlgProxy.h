
// DlgProxy.h: ͷ�ļ�
//

#pragma once

class CCaesarCipheDlg;


// CCaesarCipheDlgAutoProxy ����Ŀ��

class CCaesarCipheDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CCaesarCipheDlgAutoProxy)

	CCaesarCipheDlgAutoProxy();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��

// ����
public:
	CCaesarCipheDlg* m_pDialog;

// ����
public:

// ��д
	public:
	virtual void OnFinalRelease();

// ʵ��
protected:
	virtual ~CCaesarCipheDlgAutoProxy();

	// ���ɵ���Ϣӳ�亯��

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CCaesarCipheDlgAutoProxy)

	// ���ɵ� OLE ����ӳ�亯��

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

