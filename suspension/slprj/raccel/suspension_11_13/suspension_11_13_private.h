#include "__cf_suspension_11_13.h"
#ifndef RTW_HEADER_suspension_11_13_private_h_
#define RTW_HEADER_suspension_11_13_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "suspension_11_13.h"
#if !defined(rt_VALIDATE_MEMORY)
#define rt_VALIDATE_MEMORY(S, ptr)   if(!(ptr)) {\
  ssSetErrorStatus(rtS, RT_MEMORY_ALLOCATION_ERROR);\
  }
#endif
#if !defined(rt_FREE)
#if !defined(_WIN32)
#define rt_FREE(ptr)   if((ptr) != (NULL)) {\
  free((ptr));\
  (ptr) = (NULL);\
  }
#else
#define rt_FREE(ptr)   if((ptr) != (NULL)) {\
  free((void *)(ptr));\
  (ptr) = (NULL);\
  }
#endif
#endif
#ifndef __RTW_UTFREE__
extern void * utMalloc ( size_t ) ; extern void utFree ( void * ) ;
#endif
void * rt_TDelayCreateBuf ( int_T numBuffer , int_T bufSz , int_T elemSz ) ;
boolean_T rt_TDelayUpdateTailOrGrowBuf ( int_T * bufSzPtr , int_T * tailPtr ,
int_T * headPtr , int_T * lastPtr , real_T tMinusDelay , real_T * * tBufPtr ,
real_T * * uBufPtr , real_T * * xBufPtr , boolean_T isfixedbuf , boolean_T
istransportdelay , int_T * maxNewBufSzPtr ) ; real_T rt_TDelayInterpolate (
real_T tMinusDelay , real_T tStart , real_T * tBuf , real_T * uBuf , int_T
bufSz , int_T * lastIdx , int_T oldestIdx , int_T newIdx , real_T initOutput
, boolean_T discrete , boolean_T minorStepAndTAtLastMajorOutput ) ; void
rt_TDelayFreeBuf ( void * buf ) ; extern void ipps4dfwvh ( SimStruct * rtS_e
) ; extern void fwcmlgyrtk ( SimStruct * rtS_p ) ; extern void nbpepiek5a (
SimStruct * rtS_i , real_T js34zl0oyc , real_T * jsjyvni5bz ) ; extern void
i2sc5lqney ( SimStruct * rtS_i ) ; extern void dr3q4xjhlf ( SimStruct * rtS_m
) ; extern void fsrrbnl0on ( SimStruct * rtS_e , real_T pdgfn5gzgr , real_T *
ck1dsstaun ) ;
#if defined(MULTITASKING)
#error Models using the variable step solvers cannot define MULTITASKING
#endif
#endif
