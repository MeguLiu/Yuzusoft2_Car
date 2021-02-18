/**
 * @Descripttion: �������غ���
 * @Author: Tianle Liu
 * @Date: 2021-02-16 22:22:41
 */
#include "motor.h"

/*
 * @brief:�����ʼ�� 
 * @param[in]: ����ṹ��ָ��
 * @param[in]: ���TIM�ṹ��ָ��
 * @param[in]: �ź�ͨ��1
 * @param[in]: �ź�ͨ��2
 * @param[in]: �ٶ����泣��
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
 * @brief: PWMģ���źſ��Ƶ��
 * @param[in]: ����ṹ��ָ��
 * @param[in]: �����ٶ�
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
 * @brief: L298Nʹ�ܵ������
 * @param[in]: ���ʹ��GPIO�˿�
 * @param[in]: ���ʹ��GPIO����
 * @retval: void
 */

void Motor_L298N_Enable(GPIO_TypeDef *GPIO_Port, uint16_t GPIO_Pin)
{
    HAL_GPIO_WritePin(GPIO_Port, GPIO_Pin, GPIO_PIN_SET);
}

