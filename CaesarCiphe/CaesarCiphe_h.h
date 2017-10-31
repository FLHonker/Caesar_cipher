

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Thu Oct 19 13:27:46 2017
 */
/* Compiler settings for CaesarCiphe.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __CaesarCiphe_h_h__
#define __CaesarCiphe_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ICaesarCiphe_FWD_DEFINED__
#define __ICaesarCiphe_FWD_DEFINED__
typedef interface ICaesarCiphe ICaesarCiphe;

#endif 	/* __ICaesarCiphe_FWD_DEFINED__ */


#ifndef __CaesarCiphe_FWD_DEFINED__
#define __CaesarCiphe_FWD_DEFINED__

#ifdef __cplusplus
typedef class CaesarCiphe CaesarCiphe;
#else
typedef struct CaesarCiphe CaesarCiphe;
#endif /* __cplusplus */

#endif 	/* __CaesarCiphe_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __CaesarCiphe_LIBRARY_DEFINED__
#define __CaesarCiphe_LIBRARY_DEFINED__

/* library CaesarCiphe */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_CaesarCiphe;

#ifndef __ICaesarCiphe_DISPINTERFACE_DEFINED__
#define __ICaesarCiphe_DISPINTERFACE_DEFINED__

/* dispinterface ICaesarCiphe */
/* [uuid] */ 


EXTERN_C const IID DIID_ICaesarCiphe;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("3D764B2E-B1B9-4BE2-99AB-D8196E44048E")
    ICaesarCiphe : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct ICaesarCipheVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICaesarCiphe * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICaesarCiphe * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICaesarCiphe * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICaesarCiphe * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICaesarCiphe * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICaesarCiphe * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICaesarCiphe * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } ICaesarCipheVtbl;

    interface ICaesarCiphe
    {
        CONST_VTBL struct ICaesarCipheVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICaesarCiphe_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICaesarCiphe_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICaesarCiphe_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICaesarCiphe_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICaesarCiphe_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICaesarCiphe_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICaesarCiphe_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ICaesarCiphe_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_CaesarCiphe;

#ifdef __cplusplus

class DECLSPEC_UUID("3D38A066-FC7C-4FCE-A07C-A83A89E8AC90")
CaesarCiphe;
#endif
#endif /* __CaesarCiphe_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


