
#include "ps2.h"


#define DELAY_TIME  delay_us(2); 

#define DI HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_12)


#define DO_H HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,GPIO_PIN_SET)
#define DO_L HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,GPIO_PIN_RESET)

#define CS_H HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,GPIO_PIN_SET)
#define CS_L HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,GPIO_PIN_RESET)

#define CLK_H HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,GPIO_PIN_SET)
#define CLK_L HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,GPIO_PIN_RESET)
volatile int PS2_LX,PS2_LY,PS2_RX,PS2_RY,PS2_KEY;     //volatile??????,?????????????????
uint16_t Handkey;
//???????? :???????????
uint8_t Comd[2]={0x01,0x42};	

//??????
uint8_t Data[9]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

//???????
uint16_t MASK[]={
    PSB_SELECT,
    PSB_L3,
    PSB_R3 ,
    PSB_START,
    PSB_PAD_UP,
    PSB_PAD_RIGHT,
    PSB_PAD_DOWN,
    PSB_PAD_LEFT,
    PSB_L2,
    PSB_R2,
    PSB_L1,
    PSB_R1 ,
    PSB_GREEN,
    PSB_RED,
    PSB_BLUE,
    PSB_PINK
	};	//???????

	
/*
  ??????
  DI?DO????????8bit????
  ????????
  CLK??????????????????
*/
void PS2_Cmd(uint8_t CMD)
{
	volatile uint16_t ref=0x01;
	Data[1] = 0;
	for(ref=0x01;ref<0x0100;ref<<=1)//???,??
	{
		if(ref&CMD)//???,DO?????CMD
		{
			DO_H;                   //???????
		}
		else DO_L;

		CLK_H;                        //????
		DELAY_TIME;
		CLK_L; //??????????DO?DI??????
		DELAY_TIME;
		CLK_H;
		if(DI)
			Data[1] = ref|Data[1];//???????Data[1]?8?
	}
	delay_us(16);//??,???????????
}


//?????????  0x41=????  0x73=????
//???;0,????
//		  ??,????
uint8_t PS2_RedLight(void)
{
	CS_L;//??????????CS??????

	PS2_Cmd(Comd[0]);  //????
	PS2_Cmd(Comd[1]);  //????

	CS_H;//????,?????????CS_L,???????
	if( Data[1] == 0X73)   return 0 ;
	else return 1;

}

//??????
void PS2_ReadData(void)
{
	volatile uint8_t byte=0;
	volatile uint16_t ref=0x01;
    
	CS_L;
	PS2_Cmd(Comd[0]);  //????
	PS2_Cmd(Comd[1]);  //????
	for(byte=2;byte<9;byte++)          //??????
	{
		for(ref=0x01;ref<0x100;ref<<=1)
		{
			CLK_H;
			DELAY_TIME;
			CLK_L;
			DELAY_TIME;
			CLK_H;
		      if(DI)
		      Data[byte] = ref|Data[byte];
		}
        delay_us(16);
	}
	CS_H;
}

//?????PS2???????      ????????         ?????????  ?????????
//???0, ????1
uint8_t PS2_DataKey()
{
	uint8_t index;

	PS2_ClearData();
	PS2_ReadData();

	Handkey=(Data[4]<<8)|Data[3];     //??16???  ???0, ????1
	for(index=0;index<16;index++)
	{	    
		if((Handkey&(1<<(MASK[index]-1)))==0)
		return index+1;
	}
	return 0;          //????????
}

//??????????	 ??0~256
uint8_t PS2_AnologData(uint8_t button)
{
	return Data[button];
}

//???????
void PS2_ClearData()
{
	uint8_t a;
	for(a=0;a<9;a++)
		Data[a]=0x00;
}


//short poll
void PS2_ShortPoll(void)
{
	CS_L;
	delay_us(16);
	PS2_Cmd(0x01); //???? 
	PS2_Cmd(0x42); //????
	PS2_Cmd(0X00);
	PS2_Cmd(0x00);
	PS2_Cmd(0x00);
	CS_H;
	delay_us(16);	
}

