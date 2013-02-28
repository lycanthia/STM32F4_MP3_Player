#include "includes.hpp"
#include "init.hpp"
#include "zadania.hpp"

extern uint16_t ADC_Result;
extern uint16_t DAC_Result;
extern int zmienna1, zmienna2, zmienna3;
extern int DMA_R;
extern int DMA_B;

//PTM_02
//1)#
void Zadanie11(void)
{
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
  GPIO_InitTypeDef GPIO_InitStructure;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13| GPIO_Pin_14| GPIO_Pin_15;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOD, &GPIO_InitStructure);

  GPIO_SetBits(GPIOD, GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);

  while (1) {}
}

//2)#
void Zadanie12(void)
{
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA , ENABLE);
  GPIO_InitTypeDef GPIO_InitStructure;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13| GPIO_Pin_14| GPIO_Pin_15;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOD, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  while (1)
  {
	GPIO_ResetBits(GPIOD, GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);

	if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == 1)
	{
		GPIO_SetBits(GPIOD, GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
	}
  }
}

//3)#
void Zadanie13(void)
{
  int LEDId = 0;

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA , ENABLE);
  GPIO_InitTypeDef GPIO_InitStructure;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13| GPIO_Pin_14| GPIO_Pin_15;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOD, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  while (1)
  {
	GPIO_ResetBits(GPIOD, GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);

	if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == 1)
	{
		LEDId++;
		if (LEDId > 3)
			LEDId = 0;
	}

	GPIO_SetBits(GPIOD, GPIO_Pin_12<<LEDId);

    Delay(0x0322FF);
  }
}

//4)#
void Zadanie14(void)
{
  int LEDId = 0;

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA , ENABLE);
  GPIO_InitTypeDef GPIO_InitStructure;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13| GPIO_Pin_14| GPIO_Pin_15;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOD, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  while (1)
  {
	  GPIO_ResetBits(GPIOD, GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);

		if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == 1)
		{
			LEDId++;
			if (LEDId > 3)
				LEDId = 0;
		}

		GPIO_SetBits(GPIOD, GPIO_Pin_12<<LEDId);


    Delay(0x17FA40); //wg stopera jest to 1.03sek (na mojej p³ytce)
  }
}

//PTM_03

//1)#
void Lab3_1(void)
{
	SystemInit();
	SystemCoreClockUpdate();

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3 , ENABLE);

	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;

	TIM_TimeBaseStructure.TIM_Prescaler = 42000-1;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up ;
	TIM_TimeBaseStructure.TIM_Period = 2001;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0 ;
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0 ;
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure) ;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

	GPIO_InitTypeDef  GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOD, &GPIO_InitStructure);

	TIM_Cmd(TIM3, ENABLE);

  while (1)
  {
	  if (TIM_GetCounter(TIM3) == 1000)
	  {
		  TIM_SetCounter(TIM3, 0);
		  GPIO_ToggleBits(GPIOD, GPIO_Pin_12);
	  }
  }
}

//2)# teoretycznie to jest to
void Lab3_2()
{
	SystemInit();
	SystemCoreClockUpdate();

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOD, &GPIO_InitStructure);

	GPIO_PinAFConfig(GPIOD, GPIO_PinSource12, GPIO_AF_TIM4);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource13, GPIO_AF_TIM4);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource14, GPIO_AF_TIM4);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource15, GPIO_AF_TIM4);

	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_TimeBaseStructure.TIM_Prescaler = 42000-1; // czêstotliwosc regulujemy niby tym (wiêksza wartoæ ni¿sza czêstotliwosæ/maks 65000)
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up ;
	TIM_TimeBaseStructure.TIM_Period = 20; //maks jasnosc
	TIM_TimeBaseStructure.TIM_ClockDivision = 0 ;
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure) ;

	TIM_OCInitTypeDef TIM_OCInitStructure ;

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable ;
	TIM_OCInitStructure.TIM_Pulse = 0 ;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High ;

	TIM_OC1Init(TIM4, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);

	TIM_OC2Init(TIM4, &TIM_OCInitStructure);
	TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);

	TIM_OC3Init(TIM4, &TIM_OCInitStructure);
	TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable);

	TIM_OC4Init(TIM4, &TIM_OCInitStructure);
	TIM_OC4PreloadConfig(TIM4, TIM_OCPreload_Enable);

	TIM_ARRPreloadConfig(TIM4, ENABLE);
	TIM_Cmd(TIM4, ENABLE);

  while (1)
  {
	TIM4->CCR1 = 2;
	TIM4->CCR2 = 8;
	TIM4->CCR3 = 14;
	TIM4->CCR4 = 16;
  }
}

