
#ifndef __PS2_H__
#define __PS2_H__
#include "delay.h"
extern volatile int PS2_LX,PS2_LY,PS2_RX,PS2_RY,PS2_KEY;

//#define DI PBin(12)

//#define DO_H PBout(13)=1
//#define DO_L PBout(13)=0

//#define CS_H PBout(14)=1 
//#define CS_L PBout(14)=0

//#define CLK_H PBout(15)=1 
//#define CLK_L PBout(15)=0 

//These are our button constants
#define PSB_SELECT      1
#define PSB_L3          2
#define PSB_R3          3
#define PSB_START       4
#define PSB_PAD_UP      5
#define PSB_PAD_RIGHT   6
#define PSB_PAD_DOWN    7
#define PSB_PAD_LEFT    8
#define PSB_L2         9
#define PSB_R2          10
#define PSB_L1          11
#define PSB_R1          12
#define PSB_GREEN       13
#define PSB_RED         14
#define PSB_BLUE        15
#define PSB_PINK        16
#define PSB_TRIANGLE    13
#define PSB_CIRCLE      14
#define PSB_CROSS       15
#define PSB_SQUARE      26

//These are stick values
#define PSS_RX 5                //右摇杆X轴数据
#define PSS_RY 6
#define PSS_LX 7
#define PSS_LY 8

extern uint8_t Data[9];
extern uint16_t MASK[16];
extern uint16_t Handkey;

void PS2_Init(void);
uint8_t PS2_RedLight(void);//判断是否为红灯模式
void PS2_ReadData(void);
void PS2_Cmd(uint8_t CMD);		  //
uint8_t PS2_DataKey(void);		  //键值读取
uint8_t PS2_AnologData(uint8_t button); //得到一个摇杆的模拟量
void PS2_ClearData(void);	  //清除数据缓冲区
void delay_init(uint8_t SYSCLK);
void delay_us(uint32_t nus);

void PS2_ShortPoll(void);//short poll
void PS2_EnterConfing(void);//进入设置
void PS2_TurnOnAnalogMode(void);//保存并完成设置
void PS2_VibrationMode(void);
void PS2_ExitConfing(void);//保存并完成设置
void PS2_SetInit(void);//手柄设置初始化
void PS2_Vibration(uint8_t motor1 ,uint8_t motor2);
void PS2_Receive(void);



//位带操作,实现51类似的GPIO控制功能
//具体实现思想,参考<<CM3权威指南>>第五章(87页~92页).M4同M3类似,只是寄存器地址变了.
//IO口操作宏定义
//#define BITBAND(addr, bitnum) ((addr & 0xF0000000)+0x2000000+((addr &0xFFFFF)<<5)+(bitnum<<2)) 
//#define MEM_ADDR(addr)  *((volatile unsigned long  *)(addr)) 
//#define BIT_ADDR(addr, bitnum)   MEM_ADDR(BITBAND(addr, bitnum)) 
////IO口地址映射
//#define GPIOA_ODR_Addr    (GPIOA_BASE+12) //0x40010800
//#define GPIOB_ODR_Addr    (GPIOB_BASE+12) //0x40010c00 
//#define GPIOC_ODR_Addr    (GPIOC_BASE+12) //0x40011000 
//#define GPIOD_ODR_Addr    (GPIOD_BASE+12) //0x40011400
//#define GPIOE_ODR_Addr    (GPIOE_BASE+12) //0x40011800
//#define GPIOF_ODR_Addr    (GPIOF_BASE+12) //0x40011c00    
//#define GPIOG_ODR_Addr    (GPIOG_BASE+12) //0x40012000   
////#define GPIOH_ODR_Addr    (GPIOH_BASE+20) //0x40021C14    
////#define GPIOI_ODR_Addr    (GPIOI_BASE+20) //0x40022014     

//#define GPIOA_IDR_Addr    (GPIOA_BASE+8) //0x40020010 
//#define GPIOB_IDR_Addr    (GPIOB_BASE+8) //0x40020410 
//#define GPIOC_IDR_Addr    (GPIOC_BASE+8) //0x40020810 
//#define GPIOD_IDR_Addr    (GPIOD_BASE+8) //0x40020C10 
//#define GPIOE_IDR_Addr    (GPIOE_BASE+8) //0x40021010 
//#define GPIOF_IDR_Addr    (GPIOF_BASE+8) //0x40021410 
//#define GPIOG_IDR_Addr    (GPIOG_BASE+8) //0x40021810 
////#define GPIOH_IDR_Addr    (GPIOH_BASE+16) //0x40021C10 
////#define GPIOI_IDR_Addr    (GPIOI_BASE+16) //0x40022010 
// 
//IO口操作,只对单一的IO口!
//确保n的值小于16!
//#define PAout(n)   BIT_ADDR(GPIOA_ODR_Addr,n)  //输出 
//#define PAin(n)    BIT_ADDR(GPIOA_IDR_Addr,n)  //输入 

//#define PBout(n)   BIT_ADDR(GPIOB_ODR_Addr,n)  //输出 
//#define PBin(n)    BIT_ADDR(GPIOB_IDR_Addr,n)  //输入 

//#define PCout(n)   BIT_ADDR(GPIOC_ODR_Addr,n)  //输出 
//#define PCin(n)    BIT_ADDR(GPIOC_IDR_Addr,n)  //输入 

//#define PDout(n)   BIT_ADDR(GPIOD_ODR_Addr,n)  //输出 
//#define PDin(n)    BIT_ADDR(GPIOD_IDR_Addr,n)  //输入 

//#define PEout(n)   BIT_ADDR(GPIOE_ODR_Addr,n)  //输出 
//#define PEin(n)    BIT_ADDR(GPIOE_IDR_Addr,n)  //输入

//#define PFout(n)   BIT_ADDR(GPIOF_ODR_Addr,n)  //输出 
//#define PFin(n)    BIT_ADDR(GPIOF_IDR_Addr,n)  //输入

//#define PGout(n)   BIT_ADDR(GPIOG_ODR_Addr,n)  //输出 
//#define PGin(n)    BIT_ADDR(GPIOG_IDR_Addr,n)  //输入

////#define PHout(n)   BIT_ADDR(GPIOH_ODR_Addr,n)  //输出 
////#define PHin(n)    BIT_ADDR(GPIOH_IDR_Addr,n)  //输入

////#define PIout(n)   BIT_ADDR(GPIOI_ODR_Addr,n)  //输出 
////#define PIin(n)    BIT_ADDR(GPIOI_IDR_Addr,n)  //输入

#endif