//????
void PS2_EnterConfing(void)
{
    CS_L;
	delay_us(16);
	PS2_Cmd(0x01);  
	PS2_Cmd(0x43);  
	PS2_Cmd(0X00);
	PS2_Cmd(0x01);
	PS2_Cmd(0x00);
	PS2_Cmd(0X00);
	PS2_Cmd(0X00);
	PS2_Cmd(0X00);
	PS2_Cmd(0X00);
	CS_H;
	delay_us(16);
}

//??????
void PS2_TurnOnAnalogMode(void)
{
	CS_L;
	PS2_Cmd(0x01);  
	PS2_Cmd(0x44);  
	PS2_Cmd(0X00);
	PS2_Cmd(0x01); //analog=0x01;digital=0x00  ????????
	PS2_Cmd(0xEE); //Ox03????,???????�MODE�?????
				   //0xEE???????,?????�MODE�?????
	PS2_Cmd(0X00);
	PS2_Cmd(0X00);
	PS2_Cmd(0X00);
	PS2_Cmd(0X00);
	CS_H;
	delay_us(16);
}

// //????
// void PS2_VibrationMode(void)
// {
// 	CS_L;
// 	delay_us(16);
// 	PS2_Cmd(0x01);  
// 	PS2_Cmd(0x4D);  
// 	PS2_Cmd(0X00);
// 	PS2_Cmd(0x00);
// 	PS2_Cmd(0X01);
// 	CS_H;
// 	delay_us(16);	
// }


//???????
void PS2_ExitConfing(void)
{
  CS_L;
	delay_us(16);
	PS2_Cmd(0x01);  
	PS2_Cmd(0x43);  
	PS2_Cmd(0X00);
	PS2_Cmd(0x00);
	PS2_Cmd(0x5A);
	PS2_Cmd(0x5A);
	PS2_Cmd(0x5A);
	PS2_Cmd(0x5A);
	PS2_Cmd(0x5A);
	CS_H;
	delay_us(16);
}

//???????
void PS2_SetInit(void)
{
	PS2_ShortPoll();
	PS2_ShortPoll();
	PS2_ShortPoll();
	PS2_EnterConfing();		//??????
	PS2_TurnOnAnalogMode();	//�???�????,???????
  //PS2_VibrationMode();	//??????
	PS2_ExitConfing();		//???????
}

// /******************************************************
// Function:    void PS2_Vibration(u8 motor1, u8 motor2)
// Description: ??????,
// Calls:		 void PS2_Cmd(u8 CMD);
// Input: motor1:??????? 0x00?,???
// 	   motor2:??????? 0x40~0xFF ???,??? ????
// ******************************************************/
// void PS2_Vibration(uint8_t motor1, uint8_t motor2)
// {
// 	CS_L;
// 	delay_us(16);
//   PS2_Cmd(0x01);  //????
// 	PS2_Cmd(0x42);  //????
// 	PS2_Cmd(0X00);
// 	PS2_Cmd(motor1);
// 	PS2_Cmd(motor2);
// 	PS2_Cmd(0X00);
// 	PS2_Cmd(0X00);
// 	PS2_Cmd(0X00);
// 	PS2_Cmd(0X00);
// 	CS_H;
// 	delay_us(16);  
// }

//??????
void PS2_Receive(void)
{
		PS2_LX = PS2_AnologData(PSS_LX) - 128;
		PS2_LY = 256 - PS2_AnologData(PSS_LY) - 128 - 1;
		PS2_RX = PS2_AnologData(PSS_RX) - 128;
		PS2_RY = 256 - PS2_AnologData(PSS_RY) - 128 - 1;
			
		PS2_KEY=PS2_DataKey();
				
		if(PS2_RedLight() != 0)//?????????
		{
		  PS2_LX=0;
		  PS2_LY=0;
		  PS2_RX=0;
		  PS2_RY=0;
		}
}







