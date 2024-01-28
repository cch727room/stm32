#include "./BSP/exit/exit.h"
#include "./SYSTEM/delay/delay.h"
#include "./BSP/LED/led.h"
void track_init(void)
{
		GPIO_InitTypeDef gpio_init_struct={0};
		
		gpio_init_struct.Pin = GPIO_PIN_13;
		gpio_init_struct.Mode = GPIO_MODE_INPUT;
		gpio_init_struct.Pull = GPIO_PULLUP;
		
		__HAL_RCC_GPIOB_CLK_ENABLE();
		
		HAL_GPIO_Init(GPIOB,&gpio_init_struct);
		
}

uint8_t track_scan(void)
{
	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_13)==0)
	{
		delay_ms(10); 	
		if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_13)==0)
		{	
				return 1;
		}
	}
	return 0;
	
}


void exit_init(void)
{
	  GPIO_InitTypeDef gpio_init_struct={0};
    __HAL_RCC_GPIOE_CLK_ENABLE();
    gpio_init_struct.Pin = GPIO_PIN_4;                   
    gpio_init_struct.Mode = GPIO_MODE_IT_FALLING;       
    gpio_init_struct.Pull = GPIO_PULLUP;       //上拉             
    HAL_GPIO_Init(GPIOE, &gpio_init_struct);  
	  HAL_NVIC_SetPriority(EXTI4_IRQn,2,0);
	  HAL_NVIC_EnableIRQ(EXTI4_IRQn);
}

void EXTI4_IRQHandler(void)    //中断
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_4);
}


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	delay_ms(20);
	if(GPIO_Pin == GPIO_PIN_4)
	{
		 if(HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_4)==0)
		 {
			 LED1_TOGGLE();
		 }
		 else
		 {
			 LED1_TOGGLE();
     }
	 }
 }