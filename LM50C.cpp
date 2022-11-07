// License       : License.txt
// Specifications: Spec-LM50C.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : LM50C.cpp
// Reason for change: 01.00.00 : 01/11/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#include        "LM50C.h"

#if     iLM50C_ma == iSMA                               // Simple moving average filter
static float32 LM50C_sma_buf[iLM50C_SMA_num];
static sma_f32_t LM50C_Phy_SMA =
{
        iInitial ,                                      // Initial state
        iLM50C_SMA_num ,                                // Simple moving average number & buf size
        0U ,                                            // buffer position
        0.0F ,                                          // sum
        &LM50C_sma_buf[0]                               // buffer
};

#elif   iLM50C_ma == iEMA                               // Exponential moving average filter
static ema_f32_t LM50C_Phy_EMA =
{
        iInitial ,                                      // Initial state
        0.0F ,                                          // Xn-1
        iLM50C_EMA_K                                    // Exponential smoothing factor
};

#elif   iLM50C_ma == iWMA                               // Weighted moving average filter
static float32 LM50C_wma_buf[iLM50C_WMA_num];
static wma_f32_t LM50C_Phy_WMA =
{
        iInitial ,                                      // Initial state
        iLM50C_WMA_num ,                                // Weighted moving average number & buf size
        0U ,                                            // buffer poition
        iLM50C_WMA_num * (iLM50C_WMA_num + 1)/2 ,       // kn sum
        &LM50C_wma_buf[0]                               // Xn buffer
};

#else                                                   // Non-moving average filter
#endif

#define iDummy_adr       0xffffffff                     // Dummy address

const tbl_adc_t tbl_LM50C =
{
        iLM50C                  ,
        iLM50C_pin              ,
        iLM50C_xoff             ,
        iLM50C_yoff             ,
        iLM50C_gain             ,
        iLM50C_max              ,
        iLM50C_min              ,
        iLM50C_ma               ,
        
#if     iLM50C_ma == iSMA                               // Simple moving average filter
        &LM50C_Phy_SMA          ,
        (ema_f32_t*)iDummy_adr  ,
        (wma_f32_t*)iDummy_adr
#elif   iLM50C_ma == iEMA                               // Exponential moving average filter
        (sma_f32_t*)iDummy_adr  ,
        &LM50C_Phy_EMA          ,
        (wma_f32_t*)iDummy_adr
#elif   iLM50C_ma == iWMA                               // Weighted moving average filter
        (sma_f32_t*)iDummy_adr  ,
        (ema_f32_t*)iDummy_adr  ,
        &LM50C_Phy_WMA
#else                                                   // Non-moving average filter
        (sma_f32_t*)iDummy_adr  ,
        (ema_f32_t*)iDummy_adr  ,
        (wma_f32_t*)iDummy_adr
#endif

};
