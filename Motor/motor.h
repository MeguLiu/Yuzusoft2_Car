/**
 * @Descripttion: 电机相关结构体及函数
 * @Author: Tianle Liu
 * @Date: 2021-02-16 22:17:31
 */
#ifndef MOTOR_H
#define MOTOR_H

#include "tim.h"
#include "bsp_PWM.h"
#include "gpio.h"

typedef struct
{
    TIM_HandleTypeDef *MotorTIM;

    uint32_t L298N_IN1_Channel;
    uint32_t L298N_IN2_Channel;

    float VelocityGain;

} Motor_t;

void MotorInit(Motor_t *motor, TIM_HandleTypeDef *motor_tim, uint32_t in1_ch, uint32_t in2_ch, float velocityGain);
void MotorPWMControl(Motor_t *motor, float velocity);
void Motor_L298N_Enable(GPIO_TypeDef *GPIO_Port, uint16_t GPIO_Pin );

#endif // !MOTOR_H
