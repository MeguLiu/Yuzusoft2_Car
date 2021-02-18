
/**
 * @Descripttion: 底盘的头文件，包含底盘的结构体定义以及底盘的相关函数
 * @Author: Tianle Liu
 * @Date: 2021-02-16 22:13:36
 */
#include "Chassis.h"

Chassis_t Chassis;

/*
 * @brief: 底盘初始化函数
 * @param[in]: void
 * @retval: void
 */
void ChassisInit(void)
{
    Chassis_L298N_Enable();

    Chassis.Vr = 0;
    Chassis.Vx = 0;

    Chassis.VxGain = 1;
    Chassis.VrGain = 1;

    MotorInit(&Chassis.ChassisMotor[0], &htim1, TIM_CHANNEL_1, TIM_CHANNEL_2, 11.00f);
    MotorInit(&Chassis.ChassisMotor[1], &htim1, TIM_CHANNEL_3, TIM_CHANNEL_4, 11.00f);
}

/*
 * @brief: 底盘控制函数
 * @param[in]: void
 * @retval: void
 */
void ChassisCtrl(void)
{
    Chassis.Vr = PS2_RX * Chassis.VrGain;
    Chassis.Vx = PS2_LY * Chassis.VxGain;

    MotorPWMControl(&Chassis.ChassisMotor[0], Chassis.Vx + Chassis.Vr);
    MotorPWMControl(&Chassis.ChassisMotor[1], -Chassis.Vx + Chassis.Vr);
}

/*
 * @brief: L298N多电机使能函数
 * @param[in]: 无
 * @retval: 无
 */
void Chassis_L298N_Enable(void)
{
    Motor_L298N_Enable(ENA_GPIO_Port, ENA_Pin);
    Motor_L298N_Enable(ENB_GPIO_Port, ENB_Pin);
}

/*
 * @brief: 底盘电机数据清除
 * @param[in]: void
 * @retval: void
 */
void Chassis_Clear(void)
{
    TIM1->CCR1 = 0;
    TIM1->CCR2 = 0;
    TIM1->CCR3 = 0;
    TIM1->CCR4 = 0;
    TIM8->CCR1 = 0;
    TIM8->CCR2 = 0;
    TIM8->CCR3 = 0;
    TIM8->CCR4 = 0;
}
