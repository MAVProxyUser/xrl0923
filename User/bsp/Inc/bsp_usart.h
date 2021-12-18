#ifndef __BSP_USART_H
#define __BSP_USART_H

#include "usart.h"
#include "robot_task.h"
#include "communicating_task.h"
#include "bsp_xsens.h"
#include "bsp_6axis.h"

#define IMU_HUART huart7
#define UBUNTU_USART huart6
#define SIXAXIS_USART huart8

#define DMA_UBUNTU_LEN 150
#define DMA_IMU_LEN 150
#define DMA_SIXAXIS_LEN 150



/* External private variables ---------------------------------------------------------*/
extern DMA_HandleTypeDef hdma_usart6_rx;
extern DMA_HandleTypeDef hdma_uart8_rx;
extern uint8_t dma_ubuntu_buff[DMA_UBUNTU_LEN];
extern robot_TypeDef robot;

void user_uart_IRQHandle(UART_HandleTypeDef *huart); //�û��жϻص�����
void user_uart_IDLECallback(UART_HandleTypeDef *huart); //��������ж�

void uart_pkg_init(void); //���ڿ��� DMA��ʼ��


#endif
