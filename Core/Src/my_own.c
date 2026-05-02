/*
 * my_own.c
 *
 *  Created on: May 2, 2026
 *      Author: ChaoL
 */
#include "my_own.h"

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