//3)# nie mam wyliczonego przedzialu 1-50Hz
void Lab3_3()
{
	SystemInit();
	SystemCoreClockUpdate();

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOD, &GPIO_InitStructure);

	GPIO_PinAFConfig(GPIOD, GPIO_PinSource12, GPIO_AF_TIM4);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource13, GPIO_AF_TIM4);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource14, GPIO_AF_TIM4);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource15, GPIO_AF_TIM4);

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA , ENABLE);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_TimeBaseStructure.TIM_Prescaler = 42000-1; // czêstotliwosc regulujemy niby tym (wiêksza wartoæ ni¿sza czêstotliwosæ/maks 65000)
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up ;
	TIM_TimeBaseStructure.TIM_Period = 20; //maks jasnosc
	TIM_TimeBaseStructure.TIM_ClockDivision = 0 ;
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure) ;

	TIM_OCInitTypeDef TIM_OCInitStructure ;

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable ;
	TIM_OCInitStructure.TIM_Pulse = 0 ;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High ;

	TIM_OC1Init(TIM4, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);

	TIM_OC2Init(TIM4, &TIM_OCInitStructure);
	TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);

	TIM_OC3Init(TIM4, &TIM_OCInitStructure);
	TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable);

	TIM_OC4Init(TIM4, &TIM_OCInitStructure);
	TIM_OC4PreloadConfig(TIM4, TIM_OCPreload_Enable);

	TIM_ARRPreloadConfig(TIM4, ENABLE);
	TIM_Cmd(TIM4, ENABLE);

	int preskaler = 42000;

  while (1)
  {
	  if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == 1)
	  {
		  TIM_PrescalerConfig(TIM4, preskaler, ENABLE);
		  preskaler-=100;
	  }

		TIM4->CCR1 = 2;
		TIM4->CCR2 = 8;
		TIM4->CCR3 = 16;
		TIM4->CCR4 = 19;

		Delay(0x0322FF);
  }
}

//4)#
void Lab3_4()
{
	SystemInit();
	SystemCoreClockUpdate();

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOD, &GPIO_InitStructure);

	GPIO_PinAFConfig(GPIOD, GPIO_PinSource12, GPIO_AF_TIM4);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource13, GPIO_AF_TIM4);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource14, GPIO_AF_TIM4);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource15, GPIO_AF_TIM4);

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA , ENABLE);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_TimeBaseStructure.TIM_Prescaler = (uint16_t) ((SystemCoreClock /2) / 21000000) - 1; // czêstotliwosc regulujemy niby tym (wiêksza wartoæ ni¿sza czêstotliwosæ/maks 65000)
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up ;
	TIM_TimeBaseStructure.TIM_Period = 200; //maks jasnosc
	TIM_TimeBaseStructure.TIM_ClockDivision = 0 ;
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure) ;

	TIM_OCInitTypeDef TIM_OCInitStructure ;

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable ;
	TIM_OCInitStructure.TIM_Pulse = 0 ;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High ;

	TIM_OC1Init(TIM4, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);

	TIM_OC2Init(TIM4, &TIM_OCInitStructure);
	TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);

	TIM_OC3Init(TIM4, &TIM_OCInitStructure);
	TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable);

	TIM_OC4Init(TIM4, &TIM_OCInitStructure);
	TIM_OC4PreloadConfig(TIM4, TIM_OCPreload_Enable);

	TIM_ARRPreloadConfig(TIM4, ENABLE);
	TIM_Cmd(TIM4, ENABLE);

	int jasnosc=0;
	short int kierunek=0;

  while (1)
  {
	if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == 1)
	{
		if (!kierunek)
		{
			jasnosc+=2;
			if (jasnosc == 200)
				kierunek = 1;
		}
		else
		{
			jasnosc-=2;
			if (jasnosc == 0)
				kierunek = 0;
		}
	}

	TIM4->CCR1 = jasnosc;
	TIM4->CCR2 = jasnosc;
	TIM4->CCR3 = jasnosc;
	TIM4->CCR4 = jasnosc;


	Delay(0x0322FF);
  }
}

//PTM_04

//1)#
extern int cykli;
extern int trybDiod;

