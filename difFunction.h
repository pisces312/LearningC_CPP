//#ifndef DIFFUNCTION_H_INCLUDED
//#define DIFFUNCTION_H_INCLUDED
//#include <stdio.h>
//
//#include <new>
//
//
//
//class Base
//
//{
//
//    public:
//
//    int m_nCallCount;
//
//
//
//    Base()
//
//    {
//
//        m_nCallCount = 0;
//
//    }
//
//
//
//    void __cdecl CdeclStaticFuncation(const wchar_t *pwzMessage);
//
//    void __thiscall ThiscallStaticFunction(const wchar_t *pwzMessage);
//
//    void __stdcall StdcallStaticFuncation(const wchar_t *pwzMessage);
//
//
//
//    virtual void __thiscall VirtualFunction(const wchar_t *pwzMessage) = 0;
//
//    virtual void __thiscall VirtualFunction2(const wchar_t *pwzMessage) = 0;
//
//};
//
//
//
//
//
//class Inherited: public Base
//
//{
//
//    public:
//
//    virtual void __thiscall VirtualFunction(const wchar_t *pwzMessage);
//
//    virtual void __thiscall VirtualFunction2(const wchar_t *pwzMessage);
//
//};
//
//
//
//void Base::CdeclStaticFuncation(const wchar_t *pwzMessage)
//
//{
//
//    ++m_nCallCount;
//
//    wprintf(L"%02d CALL __cdcel static funcation: %s\n", m_nCallCount, pwzMessage);
//
//}
//
//
//
//void Base::ThiscallStaticFunction(const wchar_t *pwzMessage)
//
//{
//
//    ++m_nCallCount;
//
//    wprintf(L"%02d CALL __thiscall static funcation: %s\n", m_nCallCount, pwzMessage);
//
//}
//
//
//
//void Base::StdcallStaticFuncation(const wchar_t *pwzMessage)
//
//{
//
//    ++m_nCallCount;
//
//    wprintf(L"%02d CALL __stdcall static funcation: %s\n", m_nCallCount, pwzMessage);
//
//}
//
//
//
//void Inherited::VirtualFunction(const wchar_t *pwzMessage)
//
//{
//
//    ++m_nCallCount;
//
//    wprintf(L"%02d CALL __cdcel virtual function 1: %s\n", m_nCallCount, pwzMessage);
//
//}
//
//
//
//void Inherited::VirtualFunction2(const wchar_t *pwzMessage)
//
//{
//
//    ++m_nCallCount;
//
//    wprintf(L"%02d CALL __cdcel virtual function 2: %s\n", m_nCallCount, pwzMessage);
//
//}
//
//
//
//void CFunction(Base *pBase, const wchar_t *pwzMessage)
//
//{
//
//    ++(pBase->m_nCallCount);
//
//    wprintf(L"%02d CALL C funcation: %s\n", pBase->m_nCallCount, pwzMessage);
//
//}
//
//
//
////int wmain(int argc, wchar_t* argv[])
//void testDifFun() {
//
//    const wchar_t *pwzMessage = L"Hello World!";
//
//    Base *pBase = new(std::nothrow) Inherited();
//
//    if (NULL == pBase)
//
//    {
//
//        wprintf(L"Out of memory");
//
//        return -1;
//
//    }
//
//
//
//    //
//
//    // Call standard C function
//
//    //
//
//    __asm
//
//    {
//
//        push    pwzMessage
//
//        push    pBase
//
//        call    CFunction
//
//        add     esp,    08h         // caller cleanup stack
//
//    }
//
//
//
//    //
//
//    // Call __cdcel static function
//
//    //
//
//    __asm
//
//    {
//
//        push    pwzMessage
//
//        push    pBase               // this is passed by stack
//
//        call    Base::CdeclStaticFuncation
//
//        add     esp,    08h         // caller cleanup stack
//
//    }
//
//
//
//    //
//
//    // Call __thiscall static function
//
//    //
//
//    __asm
//
//    {
//
//        push    pwzMessage
//
//        mov     ecx,    pBase       // this is passed by register ecx
//
//        call    Base::ThiscallStaticFunction
//
//        // callee cleanup stack
//
//    }
//
//
//
//    //
//
//    // Call __stdcall static function
//
//    //
//
//    __asm
//
//    {
//
//        push    pwzMessage
//
//        push    pBase               // this is passed by stack
//
//        call    Base::StdcallStaticFuncation
//
//        // callee cleanup stack
//
//    }
//
//
//
//    //
//
//    // Call __thiscall virtual function 1
//
//    //
//
//    __asm
//
//    {
//
//        push    pwzMessage
//
//        mov     ecx,    pBase       // this is passed by register ecx
//
//        mov     eax,    [ecx]       // read address of virtual table address to eax
//
//        mov     edx,    [eax]       // read address of virtual function 1 to edx
//
//        call    edx
//
//    }
//
//
//
//    //
//
//    // Call __thiscall virtual function 2
//
//    //
//
//    __asm
//
//    {
//
//        push    pwzMessage
//
//        mov     ecx,    pBase       // this is passed by register ecx
//
//        mov     eax,    [ecx]       // read address of virtual table address to eax
//
//        mov     edx,    [eax]+4     // read address of virtual function 2 to edx
//
//        call    edx
//
//    }
//
//
//
//    delete pBase;
//
////    return 0;
//
//}
//
//
//#endif // DIFFUNCTION_H_INCLUDED
