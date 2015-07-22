#pragma once

// What OS ?
// our definition has the form _{osname}_

#if defined (_WIN64)
#   define _win64_
#   define _win32_
#elif defined (__WIN32__) || defined (_WIN32) // _WIN32 is also defined by the 64-bit compiler for backward compatibility
#   define _win32_
#else
#   define _unix_
#   if defined (__sun__) || defined (sun) || defined(sparc) || defined (__sparc)
#       define _sun_
#   endif
#   if defined (__hpux__)
#       define _hpux_
#   endif
#   if defined (__linux__)
#       define _linux_
#   endif
#   if defined (__FreeBSD__)
#       define _freebsd_
#   endif
#   if defined (__CYGWIN__)
#       define _cygwin_
#   endif
#   if defined (__APPLE__)
#       define _darwin_
#   endif
#endif

#if defined(_linux_)
    #define _glibc_
#endif

#if defined (_darwin_)
#   define   unix
#   define __unix__
#endif

#if defined (_win32_) || defined (_win64_)
#   define _win_
#endif

/* __ia64__ and __x86_64__      - defined by GNU C.
 * _M_IA64, _M_X64, _M_AMD64    - defined by Visual Studio.
 *
 * Microsoft can define _M_IX86, _M_AMD64 (before Visual Studio 8)
 * or _M_X64 (starting in Visual Studio 8).
 */
#if defined(__x86_64__) || defined(_M_X64) || defined(_M_AMD64)
#   define _x86_64_
#endif

#if defined(__ia64__) || defined(_M_IA64)
#   define _ia64_
#endif

#if !defined(sparc) && !defined(__sparc) && !defined(__hpux__) && !defined(__alpha__) && !defined(_ia64_) && !defined(_x86_64_)
#   define _i386_
#endif

#if defined(_x86_64_) || defined(_i386_)
#   define _x86_
#endif

// stdio or MessageBox
#if defined (__CONSOLE__) || defined(_CONSOLE)
#   define _console_
#endif
#if (defined (_win_) && !defined (_console_))
#   define _windows_
#elif !defined(_console_)
#   define _console_
#endif

#if defined(__SSE__) || defined(SSE_ENABLED)
    #define _sse_
#endif

#if defined(__SSE2__) || defined(SSE2_ENABLED)
    #define _sse2_
#endif

#if defined(__SSE3__) || defined(SSE3_ENABLED)
    #define _sse3_
#endif

#if defined(__SSSE3__) || defined(SSSE3_ENABLED)
    #define _ssse3_
#endif

// Multithreading
#if defined (__MT__) || defined(_MT) || defined (_THREAD_SAFE) || (defined (_REENTRANT) && !defined(__FreeBSD__))
#   define _mt_
#endif

// Multithreading
#if defined (__DLL__) || defined(_DLL)
#   define _dll_
#endif

// 16, 32 or 64
#if defined(__sparc_v9__) || defined(_x86_64_) || defined(_ia64_)
#   define _64_
#else
#   define _32_
#endif

/* All modern 64-bit Unix systems use scheme LP64 (long, pointers are 64-bit).
 * Microsoft uses a different scheme: LLP64 (long long, pointers are 64-bit).
 *
 * Scheme          LP64   LLP64
 * char              8      8
 * short            16     16
 * int              32     32
 * long             64     32
 * long long        64     64
 * pointer          64     64
 */

#if defined(_32_)
#   define SIZEOF_PTR 4
#elif defined(_64_)
#   define SIZEOF_PTR 8
#endif

#define PLATFORM_DATA_ALIGN SIZEOF_PTR

#if !defined(SIZEOF_PTR)
    #error todo
#endif

#define SIZEOF_CHAR     1
#define SIZEOF_SHORT    2
#define SIZEOF_INT      4

#if defined(_32_)
#   define SIZEOF_LONG  4
#elif defined(_64_)
#   if defined(_win_)
#       define SIZEOF_LONG  4
#   else
#       define SIZEOF_LONG  8
#   endif // _win_
#endif // _32_

#if !defined(SIZEOF_LONG)
    #error todo
#endif

#define SIZEOF_LONG_LONG 8

#undef SIZEOF_SIZE_T // in case we include <Python.h> which defines it, too
#define SIZEOF_SIZE_T SIZEOF_PTR

#define SIZEOF_UNSIGNED_CHAR SIZEOF_CHAR
#define SIZEOF_UNSIGNED_INT SIZEOF_INT
#define SIZEOF_UNSIGNED_LONG SIZEOF_LONG
#define SIZEOF_UNSIGNED_LONG_LONG SIZEOF_LONG_LONG
#define SIZEOF_UNSIGNED_SHORT SIZEOF_SHORT

#if defined(__INTEL_COMPILER)
    #pragma warning(disable 1292)
    #pragma warning(disable 1469)
    #pragma warning(disable 193)
    #pragma warning(disable 271)
    #pragma warning(disable 383)
    #pragma warning(disable 424)
    #pragma warning(disable 444)
    #pragma warning(disable 584)
    #pragma warning(disable 593)
    #pragma warning(disable 981)
    #pragma warning(disable 1418)
    #pragma warning(disable 304)
    #pragma warning(disable 810)
    #pragma warning(disable 1029)
    #pragma warning(disable 1419)
    #pragma warning(disable 177)
    #pragma warning(disable 522)
    #pragma warning(disable 858)
    #pragma warning(disable 111)
    #pragma warning(disable 1599)
    #pragma warning(disable 411)
    #pragma warning(disable 304)
    #pragma warning(disable 858)
    #pragma warning(disable 444)
    #pragma warning(disable 913)
    #pragma warning(disable 310)
    #pragma warning(disable 167)
    #pragma warning(disable 180)
    #pragma warning(disable 1572)
#endif
