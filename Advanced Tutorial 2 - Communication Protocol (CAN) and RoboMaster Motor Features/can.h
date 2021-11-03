/**
  ******************************************************************************
  * @file    can.h
  * @brief   This file contains all the function prototypes for
  *          the can.c file
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __CAN_H__
#define __CAN_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

extern CAN_HandleTypeDef hcan1;
extern CAN_HandleTypeDef hcan2;

/* USER CODE BEGIN Private defines */
typedef struct{
	uint16_t    ecd;
	int16_t     speed_rpm;
	int16_t     given_current;
	uint8_t     temperate;
	int16_t		last_ecd;
}   motor_measure_t;
typedef enum{
	motor1 = 0,
	motor2 = 1,
	motor3 = 2,
	motor4 = 3,
}   motor_return;
typedef enum{
	CAN_GROUP_ID = 0x200,
	CAN_3508_M1_ID = 0x201,
	CAN_3508_M2_ID = 0x202,
	CAN_3508_M3_ID = 0x203,
	CAN_3508_M4_ID = 0x204,
}can_msg_id_e;
#define CAN1_DEVICE_NUM     4
#define FIRST_GROUP_ID      0x200
#define MOTOR_SPEED_MAX     16384
#define CAN_DATA_SIZE       8
#define CAN1_RX_ID_START    0x201
#define MOTOR_ID            2

/* USER CODE END Private defines */

void MX_CAN1_Init(void);
void MX_CAN2_Init(void);

/* USER CODE BEGIN Prototypes */
void can_filter_enable(CAN_HandleTypeDef* hcan);
void can_filter_disable(CAN_HandleTypeDef* hcan);
void can_transmit(CAN_HandleTypeDef* hcan, uint16_t id, int16_t msg1, int16_t msg2, int16_t msg3, int16_t msg4);
void can_trigger_motor(int16_t motor1,int16_t motor2,int16_t motor3,int16_t motor4);
void can_filter_init();
void can_init();
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan);
const motor_measure_t *get_rotate_motor_measure(uint8_t i);
void can_motor_feedback(CAN_HandleTypeDef *hcan);
/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __CAN_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
