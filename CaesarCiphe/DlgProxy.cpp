
// DlgProxy.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CaesarCiphe.h"
#include "DlgProxy.h"
#include "CaesarCipheDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCaesarCipheDlgAutoProxy

IMPLEMENT_DYNCREATE(CCaesarCipheDlgAutoProxy, CCmdTarget)

CCaesarCipheDlgAutoProxy::CCaesarCipheDlgAutoProxy()
{
	EnableAutomation();
	
	// ΪʹӦ�ó������Զ��������ڻ״̬ʱһֱ���� 
	//	���У����캯������ AfxOleLockApp��
	AfxOleLockApp();

	// ͨ��Ӧ�ó����������ָ��
	//  �����ʶԻ���  ���ô�����ڲ�ָ��
	//  ָ��Ի��򣬲����öԻ���ĺ���ָ��ָ��
	//  �ô���
	ASSERT_VALID(AfxGetApp()->m_pMainWnd);
	if (AfxGetApp()->m_pMainWnd)
	{
		ASSERT_KINDOF(CCaesarCipheDlg, AfxGetApp()->m_pMainWnd);
		if (AfxGetApp()->m_pMainWnd->IsKindOf(RUNTIME_CLASS(CCaesarCipheDlg)))
		{
			m_pDialog = reinterpret_cast<CCaesarCipheDlg*>(AfxGetApp()->m_pMainWnd);
			m_pDialog->m_pAutoProxy = this;
		}
	}
}

CCaesarCipheDlgAutoProxy::~CCaesarCipheDlgAutoProxy()
{
	// Ϊ������ OLE �Զ����������ж������ֹӦ�ó���
	//	������������ AfxOleUnlockApp��
	//  ���������������⣬�⻹���������Ի���
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CCaesarCipheDlgAutoProxy::OnFinalRelease()
{
	// �ͷ��˶��Զ�����������һ�����ú󣬽�����
	// OnFinalRelease��  ���ཫ�Զ�
	// ɾ���ö���  �ڵ��øû���֮ǰ�����������
	// ��������ĸ���������롣

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CCaesarCipheDlgAutoProxy, CCmdTarget)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CCaesarCipheDlgAutoProxy, CCmdTarget)
END_DISPATCH_MAP()

// ע��: ��������˶� IID_ICaesarCiphe ��֧��
//  ��֧������ VBA �����Ͱ�ȫ�󶨡�  �� IID ����ͬ���ӵ� .IDL �ļ��е�
//  ���Ƚӿڵ� GUID ƥ�䡣

// {3D764B2E-B1B9-4BE2-99AB-D8196E44048E}
static const IID IID_ICaesarCiphe =
{ 0x3D764B2E, 0xB1B9, 0x4BE2, { 0x99, 0xAB, 0xD8, 0x19, 0x6E, 0x44, 0x4, 0x8E } };

BEGIN_INTERFACE_MAP(CCaesarCipheDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CCaesarCipheDlgAutoProxy, IID_ICaesarCiphe, Dispatch)
END_INTERFACE_MAP()

// IMPLEMENT_OLECREATE2 ���ڴ���Ŀ�� StdAfx.h �ж���
// {3D38A066-FC7C-4FCE-A07C-A83A89E8AC90}
IMPLEMENT_OLECREATE2(CCaesarCipheDlgAutoProxy, "CaesarCiphe.Application", 0x3d38a066, 0xfc7c, 0x4fce, 0xa0, 0x7c, 0xa8, 0x3a, 0x89, 0xe8, 0xac, 0x90)


// CCaesarCipheDlgAutoProxy ��Ϣ�������
