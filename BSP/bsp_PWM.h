/**
  ******************************************************************************
  * File Name          : 
  * Description        : 
  * Author             :Tianle Liu             
  ******************************************************************************
  * @attention
  
  ******************************************************************************
  */
#ifndef BSP_PWM_H
#define BSP_PWM_H
#include "tim.h"


uint8_t  SetPWM(TIM_HandleTypeDef* tim, uint32_t channel, uint32_t value);

#endif // !BSP_PWM_H
