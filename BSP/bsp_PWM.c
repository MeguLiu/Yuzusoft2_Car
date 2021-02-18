/**
 * @Descripttion: PWMģ���ź���غ���
 * @Author: Tianle Liu
 * @Date: 2021-02-16 22:32:32
 */
#include "bsp_PWM.h"


/*
 * @brief: PWMģ���ź��������
 * @param[in]: ���TIM�ṹ��ָ��
 * @param[in]: TIM channel
 * @param[in]: ���ֵ
 * @retval: 1
 */

uint8_t  SetPWM(TIM_HandleTypeDef* tim, uint32_t channel, uint32_t value)
{
	switch (channel)
	{
		case TIM_CHANNEL_1:
			tim->Instance->CCR1 = value;
			break;
		case TIM_CHANNEL_2:
			tim->Instance->CCR2 = value;
			break;
		case TIM_CHANNEL_3:
			tim->Instance->CCR3 = value;
			break;
		case TIM_CHANNEL_4:
			tim->Instance->CCR4 = value;
			break;
		case TIM_CHANNEL_ALL:
			tim->Instance->CCR1 = value;
			tim->Instance->CCR2 = value;
			tim->Instance->CCR3 = value;
			tim->Instance->CCR4 = value;
			break;
		default :
			return 1;
		
		}

}