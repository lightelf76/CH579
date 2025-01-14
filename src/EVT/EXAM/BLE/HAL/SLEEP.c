/********************************** (C) COPYRIGHT *******************************
 * File Name          : SLEEP.c
 * Author             : WCH
 * Version            : V1.1
 * Date               : 2019/11/05
 * Description        : 睡眠配置及其初始化
 *********************************************************************************
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * Attention: This software (modified or not) and binary are used for 
 * microcontroller manufactured by Nanjing Qinheng Microelectronics.
 *******************************************************************************/

/******************************************************************************/
/* 头文件包含 */
#include "CH57x_common.h"
#include "HAL.h"


/*******************************************************************************
 * @fn          CH57X_LowPower
 *
 * @brief       启动睡眠
 *
 * input parameters
 *
 * @param       time-唤醒的时间点（RTC绝对值）
 *
 * output parameters
 *
 * @param       
 *
 * @return      None.
 */
u32 CH57X_LowPower( u32 time )
{
#if (defined (HAL_SLEEP)) && (HAL_SLEEP == TRUE)
    uint32_t time_sleep, time_curr;
		unsigned long irq_status;

    SYS_DisableAllIrq(&irq_status);
    time_curr = RTC_GetCycle32k();
    // 检测睡眠时间
    if (time < time_curr) {
        time_sleep = time + (RTC_TIMER_MAX_VALUE - time_curr);
    } else {
        time_sleep = time - time_curr;
    }

    // 若睡眠时间小于最小睡眠时间或大于最大睡眠时间，则不睡眠
    if ((time_sleep < SLEEP_RTC_MIN_TIME) || 
        (time_sleep > SLEEP_RTC_MAX_TIME)) {
        SYS_RecoverIrq(irq_status);
        return 2;
    }

  RTC_SetTignTime( time );
  SYS_RecoverIrq( irq_status );
#if( DEBUG == Debug_UART1 )
  while((R8_UART1_LSR&RB_LSR_TX_ALL_EMP)== 0 ) __nop();// 使用其他串口输出打印信息需要修改这行代码
#endif
// LOW POWER-sleep模式
  if( !RTCTigFlag ){
		LowPower_Sleep(RB_PWR_RAM2K|RB_PWR_RAM14K|RB_PWR_EXTEND );
		if(RTCTigFlag) // 注意如果使用了RTC以外的唤醒方式，需要注意此时32M晶振未稳定
		{
				time+=WAKE_UP_RTC_MAX_TIME;
				if( time > 0xA8C00000 )   time -= 0xA8C00000;
				RTC_SetTignTime( time );
				LowPower_Idle();
		}
    HSECFG_Current( HSE_RCur_100 );     // 降为额定电流(低功耗函数中提升了HSE偏置电流)
		SetSysClock( CLK_SOURCE_HSE_32MHz );
  }
  else{
    return 3;
  }
#endif
  return 0;
}

/*******************************************************************************
 * @fn          HAL_SleepInit
 *
 * @brief       配置睡眠唤醒的方式-RTC唤醒，触发模式
 *
 * input parameters
 *
 * @param       None.
 *
 * output parameters
 *
 * @param       
 *
 * @return      None.
 */
void HAL_SleepInit( void )
{
#if (defined (HAL_SLEEP)) && (HAL_SLEEP == TRUE)
  R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG1;		
  R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG2;
  R8_SLP_WAKE_CTRL  |= RB_SLP_RTC_WAKE; // RTC唤醒
  R8_RTC_MODE_CTRL  |= RB_RTC_TRIG_EN;	// 触发模式
  R8_SAFE_ACCESS_SIG = 0;						    // 
  NVIC_EnableIRQ(RTC_IRQn);	
#endif
}
