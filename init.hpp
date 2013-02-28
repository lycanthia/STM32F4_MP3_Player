#ifndef INIT_INCLUDE_HPP
#define INIT_INCLUDE_HPP

void ledsInit();
void ADCInit();
void DACInit();
void userButtonInit();
void timer3Init(int prescaler, int period);
void timer4Init(int prescaler, int period);
void pwmInit();
void initRGB();
void pwmRGBInit();
void MY_DMA_initP2M(void);
void MY_ADC_init(void);
void MY_DMA_initM2P(void);
void MY_DAC_init(void);
void MY_DAC_initTimerForUpdating(void);
void DMA_M2M_Init();
void I2C_start(I2C_TypeDef* I2Cx, uint8_t address, uint8_t direction);
uint8_t I2C_read_ack(I2C_TypeDef* I2Cx);
void I2C_stop(I2C_TypeDef* I2Cx);
void I2C_slave_start(I2C_TypeDef* I2Cx);
void I2C_slave_stop(I2C_TypeDef* I2Cx);
uint8_t I2C_slave_read_nack(I2C_TypeDef* I2Cx);
uint8_t I2C_slave_read_ack(I2C_TypeDef* I2Cx);
uint8_t I2C_read_nack(I2C_TypeDef* I2Cx);
void I2C_write(I2C_TypeDef* I2Cx, uint8_t data);
void init_I2C1(void);
int abs(int a);
void Delay(__IO uint32_t nCount);

#endif
