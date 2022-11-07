// License       : License.txt
// Specifications: Spec-LM50C.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : LM50C.h
// Reason for change: 01.00.00 : 01/11/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#ifndef __LM50C_H__
#define __LM50C_H__

#include "user_define.h"

// Components number
#define iLM50C                  131U                    // Texas Instruments LM50C, LM50-Q1

// LM50C, LM50-Q1 System Parts definitions
#define iLM50C_xoff             0.5F                    // X offset [V]
#define iLM50C_yoff             0.0F                    // Y offset [degree celsius]
#define iLM50C_gain             0.01F                   // Gain [V/degree celsius]
#define iLM50C_max              125.0F                  // Temperature Max [degree celsius]
#define iLM50C_min              -40.0F                  // Temperature Min [degree celsius]

extern const tbl_adc_t tbl_LM50C;

#endif /*__LM50C_H__*/
