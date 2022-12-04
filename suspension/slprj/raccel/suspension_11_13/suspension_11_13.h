#include "__cf_suspension_11_13.h"
#ifndef RTW_HEADER_suspension_11_13_h_
#define RTW_HEADER_suspension_11_13_h_
#include <stddef.h>
#include <float.h>
#include <string.h>
#include "rtw_modelmap.h"
#ifndef suspension_11_13_COMMON_INCLUDES_
#define suspension_11_13_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "sigstream_rtw.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "suspension_11_13_types.h"
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#define MODEL_NAME suspension_11_13
#define NSAMPLE_TIMES (6) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (336) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (32)   
#elif NCSTATES != 32
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { int8_T c4bsnmlro2 ; } hz4gtbawwx ; typedef struct { int8_T
ax0ejju01d ; } hjj4s3ojud ; typedef struct { real_T ckhfos3d5d ; real_T
ctr3nygjvu ; real_T gihker42li ; real_T fgv0iw5io4 ; real_T jbu2t0zvvf ;
real_T igbnss0o0f ; real_T cwi04tubt0 ; real_T khpnmtgkim ; real_T mcgc55onte
; real_T lxtjreczcv ; real_T g2y0j4r4xp ; real_T ivrqxfr4p2 ; real_T
pawhsqlpds ; real_T j4ut0d52c5 ; real_T ppy2yksd3e ; real_T dkbiwipjls ;
real_T cwjqfhgoni ; real_T c1vwcagcv1 ; real_T ohobmojlqf ; real_T ovbcvugezj
; real_T jvzmdt5nzv ; real_T f2micsnrzs ; real_T ncrqgav3ps ; real_T
aacyykkcvt ; real_T cur3cpy4nj ; real_T bvxzxcagw2 ; real_T ges324gpjn ;
real_T bv1suo0epr ; real_T kxytv3kagx ; real_T oy1jpf0hjr ; real_T hp1xxrtth5
; real_T oop0utfex2 ; real_T oe3cby5so1 ; real_T oshpndvkvq ; real_T
jn21fsqluy ; real_T kw2jpjnlx1 ; real_T n0e2xw5ck4 ; real_T nbl2g1zklu ;
real_T kgnzsa0lua ; real_T pw4bunpnxj ; real_T husvkqrr5g ; real_T iyiruigdqg
; real_T fir0lhcte1 ; real_T pizchjzfbl ; real_T ew12od4jo4 ; real_T
k0rxxdqz3n ; real_T cbs2crqgjz ; real_T obhdstfloy ; real_T jobgxinndp ;
real_T c35haqaiz1 ; real_T nrrfaz4txr ; real_T dnyl1ewlz0 ; real_T li3nwnnqnt
; real_T ds1h3d1hfe ; real_T gpq11xa2q4 ; real_T hossx3vmtu ; real_T
mrgu1y10yn ; real_T lgzpfz3f3w ; real_T dj1wmcvi0i ; real_T jrhinsm5vq ;
real_T mjw5ulp0gg ; real_T o50fwsfxem ; real_T hb00ru01fq ; real_T p4n4hpe1b1
; real_T hee11uhjj0 ; real_T dshdg4oozs ; real_T pc2izoasnn ; real_T
lw44fbjzmd ; real_T ap5mzmnsci ; real_T m2jdcg5lrr ; real_T kxzs0jwwpz ;
real_T n3tlanomdr ; real_T jjfmleyq2w ; real_T ffhybcifud ; real_T ou1c3oxils
; real_T mycmkus1bg ; real_T ajgpsl4ddz ; real_T odlkkgirey ; real_T
akesstvlt4 ; real_T ez0vdo0vnv ; real_T cm2qntqv5p ; real_T fifo30g12w ;
real_T foo13op1ju ; real_T hzo0vy2urp ; real_T bhip02e5fq ; real_T ir2wrhmfwi
; real_T peyixfnwtk ; real_T oxl1gbubgw ; real_T eclh5z3ew4 ; real_T
ketvnzudn2 ; real_T lia3hzxqko ; real_T pyyanjtp0n ; real_T owdhyrttis ;
real_T h53izkjog2 ; real_T odp1rox02t ; real_T jpajsss3mb ; real_T ngngrfhqxt
; real_T eemaj3mw1e ; real_T gaaymicbge ; real_T aubzgcsgjd ; real_T
eintirb2zo ; real_T ioubxgazf2 ; real_T hx0qhuwqax ; real_T cwvoke4n3w ;
real_T nnypggyeoc ; real_T eqkg2xr2dn ; real_T khvs2osnrm ; real_T f0mglil0tu
; real_T ors3z5ofsx ; real_T ewfilzdy5p ; real_T adv5kzimvn ; real_T
jzz0uec2gq ; real_T c12jn5x4j0 ; real_T iqjmjwfmns ; real_T afz2yt343k ;
real_T nu4szqiw1o ; real_T l5ft2k3pks ; real_T c4o1bl135b ; real_T fsb3gaohdk
; real_T bsh0ijyg1a ; real_T nvjwsszq20 ; real_T d3p1u0mvns ; real_T
hegnhw35oi ; real_T k44fqt4bzr ; real_T mzrg2hkek3 ; real_T irdye5g1gh ;
real_T dgotzim4ft ; real_T fkz2npxwns ; real_T h24izcfegy ; real_T p5qpsydo5q
; real_T lm0o0zjx1a ; real_T p4oanyhhie ; real_T p2gjpa4kz5 ; real_T
j5wjpnvys4 ; real_T of10q24r4f ; real_T p5tntlgroy ; real_T b0qoasefti ;
real_T gbtvk2ar5t ; real_T dx2og4efcz ; real_T eotgtd3vzy ; real_T nifjgpnast
; real_T bft4uxvudw ; real_T oxpgpvieu5 ; real_T e1fwyl5oca ; real_T
mlo35lys1s ; real_T div11ckje2 ; real_T ppxwyoa2bt ; real_T d14mmlv3sc ;
real_T aazow5qyx5 ; real_T hdsrwzf2hz ; real_T assjptryio ; real_T bqmgj4wdja
; real_T huti2k1olr ; real_T kpftqud0v4 ; real_T bewrfmxe51 ; real_T
fxe0oi5raa ; real_T b2vno41brr ; real_T pudus0mnkh ; real_T dacgyfnkti ;
real_T ksqxzrlacp ; real_T dhutim4yfg ; real_T jy1dhwzsny ; real_T nbmiv4o2qv
; real_T gnam0gpyvd ; real_T mxz0zykzkm ; real_T h2riih5p4x ; real_T
ezfjneuvrq ; real_T gzm1otmdfx ; real_T pat0zgdwxm ; real_T fpu4pfoo0u ;
real_T jsbnrcbw2w ; real_T a2rcbbb2nd ; real_T auaumgkulf ; real_T ca5bcarb1z
; real_T pmv2c05bpb ; real_T ni04k2if4f ; real_T avovxjitlj ; real_T
hl0nz2vhhx ; real_T dopbnbablw ; real_T clp5ptg2aq ; real_T nezd5agty4 ;
real_T leqschf41u ; real_T ihrr5jombz ; real_T a1cpk0zahd ; real_T iw40x310lw
; real_T csvnqlqe2c ; real_T op4fqs5y2b ; real_T egvgjshusc ; real_T
lhy0d514t0 ; real_T o1tgujpptc ; real_T ot505slkkd ; real_T f1s21kqqtk ;
real_T g5dxxhvf0d ; real_T dohdzn0els ; real_T kdcnvmuwdv ; real_T m4u0zxcmnx
; real_T lfbfrtbus5 ; real_T p4sojnckke ; real_T catep12smy ; real_T
k0c4i4a3eh ; real_T khzbqlyoyt ; real_T o35dwhcnte ; real_T memjmzawon ;
real_T poz0njf0k5 ; real_T ph2e13dkoz ; real_T mmzi51sdi4 ; real_T bu3dppt1dy
; real_T ihsi5ikxem ; real_T bptwtyixo3 ; real_T enljiew2kc ; real_T
fisd51h4xh ; real_T jazm3yw1lz ; real_T fu5nvqp5ki ; real_T ib3dugswvz ;
real_T gohkxwvfgd ; real_T o00l05l5h5 ; real_T imbewi4stk ; real_T hco0swv5mb
; real_T ivmbx4exri ; real_T gbegnosnia ; real_T h3go2eb5uu ; real_T
hdmwzbgags ; real_T o0p2ll51dt ; real_T hfprs0psjz ; real_T hywsl3f1uq ;
real_T iucqadbg2k ; real_T erjlcjtp4o ; real_T dkle40ro1c ; real_T ihgsjmwc0o
; real_T dhwgonfwmn ; real_T ftodx2djd4 ; real_T ihyeehrkag ; real_T
i1gcs32wge ; real_T hoerz5xdv5 ; real_T cv3osvvlrg ; real_T gqqadn4y2w ;
real_T o210behxg1 ; real_T hcfgyld3wj ; real_T hmut22z5qh ; real_T oo2wj0jvdb
; real_T ni1kcttkok ; real_T lqnznmftiq ; real_T ktwh1fzhvq ; real_T
pmogkogkdf ; real_T kemjegf3wo ; real_T gnnxhf24lb ; real_T fugfqhq0tc ;
real_T m3uxwq3r5m ; real_T c1btrhwl4q ; real_T li502xp5qt ; real_T lpc0zrp4fv
; real_T lv5avdu4zp ; real_T ehwkpevl2t ; real_T kjzusoosz1 ; real_T
nx3vnoo2r0 ; real_T dmq1oq0lr3 ; real_T cxhhghcvvq ; real_T ey4a5uz5cz ;
real_T dppbokyij3 ; real_T l3zyv4dhgg ; real_T huaehj053c ; real_T bhkcz3ic0o
; real_T nd01hmisxb ; real_T kjvdspgfqm ; real_T elpxc0kaoh ; real_T
jxndwbjtgb ; real_T ajj44xkzb4 ; real_T dvvipddzve ; real_T mqne5uhs2r ;
real_T b2erwm3zaa ; real_T p5bk0c5qbh ; real_T k4ai1xxr1d ; real_T dyzz0owi01
; real_T nyxhckusoe ; real_T cxloeisrlx ; real_T fk4xevkgeo ; real_T
ki1cdbfr44 ; real_T eqjo2nizcs ; real_T fba3iic2xf ; real_T eqhzihanz1 ;
real_T mzef1y2inq ; real_T pfkze4zldv ; real_T oeksgiw32q ; real_T cotqcoyxuq
; real_T aak2xlfzg2 ; real_T lewexece42 ; real_T dzjno1a2on ; real_T
l4rk2cmcdr ; real_T j14ytvzi0h ; real_T eozzahwbfw ; real_T jbs5lruqei ;
real_T muwt4hjweu ; real_T mxkquiaqra ; real_T igrtwxdc2h ; real_T bvpv0c32vh
; real_T jmwufnoosm ; real_T hpln2b3wuo ; real_T ltzcpo0hwy ; real_T
bn0qdk1o0v ; real_T ehrgc2nkcd ; real_T d04m0qgpku ; real_T nuubxbg4lx ;
real_T gebhzzqqrc ; real_T onqwhhqtnq ; real_T flrmowrcgb ; real_T bxeykf3lmp
; real_T dwgmiiuskf ; real_T got041r5yx ; real_T jya4dpmecv ; real_T
k3t5arlbzl ; real_T hysbptybxp ; real_T cdxeq3tabw ; real_T fzgl12rcaq ;
real_T ftf3u5jby5 ; real_T axn3i3rmpl ; real_T cur5w2fqr5 ; real_T p0nllhwxyq
; real_T eplzkxfoow ; real_T lufwhlk53w ; real_T e1yemdo2am ; real_T
jwnrysijt2 ; real_T p3mpeqccbg ; real_T hdzf4esqkr ; real_T g4gcmmpsrw ;
real_T hdh1v0e0hz ; real_T fc035ww10i ; real_T jag5k22tya ; real_T n2zjj1zkuh
; real_T hh5p0emnle ; real_T g2uumgoeu1 ; real_T c0i4zuvblr ; real_T
lxc1s1ijc2 ; real_T o4pksvc3du ; real_T p5mmmyyyb0 ; real_T f00vunio45 ;
real_T czwkigmd1x ; } B ; typedef struct { real_T gfprm23pj3 ; real_T
fqetutrbi5 ; real_T najgra25s3 ; real_T lx2q3mhajb ; real_T nflnwukwbw ;
real_T j4zffuf2jc ; real_T de4qoi0fyx ; real_T ay4ykamdli ; real_T jpmhq0y24v
; real_T eetn342tct ; real_T ijphmshkuf ; real_T pdelqeetgv ; real_T
mntyae3rsq ; real_T bxic41ulzf ; real_T psneabumzv ; real_T jhe2qhrig2 ;
real_T goagc5i3gw ; real_T ovio5arldz ; real_T k5o3zhu0wr ; real_T lioetblzpp
; real_T dqvle0o2bf ; real_T kr1ksgnw4x ; real_T dp5dxb3enf ; real_T
edxttokajv ; real_T lxx1qcag42 ; real_T f5ldw1c3yp ; real_T nktwazk3xa ;
real_T piqig1diza ; real_T hxmdtipph3 ; real_T lcjxt5exz4 ; real_T hrm31px4c4
; real_T i31w25jb1l ; struct { real_T modelTStart ; } itb4eyllvi ; struct {
real_T modelTStart ; } kxpps4lfxs ; struct { real_T modelTStart ; }
mx4clnficd ; struct { real_T modelTStart ; } j303c3104g ; struct { real_T
modelTStart ; } beayoquk50 ; struct { real_T modelTStart ; } kabx4cifu3 ;
struct { real_T modelTStart ; } k0upgp2t11 ; struct { real_T modelTStart ; }
pujypq4cfw ; struct { void * LoggedData [ 4 ] ; } ajc4mvkjxq ; struct { void
* LoggedData [ 4 ] ; } fiob3534rc ; struct { void * LoggedData [ 4 ] ; }
cby5njrl5e ; struct { void * LoggedData [ 4 ] ; } iyh423q2e1 ; struct { void
* LoggedData [ 4 ] ; } iu2ymd21go ; struct { void * TUbufferPtrs [ 2 ] ; }
jlohj4cavb ; struct { void * TUbufferPtrs [ 2 ] ; } l1amy53ft4 ; struct {
void * LoggedData ; } lyt4jukwzk ; struct { void * LoggedData ; } ovbos1312w
; struct { void * TUbufferPtrs [ 2 ] ; } omrnl2kvox ; struct { void *
TUbufferPtrs [ 2 ] ; } b0rupvaogl ; struct { void * LoggedData ; } glyj0mwrtn
; struct { void * LoggedData ; } leludl1mfe ; struct { void * TUbufferPtrs [
2 ] ; } onssg0ise1 ; struct { void * TUbufferPtrs [ 2 ] ; } h3nqanizu1 ;
struct { void * LoggedData ; } gg0snqxwle ; struct { void * LoggedData ; }
ddiov3wlge ; struct { void * TUbufferPtrs [ 2 ] ; } ip30edpzn0 ; struct {
void * TUbufferPtrs [ 2 ] ; } nrh2tscls2 ; struct { void * LoggedData ; }
ovc2kc0cmp ; struct { void * LoggedData ; } gn1lr2gvaw ; struct { int_T Tail
; int_T Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
ewcikv2lwd ; struct { int_T Tail ; int_T Head ; int_T Last ; int_T
CircularBufSize ; int_T MaxNewBufSize ; } fv0rpgctfs ; struct { int_T Tail ;
int_T Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
ped5kwc4j1 ; struct { int_T Tail ; int_T Head ; int_T Last ; int_T
CircularBufSize ; int_T MaxNewBufSize ; } aem0ceeew5 ; struct { int_T Tail ;
int_T Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
nogfvg0pt3 ; struct { int_T Tail ; int_T Head ; int_T Last ; int_T
CircularBufSize ; int_T MaxNewBufSize ; } hs0pmpahcd ; struct { int_T Tail ;
int_T Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
pmbhiaijnw ; struct { int_T Tail ; int_T Head ; int_T Last ; int_T
CircularBufSize ; int_T MaxNewBufSize ; } mbyl5zsvhx ; int_T gupv3wkm1k ;
int_T oe2kbpvny0 ; int_T ibxrdu4cbs ; int_T o0angb0u2w ; int8_T f3jqreldag ;
int8_T lkxdv3gp4l ; int8_T jqk4qa3xek ; int8_T jcg5lahs5d ; int8_T bugzjuygkx
; int8_T dd30o4lozm ; int8_T ljkqmp5hio ; int8_T mtbsrpr2ww ; int8_T
ndweztnvdz ; int8_T jg4lsy03zm ; int8_T lgxvz4jhdw ; int8_T hgbx4f0dqj ;
int8_T c12zxjgx2e ; int8_T d3g033qzzb ; int8_T kgnaiafrhn ; int8_T k4echvbh31
; hjj4s3ojud chwszqir1s ; hjj4s3ojud n00rwomfjj ; hjj4s3ojud c51iqw5kno ;
hjj4s3ojud dl522p3brs ; hjj4s3ojud bj3t3ughuq ; hjj4s3ojud d2f14sz0ii ;
hjj4s3ojud jwm3vbffir ; hjj4s3ojud levrnc2uqr ; hjj4s3ojud airq053sdl ;
hjj4s3ojud ej5frkoyu2 ; hjj4s3ojud fallptwe4n ; hz4gtbawwx jucvauqnq3 ;
hjj4s3ojud jrnrap5jzh ; hjj4s3ojud i5omdubmni ; hjj4s3ojud cb0lxisazg ;
hz4gtbawwx a0fdk1tibo ; hjj4s3ojud nkptjiojzm ; hjj4s3ojud blc3y3lbsz ;
hjj4s3ojud fo1s40z2ng ; hz4gtbawwx lxwl2pumah ; hjj4s3ojud fibtpbiz5w ;
hjj4s3ojud htznribv1q ; hjj4s3ojud k1t5j21xa2 ; hz4gtbawwx hzattc0vf2 ;
hjj4s3ojud bxy5pgokky ; hz4gtbawwx cical55ljv ; hjj4s3ojud gciy5nryyx ;
hz4gtbawwx iwvaw3chcg ; hjj4s3ojud ajnw1b3gfz ; hz4gtbawwx mysqkq0tgk ;
hjj4s3ojud fsrrbnl0ono ; hz4gtbawwx nbpepiek5as ; } DW ; typedef struct {
real_T juvpl32rp1 ; real_T e2u4ehzbg1 ; real_T kyyzo52dwm ; real_T ku1dk4ixzj
; real_T koq0js0atb ; real_T pionb1hpkd ; real_T gjyvqirdz3 ; real_T
aq3q20solx ; real_T o3tzwtysbm ; real_T bqwvntcz2w ; real_T lsnvs0t4wu ;
real_T bzhhffa4dl ; real_T bgj1d5tkhj ; real_T ky5ai02ezd ; real_T dplugctjxc
; real_T cpl1ejbcms ; real_T n2slq3mqpo ; real_T hxtsx1lenp ; real_T
ne20tsu1eg ; real_T hyvy5y052m ; real_T lqt0ebaexk ; real_T nherdhh2v5 ;
real_T ptgllb4wkr ; real_T avtxyi5gqp ; real_T b3davkt1eh ; real_T pulwqgjkwh
; real_T g2zcmmoypm ; real_T efgd0a2xyp ; real_T i3bwmkwwlg ; real_T
a01qpr25bd ; real_T gfofwzctbq ; real_T ixsdqmndrc ; } X ; typedef struct {
real_T juvpl32rp1 ; real_T e2u4ehzbg1 ; real_T kyyzo52dwm ; real_T ku1dk4ixzj
; real_T koq0js0atb ; real_T pionb1hpkd ; real_T gjyvqirdz3 ; real_T
aq3q20solx ; real_T o3tzwtysbm ; real_T bqwvntcz2w ; real_T lsnvs0t4wu ;
real_T bzhhffa4dl ; real_T bgj1d5tkhj ; real_T ky5ai02ezd ; real_T dplugctjxc
; real_T cpl1ejbcms ; real_T n2slq3mqpo ; real_T hxtsx1lenp ; real_T
ne20tsu1eg ; real_T hyvy5y052m ; real_T lqt0ebaexk ; real_T nherdhh2v5 ;
real_T ptgllb4wkr ; real_T avtxyi5gqp ; real_T b3davkt1eh ; real_T pulwqgjkwh
; real_T g2zcmmoypm ; real_T efgd0a2xyp ; real_T i3bwmkwwlg ; real_T
a01qpr25bd ; real_T gfofwzctbq ; real_T ixsdqmndrc ; } XDot ; typedef struct
{ boolean_T juvpl32rp1 ; boolean_T e2u4ehzbg1 ; boolean_T kyyzo52dwm ;
boolean_T ku1dk4ixzj ; boolean_T koq0js0atb ; boolean_T pionb1hpkd ;
boolean_T gjyvqirdz3 ; boolean_T aq3q20solx ; boolean_T o3tzwtysbm ;
boolean_T bqwvntcz2w ; boolean_T lsnvs0t4wu ; boolean_T bzhhffa4dl ;
boolean_T bgj1d5tkhj ; boolean_T ky5ai02ezd ; boolean_T dplugctjxc ;
boolean_T cpl1ejbcms ; boolean_T n2slq3mqpo ; boolean_T hxtsx1lenp ;
boolean_T ne20tsu1eg ; boolean_T hyvy5y052m ; boolean_T lqt0ebaexk ;
boolean_T nherdhh2v5 ; boolean_T ptgllb4wkr ; boolean_T avtxyi5gqp ;
boolean_T b3davkt1eh ; boolean_T pulwqgjkwh ; boolean_T g2zcmmoypm ;
boolean_T efgd0a2xyp ; boolean_T i3bwmkwwlg ; boolean_T a01qpr25bd ;
boolean_T gfofwzctbq ; boolean_T ixsdqmndrc ; } XDis ; typedef struct {
real_T juvpl32rp1 ; real_T e2u4ehzbg1 ; real_T kyyzo52dwm ; real_T ku1dk4ixzj
; real_T koq0js0atb ; real_T pionb1hpkd ; real_T gjyvqirdz3 ; real_T
aq3q20solx ; real_T o3tzwtysbm ; real_T bqwvntcz2w ; real_T lsnvs0t4wu ;
real_T bzhhffa4dl ; real_T bgj1d5tkhj ; real_T ky5ai02ezd ; real_T dplugctjxc
; real_T cpl1ejbcms ; real_T n2slq3mqpo ; real_T hxtsx1lenp ; real_T
ne20tsu1eg ; real_T hyvy5y052m ; real_T lqt0ebaexk ; real_T nherdhh2v5 ;
real_T ptgllb4wkr ; real_T avtxyi5gqp ; real_T b3davkt1eh ; real_T pulwqgjkwh
; real_T g2zcmmoypm ; real_T efgd0a2xyp ; real_T i3bwmkwwlg ; real_T
a01qpr25bd ; real_T gfofwzctbq ; real_T ixsdqmndrc ; } CStateAbsTol ; typedef
struct { real_T fyfri4vcfq ; real_T op2jtwngd2 ; real_T jxsw51r0f5 ; real_T
ljrsoy22v0 ; real_T itu0ythezp ; real_T jl5mxhh5wz ; real_T euwx0xke1o ;
real_T e43adcwpbp ; real_T kiauknssha ; real_T ai0se3v1ku ; real_T dnjciwluue
; real_T ntgs0g4eef ; real_T loeionkeyh ; real_T dlhgspcagz ; real_T
frdwevtiou ; real_T kmxmar43xe ; real_T ck4b0o5bls ; real_T d4wmkkqjtw ;
real_T cn1ocaebjc ; real_T cg0zc0qybx ; real_T cu4ffbrkwd ; real_T kfl2zw3ics
; real_T dtaod4lzlx ; real_T mteu3qk3we ; } ZCV ; typedef struct {
rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct P_ { real_T cfs ;
real_T cft ; real_T crs ; real_T crt ; real_T iyy ; real_T kfs ; real_T kft ;
real_T krs ; real_T krt ; real_T lf ; real_T lr ; real_T mc ; real_T mf ;
real_T mr ; real_T Integrator2_IC ; real_T Integrator2_IC_clvdfmmn2j ; real_T
Integrator2_IC_icgsg0ay1z ; real_T Integrator2_IC_izuk2xqhyn ; real_T
Integrator1_IC ; real_T Integrator1_IC_kd2vqetgqx ; real_T
Integrator1_IC_ds3xtg3mkc ; real_T Integrator1_IC_n5ffr0esli ; real_T
Integrator5_IC ; real_T Integrator5_IC_iosnn25ku4 ; real_T
Integrator5_IC_pbm1hhtqvq ; real_T Integrator5_IC_fmb14y3cnw ; real_T
Integrator3_IC ; real_T Gain_Gain ; real_T Integrator3_IC_h0aez5va4u ; real_T
Gain_Gain_kfgmdgojqi ; real_T Integrator3_IC_mc4a1wd42u ; real_T
Gain_Gain_lniewnxiui ; real_T Integrator3_IC_ghtohsff01 ; real_T
Gain_Gain_ncm0idjmjp ; real_T Integrator7_IC ; real_T
Integrator7_IC_bzmaczyftv ; real_T Integrator7_IC_hsyswncslp ; real_T
Integrator7_IC_jvqwwdf42v ; real_T Integrator_IC ; real_T Integrator4_IC ;
real_T Integrator6_IC ; real_T Gain9_Gain ; real_T Gain9_Gain_mm4lob34jr ;
real_T SignalGenerator_Amplitude ; real_T SignalGenerator_Frequency ; real_T
Step_Time ; real_T Step_Y0 ; real_T Step_YFinal ; real_T Step1_Time ; real_T
Step1_Y0 ; real_T Step1_YFinal ; real_T Gain_Gain_iit24j4qxf ; real_T
TransportDelay_Delay ; real_T TransportDelay_InitOutput ; real_T
Gain9_Gain_dqygs1aszs ; real_T TransportDelay1_Delay ; real_T
TransportDelay1_InitOutput ; real_T Gain9_Gain_okhtvkgje5 ; real_T
SignalGenerator_Amplitude_eudi0mxlsb ; real_T
SignalGenerator_Frequency_a50i2lvmye ; real_T Step_Time_mvs0g1sev0 ; real_T
Step_Y0_iz131rho11 ; real_T Step_YFinal_hqre2tmqod ; real_T
Step1_Time_jphzf3vxvl ; real_T Step1_Y0_pl0xadtajh ; real_T
Step1_YFinal_awmv2dzpr0 ; real_T Saturation_UpperSat ; real_T
Saturation_LowerSat ; real_T Integrator_IC_gsjia5qsst ; real_T
Integrator4_IC_cigt4hske3 ; real_T Integrator6_IC_h1i5q5y2jf ; real_T
Gain9_Gain_jglnwjr1da ; real_T Gain9_Gain_buqm2zp1xy ; real_T
SignalGenerator_Amplitude_fbk2hkdqfm ; real_T
SignalGenerator_Frequency_i1c2jxsnux ; real_T Step_Time_kxn30foah1 ; real_T
Step_Y0_dalzojkna3 ; real_T Step_YFinal_ikormlakvz ; real_T
Step1_Time_fxtabt0hzy ; real_T Step1_Y0_ihbov1sa5i ; real_T
Step1_YFinal_dudehtwvxl ; real_T Gain_Gain_cec0fvfroz ; real_T
TransportDelay_Delay_iap2op2zgh ; real_T TransportDelay_InitOutput_ea1344nau0
; real_T Gain9_Gain_fzv5tmgqw5 ; real_T TransportDelay1_Delay_e5t1cmi5b5 ;
real_T TransportDelay1_InitOutput_etxwutwb0s ; real_T Gain9_Gain_hick3dd3rf ;
real_T SignalGenerator_Amplitude_jqvsffusiy ; real_T
SignalGenerator_Frequency_o1bkitcbhj ; real_T Step_Time_d15jg5xwxc ; real_T
Step_Y0_frz4o3t2qo ; real_T Step_YFinal_mvwpnjqziy ; real_T
Step1_Time_a0qbodifis ; real_T Step1_Y0_dkhrl3hyib ; real_T
Step1_YFinal_iovgwjmexk ; real_T Saturation_UpperSat_nmc40qz4uh ; real_T
Saturation_LowerSat_avfz2gn5tr ; real_T Integrator_IC_e0ie1xk1t1 ; real_T
Integrator4_IC_bdrpcflxad ; real_T Integrator6_IC_ktopl34sag ; real_T
SignalGenerator_Amplitude_guqpb23tpp ; real_T
SignalGenerator_Frequency_m0wbhyregv ; real_T Step_Time_facad21pf1 ; real_T
Step_Y0_jeywlji0bq ; real_T Step_YFinal_pnkyifhjta ; real_T
Step1_Time_ia1tcvue3b ; real_T Step1_Y0_dmjz2ujtxq ; real_T
Step1_YFinal_htin21ftgl ; real_T Gain_Gain_goppgbgrif ; real_T
TransportDelay_Delay_eqwrqaxknp ; real_T TransportDelay_InitOutput_cflcileqko
; real_T TransportDelay1_Delay_didz0ysu0l ; real_T
TransportDelay1_InitOutput_gsatvdlebd ; real_T
SignalGenerator_Amplitude_fh5dm5543u ; real_T
SignalGenerator_Frequency_ji325krl5r ; real_T Step_Time_bwraqreocj ; real_T
Step_Y0_kdc10z30qv ; real_T Step_YFinal_kuwyhln44e ; real_T
Step1_Time_oqjaobvqli ; real_T Step1_Y0_cerqkmzec3 ; real_T
Step1_YFinal_gb5ur2tfsw ; real_T Saturation_UpperSat_lolh1xkie1 ; real_T
Saturation_LowerSat_f31445vevn ; real_T Integrator_IC_dw0j2rkbay ; real_T
Integrator4_IC_me53n3zt1r ; real_T Integrator6_IC_osnmqre5ia ; real_T
SignalGenerator_Amplitude_g44bgrrq31 ; real_T
SignalGenerator_Frequency_k0uyvcxxrq ; real_T Step_Time_n2vdheg15a ; real_T
Step_Y0_cl32zzujww ; real_T Step_YFinal_ioed2vlmyx ; real_T
Step1_Time_nrjoxzvdeh ; real_T Step1_Y0_nln5lb0z31 ; real_T
Step1_YFinal_kymwsjvu4f ; real_T Gain_Gain_ldzy4oavtu ; real_T
TransportDelay_Delay_frmicxredo ; real_T TransportDelay_InitOutput_jhwmjqic5y
; real_T TransportDelay1_Delay_oufsiqvqky ; real_T
TransportDelay1_InitOutput_i1rr3k5rot ; real_T
SignalGenerator_Amplitude_fqfftxwwhb ; real_T
SignalGenerator_Frequency_esatikfj0t ; real_T Step_Time_ief3iynhma ; real_T
Step_Y0_hbpv5svquz ; real_T Step_YFinal_jsjbxkocsk ; real_T
Step1_Time_iwq124hwmz ; real_T Step1_Y0_cxcqlzhc5m ; real_T
Step1_YFinal_kconhbutz2 ; real_T Saturation_UpperSat_gro4c0twir ; real_T
Saturation_LowerSat_k5krwyec4a ; real_T Constant_Value ; real_T
Constant1_Value ; real_T Constant_Value_js1bbvwx44 ; real_T
Constant1_Value_boctjgkrac ; real_T Constant_Value_pcb3rcescv ; real_T
Constant1_Value_az0xekyfmv ; real_T Constant_Value_i5zgqe2wta ; real_T
Constant1_Value_ojyctmrwrg ; real_T Constant_Value_gnxcisvqkz ; real_T
Constant1_Value_krl1nmx5tb ; real_T Constant2_Value ; real_T Constant3_Value
; real_T Constant_Value_j5obrm202k ; real_T Constant1_Value_gwq5uspikg ;
real_T Constant2_Value_npn4i05u3n ; real_T Constant3_Value_f5rovkb5n0 ;
real_T Constant_Value_p33xk1nt0c ; real_T Constant1_Value_iucvhmftri ; real_T
Constant2_Value_pwplpsvmqw ; real_T Constant3_Value_iyzr1ezzvq ; real_T
Constant_Value_hzj4wvktxf ; real_T Constant1_Value_kxn2zcp3ig ; real_T
Constant2_Value_icdxaqrdvn ; real_T Constant3_Value_ej5wa025ni ; real_T
Constant_Value_f34x3v0gei ; real_T Constant1_Value_gbvvgkwbnv ; real_T
Constant_Value_b0ss3j0del ; real_T Constant1_Value_mr12qranuj ; real_T
Constant_Value_ckbzzxjmxu ; real_T Constant1_Value_b5q3lrb3hv ; real_T
Constant_Value_ivnvcq4oxu ; real_T Constant1_Value_mj2nmzyxxv ; } ; extern
const char * RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX ;
extern DW rtDW ; extern P rtP ; extern const rtwCAPI_ModelMappingStaticInfo *
suspension_11_13_GetCAPIStaticMap ( void ) ; extern SimStruct * const rtS ;
extern const int_T gblNumToFiles ; extern const int_T gblNumFrFiles ; extern
const int_T gblNumFrWksBlocks ; extern rtInportTUtable * gblInportTUtables ;
extern const char * gblInportFileName ; extern const int_T
gblNumRootInportBlks ; extern const int_T gblNumModelInputs ; extern const
int_T gblInportDataTypeIdx [ ] ; extern const int_T gblInportDims [ ] ;
extern const int_T gblInportComplex [ ] ; extern const int_T
gblInportInterpoFlag [ ] ; extern const int_T gblInportContinuous [ ] ;
extern const int_T gblParameterTuningTid ; extern DataMapInfo *
rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ;
void MdlOutputs ( int_T tid ) ; void MdlOutputsParameterSampleTime ( int_T
tid ) ; void MdlUpdate ( int_T tid ) ; void MdlTerminate ( void ) ; void
MdlInitializeSizes ( void ) ; void MdlInitializeSampleTimes ( void ) ;
SimStruct * raccel_register_model ( void ) ;
#endif