/*void TIM3_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)
	{
		if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == 1)
			cykli++;
		else
			cykli = 0;

		if (cykli >= 3)
		{
			trybDiod++;
			cykli = 0;
		}

		switch (trybDiod)
		{
			case 0:
				{
					GPIO_ResetBits(GPIOD, GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
					GPIO_ToggleBits(GPIOD, GPIO_Pin_12);
					break;
				}
			case 1: {
					GPIO_ResetBits(GPIOD, GPIO_Pin_12 | GPIO_Pin_14 | GPIO_Pin_15);
					GPIO_ToggleBits(GPIOD, GPIO_Pin_13);
					break;
				}
			case 2: {
					GPIO_ResetBits(GPIOD, GPIO_Pin_12 | GPIO_Pin_13);
					GPIO_ToggleBits(GPIOD, GPIO_Pin_14 | GPIO_Pin_15);
					break;
					}
			default: trybDiod = 0;
		}

		TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
	}
}*/

void Lab4_1()
{
	SystemInit();
	SystemCoreClockUpdate();

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);

	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	GPIO_InitTypeDef GPIO_InitStructure;

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOA, &GPIO_InitStructure);


	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOD, &GPIO_InitStructure);


	// timerek
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_TimeBaseStructure.TIM_Prescaler = 42000;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up ;
	TIM_TimeBaseStructure.TIM_Period = 1000; //800
	TIM_TimeBaseStructure.TIM_ClockDivision = 0 ;
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure) ;

	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);

	TIM_Cmd(TIM3, ENABLE);

}

//2)# Bezsensowny przyk³ad...
/*void TIM3_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)
	{
	 GPIO_ToggleBits(GPIOD, GPIO_Pin_12);
	 TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
	}
}

void TIM4_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET)
	{
	 GPIO_ToggleBits(GPIOD, GPIO_Pin_13);
	 TIM_ClearITPendingBit(TIM4, TIM_IT_Update);
	}
}

void Lab4_2()
{
	SystemInit();
	SystemCoreClockUpdate();

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

	//tim 3
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

	//tim 4
	NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);


	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

	// dioda =)
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOD, &GPIO_InitStructure);

	// tim3
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_TimeBaseStructure.TIM_Prescaler = 42000;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up ;
	TIM_TimeBaseStructure.TIM_Period = 1000; //800
	TIM_TimeBaseStructure.TIM_ClockDivision = 0 ;
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure) ;

	// tim4
	TIM_TimeBaseStructure.TIM_Prescaler = 42000;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up ;
	TIM_TimeBaseStructure.TIM_Period = 2000; //800
	TIM_TimeBaseStructure.TIM_ClockDivision = 0 ;
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure) ;

	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);

	TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);

	TIM_Cmd(TIM3, ENABLE);

	TIM_Cmd(TIM4, ENABLE);

	while (1)
	{
		GPIO_ToggleBits(GPIOD, GPIO_Pin_12);
		GPIO_ToggleBits(GPIOD, GPIO_Pin_13);
		Delay(0x107FA40);
	}

}*/

//2)#B - mój przyk³ad

/*void TIM3_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)
	{
	 GPIO_SetBits(GPIOD, GPIO_Pin_12);
	 TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
	}
}

void TIM4_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET)
	{
	 GPIO_ResetBits(GPIOD, GPIO_Pin_12);
	 TIM_ClearITPendingBit(TIM4, TIM_IT_Update);
	}
}

void Lab4_2()
{
	SystemInit();
	SystemCoreClockUpdate();

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

	//tim 3
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01; //dioda bêdzie ca³y czas zgaszona!
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

	//tim 4
	NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02; // je¿eli ten priorytet bêdzie ni¿szy dioda bêdzie ca³y czas zapalona
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	// w tym wypadku: gaszenie -> wyw³aszczenie -> zapalenie -> gaszenie [moim zdaniem =p]

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);


	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

	// dioda =)
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOD, &GPIO_InitStructure);

	// tim3
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_TimeBaseStructure.TIM_Prescaler = 42000;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up ;
	TIM_TimeBaseStructure.TIM_Period = 1000; //800
	TIM_TimeBaseStructure.TIM_ClockDivision = 0 ;
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure) ;

	// tim4
	TIM_TimeBaseStructure.TIM_Prescaler = 42000;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up ;
	TIM_TimeBaseStructure.TIM_Period = 1000; //800
	TIM_TimeBaseStructure.TIM_ClockDivision = 0 ;
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure) ;

	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);

	TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);

	TIM_Cmd(TIM3, ENABLE);

	TIM_Cmd(TIM4, ENABLE);

}*/

