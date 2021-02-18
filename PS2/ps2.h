
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
#define PSS_RX 5                //��ҡ��X������
#define PSS_RY 6
#define PSS_LX 7
#define PSS_LY 8

extern uint8_t Data[9];
extern uint16_t MASK[16];
extern uint16_t Handkey;

void PS2_Init(void);
uint8_t PS2_RedLight(void);//�ж��Ƿ�Ϊ���ģʽ
void PS2_ReadData(void);
void PS2_Cmd(uint8_t CMD);		  //
uint8_t PS2_DataKey(void);		  //��ֵ��ȡ
uint8_t PS2_AnologData(uint8_t button); //�õ�һ��ҡ�˵�ģ����
void PS2_ClearData(void);	  //������ݻ�����
void delay_init(uint8_t SYSCLK);
void delay_us(uint32_t nus);

void PS2_ShortPoll(void);//short poll
void PS2_EnterConfing(void);//��������
void PS2_TurnOnAnalogMode(void);//���沢�������
void PS2_VibrationMode(void);
void PS2_ExitConfing(void);//���沢�������
void PS2_SetInit(void);//�ֱ����ó�ʼ��
void PS2_Vibration(uint8_t motor1 ,uint8_t motor2);
void PS2_Receive(void);



//λ������,ʵ��51���Ƶ�GPIO���ƹ���
//����ʵ��˼��,�ο�<<CM3Ȩ��ָ��>>������(87ҳ~92ҳ).M4ͬM3����,ֻ�ǼĴ�����ַ����.
//IO�ڲ����궨��
//#define BITBAND(addr, bitnum) ((addr & 0xF0000000)+0x2000000+((addr &0xFFFFF)<<5)+(bitnum<<2)) 
//#define MEM_ADDR(addr)  *((volatile unsigned long  *)(addr)) 
//#define BIT_ADDR(addr, bitnum)   MEM_ADDR(BITBAND(addr, bitnum)) 
////IO�ڵ�ַӳ��
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
//IO�ڲ���,ֻ�Ե�һ��IO��!
//ȷ��n��ֵС��16!
//#define PAout(n)   BIT_ADDR(GPIOA_ODR_Addr,n)  //��� 
//#define PAin(n)    BIT_ADDR(GPIOA_IDR_Addr,n)  //���� 

//#define PBout(n)   BIT_ADDR(GPIOB_ODR_Addr,n)  //��� 
//#define PBin(n)    BIT_ADDR(GPIOB_IDR_Addr,n)  //���� 

//#define PCout(n)   BIT_ADDR(GPIOC_ODR_Addr,n)  //��� 
//#define PCin(n)    BIT_ADDR(GPIOC_IDR_Addr,n)  //���� 

//#define PDout(n)   BIT_ADDR(GPIOD_ODR_Addr,n)  //��� 
//#define PDin(n)    BIT_ADDR(GPIOD_IDR_Addr,n)  //���� 

//#define PEout(n)   BIT_ADDR(GPIOE_ODR_Addr,n)  //��� 
//#define PEin(n)    BIT_ADDR(GPIOE_IDR_Addr,n)  //����

//#define PFout(n)   BIT_ADDR(GPIOF_ODR_Addr,n)  //��� 
//#define PFin(n)    BIT_ADDR(GPIOF_IDR_Addr,n)  //����

//#define PGout(n)   BIT_ADDR(GPIOG_ODR_Addr,n)  //��� 
//#define PGin(n)    BIT_ADDR(GPIOG_IDR_Addr,n)  //����

////#define PHout(n)   BIT_ADDR(GPIOH_ODR_Addr,n)  //��� 
////#define PHin(n)    BIT_ADDR(GPIOH_IDR_Addr,n)  //����

////#define PIout(n)   BIT_ADDR(GPIOI_ODR_Addr,n)  //��� 
////#define PIin(n)    BIT_ADDR(GPIOI_IDR_Addr,n)  //����

#endif


