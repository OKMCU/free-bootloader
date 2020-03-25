/*******************************************************************************
 * Copyright (c) 2020-2021, Single-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 * 
 * Change Logs:
 * Date         Author       Notes
 * 2020-03-25   Wentao SUN   first version
 *
 ******************************************************************************/
 
/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include "hal_mcu.h"
#include "hal_uart.h"
#include "hal_flash.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static uint8_t cmd[256];
static uint16_t len;
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/* Exported variables --------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/

void main( void )
{
    hal_mcu_init();
    //hal_mcu_wdg_start();
    hal_uart_init();
    hal_uart_open(115200);

    len = 0;
    for(;;)
    {
        //hal_mcu_wdg_reset();

        len = hal_uart_read(cmd, sizeof(256));
        if(len)
        {
            hal_uart_write(cmd, len);
        }
    }

}
/****** (C) COPYRIGHT 2020 Single-Thread Development Team. *****END OF FILE****/
