/*******************************************************************************
 * Copyright (c) 2021-2022, OKMCU Development Team 
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Website: http://www.okmcu.com
 *
 * File Description: Template description.
 *
 * Change Logs:
 * Date         Author       Notes    
 * 2021-10-12   Wentao SUN   first version
 * 
 ******************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __HAL_H
#define __HAL_H
/* Includes ------------------------------------------------------------------*/
#include "bl_config.h"
/* Exported constants --------------------------------------------------------*/
#define HAL_OK                  0
#define HAL_ERR                 -1
/* Exported types ------------------------------------------------------------*/
typedef struct hal_uart_callback_s {
    void (*rxd_callback)(uint8_t rx_byte);
    void (*err_callback)(void);
}  hal_uart_callback_t;
/* Exported macro ------------------------------------------------------------*/
/* Exported variables --------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
void hal_enter_critical(void);
void hal_exit_critical(void);
void hal_reset(void);
void hal_jump_to_addr(uint32_t addr);
uint8_t hal_mcu_get_uuid(char *p_uuid, uint8_t size);

int8_t hal_wdg_config(uint16_t timeout);
int8_t hal_wdg_start(void);
int8_t hal_wdg_refresh(void);

int8_t hal_fmc_page_info(int32_t page, uint32_t *addr, uint32_t *size);
int8_t hal_fmc_page_erase(int32_t page);
int8_t hal_fmc_read(uint32_t addr, uint8_t *p_buf, uint32_t size);
int8_t hal_fmc_write(uint32_t addr, const uint8_t *p_buf, uint32_t size);

int8_t hal_emc_page_info(int32_t page, uint32_t *addr, uint32_t *size);
int8_t hal_emc_page_erase(int32_t page);
int8_t hal_emc_read(uint32_t addr, uint8_t *p_buf, uint32_t size);
int8_t hal_emc_write(uint32_t addr, const uint8_t *p_buf, uint32_t size);

int8_t hal_uart_config(uint32_t baudrate, const hal_uart_callback_t *cb);
int8_t hal_uart_send(uint8_t tx_byte);

#endif /* __HAL_H */

/******************************** END OF FILE *********************************/

