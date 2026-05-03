/*
 * my_own.c
 *
 *  Created on: May 2, 2026
 *      Author: ChaoL
 */
#include "my_own.h"

extern UART_HandleTypeDef huart4;
/*printf support*/
int _write(int file, char *ptr, int len)
{
  uart_send_poll(&huart4, (uint8_t*)ptr, len, 50);
  return len;
}


void delay(uint32_t time)
{
	HAL_Delay(time);
}
/*gpio*/
void gpio_toggle(GPIO_TypeDef *gpio, uint16_t pin)
{
	HAL_GPIO_TogglePin(gpio, pin);
}
void gpio_set(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState)
{
	HAL_GPIO_WritePin(GPIOx, GPIO_Pin, PinState);
}

/*uart pool*/
void uart_send_poll(UART_HandleTypeDef *huart, uint8_t* buffer, uint16_t len, uint32_t timeout)
{
	HAL_UART_Transmit(huart, buffer, len, timeout);
}
void uart_receive_poll(UART_HandleTypeDef *huart, uint8_t* buffer, uint16_t len, uint32_t timeout)
{
	 HAL_UART_Receive(huart, buffer, len, timeout);

}

/*uart dma receive*/
void uart_receive_dma(UART_HandleTypeDef *huart, uint8_t* buffer, uint16_t len)
{
	HAL_UART_Receive_DMA(huart, buffer, len);
	//__HAL_UART_ENABLE_IT(GPIOx, UART_IT_IDLE); //enable this if you need to detect idle
}

//void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
//    if (huart->Instance == UART4) {
//        rx_ready = 1; // Hardware is free again!
//    }
//}

/*uart dma send*/
void uart_send_dma(UART_HandleTypeDef *huart, uint8_t* buffer, uint16_t len)
{
	HAL_UART_Transmit_DMA(huart, buffer, len);

}
//void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart) {
//    if (huart->Instance == UART4) {
//        tx_ready = 1; // Hardware is free again!
//    }
//}
/*uart dma to idle*/
void uart_receive_to_idle_dma(UART_HandleTypeDef *huart, uint8_t *buffer, uint16_t len)
{
	   HAL_UARTEx_ReceiveToIdle_DMA(huart, buffer, len);
	   __HAL_DMA_DISABLE_IT(huart->hdmarx, DMA_IT_HT);
}
//void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
//{
//	if (huart->Instance == UART4)
//	{
//	    rx_ready = 1; // Hardware is free again!
//	    rx_length = Size;
//	    memcpy(tx_buffer, rx_buffer, rx_length);
//	    HAL_UARTEx_ReceiveToIdle_DMA(&huart4, rx_buffer, 10);
//	    __HAL_DMA_DISABLE_IT(huart->hdmarx, DMA_IT_HT);
//
//	}
//}

/*adc poll*/
void adc_start(ADC_HandleTypeDef* adc)
{
	HAL_ADC_Start(adc);
}
void adc_stop(ADC_HandleTypeDef* adc)
{
	HAL_ADC_Stop(adc);
}
uint32_t adc_read(ADC_HandleTypeDef* adc)
{
	uint32_t ret = 0;
	if (HAL_ADC_PollForConversion(adc, 10) == HAL_OK)
	{
	    ret = HAL_ADC_GetValue(adc);
	}
	return ret;
}

/*adc interrupt*/
void adc_start_it(ADC_HandleTypeDef* adc)
{
	HAL_ADC_Start_IT(adc);
}
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* adc)
{
	if(adc->Instance == ADC1)
	{
//		adcValue = HAL_ADC_GetValue(adc); //assign the value to a global variable here
	}
}

/*adc dma*/
void adc_start_dma(ADC_HandleTypeDef* adc, uint32_t* results, uint16_t len)
{
	HAL_ADC_Start_DMA(adc, results, len);
}

/*conversion*/
uint32_t convert_to_value(uint32_t digit)
{
	return digit*330/4095;
}
uint32_t get_temp(uint32_t value)
{
	const uint32_t avg_slope = 430;
	const uint32_t v25 = 143;

	return (v25 - value)/avg_slope + 2500;
}

/*timer*/
void start_timer(TIM_HandleTypeDef *timer)
{
	HAL_TIM_Base_Start_IT(timer);
}
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *timer)
{
	gpio_toggle(GPIOB, GPIO_PIN_9);
}

/*timer output compare*/
void start_timer_oc(TIM_HandleTypeDef *timer, uint32_t channel)
{
	HAL_TIM_OC_Start(timer, channel);
}
