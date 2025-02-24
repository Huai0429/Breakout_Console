/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
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

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdio.h" 
#include "Game.h"
#include "adc.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define Task_num 2
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */
osThreadId_t Task1Handle;
osThreadId_t Task2Handle;
osThreadId_t Task3Handle;
osMutexId_t Mutex_LCDHandle;
/* USER CODE END Variables */
/* Definitions for defaultTask */
// osThreadId_t defaultTaskHandle;
// const osThreadAttr_t defaultTask_attributes = {
//   .name = "defaultTask",
//   .stack_size = 128 * 4,
//   .priority = (osPriority_t) osPriorityNormal,
// };
// /* Definitions for Task1 */
// osThreadId_t Task1Handle;
// const osThreadAttr_t Task1_attributes = {
//   .name = "Task1",
//   .stack_size = 128 * 4,
//   .priority = (osPriority_t) osPriorityHigh3,
// };
// /* Definitions for Task2 */
// osThreadId_t Task2Handle;
// const osThreadAttr_t Task2_attributes = {
//   .name = "Task2",
//   .stack_size = 128 * 4,
//   .priority = (osPriority_t) osPriorityHigh2,
// };
// /* Definitions for Task3 */
// osThreadId_t Task3Handle;
// const osThreadAttr_t Task3_attributes = {
//   .name = "Task3",
//   .stack_size = 128 * 4,
//   .priority = (osPriority_t) osPriorityHigh1,
// };

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
void Priority_Decision(int *Priority_list);
/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void *argument);
void Task1Entry(void *argument);
void Task2Entry(void *argument);
void Task3Entry(void *argument);


void Priority_Decision(int *Priority_list){
  for(int i = 0;i<Task_num;i++){

  }
}
void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  // int P_list[Task_num] = {0};
  // Priority_Decision(P_list);
  // osThreadId_t defaultTaskHandle;
  // const osThreadAttr_t defaultTask_attributes = {
  //   .name = "defaultTask",
  //   .stack_size = 128 * 4,
  //   .priority = (osPriority_t) osPriorityNormal,
  // };
  /* Definitions for Task1 */
  
  const osThreadAttr_t Task1_attributes = {
    .name = "Task1",
    .stack_size = 256 * 4,
    .priority = (osPriority_t) osPriorityHigh3,
    // .priority = P_list[0]
  };
  /* Definitions for Task2 */

  const osThreadAttr_t Task2_attributes = {
    .name = "Task2",
    .stack_size = 256 * 4,
    .priority = (osPriority_t) osPriorityHigh2,
    // .priority = P_list[1]
  };
  /* Definitions for Task3 */

  const osThreadAttr_t Task3_attributes = {
    .name = "Task3",
    .stack_size = 256 * 4,
    .priority = (osPriority_t) osPriorityHigh1,
  };


  const osMutexAttr_t Mutex_LCD_attributes = {
    .name = "Mutex_LCD"
  };
  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  Mutex_LCDHandle = osMutexNew(&Mutex_LCD_attributes);
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of defaultTask */
  // defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* creation of Task1 */
  Task1Handle = osThreadNew(Task1Entry, NULL, &Task1_attributes);

  /* creation of Task2 */
  Task2Handle = osThreadNew(Task2Entry, NULL, &Task2_attributes);

  /* creation of Task3 */
  Task3Handle = osThreadNew(Task3Entry, NULL, &Task3_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_Task1Entry */
/**
* @brief Function implementing the Task1 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task1Entry */
void Task1Entry(void *argument)
{
  /* USER CODE BEGIN Task1Entry */
  /* Infinite loop */
  int LED_flag = 1;
  // s_Ball_stat *ptrBall = &Ball;
  for(;;)
  {
    printf("%5d In Task1\n",xTaskGetTickCount());
    // (*ptrBall)->move_pfn(0,0,0);
    // osStatus_t stat = osMutexAcquire(Mutex_LCDHandle,2000);
    // if(stat != 0){
    //   printf("error in accquire mutex %d \n",(int)stat);
    // }
    int ret = (int)Ball_Move();
    if(ret != 1){
      for(;;)
        printf("Error in ball move!!!\n");
    }
    // printf("Release mutex\n");
    // stat = osMutexRelease(Mutex_LCDHandle);
    // printf("stat %d\n",stat);
    // if(stat != 0){
    //   printf("error in accquire mutex %d \n",(int)stat);
    // }


    // if(LED_flag){
    //   HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_SET);
    //   LED_flag = 0;
    // }else{
    //   HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_RESET);
    //   LED_flag = 1;
    // }
    printf("%5d In Task1 End\n",xTaskGetTickCount());
    osDelay(3);
  }
  /* USER CODE END Task1Entry */
}

/* USER CODE BEGIN Header_Task2Entry */
/**
* @brief Function implementing the Task2 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task2Entry */
void Task2Entry(void *argument)
{
  /* USER CODE BEGIN Task2Entry */
  /* Infinite loop */
  int LED_flag = 1;
  for(;;)
  {
    // printf("%5d In Task2\n",xTaskGetTickCount());
    if(LED_flag){
      HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,GPIO_PIN_SET);
      LED_flag = 0;
    }else{
      HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,GPIO_PIN_RESET);
      LED_flag = 1;
    }
    uint8_t Toggle_Xvalue = get_adc_value(5);
    uint8_t Toggle_Yvalue = get_adc_value(4);
    // uint8_t Toggle_Bvalue = HAL_GPIO_ReadPin(Toggle_GPIO,Toggle_B);
    uint8_t K0_val = HAL_GPIO_ReadPin(Button_GPIO,Button_K0_PIN);
    uint8_t K1_val = HAL_GPIO_ReadPin(Button_GPIO,Button_K1_PIN);

    printf("Button K0 %d K1 %d \n",K0_val,K1_val);

    // printf("X : %d, Y : %d\n",Toggle_Xvalue,Toggle_Yvalue);
    // printf("%5d In Task2 End\n",xTaskGetTickCount());
    osDelay(18);
  }
  /* USER CODE END Task2Entry */
}

/* USER CODE BEGIN Header_Task3Entry */
/**
* @brief Function implementing the Task3 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task3Entry */
void Task3Entry(void *argument)
{
  /* USER CODE BEGIN Task3Entry */
  /* Infinite loop */
  for(;;)
  {
    // printf("%5d In Task3\n",xTaskGetTickCount());
    // printf("%5d In Task3 End\n",xTaskGetTickCount());
    osDelay(44);
  }
  /* USER CODE END Task3Entry */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

