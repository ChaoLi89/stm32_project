/*
 * my_own.h
 *
 *  Created on: May 2, 2026
 *      Author: ChaoL
 */

#ifndef INC_MY_OWN_H_
#define INC_MY_OWN_H_

#include "stm32f1xx_hal.h"

/*printf support*/
int _write(int file, char *ptr, int len);

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

/*adc poll*/
void adc_start(ADC_HandleTypeDef* adc);
void adc_stop(ADC_HandleTypeDef* adc);
uint32_t adc_read(ADC_HandleTypeDef* adc);


/*adc interrupt*/
void adc_start_it(ADC_HandleTypeDef* adc);
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* adc);

/*adc dma*/
void adc_start_dma(ADC_HandleTypeDef* adc, uint32_t* results, uint16_t len);
//HAL_ADC_ConvCpltCallback this callback is also called when DMA finishes moving the data from the register to memory

/*temparature*/
uint32_t get_temp(uint32_t value);
uint32_t convert_to_value(uint32_t digit);

#endif /* INC_MY_OWN_H_ */
