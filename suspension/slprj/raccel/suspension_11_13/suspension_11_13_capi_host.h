#include "__cf_suspension_11_13.h"
#ifndef RTW_HEADER_suspension_11_13_cap_host_h_
#define RTW_HEADER_suspension_11_13_cap_host_h_
#ifdef HOST_CAPI_BUILD
#include "rtw_capi.h"
#include "rtw_modelmap.h"
typedef struct { rtwCAPI_ModelMappingInfo mmi ; }
suspension_11_13_host_DataMapInfo_T ;
#ifdef __cplusplus
extern "C" {
#endif
void suspension_11_13_host_InitializeDataMapInfo (
suspension_11_13_host_DataMapInfo_T * dataMap , const char * path ) ;
#ifdef __cplusplus
}
#endif
#endif
#endif
