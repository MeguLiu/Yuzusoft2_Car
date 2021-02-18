/**
 * @Descripttion: 电机的相关函数
 * @Author: Tianle Liu
 * @Date: 2021-02-16 22:22:41
 */
#include "motor.h"

/*
 * @brief:电机初始化 
 * @param[in]: 电机结构体指针
 * @param[in]: 电机TIM结构体指针
 * @param[in]: 信号通道1
 * @param[in]: 信号通道2
 * @param[in]: 速度增益常数
 * @retval: void
 */

void MotorInit(Motor_t *motor, TIM_HandleTypeDef *motor_tim, uint32_t in1_ch, uint32_t in2_ch, float velocityGain)
{
    motor->MotorTIM = motor_tim;

    motor->L298N_IN1_Channel = in1_ch;
    motor->L298N_IN2_Channel = in2_ch;

    motor->VelocityGain = velocityGain;
}

/*
 * @brief: PWM模拟信号控制电机
 * @param[in]: 电机结构体指针
 * @param[in]: 期望速度
 * @retval: void
 */

void MotorPWMControl(Motor_t *motor, float velocity)
{
    if (velocity > 0)
    {
        SetPWM(motor->MotorTIM, motor->L298N_IN1_Channel, velocity * motor->VelocityGain);
        SetPWM(motor->MotorTIM, motor->L298N_IN2_Channel, 0);
    }
    if (velocity < 0)
    {
        SetPWM(motor->MotorTIM, motor->L298N_IN2_Channel, -velocity * motor->VelocityGain);
        SetPWM(motor->MotorTIM, motor->L298N_IN1_Channel, 0);
    }
}


/*
 * @brief: L298N使能单个电机
 * @param[in]: 电机使能GPIO端口
 * @param[in]: 电机使能GPIO引脚
 * @retval: void
 */

void Motor_L298N_Enable(GPIO_TypeDef *GPIO_Port, uint16_t GPIO_Pin)
{
    HAL_GPIO_WritePin(GPIO_Port, GPIO_Pin, GPIO_PIN_SET);
}

