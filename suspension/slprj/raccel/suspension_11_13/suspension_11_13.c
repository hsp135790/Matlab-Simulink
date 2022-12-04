#include "__cf_suspension_11_13.h"
#include "rt_logging_mmi.h"
#include "suspension_11_13_capi.h"
#include <math.h>
#include "suspension_11_13.h"
#include "suspension_11_13_private.h"
#include "suspension_11_13_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; extern boolean_T
gblExtModeStartPktReceived ; void raccelForceExtModeShutdown ( ) { if ( !
gblExtModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 5 , & stopRequested ) ; }
rtExtModeShutdown ( 5 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 6 ; const char_T
* gbl_raccel_Version = "10.0 (R2019b) 18-Jul-2019" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const char * gblSlvrJacPatternFileName =
"slprj\\raccel\\suspension_11_13\\suspension_11_13_Jpattern.mat" ; const
int_T gblNumRootInportBlks = 0 ; const int_T gblNumModelInputs = 0 ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
extern void * gblAperiodicPartitionHitTimes ; const int_T
gblInportDataTypeIdx [ ] = { - 1 } ; const int_T gblInportDims [ ] = { - 1 }
; const int_T gblInportComplex [ ] = { - 1 } ; const int_T
gblInportInterpoFlag [ ] = { - 1 } ; const int_T gblInportContinuous [ ] = {
- 1 } ; int_T enableFcnCallFlag [ ] = { 1 , 1 , 1 , 1 , 1 , 1 } ; const char
* raccelLoadInputsAndAperiodicHitTimes ( const char * inportFileName , int *
matFileFormat ) { return rt_RapidReadInportsMatFile ( inportFileName ,
matFileFormat , 1 ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
B rtB ; X rtX ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS =
& model_S ;
#ifndef __RTW_UTFREE__  
extern void * utMalloc ( size_t ) ;
#endif
void * rt_TDelayCreateBuf ( int_T numBuffer , int_T bufSz , int_T elemSz ) {
return ( ( void * ) utMalloc ( numBuffer * bufSz * elemSz ) ) ; }
#ifndef __RTW_UTFREE__  
extern void * utMalloc ( size_t ) ; extern void utFree ( void * ) ;
#endif
boolean_T rt_TDelayUpdateTailOrGrowBuf ( int_T * bufSzPtr , int_T * tailPtr ,
int_T * headPtr , int_T * lastPtr , real_T tMinusDelay , real_T * * tBufPtr ,
real_T * * uBufPtr , real_T * * xBufPtr , boolean_T isfixedbuf , boolean_T
istransportdelay , int_T * maxNewBufSzPtr ) { int_T testIdx ; int_T tail = *
tailPtr ; int_T bufSz = * bufSzPtr ; real_T * tBuf = * tBufPtr ; real_T *
xBuf = ( NULL ) ; int_T numBuffer = 2 ; if ( istransportdelay ) { numBuffer =
3 ; xBuf = * xBufPtr ; } testIdx = ( tail < ( bufSz - 1 ) ) ? ( tail + 1 ) :
0 ; if ( ( tMinusDelay <= tBuf [ testIdx ] ) && ! isfixedbuf ) { int_T j ;
real_T * tempT ; real_T * tempU ; real_T * tempX = ( NULL ) ; real_T * uBuf =
* uBufPtr ; int_T newBufSz = bufSz + 1024 ; if ( newBufSz > * maxNewBufSzPtr
) { * maxNewBufSzPtr = newBufSz ; } tempU = ( real_T * ) utMalloc ( numBuffer
* newBufSz * sizeof ( real_T ) ) ; if ( tempU == ( NULL ) ) { return ( false
) ; } tempT = tempU + newBufSz ; if ( istransportdelay ) tempX = tempT +
newBufSz ; for ( j = tail ; j < bufSz ; j ++ ) { tempT [ j - tail ] = tBuf [
j ] ; tempU [ j - tail ] = uBuf [ j ] ; if ( istransportdelay ) tempX [ j -
tail ] = xBuf [ j ] ; } for ( j = 0 ; j < tail ; j ++ ) { tempT [ j + bufSz -
tail ] = tBuf [ j ] ; tempU [ j + bufSz - tail ] = uBuf [ j ] ; if (
istransportdelay ) tempX [ j + bufSz - tail ] = xBuf [ j ] ; } if ( * lastPtr
> tail ) { * lastPtr -= tail ; } else { * lastPtr += ( bufSz - tail ) ; } *
tailPtr = 0 ; * headPtr = bufSz ; utFree ( uBuf ) ; * bufSzPtr = newBufSz ; *
tBufPtr = tempT ; * uBufPtr = tempU ; if ( istransportdelay ) * xBufPtr =
tempX ; } else { * tailPtr = testIdx ; } return ( true ) ; } real_T
rt_TDelayInterpolate ( real_T tMinusDelay , real_T tStart , real_T * tBuf ,
real_T * uBuf , int_T bufSz , int_T * lastIdx , int_T oldestIdx , int_T
newIdx , real_T initOutput , boolean_T discrete , boolean_T
minorStepAndTAtLastMajorOutput ) { int_T i ; real_T yout , t1 , t2 , u1 , u2
; if ( ( newIdx == 0 ) && ( oldestIdx == 0 ) && ( tMinusDelay > tStart ) )
return initOutput ; if ( tMinusDelay <= tStart ) return initOutput ; if ( (
tMinusDelay <= tBuf [ oldestIdx ] ) ) { if ( discrete ) { return ( uBuf [
oldestIdx ] ) ; } else { int_T tempIdx = oldestIdx + 1 ; if ( oldestIdx ==
bufSz - 1 ) tempIdx = 0 ; t1 = tBuf [ oldestIdx ] ; t2 = tBuf [ tempIdx ] ;
u1 = uBuf [ oldestIdx ] ; u2 = uBuf [ tempIdx ] ; if ( t2 == t1 ) { if (
tMinusDelay >= t2 ) { yout = u2 ; } else { yout = u1 ; } } else { real_T f1 =
( t2 - tMinusDelay ) / ( t2 - t1 ) ; real_T f2 = 1.0 - f1 ; yout = f1 * u1 +
f2 * u2 ; } return yout ; } } if ( minorStepAndTAtLastMajorOutput ) { if (
newIdx != 0 ) { if ( * lastIdx == newIdx ) { ( * lastIdx ) -- ; } newIdx -- ;
} else { if ( * lastIdx == newIdx ) { * lastIdx = bufSz - 1 ; } newIdx =
bufSz - 1 ; } } i = * lastIdx ; if ( tBuf [ i ] < tMinusDelay ) { while (
tBuf [ i ] < tMinusDelay ) { if ( i == newIdx ) break ; i = ( i < ( bufSz - 1
) ) ? ( i + 1 ) : 0 ; } } else { while ( tBuf [ i ] >= tMinusDelay ) { i = (
i > 0 ) ? i - 1 : ( bufSz - 1 ) ; } i = ( i < ( bufSz - 1 ) ) ? ( i + 1 ) : 0
; } * lastIdx = i ; if ( discrete ) { double tempEps = ( DBL_EPSILON ) *
128.0 ; double localEps = tempEps * muDoubleScalarAbs ( tBuf [ i ] ) ; if (
tempEps > localEps ) { localEps = tempEps ; } localEps = localEps / 2.0 ; if
( tMinusDelay >= ( tBuf [ i ] - localEps ) ) { yout = uBuf [ i ] ; } else {
if ( i == 0 ) { yout = uBuf [ bufSz - 1 ] ; } else { yout = uBuf [ i - 1 ] ;
} } } else { if ( i == 0 ) { t1 = tBuf [ bufSz - 1 ] ; u1 = uBuf [ bufSz - 1
] ; } else { t1 = tBuf [ i - 1 ] ; u1 = uBuf [ i - 1 ] ; } t2 = tBuf [ i ] ;
u2 = uBuf [ i ] ; if ( t2 == t1 ) { if ( tMinusDelay >= t2 ) { yout = u2 ; }
else { yout = u1 ; } } else { real_T f1 = ( t2 - tMinusDelay ) / ( t2 - t1 )
; real_T f2 = 1.0 - f1 ; yout = f1 * u1 + f2 * u2 ; } } return ( yout ) ; }
#ifndef __RTW_UTFREE__  
extern void utFree ( void * ) ;
#endif
void rt_TDelayFreeBuf ( void * buf ) { utFree ( buf ) ; } void ipps4dfwvh (
SimStruct * rtS_e ) { if ( ssGetTaskTime ( rtS_e , 0 ) != ssGetTStart ( rtS_e
) ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS_e ) ; } } void
fwcmlgyrtk ( SimStruct * rtS_p ) { ssSetBlockStateForSolverChangedAtMajorStep
( rtS_p ) ; } void nbpepiek5a ( SimStruct * rtS_i , real_T js34zl0oyc ,
real_T * jsjyvni5bz ) { if ( ssIsSampleHit ( rtS_i , 1 , 0 ) ) { * jsjyvni5bz
= js34zl0oyc ; } } void i2sc5lqney ( SimStruct * rtS_i ) { if ( ssGetTaskTime
( rtS_i , 0 ) != ssGetTStart ( rtS_i ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS_i ) ; } } void dr3q4xjhlf (
SimStruct * rtS_m ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS_m ) ;
} void fsrrbnl0on ( SimStruct * rtS_e , real_T pdgfn5gzgr , real_T *
ck1dsstaun ) { if ( ssIsSampleHit ( rtS_e , 1 , 0 ) ) { * ck1dsstaun =
pdgfn5gzgr ; } } void MdlInitialize ( void ) { rtX . juvpl32rp1 = rtP .
Integrator2_IC ; rtX . e2u4ehzbg1 = rtP . Integrator2_IC_clvdfmmn2j ; rtX .
kyyzo52dwm = rtP . Integrator2_IC_icgsg0ay1z ; rtX . ku1dk4ixzj = rtP .
Integrator2_IC_izuk2xqhyn ; rtX . koq0js0atb = rtP . Integrator1_IC ; rtX .
pionb1hpkd = rtP . Integrator1_IC_kd2vqetgqx ; rtX . gjyvqirdz3 = rtP .
Integrator1_IC_ds3xtg3mkc ; rtX . aq3q20solx = rtP .
Integrator1_IC_n5ffr0esli ; rtX . o3tzwtysbm = rtP . Integrator5_IC ; rtX .
bqwvntcz2w = rtP . Integrator5_IC_iosnn25ku4 ; rtX . lsnvs0t4wu = rtP .
Integrator5_IC_pbm1hhtqvq ; rtX . bzhhffa4dl = rtP .
Integrator5_IC_fmb14y3cnw ; rtX . bgj1d5tkhj = rtP . Integrator3_IC ; rtX .
ky5ai02ezd = rtP . Integrator3_IC_h0aez5va4u ; rtX . dplugctjxc = rtP .
Integrator3_IC_mc4a1wd42u ; rtX . cpl1ejbcms = rtP .
Integrator3_IC_ghtohsff01 ; rtX . n2slq3mqpo = rtP . Integrator7_IC ; rtX .
hxtsx1lenp = rtP . Integrator7_IC_bzmaczyftv ; rtX . ne20tsu1eg = rtP .
Integrator7_IC_hsyswncslp ; rtX . hyvy5y052m = rtP .
Integrator7_IC_jvqwwdf42v ; rtX . lqt0ebaexk = rtP . Integrator_IC ; rtX .
nherdhh2v5 = rtP . Integrator4_IC ; rtX . ptgllb4wkr = rtP . Integrator6_IC ;
rtDW . gfprm23pj3 = ( rtInf ) ; rtDW . najgra25s3 = ( rtInf ) ; rtDW .
nflnwukwbw = ( rtInf ) ; rtDW . de4qoi0fyx = ( rtInf ) ; rtX . avtxyi5gqp =
rtP . Integrator_IC_gsjia5qsst ; rtX . b3davkt1eh = rtP .
Integrator4_IC_cigt4hske3 ; rtX . pulwqgjkwh = rtP .
Integrator6_IC_h1i5q5y2jf ; rtDW . jpmhq0y24v = ( rtInf ) ; rtDW . ijphmshkuf
= ( rtInf ) ; rtDW . mntyae3rsq = ( rtInf ) ; rtDW . psneabumzv = ( rtInf ) ;
rtX . g2zcmmoypm = rtP . Integrator_IC_e0ie1xk1t1 ; rtX . efgd0a2xyp = rtP .
Integrator4_IC_bdrpcflxad ; rtX . i3bwmkwwlg = rtP .
Integrator6_IC_ktopl34sag ; rtDW . goagc5i3gw = ( rtInf ) ; rtDW . k5o3zhu0wr
= ( rtInf ) ; rtDW . dqvle0o2bf = ( rtInf ) ; rtDW . dp5dxb3enf = ( rtInf ) ;
rtX . a01qpr25bd = rtP . Integrator_IC_dw0j2rkbay ; rtX . gfofwzctbq = rtP .
Integrator4_IC_me53n3zt1r ; rtX . ixsdqmndrc = rtP .
Integrator6_IC_osnmqre5ia ; rtDW . lxx1qcag42 = ( rtInf ) ; rtDW . nktwazk3xa
= ( rtInf ) ; rtDW . hxmdtipph3 = ( rtInf ) ; rtDW . hrm31px4c4 = ( rtInf ) ;
} void MdlStart ( void ) { { void * * slioCatalogueAddr =
rt_slioCatalogueAddr ( ) ; void * r2 = ( NULL ) ; void * *
pOSigstreamManagerAddr = ( NULL ) ; const int maxErrorBufferSize = 16384 ;
char errMsgCreatingOSigstreamManager [ 16384 ] ; bool
errorCreatingOSigstreamManager = false ; const char *
errorAddingR2SharedResource = ( NULL ) ; * slioCatalogueAddr =
rtwGetNewSlioCatalogue ( rt_GetMatSigLogSelectorFileName ( ) ) ;
errorAddingR2SharedResource = rtwAddR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) , 1 ) ; if (
errorAddingR2SharedResource != ( NULL ) ) { rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = ( NULL ) ; ssSetErrorStatus ( rtS
, errorAddingR2SharedResource ) ; return ; } r2 = rtwGetR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ) ;
pOSigstreamManagerAddr = rt_GetOSigstreamManagerAddr ( ) ;
errorCreatingOSigstreamManager = rtwOSigstreamManagerCreateInstance (
rt_GetMatSigLogSelectorFileName ( ) , r2 , pOSigstreamManagerAddr ,
errMsgCreatingOSigstreamManager , maxErrorBufferSize ) ; if (
errorCreatingOSigstreamManager ) { * pOSigstreamManagerAddr = ( NULL ) ;
ssSetErrorStatus ( rtS , errMsgCreatingOSigstreamManager ) ; return ; } } {
bool externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( ) ; rtwISigstreamManagerGetInputIsInDatasetFormat (
pISigstreamManager , & externalInputIsInDatasetFormat ) ; if (
externalInputIsInDatasetFormat ) { } } rtDW . f3jqreldag = - 1 ; rtDW .
lkxdv3gp4l = - 1 ; { { real_T * pBuffer = ( real_T * ) rt_TDelayCreateBuf ( 2
, 1024 , sizeof ( real_T ) ) ; if ( pBuffer == ( NULL ) ) { ssSetErrorStatus
( rtS , "tdelay memory allocation error" ) ; return ; } rtDW . ewcikv2lwd .
Tail = 0 ; rtDW . ewcikv2lwd . Head = 0 ; rtDW . ewcikv2lwd . Last = 0 ; rtDW
. ewcikv2lwd . CircularBufSize = 1024 ; pBuffer [ 0 ] = rtP .
TransportDelay_InitOutput ; pBuffer [ 1024 ] = ssGetT ( rtS ) ; rtDW .
jlohj4cavb . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ; rtDW .
jlohj4cavb . TUbufferPtrs [ 1 ] = ( void * ) & pBuffer [ 1024 ] ; } } rtDW .
jqk4qa3xek = - 1 ; { { real_T * pBuffer = ( real_T * ) rt_TDelayCreateBuf ( 2
, 1024 , sizeof ( real_T ) ) ; if ( pBuffer == ( NULL ) ) { ssSetErrorStatus
( rtS , "tdelay memory allocation error" ) ; return ; } rtDW . fv0rpgctfs .
Tail = 0 ; rtDW . fv0rpgctfs . Head = 0 ; rtDW . fv0rpgctfs . Last = 0 ; rtDW
. fv0rpgctfs . CircularBufSize = 1024 ; pBuffer [ 0 ] = rtP .
TransportDelay1_InitOutput ; pBuffer [ 1024 ] = ssGetT ( rtS ) ; rtDW .
l1amy53ft4 . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ; rtDW .
l1amy53ft4 . TUbufferPtrs [ 1 ] = ( void * ) & pBuffer [ 1024 ] ; } } rtDW .
jcg5lahs5d = - 1 ; rtDW . bugzjuygkx = - 1 ; rtDW . dd30o4lozm = - 1 ; rtDW .
ljkqmp5hio = - 1 ; rtDW . mtbsrpr2ww = - 1 ; { { real_T * pBuffer = ( real_T
* ) rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer == (
NULL ) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ;
return ; } rtDW . ped5kwc4j1 . Tail = 0 ; rtDW . ped5kwc4j1 . Head = 0 ; rtDW
. ped5kwc4j1 . Last = 0 ; rtDW . ped5kwc4j1 . CircularBufSize = 1024 ;
pBuffer [ 0 ] = rtP . TransportDelay_InitOutput_ea1344nau0 ; pBuffer [ 1024 ]
= ssGetT ( rtS ) ; rtDW . omrnl2kvox . TUbufferPtrs [ 0 ] = ( void * ) &
pBuffer [ 0 ] ; rtDW . omrnl2kvox . TUbufferPtrs [ 1 ] = ( void * ) & pBuffer
[ 1024 ] ; } } rtDW . ndweztnvdz = - 1 ; rtDW . jg4lsy03zm = - 1 ; { { real_T
* pBuffer = ( real_T * ) rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) )
; if ( pBuffer == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; } rtDW . aem0ceeew5 . Tail = 0
; rtDW . aem0ceeew5 . Head = 0 ; rtDW . aem0ceeew5 . Last = 0 ; rtDW .
aem0ceeew5 . CircularBufSize = 1024 ; pBuffer [ 0 ] = rtP .
TransportDelay1_InitOutput_etxwutwb0s ; pBuffer [ 1024 ] = ssGetT ( rtS ) ;
rtDW . b0rupvaogl . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ; rtDW .
b0rupvaogl . TUbufferPtrs [ 1 ] = ( void * ) & pBuffer [ 1024 ] ; } } rtDW .
lgxvz4jhdw = - 1 ; rtDW . hgbx4f0dqj = - 1 ; { { real_T * pBuffer = ( real_T
* ) rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer == (
NULL ) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ;
return ; } rtDW . nogfvg0pt3 . Tail = 0 ; rtDW . nogfvg0pt3 . Head = 0 ; rtDW
. nogfvg0pt3 . Last = 0 ; rtDW . nogfvg0pt3 . CircularBufSize = 1024 ;
pBuffer [ 0 ] = rtP . TransportDelay_InitOutput_cflcileqko ; pBuffer [ 1024 ]
= ssGetT ( rtS ) ; rtDW . onssg0ise1 . TUbufferPtrs [ 0 ] = ( void * ) &
pBuffer [ 0 ] ; rtDW . onssg0ise1 . TUbufferPtrs [ 1 ] = ( void * ) & pBuffer
[ 1024 ] ; } } { { real_T * pBuffer = ( real_T * ) rt_TDelayCreateBuf ( 2 ,
1024 , sizeof ( real_T ) ) ; if ( pBuffer == ( NULL ) ) { ssSetErrorStatus (
rtS , "tdelay memory allocation error" ) ; return ; } rtDW . hs0pmpahcd .
Tail = 0 ; rtDW . hs0pmpahcd . Head = 0 ; rtDW . hs0pmpahcd . Last = 0 ; rtDW
. hs0pmpahcd . CircularBufSize = 1024 ; pBuffer [ 0 ] = rtP .
TransportDelay1_InitOutput_gsatvdlebd ; pBuffer [ 1024 ] = ssGetT ( rtS ) ;
rtDW . h3nqanizu1 . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ; rtDW .
h3nqanizu1 . TUbufferPtrs [ 1 ] = ( void * ) & pBuffer [ 1024 ] ; } } rtDW .
c12zxjgx2e = - 1 ; rtDW . d3g033qzzb = - 1 ; { { real_T * pBuffer = ( real_T
* ) rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer == (
NULL ) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ;
return ; } rtDW . pmbhiaijnw . Tail = 0 ; rtDW . pmbhiaijnw . Head = 0 ; rtDW
. pmbhiaijnw . Last = 0 ; rtDW . pmbhiaijnw . CircularBufSize = 1024 ;
pBuffer [ 0 ] = rtP . TransportDelay_InitOutput_jhwmjqic5y ; pBuffer [ 1024 ]
= ssGetT ( rtS ) ; rtDW . ip30edpzn0 . TUbufferPtrs [ 0 ] = ( void * ) &
pBuffer [ 0 ] ; rtDW . ip30edpzn0 . TUbufferPtrs [ 1 ] = ( void * ) & pBuffer
[ 1024 ] ; } } rtDW . kgnaiafrhn = - 1 ; { { real_T * pBuffer = ( real_T * )
rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer == ( NULL
) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ;
} rtDW . mbyl5zsvhx . Tail = 0 ; rtDW . mbyl5zsvhx . Head = 0 ; rtDW .
mbyl5zsvhx . Last = 0 ; rtDW . mbyl5zsvhx . CircularBufSize = 1024 ; pBuffer
[ 0 ] = rtP . TransportDelay1_InitOutput_i1rr3k5rot ; pBuffer [ 1024 ] =
ssGetT ( rtS ) ; rtDW . nrh2tscls2 . TUbufferPtrs [ 0 ] = ( void * ) &
pBuffer [ 0 ] ; rtDW . nrh2tscls2 . TUbufferPtrs [ 1 ] = ( void * ) & pBuffer
[ 1024 ] ; } } rtDW . k4echvbh31 = - 1 ; MdlInitialize ( ) ; } void
MdlOutputs ( int_T tid ) { real_T c1dadngp3u ; real_T fqgazswzy5 ; real_T
f1ev1iuyhe ; real_T dwbg3d3uz0 ; real_T nkaj01jval ; real_T pwlbimvptw ;
real_T ptcf3mv0hj ; real_T ghoyjfeb1k ; real_T * lastU ; real_T lastTime ;
int8_T rtPrevAction ; int8_T rtAction ; srClearBC ( rtDW . nbpepiek5as .
c4bsnmlro2 ) ; srClearBC ( rtDW . fsrrbnl0ono . ax0ejju01d ) ; rtB .
ckhfos3d5d = rtX . juvpl32rp1 ; rtB . ctr3nygjvu = rtX . e2u4ehzbg1 ; rtB .
gihker42li = rtX . kyyzo52dwm ; rtB . fgv0iw5io4 = rtX . ku1dk4ixzj ; rtB .
jbu2t0zvvf = rtX . koq0js0atb ; rtB . igbnss0o0f = rtX . pionb1hpkd ; rtB .
cwi04tubt0 = rtX . gjyvqirdz3 ; rtB . khpnmtgkim = rtX . aq3q20solx ; rtB .
mcgc55onte = rtX . o3tzwtysbm ; rtB . lxtjreczcv = rtX . bqwvntcz2w ; rtB .
g2y0j4r4xp = rtX . lsnvs0t4wu ; rtB . ivrqxfr4p2 = rtX . bzhhffa4dl ; rtB .
pawhsqlpds = rtX . bgj1d5tkhj ; rtB . j4ut0d52c5 = rtP . Gain_Gain * rtB .
pawhsqlpds ; rtB . ppy2yksd3e = rtX . ky5ai02ezd ; rtB . dkbiwipjls = rtP .
Gain_Gain_kfgmdgojqi * rtB . ppy2yksd3e ; rtB . cwjqfhgoni = rtX . dplugctjxc
; rtB . c1vwcagcv1 = rtP . Gain_Gain_lniewnxiui * rtB . cwjqfhgoni ; rtB .
ohobmojlqf = rtX . cpl1ejbcms ; rtB . ovbcvugezj = rtP . Gain_Gain_ncm0idjmjp
* rtB . ohobmojlqf ; rtB . jvzmdt5nzv = rtX . n2slq3mqpo ; rtB . f2micsnrzs =
rtX . hxtsx1lenp ; rtB . ncrqgav3ps = rtX . ne20tsu1eg ; rtB . aacyykkcvt =
rtX . hyvy5y052m ; rtB . cur3cpy4nj = rtP . lf * rtB . ppy2yksd3e ; rtB .
bvxzxcagw2 = ( rtB . cur3cpy4nj + rtB . igbnss0o0f ) - rtB . lxtjreczcv ; rtB
. ges324gpjn = rtP . lr * rtB . ppy2yksd3e ; rtB . bv1suo0epr = ( rtB .
ges324gpjn - rtB . igbnss0o0f ) + rtB . f2micsnrzs ; rtB . kxytv3kagx = rtP .
lf * rtB . ctr3nygjvu ; rtB . oy1jpf0hjr = rtX . lqt0ebaexk ; rtB .
hp1xxrtth5 = rtX . nherdhh2v5 ; rtB . oop0utfex2 = ( rtB . kxytv3kagx + rtB .
oy1jpf0hjr ) - rtB . hp1xxrtth5 ; rtB . oe3cby5so1 = rtP . lr * rtB .
ctr3nygjvu ; rtB . oshpndvkvq = rtX . ptgllb4wkr ; rtB . jn21fsqluy = ( rtB .
oe3cby5so1 - rtB . oy1jpf0hjr ) + rtB . oshpndvkvq ; rtB . kw2jpjnlx1 = rtP .
kfs * rtB . bvxzxcagw2 ; rtB . n0e2xw5ck4 = rtP . krs * rtB . bv1suo0epr ;
rtB . nbl2g1zklu = ( rtB . oy1jpf0hjr - rtB . hp1xxrtth5 ) * ( rtP .
Gain9_Gain * rtB . hp1xxrtth5 ) ; rtPrevAction = rtDW . f3jqreldag ; if (
ssIsMajorTimeStep ( rtS ) ) { rtAction = ( int8_T ) ! ( rtB . nbl2g1zklu >=
0.0 ) ; rtDW . f3jqreldag = rtAction ; } else { rtAction = rtDW . f3jqreldag
; } if ( rtPrevAction != rtAction ) { switch ( rtPrevAction ) { case 0 :
fwcmlgyrtk ( rtS ) ; break ; case 1 : dr3q4xjhlf ( rtS ) ; break ; } } switch
( rtAction ) { case 0 : if ( rtAction != rtPrevAction ) { ipps4dfwvh ( rtS )
; } nbpepiek5a ( rtS , rtP . Constant_Value , & rtB . kgnzsa0lua ) ; if (
ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW . nbpepiek5as . c4bsnmlro2 )
; } break ; case 1 : if ( rtAction != rtPrevAction ) { i2sc5lqney ( rtS ) ; }
fsrrbnl0on ( rtS , rtP . Constant1_Value , & rtB . kgnzsa0lua ) ; if (
ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW . fsrrbnl0ono . ax0ejju01d )
; } break ; } rtB . pw4bunpnxj = rtB . oop0utfex2 * rtB . kgnzsa0lua ; rtB .
husvkqrr5g = ( rtB . oy1jpf0hjr - rtB . oshpndvkvq ) * ( rtP .
Gain9_Gain_mm4lob34jr * rtB . oshpndvkvq ) ; rtPrevAction = rtDW . lkxdv3gp4l
; if ( ssIsMajorTimeStep ( rtS ) ) { rtAction = ( int8_T ) ! ( rtB .
husvkqrr5g >= 0.0 ) ; rtDW . lkxdv3gp4l = rtAction ; } else { rtAction = rtDW
. lkxdv3gp4l ; } if ( rtPrevAction != rtAction ) { switch ( rtPrevAction ) {
case 0 : fwcmlgyrtk ( rtS ) ; break ; case 1 : dr3q4xjhlf ( rtS ) ; break ; }
} switch ( rtAction ) { case 0 : if ( rtAction != rtPrevAction ) { ipps4dfwvh
( rtS ) ; } nbpepiek5a ( rtS , rtP . Constant_Value_js1bbvwx44 , & rtB .
iyiruigdqg ) ; if ( ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW .
mysqkq0tgk . c4bsnmlro2 ) ; } break ; case 1 : if ( rtAction != rtPrevAction
) { i2sc5lqney ( rtS ) ; } fsrrbnl0on ( rtS , rtP .
Constant1_Value_boctjgkrac , & rtB . iyiruigdqg ) ; if ( ssIsMajorTimeStep (
rtS ) ) { srUpdateBC ( rtDW . ajnw1b3gfz . ax0ejju01d ) ; } break ; } rtB .
fir0lhcte1 = rtB . jn21fsqluy * rtB . iyiruigdqg ; rtB . pizchjzfbl = ( ( rtB
. n0e2xw5ck4 - rtB . kw2jpjnlx1 ) - rtB . pw4bunpnxj ) + rtB . fir0lhcte1 ;
rtB . ew12od4jo4 = 1.0 / rtP . mc * rtB . pizchjzfbl ; if ( ssIsSampleHit (
rtS , 2 , 0 ) ) { if ( ssGetTaskTime ( rtS , 2 ) < rtP . Step_Time ) { rtB .
k0rxxdqz3n = rtP . Step_Y0 ; } else { rtB . k0rxxdqz3n = rtP . Step_YFinal ;
} } if ( ssIsSampleHit ( rtS , 3 , 0 ) ) { if ( ssGetTaskTime ( rtS , 3 ) <
rtP . Step1_Time ) { rtB . cbs2crqgjz = rtP . Step1_Y0 ; } else { rtB .
cbs2crqgjz = rtP . Step1_YFinal ; } } rtB . obhdstfloy = muDoubleScalarSin (
6.2831853071795862 * ssGetT ( rtS ) * rtP . SignalGenerator_Frequency ) * rtP
. SignalGenerator_Amplitude * rtB . k0rxxdqz3n * rtB . cbs2crqgjz ; rtB .
jobgxinndp = rtP . Gain_Gain_iit24j4qxf * rtB . obhdstfloy ; if ( ( rtDW .
gfprm23pj3 >= ssGetT ( rtS ) ) && ( rtDW . najgra25s3 >= ssGetT ( rtS ) ) ) {
rtB . c35haqaiz1 = 0.0 ; } else { lastTime = rtDW . gfprm23pj3 ; lastU = &
rtDW . fqetutrbi5 ; if ( rtDW . gfprm23pj3 < rtDW . najgra25s3 ) { if ( rtDW
. najgra25s3 < ssGetT ( rtS ) ) { lastTime = rtDW . najgra25s3 ; lastU = &
rtDW . lx2q3mhajb ; } } else { if ( rtDW . gfprm23pj3 >= ssGetT ( rtS ) ) {
lastTime = rtDW . najgra25s3 ; lastU = & rtDW . lx2q3mhajb ; } } rtB .
c35haqaiz1 = ( rtB . jobgxinndp - * lastU ) / ( ssGetT ( rtS ) - lastTime ) ;
} { real_T * * uBuffer = ( real_T * * ) & rtDW . jlohj4cavb . TUbufferPtrs [
0 ] ; real_T * * tBuffer = ( real_T * * ) & rtDW . jlohj4cavb . TUbufferPtrs
[ 1 ] ; real_T simTime = ssGetT ( rtS ) ; real_T tMinusDelay = simTime - rtP
. TransportDelay_Delay ; rtB . nrrfaz4txr = rt_TDelayInterpolate (
tMinusDelay , 0.0 , * tBuffer , * uBuffer , rtDW . ewcikv2lwd .
CircularBufSize , & rtDW . ewcikv2lwd . Last , rtDW . ewcikv2lwd . Tail ,
rtDW . ewcikv2lwd . Head , rtP . TransportDelay_InitOutput , 0 , ( boolean_T
) ( ssIsMinorTimeStep ( rtS ) && ( ssGetTimeOfLastOutput ( rtS ) == ssGetT (
rtS ) ) ) ) ; } if ( ( rtDW . nflnwukwbw >= ssGetT ( rtS ) ) && ( rtDW .
de4qoi0fyx >= ssGetT ( rtS ) ) ) { rtB . dnyl1ewlz0 = 0.0 ; } else { lastTime
= rtDW . nflnwukwbw ; lastU = & rtDW . j4zffuf2jc ; if ( rtDW . nflnwukwbw <
rtDW . de4qoi0fyx ) { if ( rtDW . de4qoi0fyx < ssGetT ( rtS ) ) { lastTime =
rtDW . de4qoi0fyx ; lastU = & rtDW . ay4ykamdli ; } } else { if ( rtDW .
nflnwukwbw >= ssGetT ( rtS ) ) { lastTime = rtDW . de4qoi0fyx ; lastU = &
rtDW . ay4ykamdli ; } } rtB . dnyl1ewlz0 = ( rtB . nrrfaz4txr - * lastU ) / (
ssGetT ( rtS ) - lastTime ) ; } rtB . li3nwnnqnt = rtP . lf * rtB .
ppy2yksd3e ; rtB . ds1h3d1hfe = ( rtB . li3nwnnqnt + rtB . igbnss0o0f ) - rtB
. lxtjreczcv ; rtB . gpq11xa2q4 = rtP . lf * rtB . ctr3nygjvu ; rtB .
hossx3vmtu = ( rtB . gpq11xa2q4 + rtB . oy1jpf0hjr ) - rtB . hp1xxrtth5 ; rtB
. mrgu1y10yn = rtB . hp1xxrtth5 - rtB . c35haqaiz1 ; rtB . lgzpfz3f3w = rtB .
lxtjreczcv - rtB . jobgxinndp ; rtB . dj1wmcvi0i = rtP . kfs * rtB .
ds1h3d1hfe ; rtB . jrhinsm5vq = ( rtB . oy1jpf0hjr - rtB . hp1xxrtth5 ) * (
rtP . Gain9_Gain_dqygs1aszs * rtB . hp1xxrtth5 ) ; rtPrevAction = rtDW .
jqk4qa3xek ; if ( ssIsMajorTimeStep ( rtS ) ) { rtAction = ( int8_T ) ! ( rtB
. jrhinsm5vq >= 0.0 ) ; rtDW . jqk4qa3xek = rtAction ; } else { rtAction =
rtDW . jqk4qa3xek ; } if ( rtPrevAction != rtAction ) { switch ( rtPrevAction
) { case 0 : fwcmlgyrtk ( rtS ) ; break ; case 1 : dr3q4xjhlf ( rtS ) ; break
; } } switch ( rtAction ) { case 0 : if ( rtAction != rtPrevAction ) {
ipps4dfwvh ( rtS ) ; } nbpepiek5a ( rtS , rtP . Constant_Value_pcb3rcescv , &
rtB . mjw5ulp0gg ) ; if ( ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW .
iwvaw3chcg . c4bsnmlro2 ) ; } break ; case 1 : if ( rtAction != rtPrevAction
) { i2sc5lqney ( rtS ) ; } fsrrbnl0on ( rtS , rtP .
Constant1_Value_az0xekyfmv , & rtB . mjw5ulp0gg ) ; if ( ssIsMajorTimeStep (
rtS ) ) { srUpdateBC ( rtDW . gciy5nryyx . ax0ejju01d ) ; } break ; } rtB .
o50fwsfxem = rtB . hossx3vmtu * rtB . mjw5ulp0gg ; rtB . hb00ru01fq = rtP .
kft * rtB . lgzpfz3f3w ; rtB . p4n4hpe1b1 = rtP . cft * rtB . mrgu1y10yn ;
rtB . hee11uhjj0 = ( ( rtB . dj1wmcvi0i + rtB . o50fwsfxem ) - rtB .
hb00ru01fq ) - rtB . p4n4hpe1b1 ; rtB . dshdg4oozs = 1.0 / rtP . mf * rtB .
hee11uhjj0 ; rtB . pc2izoasnn = rtP . lf * rtB . ppy2yksd3e ; rtB .
lw44fbjzmd = ( rtB . pc2izoasnn + rtB . igbnss0o0f ) - rtB . hp1xxrtth5 ; rtB
. ap5mzmnsci = rtP . lr * rtB . ppy2yksd3e ; rtB . m2jdcg5lrr = ( rtB .
ap5mzmnsci - rtB . igbnss0o0f ) + rtB . lxtjreczcv ; rtB . kxzs0jwwpz = rtP .
lr * rtB . ctr3nygjvu ; rtB . n3tlanomdr = ( rtB . kxzs0jwwpz - rtB .
oy1jpf0hjr ) + rtB . oshpndvkvq ; rtB . jjfmleyq2w = rtP . lf * rtB .
ctr3nygjvu ; rtB . ffhybcifud = ( rtB . jjfmleyq2w + rtB . oy1jpf0hjr ) - rtB
. oshpndvkvq ; rtB . ou1c3oxils = rtP . kfs * rtB . lw44fbjzmd ; rtB .
mycmkus1bg = rtP . lf * rtB . ou1c3oxils ; rtB . ajgpsl4ddz = rtP . krs * rtB
. m2jdcg5lrr ; rtB . odlkkgirey = rtP . lr * rtB . ajgpsl4ddz ; rtB .
akesstvlt4 = rtP . cfs * rtB . ffhybcifud ; rtB . ez0vdo0vnv = rtP . lf * rtB
. akesstvlt4 ; rtB . cm2qntqv5p = rtP . crs * rtB . n3tlanomdr ; rtB .
fifo30g12w = rtP . lr * rtB . cm2qntqv5p ; rtB . foo13op1ju = ( ( ( 0.0 - rtB
. mycmkus1bg ) - rtB . odlkkgirey ) - rtB . ez0vdo0vnv ) - rtB . fifo30g12w ;
rtB . hzo0vy2urp = 1.0 / rtP . iyy * rtB . foo13op1ju ; rtB . bhip02e5fq =
rtP . lr * rtB . ppy2yksd3e ; rtB . ir2wrhmfwi = ( rtB . bhip02e5fq - rtB .
igbnss0o0f ) + rtB . f2micsnrzs ; rtB . peyixfnwtk = rtP . lr * rtB .
ctr3nygjvu ; rtB . oxl1gbubgw = ( rtB . peyixfnwtk - rtB . oy1jpf0hjr ) + rtB
. oshpndvkvq ; rtB . eclh5z3ew4 = rtB . f2micsnrzs - rtB . nrrfaz4txr ; {
real_T * * uBuffer = ( real_T * * ) & rtDW . l1amy53ft4 . TUbufferPtrs [ 0 ]
; real_T * * tBuffer = ( real_T * * ) & rtDW . l1amy53ft4 . TUbufferPtrs [ 1
] ; real_T simTime = ssGetT ( rtS ) ; real_T tMinusDelay = simTime - rtP .
TransportDelay1_Delay ; rtB . ketvnzudn2 = rt_TDelayInterpolate ( tMinusDelay
, 0.0 , * tBuffer , * uBuffer , rtDW . fv0rpgctfs . CircularBufSize , & rtDW
. fv0rpgctfs . Last , rtDW . fv0rpgctfs . Tail , rtDW . fv0rpgctfs . Head ,
rtP . TransportDelay1_InitOutput , 0 , ( boolean_T ) ( ssIsMinorTimeStep (
rtS ) && ( ssGetTimeOfLastOutput ( rtS ) == ssGetT ( rtS ) ) ) ) ; } rtB .
lia3hzxqko = rtB . oshpndvkvq - rtB . ketvnzudn2 ; rtB . pyyanjtp0n = rtP .
krs * rtB . ir2wrhmfwi ; rtB . owdhyrttis = ( rtB . oy1jpf0hjr - rtB .
oshpndvkvq ) * ( rtP . Gain9_Gain_okhtvkgje5 * rtB . oshpndvkvq ) ;
rtPrevAction = rtDW . jcg5lahs5d ; if ( ssIsMajorTimeStep ( rtS ) ) {
rtAction = ( int8_T ) ! ( rtB . owdhyrttis >= 0.0 ) ; rtDW . jcg5lahs5d =
rtAction ; } else { rtAction = rtDW . jcg5lahs5d ; } if ( rtPrevAction !=
rtAction ) { switch ( rtPrevAction ) { case 0 : fwcmlgyrtk ( rtS ) ; break ;
case 1 : dr3q4xjhlf ( rtS ) ; break ; } } switch ( rtAction ) { case 0 : if (
rtAction != rtPrevAction ) { ipps4dfwvh ( rtS ) ; } nbpepiek5a ( rtS , rtP .
Constant_Value_i5zgqe2wta , & rtB . h53izkjog2 ) ; if ( ssIsMajorTimeStep (
rtS ) ) { srUpdateBC ( rtDW . cical55ljv . c4bsnmlro2 ) ; } break ; case 1 :
if ( rtAction != rtPrevAction ) { i2sc5lqney ( rtS ) ; } fsrrbnl0on ( rtS ,
rtP . Constant1_Value_ojyctmrwrg , & rtB . h53izkjog2 ) ; if (
ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW . bxy5pgokky . ax0ejju01d ) ;
} break ; } rtB . odp1rox02t = rtB . oxl1gbubgw * rtB . h53izkjog2 ; rtB .
jpajsss3mb = rtP . krt * rtB . eclh5z3ew4 ; rtB . ngngrfhqxt = rtP . crt *
rtB . lia3hzxqko ; rtB . eemaj3mw1e = ( ( ( 0.0 - rtB . pyyanjtp0n ) - rtB .
odp1rox02t ) - rtB . jpajsss3mb ) - rtB . ngngrfhqxt ; rtB . gaaymicbge = 1.0
/ rtP . mr * rtB . eemaj3mw1e ; if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { if (
ssGetTaskTime ( rtS , 2 ) < rtP . Step_Time_mvs0g1sev0 ) { rtB . aubzgcsgjd =
rtP . Step_Y0_iz131rho11 ; } else { rtB . aubzgcsgjd = rtP .
Step_YFinal_hqre2tmqod ; } } if ( ssIsSampleHit ( rtS , 4 , 0 ) ) { if (
ssGetTaskTime ( rtS , 4 ) < rtP . Step1_Time_jphzf3vxvl ) { rtB . eintirb2zo
= rtP . Step1_Y0_pl0xadtajh ; } else { rtB . eintirb2zo = rtP .
Step1_YFinal_awmv2dzpr0 ; } } rtB . ioubxgazf2 = muDoubleScalarSin (
6.2831853071795862 * ssGetT ( rtS ) * rtP .
SignalGenerator_Frequency_a50i2lvmye ) * rtP .
SignalGenerator_Amplitude_eudi0mxlsb * rtB . aubzgcsgjd * rtB . eintirb2zo ;
if ( ssIsMajorTimeStep ( rtS ) ) { rtDW . gupv3wkm1k = rtB . ioubxgazf2 >=
rtP . Saturation_UpperSat ? 1 : rtB . ioubxgazf2 > rtP . Saturation_LowerSat
? 0 : - 1 ; } rtB . hx0qhuwqax = rtDW . gupv3wkm1k == 1 ? rtP .
Saturation_UpperSat : rtDW . gupv3wkm1k == - 1 ? rtP . Saturation_LowerSat :
rtB . ioubxgazf2 ; rtB . cwvoke4n3w = rtP . lf * rtB . ohobmojlqf ; rtB .
nnypggyeoc = ( rtB . cwvoke4n3w + rtB . khpnmtgkim ) - rtB . ivrqxfr4p2 ; rtB
. eqkg2xr2dn = rtP . lr * rtB . ohobmojlqf ; rtB . khvs2osnrm = ( rtB .
eqkg2xr2dn - rtB . khpnmtgkim ) + rtB . aacyykkcvt ; rtB . f0mglil0tu = rtP .
lf * rtB . fgv0iw5io4 ; rtB . ors3z5ofsx = rtX . avtxyi5gqp ; rtB .
ewfilzdy5p = rtX . b3davkt1eh ; rtB . adv5kzimvn = ( rtB . f0mglil0tu + rtB .
ors3z5ofsx ) - rtB . ewfilzdy5p ; rtB . jzz0uec2gq = rtP . lr * rtB .
fgv0iw5io4 ; rtB . c12jn5x4j0 = rtX . pulwqgjkwh ; rtB . iqjmjwfmns = ( rtB .
jzz0uec2gq - rtB . ors3z5ofsx ) + rtB . c12jn5x4j0 ; rtB . afz2yt343k = rtP .
kfs * rtB . nnypggyeoc ; rtB . nu4szqiw1o = rtP . krs * rtB . khvs2osnrm ;
rtB . l5ft2k3pks = ( rtB . ors3z5ofsx - rtB . ewfilzdy5p ) * ( rtP .
Gain9_Gain_jglnwjr1da * rtB . ewfilzdy5p ) ; rtPrevAction = rtDW . bugzjuygkx
; if ( ssIsMajorTimeStep ( rtS ) ) { rtAction = ( int8_T ) ! ( rtB .
l5ft2k3pks >= 0.0 ) ; rtDW . bugzjuygkx = rtAction ; } else { rtAction = rtDW
. bugzjuygkx ; } if ( rtPrevAction != rtAction ) { switch ( rtPrevAction ) {
case 0 : fwcmlgyrtk ( rtS ) ; break ; case 1 : dr3q4xjhlf ( rtS ) ; break ; }
} switch ( rtAction ) { case 0 : if ( rtAction != rtPrevAction ) { ipps4dfwvh
( rtS ) ; } nbpepiek5a ( rtS , rtP . Constant_Value_gnxcisvqkz , & c1dadngp3u
) ; if ( ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW . hzattc0vf2 .
c4bsnmlro2 ) ; } break ; case 1 : if ( rtAction != rtPrevAction ) {
i2sc5lqney ( rtS ) ; } fsrrbnl0on ( rtS , rtP . Constant1_Value_krl1nmx5tb ,
& c1dadngp3u ) ; if ( ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW .
k1t5j21xa2 . ax0ejju01d ) ; } break ; } rtB . c4o1bl135b = ( rtB . ors3z5ofsx
- rtB . ewfilzdy5p ) * rtB . ors3z5ofsx ; rtPrevAction = rtDW . dd30o4lozm ;
if ( ssIsMajorTimeStep ( rtS ) ) { rtAction = ( int8_T ) ! ( rtB . c4o1bl135b
>= 0.0 ) ; rtDW . dd30o4lozm = rtAction ; } else { rtAction = rtDW .
dd30o4lozm ; } if ( rtPrevAction != rtAction ) { switch ( rtPrevAction ) {
case 0 : dr3q4xjhlf ( rtS ) ; break ; case 1 : dr3q4xjhlf ( rtS ) ; break ; }
} switch ( rtAction ) { case 0 : if ( rtAction != rtPrevAction ) { i2sc5lqney
( rtS ) ; } fsrrbnl0on ( rtS , rtP . Constant2_Value , & fqgazswzy5 ) ; if (
ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW . htznribv1q . ax0ejju01d ) ;
} break ; case 1 : if ( rtAction != rtPrevAction ) { i2sc5lqney ( rtS ) ; }
fsrrbnl0on ( rtS , rtP . Constant3_Value , & fqgazswzy5 ) ; if (
ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW . fibtpbiz5w . ax0ejju01d ) ;
} break ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . fsb3gaohdk =
c1dadngp3u + fqgazswzy5 ; } rtB . bsh0ijyg1a = rtB . adv5kzimvn * rtB .
fsb3gaohdk ; rtB . nvjwsszq20 = ( rtB . ors3z5ofsx - rtB . c12jn5x4j0 ) * (
rtP . Gain9_Gain_buqm2zp1xy * rtB . c12jn5x4j0 ) ; rtPrevAction = rtDW .
ljkqmp5hio ; if ( ssIsMajorTimeStep ( rtS ) ) { rtAction = ( int8_T ) ! ( rtB
. nvjwsszq20 >= 0.0 ) ; rtDW . ljkqmp5hio = rtAction ; } else { rtAction =
rtDW . ljkqmp5hio ; } if ( rtPrevAction != rtAction ) { switch ( rtPrevAction
) { case 0 : fwcmlgyrtk ( rtS ) ; break ; case 1 : dr3q4xjhlf ( rtS ) ; break
; } } switch ( rtAction ) { case 0 : if ( rtAction != rtPrevAction ) {
ipps4dfwvh ( rtS ) ; } nbpepiek5a ( rtS , rtP . Constant_Value_j5obrm202k , &
f1ev1iuyhe ) ; if ( ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW .
lxwl2pumah . c4bsnmlro2 ) ; } break ; case 1 : if ( rtAction != rtPrevAction
) { i2sc5lqney ( rtS ) ; } fsrrbnl0on ( rtS , rtP .
Constant1_Value_gwq5uspikg , & f1ev1iuyhe ) ; if ( ssIsMajorTimeStep ( rtS )
) { srUpdateBC ( rtDW . fo1s40z2ng . ax0ejju01d ) ; } break ; } rtB .
d3p1u0mvns = ( rtB . ors3z5ofsx - rtB . c12jn5x4j0 ) * rtB . ors3z5ofsx ;
rtPrevAction = rtDW . mtbsrpr2ww ; if ( ssIsMajorTimeStep ( rtS ) ) {
rtAction = ( int8_T ) ! ( rtB . d3p1u0mvns >= 0.0 ) ; rtDW . mtbsrpr2ww =
rtAction ; } else { rtAction = rtDW . mtbsrpr2ww ; } if ( rtPrevAction !=
rtAction ) { switch ( rtPrevAction ) { case 0 : dr3q4xjhlf ( rtS ) ; break ;
case 1 : dr3q4xjhlf ( rtS ) ; break ; } } switch ( rtAction ) { case 0 : if (
rtAction != rtPrevAction ) { i2sc5lqney ( rtS ) ; } fsrrbnl0on ( rtS , rtP .
Constant2_Value_npn4i05u3n , & dwbg3d3uz0 ) ; if ( ssIsMajorTimeStep ( rtS )
) { srUpdateBC ( rtDW . blc3y3lbsz . ax0ejju01d ) ; } break ; case 1 : if (
rtAction != rtPrevAction ) { i2sc5lqney ( rtS ) ; } fsrrbnl0on ( rtS , rtP .
Constant3_Value_f5rovkb5n0 , & dwbg3d3uz0 ) ; if ( ssIsMajorTimeStep ( rtS )
) { srUpdateBC ( rtDW . nkptjiojzm . ax0ejju01d ) ; } break ; } if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . hegnhw35oi = f1ev1iuyhe + dwbg3d3uz0
; } rtB . k44fqt4bzr = rtB . iqjmjwfmns * rtB . hegnhw35oi ; rtB . mzrg2hkek3
= ( ( rtB . nu4szqiw1o - rtB . afz2yt343k ) - rtB . bsh0ijyg1a ) + rtB .
k44fqt4bzr ; rtB . irdye5g1gh = 1.0 / rtP . mc * rtB . mzrg2hkek3 ; if (
ssIsSampleHit ( rtS , 2 , 0 ) ) { if ( ssGetTaskTime ( rtS , 2 ) < rtP .
Step_Time_kxn30foah1 ) { rtB . dgotzim4ft = rtP . Step_Y0_dalzojkna3 ; } else
{ rtB . dgotzim4ft = rtP . Step_YFinal_ikormlakvz ; } } if ( ssIsSampleHit (
rtS , 3 , 0 ) ) { if ( ssGetTaskTime ( rtS , 3 ) < rtP .
Step1_Time_fxtabt0hzy ) { rtB . fkz2npxwns = rtP . Step1_Y0_ihbov1sa5i ; }
else { rtB . fkz2npxwns = rtP . Step1_YFinal_dudehtwvxl ; } } rtB .
h24izcfegy = muDoubleScalarSin ( 6.2831853071795862 * ssGetT ( rtS ) * rtP .
SignalGenerator_Frequency_i1c2jxsnux ) * rtP .
SignalGenerator_Amplitude_fbk2hkdqfm * rtB . dgotzim4ft * rtB . fkz2npxwns ;
rtB . p5qpsydo5q = rtP . Gain_Gain_cec0fvfroz * rtB . h24izcfegy ; if ( (
rtDW . jpmhq0y24v >= ssGetT ( rtS ) ) && ( rtDW . ijphmshkuf >= ssGetT ( rtS
) ) ) { rtB . lm0o0zjx1a = 0.0 ; } else { lastTime = rtDW . jpmhq0y24v ;
lastU = & rtDW . eetn342tct ; if ( rtDW . jpmhq0y24v < rtDW . ijphmshkuf ) {
if ( rtDW . ijphmshkuf < ssGetT ( rtS ) ) { lastTime = rtDW . ijphmshkuf ;
lastU = & rtDW . pdelqeetgv ; } } else { if ( rtDW . jpmhq0y24v >= ssGetT (
rtS ) ) { lastTime = rtDW . ijphmshkuf ; lastU = & rtDW . pdelqeetgv ; } }
rtB . lm0o0zjx1a = ( rtB . p5qpsydo5q - * lastU ) / ( ssGetT ( rtS ) -
lastTime ) ; } { real_T * * uBuffer = ( real_T * * ) & rtDW . omrnl2kvox .
TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * * ) & rtDW . omrnl2kvox
. TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( rtS ) ; real_T tMinusDelay =
simTime - rtP . TransportDelay_Delay_iap2op2zgh ; rtB . p4oanyhhie =
rt_TDelayInterpolate ( tMinusDelay , 0.0 , * tBuffer , * uBuffer , rtDW .
ped5kwc4j1 . CircularBufSize , & rtDW . ped5kwc4j1 . Last , rtDW . ped5kwc4j1
. Tail , rtDW . ped5kwc4j1 . Head , rtP .
TransportDelay_InitOutput_ea1344nau0 , 0 , ( boolean_T ) ( ssIsMinorTimeStep
( rtS ) && ( ssGetTimeOfLastOutput ( rtS ) == ssGetT ( rtS ) ) ) ) ; } if ( (
rtDW . mntyae3rsq >= ssGetT ( rtS ) ) && ( rtDW . psneabumzv >= ssGetT ( rtS
) ) ) { rtB . p2gjpa4kz5 = 0.0 ; } else { lastTime = rtDW . mntyae3rsq ;
lastU = & rtDW . bxic41ulzf ; if ( rtDW . mntyae3rsq < rtDW . psneabumzv ) {
if ( rtDW . psneabumzv < ssGetT ( rtS ) ) { lastTime = rtDW . psneabumzv ;
lastU = & rtDW . jhe2qhrig2 ; } } else { if ( rtDW . mntyae3rsq >= ssGetT (
rtS ) ) { lastTime = rtDW . psneabumzv ; lastU = & rtDW . jhe2qhrig2 ; } }
rtB . p2gjpa4kz5 = ( rtB . p4oanyhhie - * lastU ) / ( ssGetT ( rtS ) -
lastTime ) ; } rtB . j5wjpnvys4 = rtP . lf * rtB . ohobmojlqf ; rtB .
of10q24r4f = ( rtB . j5wjpnvys4 + rtB . khpnmtgkim ) - rtB . ivrqxfr4p2 ; rtB
. p5tntlgroy = rtP . lf * rtB . fgv0iw5io4 ; rtB . b0qoasefti = ( rtB .
p5tntlgroy + rtB . ors3z5ofsx ) - rtB . ewfilzdy5p ; rtB . gbtvk2ar5t = rtB .
ewfilzdy5p - rtB . lm0o0zjx1a ; rtB . dx2og4efcz = rtB . ivrqxfr4p2 - rtB .
p5qpsydo5q ; rtB . eotgtd3vzy = rtP . kfs * rtB . of10q24r4f ; rtB .
nifjgpnast = ( rtB . ors3z5ofsx - rtB . ewfilzdy5p ) * ( rtP .
Gain9_Gain_fzv5tmgqw5 * rtB . ewfilzdy5p ) ; rtPrevAction = rtDW . ndweztnvdz
; if ( ssIsMajorTimeStep ( rtS ) ) { rtAction = ( int8_T ) ! ( rtB .
nifjgpnast >= 0.0 ) ; rtDW . ndweztnvdz = rtAction ; } else { rtAction = rtDW
. ndweztnvdz ; } if ( rtPrevAction != rtAction ) { switch ( rtPrevAction ) {
case 0 : fwcmlgyrtk ( rtS ) ; break ; case 1 : dr3q4xjhlf ( rtS ) ; break ; }
} switch ( rtAction ) { case 0 : if ( rtAction != rtPrevAction ) { ipps4dfwvh
( rtS ) ; } nbpepiek5a ( rtS , rtP . Constant_Value_p33xk1nt0c , & nkaj01jval
) ; if ( ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW . a0fdk1tibo .
c4bsnmlro2 ) ; } break ; case 1 : if ( rtAction != rtPrevAction ) {
i2sc5lqney ( rtS ) ; } fsrrbnl0on ( rtS , rtP . Constant1_Value_iucvhmftri ,
& nkaj01jval ) ; if ( ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW .
cb0lxisazg . ax0ejju01d ) ; } break ; } rtB . bft4uxvudw = ( rtB . ors3z5ofsx
- rtB . ewfilzdy5p ) * rtB . ors3z5ofsx ; rtPrevAction = rtDW . jg4lsy03zm ;
if ( ssIsMajorTimeStep ( rtS ) ) { rtAction = ( int8_T ) ! ( rtB . bft4uxvudw
>= 0.0 ) ; rtDW . jg4lsy03zm = rtAction ; } else { rtAction = rtDW .
jg4lsy03zm ; } if ( rtPrevAction != rtAction ) { switch ( rtPrevAction ) {
case 0 : dr3q4xjhlf ( rtS ) ; break ; case 1 : dr3q4xjhlf ( rtS ) ; break ; }
} switch ( rtAction ) { case 0 : if ( rtAction != rtPrevAction ) { i2sc5lqney
( rtS ) ; } fsrrbnl0on ( rtS , rtP . Constant2_Value_pwplpsvmqw , &
pwlbimvptw ) ; if ( ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW .
i5omdubmni . ax0ejju01d ) ; } break ; case 1 : if ( rtAction != rtPrevAction
) { i2sc5lqney ( rtS ) ; } fsrrbnl0on ( rtS , rtP .
Constant3_Value_iyzr1ezzvq , & pwlbimvptw ) ; if ( ssIsMajorTimeStep ( rtS )
) { srUpdateBC ( rtDW . jrnrap5jzh . ax0ejju01d ) ; } break ; } if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . oxpgpvieu5 = nkaj01jval + pwlbimvptw
; } rtB . e1fwyl5oca = rtB . b0qoasefti * rtB . oxpgpvieu5 ; rtB . mlo35lys1s
= rtP . kft * rtB . dx2og4efcz ; rtB . div11ckje2 = rtP . cft * rtB .
gbtvk2ar5t ; rtB . ppxwyoa2bt = ( ( rtB . eotgtd3vzy + rtB . e1fwyl5oca ) -
rtB . mlo35lys1s ) - rtB . div11ckje2 ; rtB . d14mmlv3sc = 1.0 / rtP . mf *
rtB . ppxwyoa2bt ; rtB . aazow5qyx5 = rtP . lf * rtB . ohobmojlqf ; rtB .
hdsrwzf2hz = ( rtB . aazow5qyx5 + rtB . khpnmtgkim ) - rtB . ewfilzdy5p ; rtB
. assjptryio = rtP . lr * rtB . ohobmojlqf ; rtB . bqmgj4wdja = ( rtB .
assjptryio - rtB . khpnmtgkim ) + rtB . ivrqxfr4p2 ; rtB . huti2k1olr = rtP .
lr * rtB . fgv0iw5io4 ; rtB . kpftqud0v4 = ( rtB . huti2k1olr - rtB .
ors3z5ofsx ) + rtB . c12jn5x4j0 ; rtB . bewrfmxe51 = rtP . lf * rtB .
fgv0iw5io4 ; rtB . fxe0oi5raa = ( rtB . bewrfmxe51 + rtB . ors3z5ofsx ) - rtB
. c12jn5x4j0 ; rtB . b2vno41brr = rtP . kfs * rtB . hdsrwzf2hz ; rtB .
pudus0mnkh = rtP . lf * rtB . b2vno41brr ; rtB . dacgyfnkti = rtP . krs * rtB
. bqmgj4wdja ; rtB . ksqxzrlacp = rtP . lr * rtB . dacgyfnkti ; rtB .
dhutim4yfg = rtP . cfs * rtB . fxe0oi5raa ; rtB . jy1dhwzsny = rtP . lf * rtB
. dhutim4yfg ; rtB . nbmiv4o2qv = rtP . crs * rtB . kpftqud0v4 ; rtB .
gnam0gpyvd = rtP . lr * rtB . nbmiv4o2qv ; rtB . mxz0zykzkm = ( ( ( 0.0 - rtB
. pudus0mnkh ) - rtB . ksqxzrlacp ) - rtB . jy1dhwzsny ) - rtB . gnam0gpyvd ;
rtB . h2riih5p4x = 1.0 / rtP . iyy * rtB . mxz0zykzkm ; rtB . ezfjneuvrq =
rtP . lr * rtB . ohobmojlqf ; rtB . gzm1otmdfx = ( rtB . ezfjneuvrq - rtB .
khpnmtgkim ) + rtB . aacyykkcvt ; rtB . pat0zgdwxm = rtP . lr * rtB .
fgv0iw5io4 ; rtB . fpu4pfoo0u = ( rtB . pat0zgdwxm - rtB . ors3z5ofsx ) + rtB
. c12jn5x4j0 ; rtB . jsbnrcbw2w = rtB . aacyykkcvt - rtB . p4oanyhhie ; {
real_T * * uBuffer = ( real_T * * ) & rtDW . b0rupvaogl . TUbufferPtrs [ 0 ]
; real_T * * tBuffer = ( real_T * * ) & rtDW . b0rupvaogl . TUbufferPtrs [ 1
] ; real_T simTime = ssGetT ( rtS ) ; real_T tMinusDelay = simTime - rtP .
TransportDelay1_Delay_e5t1cmi5b5 ; rtB . a2rcbbb2nd = rt_TDelayInterpolate (
tMinusDelay , 0.0 , * tBuffer , * uBuffer , rtDW . aem0ceeew5 .
CircularBufSize , & rtDW . aem0ceeew5 . Last , rtDW . aem0ceeew5 . Tail ,
rtDW . aem0ceeew5 . Head , rtP . TransportDelay1_InitOutput_etxwutwb0s , 0 ,
( boolean_T ) ( ssIsMinorTimeStep ( rtS ) && ( ssGetTimeOfLastOutput ( rtS )
== ssGetT ( rtS ) ) ) ) ; } rtB . auaumgkulf = rtB . c12jn5x4j0 - rtB .
a2rcbbb2nd ; rtB . ca5bcarb1z = rtP . krs * rtB . gzm1otmdfx ; rtB .
pmv2c05bpb = ( rtB . ors3z5ofsx - rtB . c12jn5x4j0 ) * ( rtP .
Gain9_Gain_hick3dd3rf * rtB . c12jn5x4j0 ) ; rtPrevAction = rtDW . lgxvz4jhdw
; if ( ssIsMajorTimeStep ( rtS ) ) { rtAction = ( int8_T ) ! ( rtB .
pmv2c05bpb >= 0.0 ) ; rtDW . lgxvz4jhdw = rtAction ; } else { rtAction = rtDW
. lgxvz4jhdw ; } if ( rtPrevAction != rtAction ) { switch ( rtPrevAction ) {
case 0 : fwcmlgyrtk ( rtS ) ; break ; case 1 : dr3q4xjhlf ( rtS ) ; break ; }
} switch ( rtAction ) { case 0 : if ( rtAction != rtPrevAction ) { ipps4dfwvh
( rtS ) ; } nbpepiek5a ( rtS , rtP . Constant_Value_hzj4wvktxf , & ptcf3mv0hj
) ; if ( ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW . jucvauqnq3 .
c4bsnmlro2 ) ; } break ; case 1 : if ( rtAction != rtPrevAction ) {
i2sc5lqney ( rtS ) ; } fsrrbnl0on ( rtS , rtP . Constant1_Value_kxn2zcp3ig ,
& ptcf3mv0hj ) ; if ( ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW .
fallptwe4n . ax0ejju01d ) ; } break ; } rtB . ni04k2if4f = ( rtB . ors3z5ofsx
- rtB . c12jn5x4j0 ) * rtB . ors3z5ofsx ; rtPrevAction = rtDW . hgbx4f0dqj ;
if ( ssIsMajorTimeStep ( rtS ) ) { rtAction = ( int8_T ) ! ( rtB . ni04k2if4f
>= 0.0 ) ; rtDW . hgbx4f0dqj = rtAction ; } else { rtAction = rtDW .
hgbx4f0dqj ; } if ( rtPrevAction != rtAction ) { switch ( rtPrevAction ) {
case 0 : dr3q4xjhlf ( rtS ) ; break ; case 1 : dr3q4xjhlf ( rtS ) ; break ; }
} switch ( rtAction ) { case 0 : if ( rtAction != rtPrevAction ) { i2sc5lqney
( rtS ) ; } fsrrbnl0on ( rtS , rtP . Constant2_Value_icdxaqrdvn , &
ghoyjfeb1k ) ; if ( ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW .
ej5frkoyu2 . ax0ejju01d ) ; } break ; case 1 : if ( rtAction != rtPrevAction
) { i2sc5lqney ( rtS ) ; } fsrrbnl0on ( rtS , rtP .
Constant3_Value_ej5wa025ni , & ghoyjfeb1k ) ; if ( ssIsMajorTimeStep ( rtS )
) { srUpdateBC ( rtDW . airq053sdl . ax0ejju01d ) ; } break ; } if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . avovxjitlj = ptcf3mv0hj + ghoyjfeb1k
; } rtB . hl0nz2vhhx = rtB . fpu4pfoo0u * rtB . avovxjitlj ; rtB . dopbnbablw
= rtP . krt * rtB . jsbnrcbw2w ; rtB . clp5ptg2aq = rtP . crt * rtB .
auaumgkulf ; rtB . nezd5agty4 = ( ( ( 0.0 - rtB . ca5bcarb1z ) - rtB .
hl0nz2vhhx ) - rtB . dopbnbablw ) - rtB . clp5ptg2aq ; rtB . leqschf41u = 1.0
/ rtP . mr * rtB . nezd5agty4 ; if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { if (
ssGetTaskTime ( rtS , 2 ) < rtP . Step_Time_d15jg5xwxc ) { rtB . ihrr5jombz =
rtP . Step_Y0_frz4o3t2qo ; } else { rtB . ihrr5jombz = rtP .
Step_YFinal_mvwpnjqziy ; } } if ( ssIsSampleHit ( rtS , 4 , 0 ) ) { if (
ssGetTaskTime ( rtS , 4 ) < rtP . Step1_Time_a0qbodifis ) { rtB . a1cpk0zahd
= rtP . Step1_Y0_dkhrl3hyib ; } else { rtB . a1cpk0zahd = rtP .
Step1_YFinal_iovgwjmexk ; } } rtB . iw40x310lw = muDoubleScalarSin (
6.2831853071795862 * ssGetT ( rtS ) * rtP .
SignalGenerator_Frequency_o1bkitcbhj ) * rtP .
SignalGenerator_Amplitude_jqvsffusiy * rtB . ihrr5jombz * rtB . a1cpk0zahd ;
if ( ssIsMajorTimeStep ( rtS ) ) { rtDW . oe2kbpvny0 = rtB . iw40x310lw >=
rtP . Saturation_UpperSat_nmc40qz4uh ? 1 : rtB . iw40x310lw > rtP .
Saturation_LowerSat_avfz2gn5tr ? 0 : - 1 ; } rtB . csvnqlqe2c = rtDW .
oe2kbpvny0 == 1 ? rtP . Saturation_UpperSat_nmc40qz4uh : rtDW . oe2kbpvny0 ==
- 1 ? rtP . Saturation_LowerSat_avfz2gn5tr : rtB . iw40x310lw ; rtB .
op4fqs5y2b = rtP . lf * rtB . pawhsqlpds ; rtB . egvgjshusc = ( rtB .
op4fqs5y2b + rtB . jbu2t0zvvf ) - rtB . mcgc55onte ; rtB . lhy0d514t0 = rtP .
lr * rtB . pawhsqlpds ; rtB . o1tgujpptc = ( rtB . lhy0d514t0 - rtB .
jbu2t0zvvf ) + rtB . jvzmdt5nzv ; rtB . ot505slkkd = rtP . lf * rtB .
ckhfos3d5d ; rtB . f1s21kqqtk = rtX . g2zcmmoypm ; rtB . g5dxxhvf0d = rtX .
efgd0a2xyp ; rtB . dohdzn0els = ( rtB . ot505slkkd + rtB . f1s21kqqtk ) - rtB
. g5dxxhvf0d ; rtB . kdcnvmuwdv = rtP . lr * rtB . ckhfos3d5d ; rtB .
m4u0zxcmnx = rtX . i3bwmkwwlg ; rtB . lfbfrtbus5 = ( rtB . kdcnvmuwdv - rtB .
f1s21kqqtk ) + rtB . m4u0zxcmnx ; rtB . p4sojnckke = rtP . kfs * rtB .
egvgjshusc ; rtB . catep12smy = rtP . krs * rtB . o1tgujpptc ; rtB .
k0c4i4a3eh = rtP . cfs * rtB . dohdzn0els ; rtB . khzbqlyoyt = rtP . crs *
rtB . lfbfrtbus5 ; rtB . o35dwhcnte = ( ( rtB . catep12smy - rtB . p4sojnckke
) - rtB . k0c4i4a3eh ) + rtB . khzbqlyoyt ; rtB . memjmzawon = 1.0 / rtP . mc
* rtB . o35dwhcnte ; if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { if (
ssGetTaskTime ( rtS , 2 ) < rtP . Step_Time_facad21pf1 ) { rtB . poz0njf0k5 =
rtP . Step_Y0_jeywlji0bq ; } else { rtB . poz0njf0k5 = rtP .
Step_YFinal_pnkyifhjta ; } } if ( ssIsSampleHit ( rtS , 3 , 0 ) ) { if (
ssGetTaskTime ( rtS , 3 ) < rtP . Step1_Time_ia1tcvue3b ) { rtB . ph2e13dkoz
= rtP . Step1_Y0_dmjz2ujtxq ; } else { rtB . ph2e13dkoz = rtP .
Step1_YFinal_htin21ftgl ; } } rtB . mmzi51sdi4 = muDoubleScalarSin (
6.2831853071795862 * ssGetT ( rtS ) * rtP .
SignalGenerator_Frequency_m0wbhyregv ) * rtP .
SignalGenerator_Amplitude_guqpb23tpp * rtB . poz0njf0k5 * rtB . ph2e13dkoz ;
rtB . bu3dppt1dy = rtP . Gain_Gain_goppgbgrif * rtB . mmzi51sdi4 ; if ( (
rtDW . goagc5i3gw >= ssGetT ( rtS ) ) && ( rtDW . k5o3zhu0wr >= ssGetT ( rtS
) ) ) { rtB . ihsi5ikxem = 0.0 ; } else { lastTime = rtDW . goagc5i3gw ;
lastU = & rtDW . ovio5arldz ; if ( rtDW . goagc5i3gw < rtDW . k5o3zhu0wr ) {
if ( rtDW . k5o3zhu0wr < ssGetT ( rtS ) ) { lastTime = rtDW . k5o3zhu0wr ;
lastU = & rtDW . lioetblzpp ; } } else { if ( rtDW . goagc5i3gw >= ssGetT (
rtS ) ) { lastTime = rtDW . k5o3zhu0wr ; lastU = & rtDW . lioetblzpp ; } }
rtB . ihsi5ikxem = ( rtB . bu3dppt1dy - * lastU ) / ( ssGetT ( rtS ) -
lastTime ) ; } { real_T * * uBuffer = ( real_T * * ) & rtDW . onssg0ise1 .
TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * * ) & rtDW . onssg0ise1
. TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( rtS ) ; real_T tMinusDelay =
simTime - rtP . TransportDelay_Delay_eqwrqaxknp ; rtB . bptwtyixo3 =
rt_TDelayInterpolate ( tMinusDelay , 0.0 , * tBuffer , * uBuffer , rtDW .
nogfvg0pt3 . CircularBufSize , & rtDW . nogfvg0pt3 . Last , rtDW . nogfvg0pt3
. Tail , rtDW . nogfvg0pt3 . Head , rtP .
TransportDelay_InitOutput_cflcileqko , 0 , ( boolean_T ) ( ssIsMinorTimeStep
( rtS ) && ( ssGetTimeOfLastOutput ( rtS ) == ssGetT ( rtS ) ) ) ) ; } if ( (
rtDW . dqvle0o2bf >= ssGetT ( rtS ) ) && ( rtDW . dp5dxb3enf >= ssGetT ( rtS
) ) ) { rtB . enljiew2kc = 0.0 ; } else { lastTime = rtDW . dqvle0o2bf ;
lastU = & rtDW . kr1ksgnw4x ; if ( rtDW . dqvle0o2bf < rtDW . dp5dxb3enf ) {
if ( rtDW . dp5dxb3enf < ssGetT ( rtS ) ) { lastTime = rtDW . dp5dxb3enf ;
lastU = & rtDW . edxttokajv ; } } else { if ( rtDW . dqvle0o2bf >= ssGetT (
rtS ) ) { lastTime = rtDW . dp5dxb3enf ; lastU = & rtDW . edxttokajv ; } }
rtB . enljiew2kc = ( rtB . bptwtyixo3 - * lastU ) / ( ssGetT ( rtS ) -
lastTime ) ; } rtB . fisd51h4xh = rtP . lf * rtB . pawhsqlpds ; rtB .
jazm3yw1lz = ( rtB . fisd51h4xh + rtB . jbu2t0zvvf ) - rtB . mcgc55onte ; rtB
. fu5nvqp5ki = rtP . lf * rtB . ckhfos3d5d ; rtB . ib3dugswvz = ( rtB .
fu5nvqp5ki + rtB . f1s21kqqtk ) - rtB . g5dxxhvf0d ; rtB . gohkxwvfgd = rtB .
g5dxxhvf0d - rtB . ihsi5ikxem ; rtB . o00l05l5h5 = rtB . mcgc55onte - rtB .
bu3dppt1dy ; rtB . imbewi4stk = rtP . kfs * rtB . jazm3yw1lz ; rtB .
hco0swv5mb = rtP . cfs * rtB . ib3dugswvz ; rtB . ivmbx4exri = rtP . kft *
rtB . o00l05l5h5 ; rtB . gbegnosnia = rtP . cft * rtB . gohkxwvfgd ; rtB .
h3go2eb5uu = ( ( rtB . imbewi4stk + rtB . hco0swv5mb ) - rtB . ivmbx4exri ) -
rtB . gbegnosnia ; rtB . hdmwzbgags = 1.0 / rtP . mf * rtB . h3go2eb5uu ; rtB
. o0p2ll51dt = rtP . lf * rtB . pawhsqlpds ; rtB . hfprs0psjz = ( rtB .
o0p2ll51dt + rtB . jbu2t0zvvf ) - rtB . g5dxxhvf0d ; rtB . hywsl3f1uq = rtP .
lr * rtB . pawhsqlpds ; rtB . iucqadbg2k = ( rtB . hywsl3f1uq - rtB .
jbu2t0zvvf ) + rtB . mcgc55onte ; rtB . erjlcjtp4o = rtP . lr * rtB .
ckhfos3d5d ; rtB . dkle40ro1c = ( rtB . erjlcjtp4o - rtB . f1s21kqqtk ) + rtB
. m4u0zxcmnx ; rtB . ihgsjmwc0o = rtP . lf * rtB . ckhfos3d5d ; rtB .
dhwgonfwmn = ( rtB . ihgsjmwc0o + rtB . f1s21kqqtk ) - rtB . m4u0zxcmnx ; rtB
. ftodx2djd4 = rtP . kfs * rtB . hfprs0psjz ; rtB . ihyeehrkag = rtP . lf *
rtB . ftodx2djd4 ; rtB . i1gcs32wge = rtP . krs * rtB . iucqadbg2k ; rtB .
hoerz5xdv5 = rtP . lr * rtB . i1gcs32wge ; rtB . cv3osvvlrg = rtP . cfs * rtB
. dhwgonfwmn ; rtB . gqqadn4y2w = rtP . lf * rtB . cv3osvvlrg ; rtB .
o210behxg1 = rtP . crs * rtB . dkle40ro1c ; rtB . hcfgyld3wj = rtP . lr * rtB
. o210behxg1 ; rtB . hmut22z5qh = ( ( ( 0.0 - rtB . ihyeehrkag ) - rtB .
hoerz5xdv5 ) - rtB . gqqadn4y2w ) - rtB . hcfgyld3wj ; rtB . oo2wj0jvdb = 1.0
/ rtP . iyy * rtB . hmut22z5qh ; rtB . ni1kcttkok = rtP . lr * rtB .
pawhsqlpds ; rtB . lqnznmftiq = ( rtB . ni1kcttkok - rtB . jbu2t0zvvf ) + rtB
. jvzmdt5nzv ; rtB . ktwh1fzhvq = rtP . lr * rtB . ckhfos3d5d ; rtB .
pmogkogkdf = ( rtB . ktwh1fzhvq - rtB . f1s21kqqtk ) + rtB . m4u0zxcmnx ; rtB
. kemjegf3wo = rtB . jvzmdt5nzv - rtB . bptwtyixo3 ; { real_T * * uBuffer = (
real_T * * ) & rtDW . h3nqanizu1 . TUbufferPtrs [ 0 ] ; real_T * * tBuffer =
( real_T * * ) & rtDW . h3nqanizu1 . TUbufferPtrs [ 1 ] ; real_T simTime =
ssGetT ( rtS ) ; real_T tMinusDelay = simTime - rtP .
TransportDelay1_Delay_didz0ysu0l ; rtB . gnnxhf24lb = rt_TDelayInterpolate (
tMinusDelay , 0.0 , * tBuffer , * uBuffer , rtDW . hs0pmpahcd .
CircularBufSize , & rtDW . hs0pmpahcd . Last , rtDW . hs0pmpahcd . Tail ,
rtDW . hs0pmpahcd . Head , rtP . TransportDelay1_InitOutput_gsatvdlebd , 0 ,
( boolean_T ) ( ssIsMinorTimeStep ( rtS ) && ( ssGetTimeOfLastOutput ( rtS )
== ssGetT ( rtS ) ) ) ) ; } rtB . fugfqhq0tc = rtB . m4u0zxcmnx - rtB .
gnnxhf24lb ; rtB . m3uxwq3r5m = rtP . krs * rtB . lqnznmftiq ; rtB .
c1btrhwl4q = rtP . crs * rtB . pmogkogkdf ; rtB . li502xp5qt = rtP . krt *
rtB . kemjegf3wo ; rtB . lpc0zrp4fv = rtP . crt * rtB . fugfqhq0tc ; rtB .
lv5avdu4zp = ( ( ( 0.0 - rtB . m3uxwq3r5m ) - rtB . c1btrhwl4q ) - rtB .
li502xp5qt ) - rtB . lpc0zrp4fv ; rtB . ehwkpevl2t = 1.0 / rtP . mr * rtB .
lv5avdu4zp ; if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { if ( ssGetTaskTime ( rtS
, 2 ) < rtP . Step_Time_bwraqreocj ) { rtB . kjzusoosz1 = rtP .
Step_Y0_kdc10z30qv ; } else { rtB . kjzusoosz1 = rtP . Step_YFinal_kuwyhln44e
; } } if ( ssIsSampleHit ( rtS , 4 , 0 ) ) { if ( ssGetTaskTime ( rtS , 4 ) <
rtP . Step1_Time_oqjaobvqli ) { rtB . nx3vnoo2r0 = rtP . Step1_Y0_cerqkmzec3
; } else { rtB . nx3vnoo2r0 = rtP . Step1_YFinal_gb5ur2tfsw ; } } rtB .
dmq1oq0lr3 = muDoubleScalarSin ( 6.2831853071795862 * ssGetT ( rtS ) * rtP .
SignalGenerator_Frequency_ji325krl5r ) * rtP .
SignalGenerator_Amplitude_fh5dm5543u * rtB . kjzusoosz1 * rtB . nx3vnoo2r0 ;
if ( ssIsMajorTimeStep ( rtS ) ) { rtDW . ibxrdu4cbs = rtB . dmq1oq0lr3 >=
rtP . Saturation_UpperSat_lolh1xkie1 ? 1 : rtB . dmq1oq0lr3 > rtP .
Saturation_LowerSat_f31445vevn ? 0 : - 1 ; } rtB . cxhhghcvvq = rtDW .
ibxrdu4cbs == 1 ? rtP . Saturation_UpperSat_lolh1xkie1 : rtDW . ibxrdu4cbs ==
- 1 ? rtP . Saturation_LowerSat_f31445vevn : rtB . dmq1oq0lr3 ; rtB .
ey4a5uz5cz = rtP . lf * rtB . cwjqfhgoni ; rtB . dppbokyij3 = ( rtB .
ey4a5uz5cz + rtB . cwi04tubt0 ) - rtB . g2y0j4r4xp ; rtB . l3zyv4dhgg = rtP .
lr * rtB . cwjqfhgoni ; rtB . huaehj053c = ( rtB . l3zyv4dhgg - rtB .
cwi04tubt0 ) + rtB . ncrqgav3ps ; rtB . bhkcz3ic0o = rtP . lf * rtB .
gihker42li ; rtB . nd01hmisxb = rtX . a01qpr25bd ; rtB . kjvdspgfqm = rtX .
gfofwzctbq ; rtB . elpxc0kaoh = ( rtB . bhkcz3ic0o + rtB . nd01hmisxb ) - rtB
. kjvdspgfqm ; rtB . jxndwbjtgb = rtP . lr * rtB . gihker42li ; rtB .
ajj44xkzb4 = rtX . ixsdqmndrc ; rtB . dvvipddzve = ( rtB . jxndwbjtgb - rtB .
nd01hmisxb ) + rtB . ajj44xkzb4 ; rtB . mqne5uhs2r = rtP . kfs * rtB .
dppbokyij3 ; rtB . b2erwm3zaa = rtP . krs * rtB . huaehj053c ; rtB .
p5bk0c5qbh = ( rtB . nd01hmisxb - rtB . kjvdspgfqm ) * rtB . nd01hmisxb ;
rtPrevAction = rtDW . c12zxjgx2e ; if ( ssIsMajorTimeStep ( rtS ) ) {
rtAction = ( int8_T ) ! ( rtB . p5bk0c5qbh >= 0.0 ) ; rtDW . c12zxjgx2e =
rtAction ; } else { rtAction = rtDW . c12zxjgx2e ; } if ( rtPrevAction !=
rtAction ) { switch ( rtPrevAction ) { case 0 : dr3q4xjhlf ( rtS ) ; break ;
case 1 : dr3q4xjhlf ( rtS ) ; break ; } } switch ( rtAction ) { case 0 : if (
rtAction != rtPrevAction ) { i2sc5lqney ( rtS ) ; } fsrrbnl0on ( rtS , rtP .
Constant_Value_f34x3v0gei , & rtB . k4ai1xxr1d ) ; if ( ssIsMajorTimeStep (
rtS ) ) { srUpdateBC ( rtDW . levrnc2uqr . ax0ejju01d ) ; } break ; case 1 :
if ( rtAction != rtPrevAction ) { i2sc5lqney ( rtS ) ; } fsrrbnl0on ( rtS ,
rtP . Constant1_Value_gbvvgkwbnv , & rtB . k4ai1xxr1d ) ; if (
ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW . jwm3vbffir . ax0ejju01d ) ;
} break ; } rtB . dyzz0owi01 = rtB . elpxc0kaoh * rtB . k4ai1xxr1d ; rtB .
nyxhckusoe = ( rtB . nd01hmisxb - rtB . ajj44xkzb4 ) * rtB . nd01hmisxb ;
rtPrevAction = rtDW . d3g033qzzb ; if ( ssIsMajorTimeStep ( rtS ) ) {
rtAction = ( int8_T ) ! ( rtB . nyxhckusoe >= 0.0 ) ; rtDW . d3g033qzzb =
rtAction ; } else { rtAction = rtDW . d3g033qzzb ; } if ( rtPrevAction !=
rtAction ) { switch ( rtPrevAction ) { case 0 : dr3q4xjhlf ( rtS ) ; break ;
case 1 : dr3q4xjhlf ( rtS ) ; break ; } } switch ( rtAction ) { case 0 : if (
rtAction != rtPrevAction ) { i2sc5lqney ( rtS ) ; } fsrrbnl0on ( rtS , rtP .
Constant_Value_b0ss3j0del , & rtB . cxloeisrlx ) ; if ( ssIsMajorTimeStep (
rtS ) ) { srUpdateBC ( rtDW . d2f14sz0ii . ax0ejju01d ) ; } break ; case 1 :
if ( rtAction != rtPrevAction ) { i2sc5lqney ( rtS ) ; } fsrrbnl0on ( rtS ,
rtP . Constant1_Value_mr12qranuj , & rtB . cxloeisrlx ) ; if (
ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW . bj3t3ughuq . ax0ejju01d ) ;
} break ; } rtB . fk4xevkgeo = rtB . dvvipddzve * rtB . cxloeisrlx ; rtB .
ki1cdbfr44 = ( ( rtB . b2erwm3zaa - rtB . mqne5uhs2r ) - rtB . dyzz0owi01 ) +
rtB . fk4xevkgeo ; rtB . eqjo2nizcs = 1.0 / rtP . mc * rtB . ki1cdbfr44 ; if
( ssIsSampleHit ( rtS , 2 , 0 ) ) { if ( ssGetTaskTime ( rtS , 2 ) < rtP .
Step_Time_n2vdheg15a ) { rtB . fba3iic2xf = rtP . Step_Y0_cl32zzujww ; } else
{ rtB . fba3iic2xf = rtP . Step_YFinal_ioed2vlmyx ; } } if ( ssIsSampleHit (
rtS , 3 , 0 ) ) { if ( ssGetTaskTime ( rtS , 3 ) < rtP .
Step1_Time_nrjoxzvdeh ) { rtB . eqhzihanz1 = rtP . Step1_Y0_nln5lb0z31 ; }
else { rtB . eqhzihanz1 = rtP . Step1_YFinal_kymwsjvu4f ; } } rtB .
mzef1y2inq = muDoubleScalarSin ( 6.2831853071795862 * ssGetT ( rtS ) * rtP .
SignalGenerator_Frequency_k0uyvcxxrq ) * rtP .
SignalGenerator_Amplitude_g44bgrrq31 * rtB . fba3iic2xf * rtB . eqhzihanz1 ;
rtB . pfkze4zldv = rtP . Gain_Gain_ldzy4oavtu * rtB . mzef1y2inq ; if ( (
rtDW . lxx1qcag42 >= ssGetT ( rtS ) ) && ( rtDW . nktwazk3xa >= ssGetT ( rtS
) ) ) { rtB . oeksgiw32q = 0.0 ; } else { lastTime = rtDW . lxx1qcag42 ;
lastU = & rtDW . f5ldw1c3yp ; if ( rtDW . lxx1qcag42 < rtDW . nktwazk3xa ) {
if ( rtDW . nktwazk3xa < ssGetT ( rtS ) ) { lastTime = rtDW . nktwazk3xa ;
lastU = & rtDW . piqig1diza ; } } else { if ( rtDW . lxx1qcag42 >= ssGetT (
rtS ) ) { lastTime = rtDW . nktwazk3xa ; lastU = & rtDW . piqig1diza ; } }
rtB . oeksgiw32q = ( rtB . pfkze4zldv - * lastU ) / ( ssGetT ( rtS ) -
lastTime ) ; } { real_T * * uBuffer = ( real_T * * ) & rtDW . ip30edpzn0 .
TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * * ) & rtDW . ip30edpzn0
. TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( rtS ) ; real_T tMinusDelay =
simTime - rtP . TransportDelay_Delay_frmicxredo ; rtB . cotqcoyxuq =
rt_TDelayInterpolate ( tMinusDelay , 0.0 , * tBuffer , * uBuffer , rtDW .
pmbhiaijnw . CircularBufSize , & rtDW . pmbhiaijnw . Last , rtDW . pmbhiaijnw
. Tail , rtDW . pmbhiaijnw . Head , rtP .
TransportDelay_InitOutput_jhwmjqic5y , 0 , ( boolean_T ) ( ssIsMinorTimeStep
( rtS ) && ( ssGetTimeOfLastOutput ( rtS ) == ssGetT ( rtS ) ) ) ) ; } if ( (
rtDW . hxmdtipph3 >= ssGetT ( rtS ) ) && ( rtDW . hrm31px4c4 >= ssGetT ( rtS
) ) ) { rtB . aak2xlfzg2 = 0.0 ; } else { lastTime = rtDW . hxmdtipph3 ;
lastU = & rtDW . lcjxt5exz4 ; if ( rtDW . hxmdtipph3 < rtDW . hrm31px4c4 ) {
if ( rtDW . hrm31px4c4 < ssGetT ( rtS ) ) { lastTime = rtDW . hrm31px4c4 ;
lastU = & rtDW . i31w25jb1l ; } } else { if ( rtDW . hxmdtipph3 >= ssGetT (
rtS ) ) { lastTime = rtDW . hrm31px4c4 ; lastU = & rtDW . i31w25jb1l ; } }
rtB . aak2xlfzg2 = ( rtB . cotqcoyxuq - * lastU ) / ( ssGetT ( rtS ) -
lastTime ) ; } rtB . lewexece42 = rtP . lf * rtB . cwjqfhgoni ; rtB .
dzjno1a2on = ( rtB . lewexece42 + rtB . cwi04tubt0 ) - rtB . g2y0j4r4xp ; rtB
. l4rk2cmcdr = rtP . lf * rtB . gihker42li ; rtB . j14ytvzi0h = ( rtB .
l4rk2cmcdr + rtB . nd01hmisxb ) - rtB . kjvdspgfqm ; rtB . eozzahwbfw = rtB .
kjvdspgfqm - rtB . oeksgiw32q ; rtB . jbs5lruqei = rtB . g2y0j4r4xp - rtB .
pfkze4zldv ; rtB . muwt4hjweu = rtP . kfs * rtB . dzjno1a2on ; rtB .
mxkquiaqra = ( rtB . nd01hmisxb - rtB . kjvdspgfqm ) * rtB . nd01hmisxb ;
rtPrevAction = rtDW . kgnaiafrhn ; if ( ssIsMajorTimeStep ( rtS ) ) {
rtAction = ( int8_T ) ! ( rtB . mxkquiaqra >= 0.0 ) ; rtDW . kgnaiafrhn =
rtAction ; } else { rtAction = rtDW . kgnaiafrhn ; } if ( rtPrevAction !=
rtAction ) { switch ( rtPrevAction ) { case 0 : dr3q4xjhlf ( rtS ) ; break ;
case 1 : dr3q4xjhlf ( rtS ) ; break ; } } switch ( rtAction ) { case 0 : if (
rtAction != rtPrevAction ) { i2sc5lqney ( rtS ) ; } fsrrbnl0on ( rtS , rtP .
Constant_Value_ckbzzxjmxu , & rtB . igrtwxdc2h ) ; if ( ssIsMajorTimeStep (
rtS ) ) { srUpdateBC ( rtDW . dl522p3brs . ax0ejju01d ) ; } break ; case 1 :
if ( rtAction != rtPrevAction ) { i2sc5lqney ( rtS ) ; } fsrrbnl0on ( rtS ,
rtP . Constant1_Value_b5q3lrb3hv , & rtB . igrtwxdc2h ) ; if (
ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW . c51iqw5kno . ax0ejju01d ) ;
} break ; } rtB . bvpv0c32vh = rtB . j14ytvzi0h * rtB . igrtwxdc2h ; rtB .
jmwufnoosm = rtP . kft * rtB . jbs5lruqei ; rtB . hpln2b3wuo = rtP . cft *
rtB . eozzahwbfw ; rtB . ltzcpo0hwy = ( ( rtB . muwt4hjweu + rtB . bvpv0c32vh
) - rtB . jmwufnoosm ) - rtB . hpln2b3wuo ; rtB . bn0qdk1o0v = 1.0 / rtP . mf
* rtB . ltzcpo0hwy ; rtB . ehrgc2nkcd = rtP . lf * rtB . cwjqfhgoni ; rtB .
d04m0qgpku = ( rtB . ehrgc2nkcd + rtB . cwi04tubt0 ) - rtB . kjvdspgfqm ; rtB
. nuubxbg4lx = rtP . lr * rtB . cwjqfhgoni ; rtB . gebhzzqqrc = ( rtB .
nuubxbg4lx - rtB . cwi04tubt0 ) + rtB . g2y0j4r4xp ; rtB . onqwhhqtnq = rtP .
lr * rtB . gihker42li ; rtB . flrmowrcgb = ( rtB . onqwhhqtnq - rtB .
nd01hmisxb ) + rtB . ajj44xkzb4 ; rtB . bxeykf3lmp = rtP . lf * rtB .
gihker42li ; rtB . dwgmiiuskf = ( rtB . bxeykf3lmp + rtB . nd01hmisxb ) - rtB
. ajj44xkzb4 ; rtB . got041r5yx = rtP . kfs * rtB . d04m0qgpku ; rtB .
jya4dpmecv = rtP . lf * rtB . got041r5yx ; rtB . k3t5arlbzl = rtP . krs * rtB
. gebhzzqqrc ; rtB . hysbptybxp = rtP . lr * rtB . k3t5arlbzl ; rtB .
cdxeq3tabw = rtP . cfs * rtB . dwgmiiuskf ; rtB . fzgl12rcaq = rtP . lf * rtB
. cdxeq3tabw ; rtB . ftf3u5jby5 = rtP . crs * rtB . flrmowrcgb ; rtB .
axn3i3rmpl = rtP . lr * rtB . ftf3u5jby5 ; rtB . cur5w2fqr5 = ( ( ( 0.0 - rtB
. jya4dpmecv ) - rtB . hysbptybxp ) - rtB . fzgl12rcaq ) - rtB . axn3i3rmpl ;
rtB . p0nllhwxyq = 1.0 / rtP . iyy * rtB . cur5w2fqr5 ; rtB . eplzkxfoow =
rtP . lr * rtB . cwjqfhgoni ; rtB . lufwhlk53w = ( rtB . eplzkxfoow - rtB .
cwi04tubt0 ) + rtB . ncrqgav3ps ; rtB . e1yemdo2am = rtP . lr * rtB .
gihker42li ; rtB . jwnrysijt2 = ( rtB . e1yemdo2am - rtB . nd01hmisxb ) + rtB
. ajj44xkzb4 ; rtB . p3mpeqccbg = rtB . ncrqgav3ps - rtB . cotqcoyxuq ; {
real_T * * uBuffer = ( real_T * * ) & rtDW . nrh2tscls2 . TUbufferPtrs [ 0 ]
; real_T * * tBuffer = ( real_T * * ) & rtDW . nrh2tscls2 . TUbufferPtrs [ 1
] ; real_T simTime = ssGetT ( rtS ) ; real_T tMinusDelay = simTime - rtP .
TransportDelay1_Delay_oufsiqvqky ; rtB . hdzf4esqkr = rt_TDelayInterpolate (
tMinusDelay , 0.0 , * tBuffer , * uBuffer , rtDW . mbyl5zsvhx .
CircularBufSize , & rtDW . mbyl5zsvhx . Last , rtDW . mbyl5zsvhx . Tail ,
rtDW . mbyl5zsvhx . Head , rtP . TransportDelay1_InitOutput_i1rr3k5rot , 0 ,
( boolean_T ) ( ssIsMinorTimeStep ( rtS ) && ( ssGetTimeOfLastOutput ( rtS )
== ssGetT ( rtS ) ) ) ) ; } rtB . g4gcmmpsrw = rtB . ajj44xkzb4 - rtB .
hdzf4esqkr ; rtB . hdh1v0e0hz = rtP . krs * rtB . lufwhlk53w ; rtB .
fc035ww10i = ( rtB . nd01hmisxb - rtB . ajj44xkzb4 ) * rtB . nd01hmisxb ;
rtPrevAction = rtDW . k4echvbh31 ; if ( ssIsMajorTimeStep ( rtS ) ) {
rtAction = ( int8_T ) ! ( rtB . fc035ww10i >= 0.0 ) ; rtDW . k4echvbh31 =
rtAction ; } else { rtAction = rtDW . k4echvbh31 ; } if ( rtPrevAction !=
rtAction ) { switch ( rtPrevAction ) { case 0 : dr3q4xjhlf ( rtS ) ; break ;
case 1 : dr3q4xjhlf ( rtS ) ; break ; } } switch ( rtAction ) { case 0 : if (
rtAction != rtPrevAction ) { i2sc5lqney ( rtS ) ; } fsrrbnl0on ( rtS , rtP .
Constant_Value_ivnvcq4oxu , & rtB . jag5k22tya ) ; if ( ssIsMajorTimeStep (
rtS ) ) { srUpdateBC ( rtDW . n00rwomfjj . ax0ejju01d ) ; } break ; case 1 :
if ( rtAction != rtPrevAction ) { i2sc5lqney ( rtS ) ; } fsrrbnl0on ( rtS ,
rtP . Constant1_Value_mj2nmzyxxv , & rtB . jag5k22tya ) ; if (
ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW . chwszqir1s . ax0ejju01d ) ;
} break ; } rtB . n2zjj1zkuh = rtB . jwnrysijt2 * rtB . jag5k22tya ; rtB .
hh5p0emnle = rtP . krt * rtB . p3mpeqccbg ; rtB . g2uumgoeu1 = rtP . crt *
rtB . g4gcmmpsrw ; rtB . c0i4zuvblr = ( ( ( 0.0 - rtB . hdh1v0e0hz ) - rtB .
n2zjj1zkuh ) - rtB . hh5p0emnle ) - rtB . g2uumgoeu1 ; rtB . lxc1s1ijc2 = 1.0
/ rtP . mr * rtB . c0i4zuvblr ; if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { if (
ssGetTaskTime ( rtS , 2 ) < rtP . Step_Time_ief3iynhma ) { rtB . o4pksvc3du =
rtP . Step_Y0_hbpv5svquz ; } else { rtB . o4pksvc3du = rtP .
Step_YFinal_jsjbxkocsk ; } } if ( ssIsSampleHit ( rtS , 4 , 0 ) ) { if (
ssGetTaskTime ( rtS , 4 ) < rtP . Step1_Time_iwq124hwmz ) { rtB . p5mmmyyyb0
= rtP . Step1_Y0_cxcqlzhc5m ; } else { rtB . p5mmmyyyb0 = rtP .
Step1_YFinal_kconhbutz2 ; } } rtB . f00vunio45 = muDoubleScalarSin (
6.2831853071795862 * ssGetT ( rtS ) * rtP .
SignalGenerator_Frequency_esatikfj0t ) * rtP .
SignalGenerator_Amplitude_fqfftxwwhb * rtB . o4pksvc3du * rtB . p5mmmyyyb0 ;
if ( ssIsMajorTimeStep ( rtS ) ) { rtDW . o0angb0u2w = rtB . f00vunio45 >=
rtP . Saturation_UpperSat_gro4c0twir ? 1 : rtB . f00vunio45 > rtP .
Saturation_LowerSat_k5krwyec4a ? 0 : - 1 ; } rtB . czwkigmd1x = rtDW .
o0angb0u2w == 1 ? rtP . Saturation_UpperSat_gro4c0twir : rtDW . o0angb0u2w ==
- 1 ? rtP . Saturation_LowerSat_k5krwyec4a : rtB . f00vunio45 ;
UNUSED_PARAMETER ( tid ) ; } void MdlUpdate ( int_T tid ) { real_T * lastU ;
if ( rtDW . gfprm23pj3 == ( rtInf ) ) { rtDW . gfprm23pj3 = ssGetT ( rtS ) ;
lastU = & rtDW . fqetutrbi5 ; } else if ( rtDW . najgra25s3 == ( rtInf ) ) {
rtDW . najgra25s3 = ssGetT ( rtS ) ; lastU = & rtDW . lx2q3mhajb ; } else if
( rtDW . gfprm23pj3 < rtDW . najgra25s3 ) { rtDW . gfprm23pj3 = ssGetT ( rtS
) ; lastU = & rtDW . fqetutrbi5 ; } else { rtDW . najgra25s3 = ssGetT ( rtS )
; lastU = & rtDW . lx2q3mhajb ; } * lastU = rtB . jobgxinndp ; { real_T * *
uBuffer = ( real_T * * ) & rtDW . jlohj4cavb . TUbufferPtrs [ 0 ] ; real_T *
* tBuffer = ( real_T * * ) & rtDW . jlohj4cavb . TUbufferPtrs [ 1 ] ; real_T
simTime = ssGetT ( rtS ) ; rtDW . ewcikv2lwd . Head = ( ( rtDW . ewcikv2lwd .
Head < ( rtDW . ewcikv2lwd . CircularBufSize - 1 ) ) ? ( rtDW . ewcikv2lwd .
Head + 1 ) : 0 ) ; if ( rtDW . ewcikv2lwd . Head == rtDW . ewcikv2lwd . Tail
) { if ( ! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . ewcikv2lwd .
CircularBufSize , & rtDW . ewcikv2lwd . Tail , & rtDW . ewcikv2lwd . Head , &
rtDW . ewcikv2lwd . Last , simTime - rtP . TransportDelay_Delay , tBuffer ,
uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & rtDW . ewcikv2lwd .
MaxNewBufSize ) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error"
) ; return ; } } ( * tBuffer ) [ rtDW . ewcikv2lwd . Head ] = simTime ; ( *
uBuffer ) [ rtDW . ewcikv2lwd . Head ] = rtB . jobgxinndp ; } if ( rtDW .
nflnwukwbw == ( rtInf ) ) { rtDW . nflnwukwbw = ssGetT ( rtS ) ; lastU = &
rtDW . j4zffuf2jc ; } else if ( rtDW . de4qoi0fyx == ( rtInf ) ) { rtDW .
de4qoi0fyx = ssGetT ( rtS ) ; lastU = & rtDW . ay4ykamdli ; } else if ( rtDW
. nflnwukwbw < rtDW . de4qoi0fyx ) { rtDW . nflnwukwbw = ssGetT ( rtS ) ;
lastU = & rtDW . j4zffuf2jc ; } else { rtDW . de4qoi0fyx = ssGetT ( rtS ) ;
lastU = & rtDW . ay4ykamdli ; } * lastU = rtB . nrrfaz4txr ; { real_T * *
uBuffer = ( real_T * * ) & rtDW . l1amy53ft4 . TUbufferPtrs [ 0 ] ; real_T *
* tBuffer = ( real_T * * ) & rtDW . l1amy53ft4 . TUbufferPtrs [ 1 ] ; real_T
simTime = ssGetT ( rtS ) ; rtDW . fv0rpgctfs . Head = ( ( rtDW . fv0rpgctfs .
Head < ( rtDW . fv0rpgctfs . CircularBufSize - 1 ) ) ? ( rtDW . fv0rpgctfs .
Head + 1 ) : 0 ) ; if ( rtDW . fv0rpgctfs . Head == rtDW . fv0rpgctfs . Tail
) { if ( ! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . fv0rpgctfs .
CircularBufSize , & rtDW . fv0rpgctfs . Tail , & rtDW . fv0rpgctfs . Head , &
rtDW . fv0rpgctfs . Last , simTime - rtP . TransportDelay1_Delay , tBuffer ,
uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & rtDW . fv0rpgctfs .
MaxNewBufSize ) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error"
) ; return ; } } ( * tBuffer ) [ rtDW . fv0rpgctfs . Head ] = simTime ; ( *
uBuffer ) [ rtDW . fv0rpgctfs . Head ] = rtB . dnyl1ewlz0 ; } if ( rtDW .
jpmhq0y24v == ( rtInf ) ) { rtDW . jpmhq0y24v = ssGetT ( rtS ) ; lastU = &
rtDW . eetn342tct ; } else if ( rtDW . ijphmshkuf == ( rtInf ) ) { rtDW .
ijphmshkuf = ssGetT ( rtS ) ; lastU = & rtDW . pdelqeetgv ; } else if ( rtDW
. jpmhq0y24v < rtDW . ijphmshkuf ) { rtDW . jpmhq0y24v = ssGetT ( rtS ) ;
lastU = & rtDW . eetn342tct ; } else { rtDW . ijphmshkuf = ssGetT ( rtS ) ;
lastU = & rtDW . pdelqeetgv ; } * lastU = rtB . p5qpsydo5q ; { real_T * *
uBuffer = ( real_T * * ) & rtDW . omrnl2kvox . TUbufferPtrs [ 0 ] ; real_T *
* tBuffer = ( real_T * * ) & rtDW . omrnl2kvox . TUbufferPtrs [ 1 ] ; real_T
simTime = ssGetT ( rtS ) ; rtDW . ped5kwc4j1 . Head = ( ( rtDW . ped5kwc4j1 .
Head < ( rtDW . ped5kwc4j1 . CircularBufSize - 1 ) ) ? ( rtDW . ped5kwc4j1 .
Head + 1 ) : 0 ) ; if ( rtDW . ped5kwc4j1 . Head == rtDW . ped5kwc4j1 . Tail
) { if ( ! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . ped5kwc4j1 .
CircularBufSize , & rtDW . ped5kwc4j1 . Tail , & rtDW . ped5kwc4j1 . Head , &
rtDW . ped5kwc4j1 . Last , simTime - rtP . TransportDelay_Delay_iap2op2zgh ,
tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & rtDW . ped5kwc4j1
. MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ) [ rtDW .
ped5kwc4j1 . Head ] = simTime ; ( * uBuffer ) [ rtDW . ped5kwc4j1 . Head ] =
rtB . p5qpsydo5q ; } if ( rtDW . mntyae3rsq == ( rtInf ) ) { rtDW .
mntyae3rsq = ssGetT ( rtS ) ; lastU = & rtDW . bxic41ulzf ; } else if ( rtDW
. psneabumzv == ( rtInf ) ) { rtDW . psneabumzv = ssGetT ( rtS ) ; lastU = &
rtDW . jhe2qhrig2 ; } else if ( rtDW . mntyae3rsq < rtDW . psneabumzv ) {
rtDW . mntyae3rsq = ssGetT ( rtS ) ; lastU = & rtDW . bxic41ulzf ; } else {
rtDW . psneabumzv = ssGetT ( rtS ) ; lastU = & rtDW . jhe2qhrig2 ; } * lastU
= rtB . p4oanyhhie ; { real_T * * uBuffer = ( real_T * * ) & rtDW .
b0rupvaogl . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * * ) & rtDW
. b0rupvaogl . TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( rtS ) ; rtDW .
aem0ceeew5 . Head = ( ( rtDW . aem0ceeew5 . Head < ( rtDW . aem0ceeew5 .
CircularBufSize - 1 ) ) ? ( rtDW . aem0ceeew5 . Head + 1 ) : 0 ) ; if ( rtDW
. aem0ceeew5 . Head == rtDW . aem0ceeew5 . Tail ) { if ( !
rt_TDelayUpdateTailOrGrowBuf ( & rtDW . aem0ceeew5 . CircularBufSize , & rtDW
. aem0ceeew5 . Tail , & rtDW . aem0ceeew5 . Head , & rtDW . aem0ceeew5 . Last
, simTime - rtP . TransportDelay1_Delay_e5t1cmi5b5 , tBuffer , uBuffer , (
NULL ) , ( boolean_T ) 0 , false , & rtDW . aem0ceeew5 . MaxNewBufSize ) ) {
ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ; } } (
* tBuffer ) [ rtDW . aem0ceeew5 . Head ] = simTime ; ( * uBuffer ) [ rtDW .
aem0ceeew5 . Head ] = rtB . p2gjpa4kz5 ; } if ( rtDW . goagc5i3gw == ( rtInf
) ) { rtDW . goagc5i3gw = ssGetT ( rtS ) ; lastU = & rtDW . ovio5arldz ; }
else if ( rtDW . k5o3zhu0wr == ( rtInf ) ) { rtDW . k5o3zhu0wr = ssGetT ( rtS
) ; lastU = & rtDW . lioetblzpp ; } else if ( rtDW . goagc5i3gw < rtDW .
k5o3zhu0wr ) { rtDW . goagc5i3gw = ssGetT ( rtS ) ; lastU = & rtDW .
ovio5arldz ; } else { rtDW . k5o3zhu0wr = ssGetT ( rtS ) ; lastU = & rtDW .
lioetblzpp ; } * lastU = rtB . bu3dppt1dy ; { real_T * * uBuffer = ( real_T *
* ) & rtDW . onssg0ise1 . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T
* * ) & rtDW . onssg0ise1 . TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT (
rtS ) ; rtDW . nogfvg0pt3 . Head = ( ( rtDW . nogfvg0pt3 . Head < ( rtDW .
nogfvg0pt3 . CircularBufSize - 1 ) ) ? ( rtDW . nogfvg0pt3 . Head + 1 ) : 0 )
; if ( rtDW . nogfvg0pt3 . Head == rtDW . nogfvg0pt3 . Tail ) { if ( !
rt_TDelayUpdateTailOrGrowBuf ( & rtDW . nogfvg0pt3 . CircularBufSize , & rtDW
. nogfvg0pt3 . Tail , & rtDW . nogfvg0pt3 . Head , & rtDW . nogfvg0pt3 . Last
, simTime - rtP . TransportDelay_Delay_eqwrqaxknp , tBuffer , uBuffer , (
NULL ) , ( boolean_T ) 0 , false , & rtDW . nogfvg0pt3 . MaxNewBufSize ) ) {
ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ; } } (
* tBuffer ) [ rtDW . nogfvg0pt3 . Head ] = simTime ; ( * uBuffer ) [ rtDW .
nogfvg0pt3 . Head ] = rtB . bu3dppt1dy ; } if ( rtDW . dqvle0o2bf == ( rtInf
) ) { rtDW . dqvle0o2bf = ssGetT ( rtS ) ; lastU = & rtDW . kr1ksgnw4x ; }
else if ( rtDW . dp5dxb3enf == ( rtInf ) ) { rtDW . dp5dxb3enf = ssGetT ( rtS
) ; lastU = & rtDW . edxttokajv ; } else if ( rtDW . dqvle0o2bf < rtDW .
dp5dxb3enf ) { rtDW . dqvle0o2bf = ssGetT ( rtS ) ; lastU = & rtDW .
kr1ksgnw4x ; } else { rtDW . dp5dxb3enf = ssGetT ( rtS ) ; lastU = & rtDW .
edxttokajv ; } * lastU = rtB . bptwtyixo3 ; { real_T * * uBuffer = ( real_T *
* ) & rtDW . h3nqanizu1 . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T
* * ) & rtDW . h3nqanizu1 . TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT (
rtS ) ; rtDW . hs0pmpahcd . Head = ( ( rtDW . hs0pmpahcd . Head < ( rtDW .
hs0pmpahcd . CircularBufSize - 1 ) ) ? ( rtDW . hs0pmpahcd . Head + 1 ) : 0 )
; if ( rtDW . hs0pmpahcd . Head == rtDW . hs0pmpahcd . Tail ) { if ( !
rt_TDelayUpdateTailOrGrowBuf ( & rtDW . hs0pmpahcd . CircularBufSize , & rtDW
. hs0pmpahcd . Tail , & rtDW . hs0pmpahcd . Head , & rtDW . hs0pmpahcd . Last
, simTime - rtP . TransportDelay1_Delay_didz0ysu0l , tBuffer , uBuffer , (
NULL ) , ( boolean_T ) 0 , false , & rtDW . hs0pmpahcd . MaxNewBufSize ) ) {
ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ; } } (
* tBuffer ) [ rtDW . hs0pmpahcd . Head ] = simTime ; ( * uBuffer ) [ rtDW .
hs0pmpahcd . Head ] = rtB . enljiew2kc ; } if ( rtDW . lxx1qcag42 == ( rtInf
) ) { rtDW . lxx1qcag42 = ssGetT ( rtS ) ; lastU = & rtDW . f5ldw1c3yp ; }
else if ( rtDW . nktwazk3xa == ( rtInf ) ) { rtDW . nktwazk3xa = ssGetT ( rtS
) ; lastU = & rtDW . piqig1diza ; } else if ( rtDW . lxx1qcag42 < rtDW .
nktwazk3xa ) { rtDW . lxx1qcag42 = ssGetT ( rtS ) ; lastU = & rtDW .
f5ldw1c3yp ; } else { rtDW . nktwazk3xa = ssGetT ( rtS ) ; lastU = & rtDW .
piqig1diza ; } * lastU = rtB . pfkze4zldv ; { real_T * * uBuffer = ( real_T *
* ) & rtDW . ip30edpzn0 . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T
* * ) & rtDW . ip30edpzn0 . TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT (
rtS ) ; rtDW . pmbhiaijnw . Head = ( ( rtDW . pmbhiaijnw . Head < ( rtDW .
pmbhiaijnw . CircularBufSize - 1 ) ) ? ( rtDW . pmbhiaijnw . Head + 1 ) : 0 )
; if ( rtDW . pmbhiaijnw . Head == rtDW . pmbhiaijnw . Tail ) { if ( !
rt_TDelayUpdateTailOrGrowBuf ( & rtDW . pmbhiaijnw . CircularBufSize , & rtDW
. pmbhiaijnw . Tail , & rtDW . pmbhiaijnw . Head , & rtDW . pmbhiaijnw . Last
, simTime - rtP . TransportDelay_Delay_frmicxredo , tBuffer , uBuffer , (
NULL ) , ( boolean_T ) 0 , false , & rtDW . pmbhiaijnw . MaxNewBufSize ) ) {
ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ; } } (
* tBuffer ) [ rtDW . pmbhiaijnw . Head ] = simTime ; ( * uBuffer ) [ rtDW .
pmbhiaijnw . Head ] = rtB . pfkze4zldv ; } if ( rtDW . hxmdtipph3 == ( rtInf
) ) { rtDW . hxmdtipph3 = ssGetT ( rtS ) ; lastU = & rtDW . lcjxt5exz4 ; }
else if ( rtDW . hrm31px4c4 == ( rtInf ) ) { rtDW . hrm31px4c4 = ssGetT ( rtS
) ; lastU = & rtDW . i31w25jb1l ; } else if ( rtDW . hxmdtipph3 < rtDW .
hrm31px4c4 ) { rtDW . hxmdtipph3 = ssGetT ( rtS ) ; lastU = & rtDW .
lcjxt5exz4 ; } else { rtDW . hrm31px4c4 = ssGetT ( rtS ) ; lastU = & rtDW .
i31w25jb1l ; } * lastU = rtB . cotqcoyxuq ; { real_T * * uBuffer = ( real_T *
* ) & rtDW . nrh2tscls2 . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T
* * ) & rtDW . nrh2tscls2 . TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT (
rtS ) ; rtDW . mbyl5zsvhx . Head = ( ( rtDW . mbyl5zsvhx . Head < ( rtDW .
mbyl5zsvhx . CircularBufSize - 1 ) ) ? ( rtDW . mbyl5zsvhx . Head + 1 ) : 0 )
; if ( rtDW . mbyl5zsvhx . Head == rtDW . mbyl5zsvhx . Tail ) { if ( !
rt_TDelayUpdateTailOrGrowBuf ( & rtDW . mbyl5zsvhx . CircularBufSize , & rtDW
. mbyl5zsvhx . Tail , & rtDW . mbyl5zsvhx . Head , & rtDW . mbyl5zsvhx . Last
, simTime - rtP . TransportDelay1_Delay_oufsiqvqky , tBuffer , uBuffer , (
NULL ) , ( boolean_T ) 0 , false , & rtDW . mbyl5zsvhx . MaxNewBufSize ) ) {
ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ; } } (
* tBuffer ) [ rtDW . mbyl5zsvhx . Head ] = simTime ; ( * uBuffer ) [ rtDW .
mbyl5zsvhx . Head ] = rtB . aak2xlfzg2 ; } UNUSED_PARAMETER ( tid ) ; } void
MdlUpdateTID5 ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void
MdlDerivatives ( void ) { XDot * _rtXdot ; _rtXdot = ( ( XDot * ) ssGetdX (
rtS ) ) ; _rtXdot -> juvpl32rp1 = rtB . oo2wj0jvdb ; _rtXdot -> e2u4ehzbg1 =
rtB . hzo0vy2urp ; _rtXdot -> kyyzo52dwm = rtB . p0nllhwxyq ; _rtXdot ->
ku1dk4ixzj = rtB . h2riih5p4x ; _rtXdot -> koq0js0atb = rtB . f1s21kqqtk ;
_rtXdot -> pionb1hpkd = rtB . oy1jpf0hjr ; _rtXdot -> gjyvqirdz3 = rtB .
nd01hmisxb ; _rtXdot -> aq3q20solx = rtB . ors3z5ofsx ; _rtXdot -> o3tzwtysbm
= rtB . g5dxxhvf0d ; _rtXdot -> bqwvntcz2w = rtB . hp1xxrtth5 ; _rtXdot ->
lsnvs0t4wu = rtB . kjvdspgfqm ; _rtXdot -> bzhhffa4dl = rtB . ewfilzdy5p ;
_rtXdot -> bgj1d5tkhj = rtB . ckhfos3d5d ; _rtXdot -> ky5ai02ezd = rtB .
ctr3nygjvu ; _rtXdot -> dplugctjxc = rtB . gihker42li ; _rtXdot -> cpl1ejbcms
= rtB . fgv0iw5io4 ; _rtXdot -> n2slq3mqpo = rtB . m4u0zxcmnx ; _rtXdot ->
hxtsx1lenp = rtB . oshpndvkvq ; _rtXdot -> ne20tsu1eg = rtB . ajj44xkzb4 ;
_rtXdot -> hyvy5y052m = rtB . c12jn5x4j0 ; _rtXdot -> lqt0ebaexk = rtB .
ew12od4jo4 ; _rtXdot -> nherdhh2v5 = rtB . dshdg4oozs ; _rtXdot -> ptgllb4wkr
= rtB . gaaymicbge ; _rtXdot -> avtxyi5gqp = rtB . irdye5g1gh ; _rtXdot ->
b3davkt1eh = rtB . d14mmlv3sc ; _rtXdot -> pulwqgjkwh = rtB . leqschf41u ;
_rtXdot -> g2zcmmoypm = rtB . memjmzawon ; _rtXdot -> efgd0a2xyp = rtB .
hdmwzbgags ; _rtXdot -> i3bwmkwwlg = rtB . ehwkpevl2t ; _rtXdot -> a01qpr25bd
= rtB . eqjo2nizcs ; _rtXdot -> gfofwzctbq = rtB . bn0qdk1o0v ; _rtXdot ->
ixsdqmndrc = rtB . lxc1s1ijc2 ; } void MdlProjection ( void ) { } void
MdlZeroCrossings ( void ) { ZCV * _rtZCSV ; _rtZCSV = ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) ; _rtZCSV -> fyfri4vcfq = 0.0 ; if ( rtB
. nbl2g1zklu >= 0.0 ) { _rtZCSV -> fyfri4vcfq = 1.0 ; } _rtZCSV -> op2jtwngd2
= 0.0 ; if ( rtB . husvkqrr5g >= 0.0 ) { _rtZCSV -> op2jtwngd2 = 1.0 ; }
_rtZCSV -> jxsw51r0f5 = 0.0 ; if ( rtB . jrhinsm5vq >= 0.0 ) { _rtZCSV ->
jxsw51r0f5 = 1.0 ; } _rtZCSV -> ljrsoy22v0 = 0.0 ; if ( rtB . owdhyrttis >=
0.0 ) { _rtZCSV -> ljrsoy22v0 = 1.0 ; } _rtZCSV -> itu0ythezp = rtB .
ioubxgazf2 - rtP . Saturation_UpperSat ; _rtZCSV -> jl5mxhh5wz = rtB .
ioubxgazf2 - rtP . Saturation_LowerSat ; _rtZCSV -> euwx0xke1o = 0.0 ; if (
rtB . l5ft2k3pks >= 0.0 ) { _rtZCSV -> euwx0xke1o = 1.0 ; } _rtZCSV ->
e43adcwpbp = 0.0 ; if ( rtB . c4o1bl135b >= 0.0 ) { _rtZCSV -> e43adcwpbp =
1.0 ; } _rtZCSV -> kiauknssha = 0.0 ; if ( rtB . nvjwsszq20 >= 0.0 ) {
_rtZCSV -> kiauknssha = 1.0 ; } _rtZCSV -> ai0se3v1ku = 0.0 ; if ( rtB .
d3p1u0mvns >= 0.0 ) { _rtZCSV -> ai0se3v1ku = 1.0 ; } _rtZCSV -> dnjciwluue =
0.0 ; if ( rtB . nifjgpnast >= 0.0 ) { _rtZCSV -> dnjciwluue = 1.0 ; }
_rtZCSV -> ntgs0g4eef = 0.0 ; if ( rtB . bft4uxvudw >= 0.0 ) { _rtZCSV ->
ntgs0g4eef = 1.0 ; } _rtZCSV -> loeionkeyh = 0.0 ; if ( rtB . pmv2c05bpb >=
0.0 ) { _rtZCSV -> loeionkeyh = 1.0 ; } _rtZCSV -> dlhgspcagz = 0.0 ; if (
rtB . ni04k2if4f >= 0.0 ) { _rtZCSV -> dlhgspcagz = 1.0 ; } _rtZCSV ->
frdwevtiou = rtB . iw40x310lw - rtP . Saturation_UpperSat_nmc40qz4uh ;
_rtZCSV -> kmxmar43xe = rtB . iw40x310lw - rtP .
Saturation_LowerSat_avfz2gn5tr ; _rtZCSV -> ck4b0o5bls = rtB . dmq1oq0lr3 -
rtP . Saturation_UpperSat_lolh1xkie1 ; _rtZCSV -> d4wmkkqjtw = rtB .
dmq1oq0lr3 - rtP . Saturation_LowerSat_f31445vevn ; _rtZCSV -> cn1ocaebjc =
0.0 ; if ( rtB . p5bk0c5qbh >= 0.0 ) { _rtZCSV -> cn1ocaebjc = 1.0 ; }
_rtZCSV -> cg0zc0qybx = 0.0 ; if ( rtB . nyxhckusoe >= 0.0 ) { _rtZCSV ->
cg0zc0qybx = 1.0 ; } _rtZCSV -> cu4ffbrkwd = 0.0 ; if ( rtB . mxkquiaqra >=
0.0 ) { _rtZCSV -> cu4ffbrkwd = 1.0 ; } _rtZCSV -> kfl2zw3ics = 0.0 ; if (
rtB . fc035ww10i >= 0.0 ) { _rtZCSV -> kfl2zw3ics = 1.0 ; } _rtZCSV ->
dtaod4lzlx = rtB . f00vunio45 - rtP . Saturation_UpperSat_gro4c0twir ;
_rtZCSV -> mteu3qk3we = rtB . f00vunio45 - rtP .
Saturation_LowerSat_k5krwyec4a ; } void MdlTerminate ( void ) {
rt_TDelayFreeBuf ( rtDW . jlohj4cavb . TUbufferPtrs [ 0 ] ) ;
rt_TDelayFreeBuf ( rtDW . l1amy53ft4 . TUbufferPtrs [ 0 ] ) ;
rt_TDelayFreeBuf ( rtDW . omrnl2kvox . TUbufferPtrs [ 0 ] ) ;
rt_TDelayFreeBuf ( rtDW . b0rupvaogl . TUbufferPtrs [ 0 ] ) ;
rt_TDelayFreeBuf ( rtDW . onssg0ise1 . TUbufferPtrs [ 0 ] ) ;
rt_TDelayFreeBuf ( rtDW . h3nqanizu1 . TUbufferPtrs [ 0 ] ) ;
rt_TDelayFreeBuf ( rtDW . ip30edpzn0 . TUbufferPtrs [ 0 ] ) ;
rt_TDelayFreeBuf ( rtDW . nrh2tscls2 . TUbufferPtrs [ 0 ] ) ; if (
rt_slioCatalogue ( ) != ( NULL ) ) { void * * slioCatalogueAddr =
rt_slioCatalogueAddr ( ) ; rtwSaveDatasetsToMatFile (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ,
rt_GetMatSigstreamLoggingFileName ( ) ) ; rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = NULL ; } } void
MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 32 ) ;
ssSetNumPeriodicContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 0 ) ; ssSetNumU (
rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ; ssSetNumSampleTimes ( rtS ,
5 ) ; ssSetNumBlocks ( rtS , 471 ) ; ssSetNumBlockIO ( rtS , 336 ) ;
ssSetNumBlockParams ( rtS , 182 ) ; } void MdlInitializeSampleTimes ( void )
{ ssSetSampleTime ( rtS , 0 , 0.0 ) ; ssSetSampleTime ( rtS , 1 , 0.0 ) ;
ssSetSampleTime ( rtS , 2 , 1.08 ) ; ssSetSampleTime ( rtS , 3 , 1.35 ) ;
ssSetSampleTime ( rtS , 4 , 4.0 ) ; ssSetOffsetTime ( rtS , 0 , 0.0 ) ;
ssSetOffsetTime ( rtS , 1 , 1.0 ) ; ssSetOffsetTime ( rtS , 2 , 0.0 ) ;
ssSetOffsetTime ( rtS , 3 , 0.0 ) ; ssSetOffsetTime ( rtS , 4 , 0.0 ) ; }
void raccel_set_checksum ( ) { ssSetChecksumVal ( rtS , 0 , 4216868706U ) ;
ssSetChecksumVal ( rtS , 1 , 730283112U ) ; ssSetChecksumVal ( rtS , 2 ,
4144769863U ) ; ssSetChecksumVal ( rtS , 3 , 4039461416U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( void ) { static struct _ssMdlInfo mdlInfo
; ( void ) memset ( ( char * ) rtS , 0 , sizeof ( SimStruct ) ) ; ( void )
memset ( ( char * ) & mdlInfo , 0 , sizeof ( struct _ssMdlInfo ) ) ;
ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } { real_T * x = ( real_T * ) & rtX ; ssSetContStates ( rtS , x ) ;
( void ) memset ( ( void * ) x , 0 , sizeof ( X ) ) ; } { void * dwork = (
void * ) & rtDW ; ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork ,
0 , sizeof ( DW ) ) ; } { static DataTypeTransInfo dtInfo ; ( void ) memset (
( char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS
, & dtInfo ) ; dtInfo . numDataTypes = 14 ; dtInfo . dataTypeSizes = &
rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ;
dtInfo . BTransTable = & rtBTransTable ; dtInfo . PTransTable = &
rtPTransTable ; dtInfo . dataTypeInfoTable = rtDataTypeInfoTable ; }
suspension_11_13_InitializeDataMapInfo ( ) ; ssSetIsRapidAcceleratorActive (
rtS , true ) ; ssSetRootSS ( rtS , rtS ) ; ssSetVersion ( rtS ,
SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS , "suspension_11_13" ) ;
ssSetPath ( rtS , "suspension_11_13" ) ; ssSetTStart ( rtS , 0.0 ) ;
ssSetTFinal ( rtS , 10.0 ) ; { static RTWLogInfo rt_DataLoggingInfo ;
rt_DataLoggingInfo . loggingInterval = NULL ; ssSetRTWLogInfo ( rtS , &
rt_DataLoggingInfo ) ; } { rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) ,
( NULL ) ) ; rtliSetLogXSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) ,
"" ) ; rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS , & statesInfo2 )
; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 32 ] ; static
real_T absTol [ 32 ] = { 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6
, 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 } ; static uint8_T absTolControl [ 32 ] = { 0U , 0U , 0U , 0U
, 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U ,
0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U } ; static
uint8_T zcAttributes [ 24 ] = { ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) } ; static ssNonContDerivSigInfo
nonContDerivSigInfo [ 20 ] = { { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
jag5k22tya ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
igrtwxdc2h ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
eqhzihanz1 ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
fba3iic2xf ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
cxloeisrlx ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
k4ai1xxr1d ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
ph2e13dkoz ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
poz0njf0k5 ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
avovxjitlj ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
oxpgpvieu5 ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
fkz2npxwns ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
dgotzim4ft ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
hegnhw35oi ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
fsb3gaohdk ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
h53izkjog2 ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
mjw5ulp0gg ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
cbs2crqgjz ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
k0rxxdqz3n ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
iyiruigdqg ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
kgnzsa0lua ) , ( NULL ) } } ; ssSetSolverRelTol ( rtS , 0.001 ) ;
ssSetStepSize ( rtS , 0.0 ) ; ssSetMinStepSize ( rtS , 0.0 ) ;
ssSetMaxNumMinSteps ( rtS , - 1 ) ; ssSetMinStepViolatedError ( rtS , 0 ) ;
ssSetMaxStepSize ( rtS , 0.18181818181818182 ) ; ssSetSolverMaxOrder ( rtS ,
- 1 ) ; ssSetSolverRefineFactor ( rtS , 1 ) ; ssSetOutputTimes ( rtS , ( NULL
) ) ; ssSetNumOutputTimes ( rtS , 0 ) ; ssSetOutputTimesOnly ( rtS , 0 ) ;
ssSetOutputTimesIndex ( rtS , 0 ) ; ssSetZCCacheNeedsReset ( rtS , 1 ) ;
ssSetDerivCacheNeedsReset ( rtS , 0 ) ; ssSetNumNonContDerivSigInfos ( rtS ,
20 ) ; ssSetNonContDerivSigInfos ( rtS , nonContDerivSigInfo ) ;
ssSetSolverInfo ( rtS , & slvrInfo ) ; ssSetSolverName ( rtS ,
"VariableStepAuto" ) ; ssSetVariableStepSolver ( rtS , 1 ) ;
ssSetSolverConsistencyChecking ( rtS , 0 ) ; ssSetSolverAdaptiveZcDetection (
rtS , 0 ) ; ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetAbsTolVector (
rtS , absTol ) ; ssSetAbsTolControlVector ( rtS , absTolControl ) ;
ssSetSolverAbsTol_Obsolete ( rtS , absTol ) ;
ssSetSolverAbsTolControl_Obsolete ( rtS , absTolControl ) ;
ssSetSolverStateProjection ( rtS , 0 ) ; ssSetSolverMassMatrixType ( rtS , (
ssMatrixType ) 0 ) ; ssSetSolverMassMatrixNzMax ( rtS , 0 ) ;
ssSetModelOutputs ( rtS , MdlOutputs ) ; ssSetModelLogData ( rtS ,
rt_UpdateTXYLogVars ) ; ssSetModelLogDataIfInInterval ( rtS ,
rt_UpdateTXXFYLogVars ) ; ssSetModelUpdate ( rtS , MdlUpdate ) ;
ssSetModelDerivatives ( rtS , MdlDerivatives ) ; ssSetSolverZcSignalAttrib (
rtS , zcAttributes ) ; ssSetSolverNumZcSignals ( rtS , 24 ) ;
ssSetModelZeroCrossings ( rtS , MdlZeroCrossings ) ;
ssSetSolverConsecutiveZCsStepRelTol ( rtS , 2.8421709430404007E-13 ) ;
ssSetSolverMaxConsecutiveZCs ( rtS , 1000 ) ; ssSetSolverConsecutiveZCsError
( rtS , 2 ) ; ssSetSolverMaskedZcDiagnostic ( rtS , 1 ) ;
ssSetSolverIgnoredZcDiagnostic ( rtS , 1 ) ; ssSetSolverMaxConsecutiveMinStep
( rtS , 1 ) ; ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid (
rtS , INT_MIN ) ; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset (
rtS ) ; ssSetNumNonsampledZCs ( rtS , 24 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; }
ssSetChecksumVal ( rtS , 0 , 4216868706U ) ; ssSetChecksumVal ( rtS , 1 ,
730283112U ) ; ssSetChecksumVal ( rtS , 2 , 4144769863U ) ; ssSetChecksumVal
( rtS , 3 , 4039461416U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 33 ] ; gblRTWExtModeInfo = & rt_ExtModeInfo ;
ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo ) ;
rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = ( sysRanDType * ) &
rtDW . nbpepiek5as . c4bsnmlro2 ; systemRan [ 2 ] = ( sysRanDType * ) & rtDW
. fsrrbnl0ono . ax0ejju01d ; systemRan [ 3 ] = ( sysRanDType * ) & rtDW .
mysqkq0tgk . c4bsnmlro2 ; systemRan [ 4 ] = ( sysRanDType * ) & rtDW .
ajnw1b3gfz . ax0ejju01d ; systemRan [ 5 ] = ( sysRanDType * ) & rtDW .
iwvaw3chcg . c4bsnmlro2 ; systemRan [ 6 ] = ( sysRanDType * ) & rtDW .
gciy5nryyx . ax0ejju01d ; systemRan [ 7 ] = ( sysRanDType * ) & rtDW .
cical55ljv . c4bsnmlro2 ; systemRan [ 8 ] = ( sysRanDType * ) & rtDW .
bxy5pgokky . ax0ejju01d ; systemRan [ 9 ] = ( sysRanDType * ) & rtDW .
hzattc0vf2 . c4bsnmlro2 ; systemRan [ 10 ] = ( sysRanDType * ) & rtDW .
k1t5j21xa2 . ax0ejju01d ; systemRan [ 11 ] = ( sysRanDType * ) & rtDW .
htznribv1q . ax0ejju01d ; systemRan [ 12 ] = ( sysRanDType * ) & rtDW .
fibtpbiz5w . ax0ejju01d ; systemRan [ 13 ] = ( sysRanDType * ) & rtDW .
lxwl2pumah . c4bsnmlro2 ; systemRan [ 14 ] = ( sysRanDType * ) & rtDW .
fo1s40z2ng . ax0ejju01d ; systemRan [ 15 ] = ( sysRanDType * ) & rtDW .
blc3y3lbsz . ax0ejju01d ; systemRan [ 16 ] = ( sysRanDType * ) & rtDW .
nkptjiojzm . ax0ejju01d ; systemRan [ 17 ] = ( sysRanDType * ) & rtDW .
a0fdk1tibo . c4bsnmlro2 ; systemRan [ 18 ] = ( sysRanDType * ) & rtDW .
cb0lxisazg . ax0ejju01d ; systemRan [ 19 ] = ( sysRanDType * ) & rtDW .
i5omdubmni . ax0ejju01d ; systemRan [ 20 ] = ( sysRanDType * ) & rtDW .
jrnrap5jzh . ax0ejju01d ; systemRan [ 21 ] = ( sysRanDType * ) & rtDW .
jucvauqnq3 . c4bsnmlro2 ; systemRan [ 22 ] = ( sysRanDType * ) & rtDW .
fallptwe4n . ax0ejju01d ; systemRan [ 23 ] = ( sysRanDType * ) & rtDW .
ej5frkoyu2 . ax0ejju01d ; systemRan [ 24 ] = ( sysRanDType * ) & rtDW .
airq053sdl . ax0ejju01d ; systemRan [ 25 ] = ( sysRanDType * ) & rtDW .
levrnc2uqr . ax0ejju01d ; systemRan [ 26 ] = ( sysRanDType * ) & rtDW .
jwm3vbffir . ax0ejju01d ; systemRan [ 27 ] = ( sysRanDType * ) & rtDW .
d2f14sz0ii . ax0ejju01d ; systemRan [ 28 ] = ( sysRanDType * ) & rtDW .
bj3t3ughuq . ax0ejju01d ; systemRan [ 29 ] = ( sysRanDType * ) & rtDW .
dl522p3brs . ax0ejju01d ; systemRan [ 30 ] = ( sysRanDType * ) & rtDW .
c51iqw5kno . ax0ejju01d ; systemRan [ 31 ] = ( sysRanDType * ) & rtDW .
n00rwomfjj . ax0ejju01d ; systemRan [ 32 ] = ( sysRanDType * ) & rtDW .
chwszqir1s . ax0ejju01d ; rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo (
rtS ) , & ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr (
ssGetRTWExtModeInfo ( rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr (
ssGetRTWExtModeInfo ( rtS ) , ssGetTPtr ( rtS ) ) ; } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 5 ; void MdlOutputsParameterSampleTime (
int_T tid ) { UNUSED_PARAMETER ( tid ) ; }
