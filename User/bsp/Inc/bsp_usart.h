#ifndef __BSP_USART_H
#define __BSP_USART_H

#include "usart.h"
#include "robot_task.h"
#include "communicating_task.h"

//#define PRINTF_USART huart6
#define UBUNTU_USART huart6


#define DMA_UBUNTU_LEN 150



/* External private variables ---------------------------------------------------------*/
extern DMA_HandleTypeDef hdma_usart6_rx;
extern uint8_t dma_ubuntu_buff[DMA_UBUNTU_LEN];
extern robot_TypeDef robot;

void user_uart_IRQHandle(UART_HandleTypeDef *huart); //�û��жϻص�����
void user_uart_IDLECallback(UART_HandleTypeDef *huart); //��������ж�

void uart_pkg_init(void); //���ڿ��� DMA��ʼ��


#endif
