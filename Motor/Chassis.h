/**
  ******************************************************************************
  * File Name          : 
  * Description        : 
  * Author             :Tianle Liu             
  ******************************************************************************
  * @attention
  
  ******************************************************************************
  */
#ifndef _CHASSIS_H
#define _CHASSIS_H

#include "motor.h"
#include "ps2.h"
typedef struct 
{
    float Vx;
    float Vr;

    float VxGain;
    float VrGain;
    
    Motor_t ChassisMotor[2];
}Chassis_t;

void ChassisInit(void);
void ChassisCtrl(void);
void Chassis_L298N_Enable(void);
void Chassis_Clear(void);

#endif