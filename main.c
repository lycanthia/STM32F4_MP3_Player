#include "includes.hpp"
#include "player.cpp"
#include "audio_sample.h"

int main(void)
{

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE);
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure ;
	TIM_TimeBaseStructure.TIM_Prescaler = 0;//Dzielnik czêstotliwosci sygnalu
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;//okresla tryb pracy licznika
	TIM_TimeBaseStructure.TIM_Period = 100;//Okresla liczbe impulsow do ktorej licznik zlicza
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;//okresla wybór dzielnika zegara dla uk³adu generacji dead-time i filtra
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;//okresla liczbe powtórzen w liczniku powtórzen.
	TIM_TimeBaseInit(TIM6, &TIM_TimeBaseStructure);
	TIM_SelectOutputTrigger(TIM6, TIM_TRGOSource_Update);
	TIM_Cmd(TIM6, ENABLE);
  	DACInit();
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA | RCC_AHB1Periph_GPIOB | RCC_AHB1Periph_GPIOC | RCC_AHB1Periph_GPIOD, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1 | RCC_APB1Periph_SPI3, ENABLE);
	RCC_PLLI2SCmd(ENABLE);

	GPIO_InitTypeDef PinInitStruct;
	PinInitStruct.GPIO_Pin = GPIO_Pin_4;
	PinInitStruct.GPIO_Mode = GPIO_Mode_OUT;
	PinInitStruct.GPIO_OType = GPIO_OType_PP;
	PinInitStruct.GPIO_PuPd = GPIO_PuPd_DOWN;
	PinInitStruct.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_Init(GPIOD, &PinInitStruct);

	PinInitStruct.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_9; //I2S SCL and SDA pins
	PinInitStruct.GPIO_Mode = GPIO_Mode_AF;
	PinInitStruct.GPIO_OType = GPIO_OType_OD;
	PinInitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	PinInitStruct.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_Init(GPIOB, &PinInitStruct);

	GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_I2C1);
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource9, GPIO_AF_I2C1);

	GPIO_PinAFConfig(GPIOA, GPIO_PinSource4, GPIO_AF_SPI3); //connecting pin 4 of port A to the SPI3 peripheral

	 /* CODEC_I2S pins configuration: WS, SCK and SD pins -----------------------------*/
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	I2S_InitTypeDef I2S_InitType;
	I2S_InitType.I2S_AudioFreq = I2S_AudioFreq_48k;
	I2S_InitType.I2S_MCLKOutput = I2S_MCLKOutput_Enable;
	I2S_InitType.I2S_Mode = I2S_Mode_MasterTx;
	I2S_InitType.I2S_DataFormat = I2S_DataFormat_16b;
	I2S_InitType.I2S_Standard = I2S_Standard_Phillips;
	I2S_InitType.I2S_CPOL = I2S_CPOL_Low;

	I2S_Init(SPI3, &I2S_InitType);
	I2S_Cmd(SPI3, ENABLE);

	/* Connect pins to I2S peripheral  */
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource4, GPIO_AF_SPI3);
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource10, GPIO_AF_SPI3);



	  /* Connect pins to I2C peripheral */

	 /* CODEC_I2S pins configuration: MCK pin */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	/* Connect pins to I2S peripheral  */
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource7, GPIO_AF_SPI3);

	I2C_InitTypeDef I2C_InitType;
	I2C_InitType.I2C_ClockSpeed = 100000;
	I2C_InitType.I2C_Mode = I2C_Mode_I2C;
	I2C_InitType.I2C_OwnAddress1 = 99;
	I2C_InitType.I2C_Ack = I2C_Ack_Enable;
	I2C_InitType.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
	I2C_InitType.I2C_DutyCycle = I2C_DutyCycle_2;



	I2C_Init(I2C1, &I2C_InitType);   //initialize the I2C peripheral ...
	I2C_Cmd(I2C1, ENABLE);          //... and turn it on

	GPIO_SetBits(GPIOD, GPIO_Pin_4);

	I2C_Write(0x02, 0x01);
	I2C_Write(0x04, 0xAF);
	I2C_Write(0x05, 0x81);
	I2C_Write(0x06, 0x04);
	I2C_Write(0x08, 0x01);
	I2C_Write(0x09, 0x01);
	I2C_Write(0x0E, 0xC0);
	I2C_Write(0x14, 0x00);
	I2C_Write(0x15, 0x00);
	I2C_Write(0x02, 0x9E);

	I2C_Write(0x1A, 0x00);
	I2C_Write(0x1B, 0x3F);

	I2C_Write(0x20, 0x00);
	I2C_Write(0x21, 0xFF);
	int16_t i = 0;
	//

	int a = 2;
	while(1)
    {


		while(SPI_I2S_GetFlagStatus(SPI3, SPI_I2S_FLAG_TXE) == RESET);
			SPI_I2S_SendData(SPI3, 0x00FF);
		i++;
    }
}