//3)#EXTRA - przerwania zewnêtrzne
/*void EXTI0_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line0) != RESET)
	{
		GPIO_SetBits(GPIOD, GPIO_Pin_12);

		EXTI_ClearITPendingBit(EXTI_Line0);
	}
}

void Lab4_3()
{
	SystemInit();
	SystemCoreClockUpdate();

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);

	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	EXTI_InitTypeDef EXTI_InitStructure;
	EXTI_InitStructure.EXTI_Line = GPIO_Pin_0;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);

	GPIO_InitTypeDef GPIO_InitStructure;

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOD, &GPIO_InitStructure);

	SYSCFG_EXTILineConfig((uint32_t)GPIOA, EXTI_PinSource1);
}*/

//PTM_05
//1)#
void Lab5_1()
{
	SystemInit();
	SystemCoreClockUpdate();

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

	//tim 3
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	// dioda =)
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOD, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	// tim3
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_TimeBaseStructure.TIM_Prescaler = 42000;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up ;
	TIM_TimeBaseStructure.TIM_Period = 1000; //800
	TIM_TimeBaseStructure.TIM_ClockDivision = 0 ;
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure) ;

	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);

	TIM_Cmd(TIM3, ENABLE);

	while (1)
	{
		GPIO_ResetBits(GPIOD, GPIO_Pin_12);
		if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0))
			GPIO_SetBits(GPIOD, GPIO_Pin_12);
	}

}

//2)#
extern int LEDId;

/*void EXTI0_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line0) != RESET)
	{
		TIM_Cmd(TIM3, ENABLE);
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update);

		EXTI_ClearITPendingBit(EXTI_Line0);
	}
}

void TIM3_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)
	{
		if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0))
			LEDId++;

		TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
		TIM_Cmd(TIM3, DISABLE);
	}
}

void Lab5_2()
{
	SystemInit();
	SystemCoreClockUpdate();

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);

	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	EXTI_InitTypeDef EXTI_InitStructure;
	EXTI_InitStructure.EXTI_Line = GPIO_Pin_0;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);

	GPIO_InitTypeDef GPIO_InitStructure;

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOD, &GPIO_InitStructure);

	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_TimeBaseStructure.TIM_Prescaler = 42000;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up ;
	TIM_TimeBaseStructure.TIM_Period = 10; //800
	TIM_TimeBaseStructure.TIM_ClockDivision = 0 ;
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure) ;

	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);

	SYSCFG_EXTILineConfig((uint32_t)GPIOA, EXTI_PinSource0);

	while (1)
	{
		if (LEDId > 3)
			LEDId = 0;

		GPIO_ResetBits(GPIOD, GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
		GPIO_SetBits(GPIOD, GPIO_Pin_12<<LEDId); // tak powinno byæ wszêdzie, bêdzie trzeba pozamieniaæ =]
	}
}*/

//3)# obs³uguje zbocza narastajace, liczy cykle (przepe³nienia) zegara || nie uwzglêdnia zbocza opadaj¹cego, brak przeliczania na sekundy (nie wiem ile cykli jest wykonywanych w trakcie 1 sek)
#define period 65535

extern int liczba_impulsow1;
extern int liczba_impulsow2;

extern int cykle;

void TIM2_IRQHandler ( void )
{
	if (TIM_GetITStatus(TIM2, TIM_IT_CC1) == SET)
	{
		TIM_ClearITPendingBit (TIM2 ,TIM_IT_CC1);
		if (liczba_impulsow1 == -1)
			liczba_impulsow1 = TIM_GetCapture1(TIM2);
		else
			if (liczba_impulsow2 == -1)
				liczba_impulsow2 = TIM_GetCapture1(TIM2);
	}
}

void Lab5_3()
{
	SystemInit();
	SystemCoreClockUpdate();

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);

	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	GPIO_PinAFConfig (GPIOA, GPIO_PinSource0, GPIO_AF_TIM2);

	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_TimeBaseStructure.TIM_Prescaler = 1;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up ;
	TIM_TimeBaseStructure.TIM_Period = period;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0 ;
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure) ;

	TIM_ICInitTypeDef TIM_ICInitStructure ;
	TIM_ICInitStructure.TIM_Channel = TIM_Channel_1 ;
	TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising ;
	TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI ; //PA0
	TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1 ; // Div : 1 , every edge
	TIM_ICInitStructure.TIM_ICFilter = 0x0 ;
	TIM_ICInit(TIM2 ,&TIM_ICInitStructure ) ;

	TIM_ClearITPendingBit(TIM2 ,TIM_IT_CC1) ;
	TIM_ITConfig(TIM2, TIM_IT_CC1, ENABLE) ;

	TIM_Cmd (TIM2 , ENABLE) ;

	//TIM_ARRPreloadConfig(TIM2, ENABLE);

	int cyklePomiedzyKlikami = 0.0; // cykli

	int temp = 0;
	while (1)
	{
		if (TIM_GetCounter(TIM2) >= period-1)
			if ((liczba_impulsow1 > -1) && (liczba_impulsow2 == -1))
				cykle++;

		cyklePomiedzyKlikami = abs((liczba_impulsow2+cykle*period-cykle)-liczba_impulsow1);
	}
}

