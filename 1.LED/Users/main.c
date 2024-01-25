
#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "./BSP/exit/exit.h"
#include "./BSP/LED/led.h"
void led_init(void);                       /* LED初始化函数声明 */

int main(void)
{
    HAL_Init();                         /* 初始化HAL库 */
    SystemClock_Config();/* 设置时钟, 72Mhz */
    delay_init(72);                     /* 延时初始化 */
    led_init();  	/* LED初始化 */
	  exit_init();
	  usart_init(115200);
	
	
	
    while(1)
    { 
			LED1_TOGGLE();
				delay_ms(500);
		}
			
        

    
}

/**
 * @brief       初始化LED相关IO口, 并使能时钟
 * @param       无
 * @retval      无
 */

