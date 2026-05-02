/*
 * my_own.h
 *
 *  Created on: May 2, 2026
 *      Author: ChaoL
 */

#ifndef INC_MY_OWN_H_
#define INC_MY_OWN_H_

#include "stm32f1xx_hal.h"

/*delay*/
void delay(uint32_t time);
/*gpio*/
void gpio_toggle(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
void gpio_set(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState);

/*uart pool*/
void uart_send_poll(UART_HandleTypeDef *huart, uint8_t* buffer, uint16_t len, uint32_t timeout);
void uart_receive_poll(UART_HandleTypeDef *huart, uint8_t* buffer, uint16_t len, uint32_t timeout);

/*uart dma*/
void uart_receive_dma(UART_HandleTypeDef *huart, uint8_t* buffer, uint16_t len);
void uart_send_dma(UART_HandleTypeDef *huart, uint8_t* buffer, uint16_t len);

/*uart dma to idle*/
void uart_receive_to_idle_dma(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Sizen);


#endif /* INC_MY_OWN_H_ */
