/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
// #include "Game.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
// void Game_Initial(void);
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED_D2_Pin GPIO_PIN_6
#define LED_D2_GPIO_Port GPIOA
#define LED_D3_Pin GPIO_PIN_7
#define LED_D3_GPIO_Port GPIOA
#define LCD_RST_Pin GPIO_PIN_11
#define LCD_RST_GPIO_Port GPIOB
#define LCD_DC_Pin GPIO_PIN_12
#define LCD_DC_GPIO_Port GPIOB
#define LCD_CS_Pin GPIO_PIN_8
#define LCD_CS_GPIO_Port GPIOD




/* USER CODE BEGIN Private defines */
#define Toggle_GPIO GPIOA
#define Toggle_X GPIO_PIN_5
#define Toggle_Y GPIO_PIN_4
#define Toggle_B GPIO_PIN_6
#define Button_GPIO GPIOE
#define Button_K0_PIN GPIO_PIN_3
#define Button_K1_PIN GPIO_PIN_4
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