void PTM6_Init(){
	ledsInit();
	userButtonInit();
	ADCInit();
	DACInit();
	DMA_R = 1000;//Sk¹d przepisujemy
	DMA_B = 0;//Dok¹d przepisujemy
}

void PTM6_Zadanie1(){//Standardowe polaczenie ADC+DAC
	ADC_SoftwareStartConv(ADC1);
	while(ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET);
	ADC_Result = ADC_GetConversionValue(ADC1);
}

void PTM6_Zadanie2(){//DAC+ADC ze zmienna wartoscia DAC na przycisk
	static int i = 0;
	switch(i){
	case 0:
		i++;
		DAC_SetChannel1Data(DAC_Align_12b_R, 0xFFF);
	break;
	case 1:
		i++;
		DAC_SetChannel1Data(DAC_Align_12b_R, 0xFFF);
	break;
	case 2:
		i++;
		DAC_SetChannel1Data(DAC_Align_12b_R, 0x000);
	case 3:
		i = 0;
		DAC_SetChannel1Data(DAC_Align_12b_R, 0x000);
	break;
	}
	DAC_Result = DAC_GetDataOutputValue(DAC_Channel_1);
	ADC_SoftwareStartConv(ADC1);
	while(ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET);
		ADC_Result = ADC_GetConversionValue(ADC1);
	Delay(4000);
}
void PTM6_Zadanie3(){//DMA M2M, trzeba ustawic w mainie wartosci DMA_R i DMA_B
	static BOOL a = TRUE;
	if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) && a){
		DMA_M2M_Init();
		while(DMA_GetITStatus(DMA2_Stream0, DMA_IT_TCIF0) == SET)
		{
			asm("nop");
		}
		a = FALSE;
	}
}

void PTM9_Init(){
	//Odczytywanie wartosci potencjometru
	/*MY_DMA_initP2M();
	MY_ADC_init();
	ADC_SoftwareStartConv(ADC1);
	while(ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET);
		ADC_Result = ADC_GetConversionValue(ADC1);
	*/
	//Generowanie dzwieku na plytce rozszerzen, zmiana czestotliwosci ustawieniami timera 6
	MY_DAC_init();
	MY_DAC_initTimerForUpdating();
	MY_DMA_initM2P();
	DAC_Result = DAC_GetDataOutputValue(DAC_Channel_1);
}

void PTM10_Init(){
	//I2C
	SystemInit();
	SystemCoreClockUpdate(); // inicjalizacja dystrybucji czasu procesora
	init_I2C1(); // na podstawie: http://eliaselectronics.com/stm32f4-tutorials/stm32f4-i2c-mastertutorial
	I2C_start(I2C1, MCP9800_ADDRESS, I2C_Direction_Transmitter);
	I2C_write(I2C1,0x01); // ustaw adres rejestru Configuration Register
	I2C_write(I2C1,0x30); // ustaw rozdzielczosc na 12 bit
	I2C_stop(I2C1); // stop the transmission
	I2C_start(I2C1, MCP9800_ADDRESS, I2C_Direction_Transmitter);
	I2C_write(I2C1,0x00); // ustaw adres rejestru z temperatur¹
	I2C_stop(I2C1); // stop the transmission
}

void PTM10_Zadanie1(){//Odczytywanie temperatury, zmienna 3 to wynik
	I2C_start(I2C1, MCP9800_ADDRESS, I2C_Direction_Receiver); // start a transmission in Master
	//receiver mode
	zmienna2 = I2C_read_ack(I2C1); // read one byte and request another byte
	zmienna1 = I2C_read_nack(I2C1); // read one byte and don't request another byte
	I2C_stop(I2C1); // stop the transmission
	zmienna3 = (zmienna2 << 4) + (zmienna1 >> 4);
}
